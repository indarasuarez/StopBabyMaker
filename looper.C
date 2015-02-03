#include <string.h>
#include <iostream>
#include <vector>
#include <typeinfo>

#include "looper.h"
#include "CORE/CMS3.h" 
#include "CORE/MuonSelections.h"
#include "CORE/ElectronSelections.h"

#include "TBenchmark.h"
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TROOT.h"
#include "TTreeCache.h"
/*
#include "TBufferFile.h"
#include "TStreamer.h"
#include "TStreamerInfo.h"
#include "TBenchmark.h"
*/
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

using namespace std;
//using namespace tas;
//Switches
char* path = ".";

babyMaker::babyMaker()
{
   lep1 = LeptonTree("lep1_");
   lep2 = LeptonTree("lep2_");
}

//Main functions
void babyMaker::MakeBabyNtuple(const char* output_name){

  BabyFile = new TFile(Form("%s/%s", path, output_name), "RECREATE");
  BabyTree = new TTree("t", "Stop2015 Baby Ntuple");

  //Define Branches
  StopEvt.SetBranches(BabyTree);
  lep1.SetBranches(BabyTree);
  lep2.SetBranches(BabyTree);
  jets.SetBranches(BabyTree);
}

void babyMaker::InitBabyNtuple(){
    //Clear variables
    StopEvt.Reset();
    lep1.Reset();
    lep2.Reset();
    jets.Reset();
} 

