#include "ElectronSelections.h"
#include "Math/LorentzVector.h"
#include "Math/VectorUtil.h"

using namespace tas;

//POG Electron IDs
//https://twiki.cern.ch/twiki/bin/viewauth/CMS/EgammaCutBasedIdentification#Electron_ID_Working_Points
bool isVetoElectron(unsigned int elIdx){
  if(fabs(els_etaSC().at(elIdx)) <= 1.479){
    if(fabs(els_dEtaIn().at(elIdx)) >= 0.007) return false; 
    if(fabs(els_dPhiIn().at(elIdx)) >= 0.8) return false; 
    if(els_sigmaIEtaIEta_full5x5().at(elIdx) >= 0.01) return false; 
    if(els_hOverE().at(elIdx) >= 0.15) return false; 
    if(fabs(els_dxyPV().at(elIdx)) >= 0.04) return false; //is this wrt the correct PV?
    if(fabs(els_dzPV().at(elIdx)) >= 0.2) return false; //is this wrt the correct PV?
    if( eleRelIso03(elIdx) >= 0.15) return false; 
    return true;
  } else if((fabs(els_etaSC().at(elIdx)) > 1.479) && (fabs(els_etaSC().at(elIdx)) < 2.5)){
    if(fabs(els_dEtaIn().at(elIdx)) >= 0.01) return false; 
    if(fabs(els_dPhiIn().at(elIdx)) >= 0.7) return false; 
    if(els_sigmaIEtaIEta_full5x5().at(elIdx) >= 0.03) return false; 
    if(fabs(els_dxyPV().at(elIdx)) >= 0.04) return false; //is this wrt the correct PV?
    if(fabs(els_dzPV().at(elIdx)) >= 0.2) return false; //is this wrt the correct PV?
    if( eleRelIso03(elIdx) >= 0.15 ) return false; 
    return true;
  } else return false;
}

bool isElectronFO(unsigned int elIdx){//fixme
  //same as medium but removed dxy cut and iso<0.6
  if(fabs(els_etaSC().at(elIdx)) <= 1.479){
    if(fabs(els_dEtaIn().at(elIdx)) >= 0.004) return false;
    if(fabs(els_dPhiIn().at(elIdx)) >= 0.06) return false; 
    if(els_sigmaIEtaIEta_full5x5().at(elIdx) >= 0.01) return false; 
    if(els_hOverE().at(elIdx) >= 0.12) return false; 
    if(fabs(els_dxyPV().at(elIdx)) >= 0.05) return false; //is this wrt the correct PV?
    if(fabs(els_dzPV().at(elIdx)) >= 0.1) return false; //is this wrt the correct PV?
    if( fabs( (1.0/els_ecalEnergy().at(elIdx)) - (els_eOverPIn().at(elIdx)/els_ecalEnergy().at(elIdx)) ) >= 0.05) return false; // |1/E - 1/p|
    if( eleRelIso03(elIdx) >= 0.5 ) return false; 
    if( els_conv_vtx_flag().at(elIdx) ) return false;
    if( els_exp_innerlayers().at(elIdx) > 0) return false;
    return true;
  } else if((fabs(els_etaSC().at(elIdx)) > 1.479) && (fabs(els_etaSC().at(elIdx)) < 2.5)){
    if(fabs(els_dEtaIn().at(elIdx)) >= 0.007) return false;
    if(fabs(els_dPhiIn().at(elIdx)) >= 0.03) return false; 
    if(els_sigmaIEtaIEta_full5x5().at(elIdx) >= 0.03) return false; 
    if(els_hOverE().at(elIdx) >= 0.1) return false; 
    if(fabs(els_dxyPV().at(elIdx)) >= 0.05) return false; //is this wrt the correct PV?
    if(fabs(els_dzPV().at(elIdx)) >= 0.1) return false; //is this wrt the correct PV?
    if( fabs( (1.0/els_ecalEnergy().at(elIdx)) - (els_eOverPIn().at(elIdx)/els_ecalEnergy().at(elIdx)) ) >= 0.05) return false; // |1/E - 1/p|
    if( eleRelIso03(elIdx) >= 0.5 ) return false; 
    if( els_conv_vtx_flag().at(elIdx) ) return false;
    if( els_exp_innerlayers().at(elIdx) > 0) return false;
    return true;
  } else return false;
}

