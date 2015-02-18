#include "TauTree.h"
#include "Math/GenVector/PtEtaPhiE4D.h"
#include "/home/users/isuarez/CORE/CMS3.h"

TauTree::TauTree ()
{
}

using namespace tas;

void TauTree::FillCommon ()
{
    float tau_pt_cut = 20.;
    float tau_eta_cut = 2.4;

    int ntau = 0;
    for(unsigned int iTau = 0; iTau < taus_pf_p4().size(); iTau++){
      if(taus_pf_p4().at(iTau).pt() < tau_pt_cut) continue;
      if(fabs(taus_pf_p4().at(iTau).eta()) > tau_eta_cut) continue;
      if (!taus_pf_byLooseCombinedIsolationDeltaBetaCorr3Hits().at(iTau)) continue; // HPS3 hits taus

      tau_p4.push_back(taus_pf_p4().at(iTau));
      tau_charge.push_back(taus_pf_charge().at(iTau));
      
    //  tau_byDecayModeFinding.push_back(taus_pf_byDecayModeFinding().at(iTau)); //NOT FILLED IN NTUPLE
      tau_MedisoCI3hit.push_back(taus_pf_byMediumCombinedIsolationDeltaBetaCorr3Hits().at(iTau));
      tau_againstElectronLoose.push_back(taus_pf_againstElectronLoose().at(iTau));
      tau_againstMuonTight.push_back(taus_pf_againstMuonTight().at(iTau));

      ntau++;
    }
    ngoodtaus=ntau;
}


void TauTree::Reset()
{
    tau_p4.clear();
    tau_charge.clear();
    tau_MedisoCI3hit.clear();
    ngoodtaus	= -9999;
    tau_againstElectronLoose.clear();
    tau_againstMuonTight.clear();
//    tau_byDecayModeFinding.clear();
}

void TauTree::SetBranches(TTree* tree)
{

    tree->Branch("tau_p4", &tau_p4);
    tree->Branch("tau_charge", &tau_charge);
//    tree->Branch("tau_byDecayModeFinding", &tau_byDecayModeFinding);
    tree->Branch("tau_isoCI3hit", &tau_MedisoCI3hit);
    tree->Branch("tau_againstElectronLoose", &tau_againstElectronLoose);
    tree->Branch("tau_againstMuonTight", &tau_againstMuonTight);
    tree->Branch("ngoodtaus", &ngoodtaus);

}
