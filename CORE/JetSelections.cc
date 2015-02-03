#include "JetSelections.h"                                                                                                                                                                          
#include "Math/VectorUtil.h"
#include "ElectronSelections.h"
#include "MuonSelections.h" 

using namespace tas;

bool isLoosePFJet(unsigned int pfJetIdx){

    float pfjet_chf_  = pfjets_chargedHadronE()[pfJetIdx] / pfjets_p4()[pfJetIdx].energy();
    float pfjet_nhf_  = pfjets_neutralHadronE()[pfJetIdx] / pfjets_p4()[pfJetIdx].energy();
    float pfjet_cef_  = pfjets_chargedEmE()[pfJetIdx] / pfjets_p4()[pfJetIdx].energy();
    float pfjet_nef_  = pfjets_neutralEmE()[pfJetIdx] / pfjets_p4()[pfJetIdx].energy();
    int   pfjet_cm_   = pfjets_chargedMultiplicity()[pfJetIdx];
    float pfjet_eta   = fabs(pfjets_p4()[pfJetIdx].eta());

    if (pfjets_pfcandIndicies().size() < 2)
        return false;
    if (pfjet_nef_ >= 0.99)
        return false;
    if (pfjet_nhf_ >= 0.99)
        return false;

    if (pfjet_eta < 2.4){
      if (pfjet_cm_ < 1)
          return false;
      if (pfjet_chf_ < 1e-6)
          return false;
      if (pfjet_cef_ >= 0.99)
          return false;
    }

    return true;
}

bool isMediumPFJet(unsigned int pfJetIdx){


    float pfjet_nhf_  = pfjets_neutralHadronE()[pfJetIdx] / pfjets_p4()[pfJetIdx].energy();
    float pfjet_nef_  = pfjets_neutralEmE()[pfJetIdx] / pfjets_p4()[pfJetIdx].energy();

    if (pfjet_nef_ >= 0.95)
        return false;
    if (pfjet_nhf_ >= 0.95)
        return false;

    if (!isLoosePFJet(pfJetIdx)) return false;

    return true;
}

bool isTightPFJet(unsigned int pfJetIdx){


    float pfjet_nhf_  = pfjets_neutralHadronE()[pfJetIdx] / pfjets_p4()[pfJetIdx].energy();
    float pfjet_nef_  = pfjets_neutralEmE()[pfJetIdx] / pfjets_p4()[pfJetIdx].energy();

    if (pfjet_nef_ >= 0.90)
        return false;
    if (pfjet_nhf_ >= 0.90)
        return false;

    if (!isLoosePFJet(pfJetIdx)) return false;

    return true;
}

bool passesPFJetID(unsigned int pfJetIdx) {

    float pfjet_chf_  = cms3.pfjets_chargedHadronE()[pfJetIdx] / cms3.pfjets_p4()[pfJetIdx].energy();
    float pfjet_nhf_  = cms3.pfjets_neutralHadronE()[pfJetIdx] / cms3.pfjets_p4()[pfJetIdx].energy();
    float pfjet_cef_  = cms3.pfjets_chargedEmE()[pfJetIdx] / cms3.pfjets_p4()[pfJetIdx].energy();
    float pfjet_nef_  = cms3.pfjets_neutralEmE()[pfJetIdx] / cms3.pfjets_p4()[pfJetIdx].energy();
    int   pfjet_cm_   = cms3.pfjets_chargedMultiplicity()[pfJetIdx];
    int   pfjet_mult_ = pfjet_cm_ + cms3.pfjets_neutralMultiplicity()[pfJetIdx];

    if (pfjet_nef_ >= 0.99)
        return false;
    if (pfjet_nhf_ >= 0.99)
        return false;
    if (pfjet_mult_ < 2)
        return false;

    if (fabs(cms3.pfjets_p4()[pfJetIdx].eta()) < 2.4)
    {   
        if (pfjet_chf_ < 1e-6)
            return false;
        if (pfjet_cm_ < 1)
            return false;
        if (pfjet_cef_ >= 0.99)
            return false;
    }   

    return true;
}

//Jet cleaning -- electrons
bool JetIsElectron(LorentzVector pfJet) {
        bool jetIsLep = false;
        for (unsigned int eidx = 0; eidx < tas::els_p4().size(); eidx++){
          LorentzVector electron = tas::els_p4().at(eidx);
          if (electron.pt() < 7) continue;
          if (!isGoodVetoElectron(eidx)) continue;
          if (ROOT::Math::VectorUtil::DeltaR(pfJet, electron) > 0.4) continue;
          jetIsLep = true;
        }
	return jetIsLep;
}

//Jet cleaning -- muons
bool JetIsMuon(LorentzVector pfJet) {
        bool jetIsLep = false;
        for (unsigned int muidx = 0; muidx < tas::mus_p4().size(); muidx++){
          LorentzVector muon = tas::mus_p4().at(muidx);
          if (muon.pt() < 5) continue;
          if (!isGoodVetoMuon(muidx)) continue;
          if (ROOT::Math::VectorUtil::DeltaR(pfJet, muon) > 0.4) continue;
          jetIsLep = true;
        }
	return jetIsLep;
}