bool isLooseElectron(unsigned int elIdx){
  if(fabs(els_etaSC().at(elIdx)) <= 1.479){
    if(fabs(els_dEtaIn().at(elIdx)) >= 0.007) return false;
    if(fabs(els_dPhiIn().at(elIdx)) >= 0.15) return false;
    if(els_sigmaIEtaIEta_full5x5().at(elIdx) >= 0.01) return false;
    if(els_hOverE().at(elIdx) >= 0.12) return false;
    if(fabs(els_dxyPV().at(elIdx)) >= 0.02) return false;//   if(fabs(els_ip3d().at(elIdx))/els_ip3derr().at(elIdx) >= 4) return false;
    if(fabs(els_dzPV().at(elIdx)) >= 0.2) return false; //is this wrt the correct PV?
    if( fabs( (1.0/els_ecalEnergy().at(elIdx)) - (els_eOverPIn().at(elIdx)/els_ecalEnergy().at(elIdx)) ) >= 0.05) return false; // |1/E - 1/p|
    if( eleRelIso03(elIdx) >= 0.15 ) return false;
    if( els_conv_vtx_flag().at(elIdx) ) return false;
    if( els_exp_innerlayers().at(elIdx) > 1) return false;//RA5, not sure it's the right choice
    return true;
  } else if((fabs(els_etaSC().at(elIdx)) > 1.479) && (fabs(els_etaSC().at(elIdx)) < 2.5)){
    if(fabs(els_dEtaIn().at(elIdx)) >= 0.009) return false;
    if(fabs(els_dPhiIn().at(elIdx)) >= 0.10) return false;
    if(els_sigmaIEtaIEta_full5x5().at(elIdx) >= 0.03) return false;
    if(els_hOverE().at(elIdx) >= 0.1) return false;
    if(fabs(els_dxyPV().at(elIdx)) >= 0.02) return false; //if(fabs(els_ip3d().at(elIdx))/els_ip3derr().at(elIdx) >= 4) return false;
    if(fabs(els_dzPV().at(elIdx)) >= 0.2) return false; //is this wrt the correct PV?
    if( fabs( (1.0/els_ecalEnergy().at(elIdx)) - (els_eOverPIn().at(elIdx)/els_ecalEnergy().at(elIdx)) ) >= 0.05) return false; // |1/E - 1/p|
    if( eleRelIso03(elIdx) >= 0.15 ) return false;
    if( els_conv_vtx_flag().at(elIdx) ) return false;
    if( els_exp_innerlayers().at(elIdx) > 1) return false;//RA5, not sure it's the right choice
    return true;
  } else return false;
}

bool isMediumElectron(unsigned int elIdx){

  if(fabs(els_etaSC().at(elIdx)) <= 1.479){
    if(fabs(els_dEtaIn().at(elIdx)) >= 0.004) return false;
    if(fabs(els_dPhiIn().at(elIdx)) >= 0.06) return false; 
    if(els_sigmaIEtaIEta_full5x5().at(elIdx) >= 0.01) return false; 
    if(els_hOverE().at(elIdx) >= 0.12) return false; 
    if(fabs(els_dxyPV().at(elIdx)) >= 0.02) return false; //if(fabs(els_ip3d().at(elIdx))/els_ip3derr().at(elIdx) >= 4) return false;
    if(fabs(els_dzPV().at(elIdx)) >= 0.1) return false; //is this wrt the correct PV?
    if( fabs( (1.0/els_ecalEnergy().at(elIdx)) - (els_eOverPIn().at(elIdx)/els_ecalEnergy().at(elIdx)) ) >= 0.05) return false; // |1/E - 1/p|
    if( eleRelIso03(elIdx) >= 0.15 ) return false; 
    if( els_conv_vtx_flag().at(elIdx) ) return false;
    if( els_exp_innerlayers().at(elIdx) > 1) return false;//RA5, not sure it's the right choice
    return true;
  } else if((fabs(els_etaSC().at(elIdx)) > 1.479) && (fabs(els_etaSC().at(elIdx)) < 2.5)){
    if(fabs(els_dEtaIn().at(elIdx)) >= 0.007) return false;
    if(fabs(els_dPhiIn().at(elIdx)) >= 0.03) return false; 
    if(els_sigmaIEtaIEta_full5x5().at(elIdx) >= 0.03) return false; 
    if(els_hOverE().at(elIdx) >= 0.1) return false; 
    if(fabs(els_dxyPV().at(elIdx)) >= 0.02) return false; //if(fabs(els_ip3d().at(elIdx))/els_ip3derr().at(elIdx) >= 4) return false;
    if(fabs(els_dzPV().at(elIdx)) >= 0.1) return false; //is this wrt the correct PV?
    if( fabs( (1.0/els_ecalEnergy().at(elIdx)) - (els_eOverPIn().at(elIdx)/els_ecalEnergy().at(elIdx)) ) >= 0.05) return false; // |1/E - 1/p|
    if( eleRelIso03(elIdx) >= 0.15 ) return false; 
    if( els_conv_vtx_flag().at(elIdx) ) return false;
    if( els_exp_innerlayers().at(elIdx) > 0) return false;//RA5, not sure it's the right choice
    return true;
  } else return false;

}

