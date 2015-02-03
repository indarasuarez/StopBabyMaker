#include "EventTree.h"
#include "CORE/CMS3.h"
#include "CORE/EventSelections.h"
 
#include "TString.h"
 
EventTree::EventTree ()
{
}
 
EventTree::EventTree (const std::string &prefix)
    : prefix_(prefix)
{
}
 
void EventTree::FillCommon (const std::string &root_file_name)
{
    run = cms3.evt_run();
    ls = cms3.evt_lumiBlock();
    evt = cms3.evt_event();
    nvtxs = numberOfGoodVertices();
 
    pfmet = cms3.evt_pfmet();
    pfmet_phi = cms3.evt_pfmetPhi();
     
    is_data = cms3.evt_isRealData();
 
    if (!is_data)
    {
        genmet = cms3.gen_met();
        genmet_phi = cms3.gen_metPhi();
        scale1fb = cms3.evt_scale1fb();
        xsec = cms3.evt_xsec_incl();
        kfactor = cms3.evt_kfactor();

	 // gen lepton counts
        gen_nleps              = leptonGenpCount(gen_nels, gen_nmus, gen_ntaus);
        gen_nleps_fromtau = leptonGenpCount_lepTauDecays(gen_nels_fromtau, gen_nmus_fromtau, gen_ntaus_fromtau);
 
        //sparm_values = cms3.sparm_values();
       // for ( auto name : cms3.sparm_names() )
         //   sparm_names.push_back(name.Data());
	pu_nvtxs    = cms3.puInfo_nPUvertices().at(6);
	pu_ntrue = cms3.puInfo_trueNumInteractions().at(0);
    }
 /*
      int ntau = 0;
      for(unsigned int iTau = 0; iTau < cms3.taus_pf_p4().size(); iTau++){
        if(cms3.taus_pf_p4().at(iTau).pt() < 20.0) continue;
        if(fabs(cms3.taus_pf_p4().at(iTau).eta()) > 2.3) continue;
  //     	      if(!cms3.taus_pf_byDecayModeFinding().at(iTau)) continue;
              if (!cms3.taus_pf_byLooseCombinedIsolationDeltaBetaCorr3Hits().at(iTau)) continue; // HPS3 hits taus
           //   if (!cms3.taus_pf_againstElectronLoose().at(iTau)) continue; // loose electron rejection 
             // if (!cms3.taus_pf_againstMuonTight().at(iTau)) continue; // loose muon rejection                                                                                                                                            
        tau_p4.push_back(cms3.taus_pf_p4().at(iTau));
        tau_charge.push_back(cms3.taus_pf_charge().at(iTau));
        tau_isoCI3hit.push_back(cms3.taus_pf_byCombinedIsolationDeltaBetaCorrRaw3Hits().at(iTau));

         ntau++;
      }
     
      Ntaus=ntau;

     //iso pf candidates (charged)
     for (unsigned int ipf = 0; ipf < cms3.pfcands_p4().size(); ipf++) {
 
        if(cms3.pfcands_charge().at(ipf) == 0) continue;
        if(fabs(cms3.pfcands_dz().at(ipf)) > 0.1) continue;

        if(cms3.pfcands_p4().at(ipf).pt() < 5) continue;
        
        isoTrack_pt.push_back    ( cms3.pfcands_p4().at(ipf).pt()   );
        isoTrack_eta.push_back   ( cms3.pfcands_p4().at(ipf).eta()  );
        isoTrack_phi.push_back   ( cms3.pfcands_p4().at(ipf).phi()  );
        isoTrack_mass.push_back  ( cms3.pfcands_mass().at(ipf)      );
        isoTrack_absIso.push_back( TrackIso(ipf)                    );
        isoTrack_dz.push_back    ( cms3.pfcands_dz().at(ipf)        );
        isoTrack_pdgId.push_back ( cms3.pfcands_particleId().at(ipf));
     }
*/
    dataset = cms3.evt_dataset().at(0).Data();
    filename = root_file_name;
    cms3tag = cms3.evt_CMS2tag().at(0).Data();
    
}
 