//Main function
int babyMaker::looper(TChain* chain, char* output_name, int nEvents, string signal_in){

  // Benchmark
    TBenchmark *bmark = new TBenchmark();
    bmark->Start("benchmark");

  //Set up loop over chain
    unsigned int nEventsDone = 0;
    unsigned int nEvents_GoodVtx = 0;
    unsigned int nEvents_MET30 = 0;
    unsigned int nEvents_GoodLep = 0;
    unsigned int nEvents_2GoodJets = 0;
    unsigned int nEventsToDo = chain->GetEntries();

  if( nEvents >= 0 ) nEventsToDo = nEvents;
  TObjArray *listOfFiles = chain->GetListOfFiles();
  TIter fileIter(listOfFiles);
  TFile *currentFile = 0;

 //Make Baby Ntuple  
  MakeBabyNtuple( Form("%s.root", output_name) );
 //Initialize Baby Ntuple
  InitBabyNtuple();

  // File Loop
  while ( (currentFile = (TFile*)fileIter.Next()) ) { 

    // Get File Content
    if(nEventsDone >= nEventsToDo) continue;
    TFile *file = new TFile( currentFile->GetTitle() );
    TTree *tree = (TTree*)file->Get("Events");
    cms3.Init(tree);
    cout << "file name is " << file->GetName() << endl;

    // Loop over Events in current file
    unsigned int nEventsTree = tree->GetEntriesFast();

    for(unsigned int evt = 0; evt < nEventsTree; evt++){

      // Get Event Content
      if(nEventsDone >= nEventsToDo) break;
      cms3.GetEntry(evt);
      nEventsDone++;

      // Progress
      CMS3::progress(nEventsDone, nEventsToDo);

      InitBabyNtuple();

   //   std::cout << "[babymaker::looper]: filling event vars" << std::endl;
      //Fill Event Variables
      StopEvt.FillCommon(file->GetName()); 
      if(StopEvt.nvtxs<1) continue;
      nEvents_GoodVtx++;
      if(cms3.evt_pfmet()<30.) continue;
      nEvents_MET30++;

      //Lepton Variables
      int nGoodLeptons = 0;
      for (unsigned int eidx = 0; eidx < cms3.els_p4().size(); eidx++){
       // if (!isGoodVetoElectron(eidx)) continue;
        if(!PassElectronPreSelections(eidx)) continue;
        nGoodLeptons++;
        if(nGoodLeptons==1) lep1.FillCommon(11,eidx);
        if(nGoodLeptons==2) lep2.FillCommon(11,eidx);
      }
      for (unsigned int muidx = 0; muidx < cms3.mus_p4().size(); muidx++){
        //if (!isGoodVetoMuon(muidx)) continue;
       if(!PassMuonPreSelections(muidx)) continue;
       nGoodLeptons++;
       if(nGoodLeptons==1) lep1.FillCommon(13,muidx);
       if(nGoodLeptons==2) lep2.FillCommon(13,muidx);
      }
      if(nGoodLeptons<1) continue;
      nEvents_GoodLep++;
      StopEvt.ngoodlep = nGoodLeptons;

      // std::cout << "[babymaker::looper]: filling jets vars" << std::endl;         
     //jets and b-tag variables
       jets.FillCommon();
      if(jets.ak4GoodPFJets < 2) continue;
      nEvents_2GoodJets++;

     //taus and pf charged cands
      int ntau = 0;
      for(unsigned int iTau = 0; iTau < cms3.taus_pf_p4().size(); iTau++){
        if(cms3.taus_pf_p4().at(iTau).pt() < 20.0) continue;
        if(fabs(cms3.taus_pf_p4().at(iTau).eta()) > 2.3) continue;
  //                  if(!cms3.taus_pf_byDecayModeFinding().at(iTau)) continue;
              if (!cms3.taus_pf_byLooseCombinedIsolationDeltaBetaCorr3Hits().at(iTau)) continue; // HPS3 hits taus
           //   if (!cms3.taus_pf_againstElectronLoose().at(iTau)) continue; // loose electron rejection                                                                                                                                  
           //                // if (!cms3.taus_pf_againstMuonTight().at(iTau)) continue; // loose muon rejection                                                                      
        StopEvt.tau_p4.push_back(cms3.taus_pf_p4().at(iTau));
        StopEvt.tau_charge.push_back(cms3.taus_pf_charge().at(iTau));
        StopEvt.tau_MedisoCI3hit.push_back(cms3.taus_pf_byMediumCombinedIsolationDeltaBetaCorr3Hits().at(iTau));
         StopEvt.tau_againstElectronLoose.push_back(cms3.taus_pf_againstElectronLoose().at(iTau));
         StopEvt.tau_againstMuonTight.push_back(cms3.taus_pf_againstMuonTight().at(iTau));

         ntau++;
      }
     StopEvt.Ntaus=ntau;
     for (unsigned int ipf = 0; ipf < cms3.pfcands_p4().size(); ipf++) {

        if(cms3.pfcands_charge().at(ipf) == 0) continue;
        if(cms3.pfcands_p4().at(ipf).pt() < 5) continue;
        if(fabs(cms3.pfcands_dz().at(ipf)) > 0.1) continue;

        StopEvt.isoTrack_pt.push_back    ( cms3.pfcands_p4().at(ipf).pt()   );
        StopEvt.isoTrack_eta.push_back   ( cms3.pfcands_p4().at(ipf).eta()  );
        StopEvt.isoTrack_phi.push_back   ( cms3.pfcands_p4().at(ipf).phi()  );
        StopEvt.isoTrack_mass.push_back  ( cms3.pfcands_mass().at(ipf)      );
        StopEvt.isoTrack_absIso.push_back( TrackIso(ipf)                    );
        StopEvt.isoTrack_dz.push_back    ( cms3.pfcands_dz().at(ipf)        );
        StopEvt.isoTrack_pdgId.push_back ( cms3.pfcands_particleId().at(ipf));
     } 


      BabyTree->Fill();

    }//close event loop
    
    file->Close();
    delete file;

  }//close file loop

  BabyFile->cd();
  BabyTree->Write();
  BabyFile->Close();

  bmark->Stop("benchmark");
  cout << endl;
  cout << "Events Processed		" << nEventsDone << endl;
  cout << "Events with 1 Good Vertex	" << nEvents_GoodVtx << endl;
  cout << "Events with MET > 30 GeV	" << nEvents_MET30 << endl;
  cout << "Events with 1 Good Lepton	" << nEvents_GoodLep << endl;
  cout << "Events with 2 Good Jets	" << nEvents_2GoodJets << endl;
  cout << "-----------------------------" << endl;
  cout << "CPU  Time:   " << Form( "%.01f", bmark->GetCpuTime("benchmark")  ) << endl;                                                                                          
  cout << "Real Time:   " << Form( "%.01f", bmark->GetRealTime("benchmark") ) << endl;
  cout << endl;
  delete bmark;

  return 0;  

}