bool isTightElectron(unsigned int elIdx){

  if(fabs(els_etaSC().at(elIdx)) <= 1.479){
    if(fabs(els_dEtaIn().at(elIdx)) >= 0.004) return false;
    if(fabs(els_dPhiIn().at(elIdx)) >= 0.03) return false; 
    if(els_sigmaIEtaIEta_full5x5().at(elIdx) >= 0.01) return false; 
    if(els_hOverE().at(elIdx) >= 0.12) return false; 
    if(fabs(els_dxyPV().at(elIdx)) >= 0.02) return false; //if(fabs(els_ip3d().at(elIdx))/els_ip3derr().at(elIdx) >= 4) return false;
    if(fabs(els_dzPV().at(elIdx)) >= 0.1) return false; //is this wrt the correct PV?
    if( fabs( (1.0/els_ecalEnergy().at(elIdx)) - (els_eOverPIn().at(elIdx)/els_ecalEnergy().at(elIdx)) ) >= 0.05) return false; // |1/E - 1/p|
    if( eleRelIso03(elIdx) >= 0.1 ) return false; 
    if( els_conv_vtx_flag().at(elIdx) ) return false;
    if( els_exp_innerlayers().at(elIdx) > 0) return false;//RA5, not sure it's the right choice
    return true;
  } else if((fabs(els_etaSC().at(elIdx)) > 1.479) && (fabs(els_etaSC().at(elIdx)) < 2.5)){
    if(fabs(els_dEtaIn().at(elIdx)) >= 0.005) return false;
    if(fabs(els_dPhiIn().at(elIdx)) >= 0.02) return false; 
    if(els_sigmaIEtaIEta_full5x5().at(elIdx) >= 0.03) return false; 
    if(els_hOverE().at(elIdx) >= 0.1) return false; 
    if(fabs(els_dxyPV().at(elIdx)) >= 0.02) return false;//if(fabs(els_ip3d().at(elIdx))/els_ip3derr().at(elIdx) >= 4) return false;
    if(fabs(els_dzPV().at(elIdx)) >= 0.1) return false; //is this wrt the correct PV?
    if( fabs( (1.0/els_ecalEnergy().at(elIdx)) - (els_eOverPIn().at(elIdx)/els_ecalEnergy().at(elIdx)) ) >= 0.05) return false; // |1/E - 1/p|
    if( eleRelIso03(elIdx) >= 0.1 ) return false; 
    if( els_conv_vtx_flag().at(elIdx) ) return false;
    if( els_exp_innerlayers().at(elIdx) > 0) return false;//RA5, not sure it's the right choice
    return true;
  } else return false;

}

bool PassElectronPreSelections(unsigned int elIdx){
  if(els_p4().at(elIdx).pt() <= 20.) return false;
  if(!isLooseElectron(elIdx)) return false;
  return true;
} 

float eleRelIso03DB(unsigned int elIdx){
  float chiso     = els_pfChargedHadronIso().at(elIdx);
  float nhiso     = els_pfNeutralHadronIso().at(elIdx);
  float emiso     = els_pfPhotonIso().at(elIdx);
  float deltaBeta = els_pfPUIso().at(elIdx);
  float absiso = chiso + std::max(0.0, nhiso + emiso - 0.5 * deltaBeta);
  return absiso/(els_p4().at(elIdx).pt());
}

////OTHER SS stuff that I am not using////

bool isGoodVetoElectron(unsigned int elidx){
  if (fabs(els_p4().at(elidx).eta())>2.4) return false;
  if (els_p4().at(elidx).pt()<7.) return false;//fixme
  if (isVetoElectron(elidx)==0) return false;
  if( eleRelIso03(elidx) >= 0.5) return false; 
  return true;
}
bool isFakableElectron(unsigned int elidx){
  if (els_p4().at(elidx).pt()<10.) return false;//fixme
  if (isGoodVetoElectron(elidx)==0) return false;
  if (isElectronFO(elidx)==0) return false;
  if (threeChargeAgree(elidx)==0) return false;
  return true;
}
bool isGoodElectron(unsigned int elidx){
  if (isFakableElectron(elidx)==0) return false;
  if (isMediumElectron(elidx)==0) return false;
  if (fabs(els_ip3d().at(elidx))/els_ip3derr().at(elidx) >= 4) return false;
  if (fabs(els_dzPV().at(elidx)) >= 0.1) return false;//fixme
  return true;
}

bool threeChargeAgree(unsigned int elIdx){
  return els_isGsfCtfScPixChargeConsistent().at(elIdx);
}

float eleRelIso03(unsigned int elIdx){
  return eleRelIso03EA(elIdx);
}

float eleRelIso03EA(unsigned int elIdx){
  float chiso     = els_pfChargedHadronIso().at(elIdx);
  float nhiso     = els_pfNeutralHadronIso().at(elIdx);
  float emiso     = els_pfPhotonIso().at(elIdx);
  float ea = 0.;
  if      (fabs(els_p4().at(elIdx).eta())<=0.800) ea = 0.1013;
  else if (fabs(els_p4().at(elIdx).eta())<=1.300) ea = 0.0988;
  else if (fabs(els_p4().at(elIdx).eta())<=2.000) ea = 0.0572;
  else if (fabs(els_p4().at(elIdx).eta())<=2.200) ea = 0.0842;
  else if (fabs(els_p4().at(elIdx).eta())<=2.500) ea = 0.1530;
  float absiso = chiso + std::max(float(0.0), nhiso + emiso - evt_fixgrid_all_rho() * ea);
  //cout << "chiso=" << chiso << " nhiso=" << nhiso << " emiso=" << emiso << " deltaBeta=" << deltaBeta << " absiso=" << absiso << " relIso=" << absiso/(els_p4().at(elIdx).pt()) << endl;
  return absiso/(els_p4().at(elIdx).pt());
}