void EventTree::Reset ()
{
    run = 0;
    ls = 0;
    evt = 0;

    ngoodlep =  -999999;
     
    nvtxs = -999999;
    pu_nvtxs = -999999;
    gen_nleps = -999999;
    gen_nels = -999999;
    gen_nmus = -999999;
    gen_ntaus = -999999;
    gen_nleps_fromtau = -999999;
    gen_nels_fromtau = -999999;
    gen_nmus_fromtau = -999999;
    gen_ntaus_fromtau = -999999;
     
    pfmet = -999999.;
    pfmet_phi = -999999.;
    genmet = -999999.;
    genmet_phi = -999999.;
    scale1fb = -999999.;
    xsec = -999999.;
    kfactor = -999999.;
    pu_ntrue = -999999.;

 
    is_data = false;
 
    dataset = "";
    filename = "";
    cms3tag = "";

	tau_p4.clear();
        tau_charge.clear();
        tau_MedisoCI3hit.clear();
        Ntaus=-9999999;
        tau_againstElectronLoose.clear();
        tau_againstMuonTight.clear();

        isoTrack_pt.clear();    
        isoTrack_eta.clear();  
        isoTrack_phi.clear();  
        isoTrack_mass.clear();  
        isoTrack_absIso.clear();  
        isoTrack_dz.clear();  
        isoTrack_pdgId.clear();
 
    sparm_names.clear();    
}
 
void EventTree::SetBranches (TTree* tree)
{
    tree->Branch("run", &run, "run/i");
    tree->Branch("ls", &ls, "ls/i");
    tree->Branch("evt", &evt, "evt/i");   
    tree->Branch("nvtxs", &nvtxs, "nvtxs/I");
    tree->Branch("pu_nvtxs", &pu_nvtxs, "pu_nvtxs/I");
    tree->Branch("gen_nleps", &gen_nleps, "gen_nleps/I");
    tree->Branch("gen_nels", &gen_nels, "gen_nels/I");
    tree->Branch("gen_nmus", &gen_nmus, "gen_nmus/I");
    tree->Branch("gen_ntaus", &gen_ntaus, "gen_ntaus/I");
    tree->Branch("gen_nleps_fromtau", &gen_nleps_fromtau, "gen_nleps_fromtau/I");
    tree->Branch("gen_nels_fromtau", &gen_nels_fromtau, "gen_nels_fromtau/I");
    tree->Branch("gen_nmus_fromtau", &gen_nmus_fromtau, "gen_nmus_fromtau/I");
    tree->Branch("gen_ntaus_fromtau", &gen_ntaus_fromtau, "gen_ntaus_fromtau/I");    
    tree->Branch("pfmet", &pfmet, "pfmet/F");
    tree->Branch("pfmet_phi", &pfmet_phi, "pfmet_phi/F");
    tree->Branch("genmet", &genmet, "genmet/F");
    tree->Branch("genmet_phi", &genmet_phi, "genmet_phi/F");
    tree->Branch("scale1fb", &scale1fb, "scale1fb/F");
    tree->Branch("xsec", &xsec, "xsec/F");
    tree->Branch("kfactor", &kfactor, "kfactor/F");
    tree->Branch("pu_ntrue", &pu_ntrue, "pu_ntrue/F");    
    tree->Branch("ngoodlep",&ngoodlep,"ngoodlep/I");
    tree->Branch("is_data", &is_data, "is_data/O");
    tree->Branch("dataset", &dataset);
    tree->Branch("filename", &filename);
    tree->Branch("cms3tag", &cms3tag);
    //tree->Branch("taus_byMediumCombinedIsolationDeltaBetaCorr3Hits", &taus_byMediumCombinedIsolationDeltaBetaCorr3Hits);
    tree->Branch("tau_p4", &tau_p4);
    tree->Branch("tau_charge", &tau_charge);
    tree->Branch("tau_isoCI3hit", &tau_MedisoCI3hit);
    tree->Branch("tau_againstElectronLoose", &tau_againstElectronLoose);
    tree->Branch("tau_againstMuonTight", &tau_againstMuonTight);
    tree->Branch("Ntaus", &Ntaus);
    tree->Branch("isoTrack_pt", &isoTrack_pt);
    tree->Branch("isoTrack_eta",&isoTrack_eta);
    tree->Branch("isoTrack_phi", &isoTrack_phi);
    tree->Branch("isoTrack_mass", &isoTrack_mass);
    tree->Branch("isoTrack_absIso", &isoTrack_absIso);
    tree->Branch("isoTrack_dz", &isoTrack_dz);
    tree->Branch("isoTrack_pdgId", &isoTrack_pdgId);
    tree->Branch("sparm_names", &sparm_names);    
    tree->Branch("nEvents", &nEvents);
    tree->Branch("nEvents_goodvtx", &nEvents_goodvtx);
    tree->Branch("nEvents_MET30", &nEvents_MET30);
    tree->Branch("nEvents_1goodlep", &nEvents_1goodlep);
    tree->Branch("nEvents_2goodjets", &nEvents_2goodjets);

}
