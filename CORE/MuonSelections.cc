#include "MuonSelections.h"

using namespace tas;

bool isLooseMuon(unsigned int muIdx){
  if(!mus_pid_PFMuon().at(muIdx)) return false;    
  bool isGlobal  = true;
  bool isTracker = true;
  if (((mus_type().at(muIdx)) & (1<<1)) == 0) isGlobal  = false;
  if (((mus_type().at(muIdx)) & (1<<2)) == 0) isTracker = false;
  if(!(isGlobal || isTracker)) return false;  
  return true;
}

bool isMuonFO(unsigned int muIdx){
  if (!isLooseMuon(muIdx)) return false;
  if (mus_gfit_chi2().at(muIdx)/mus_gfit_ndof().at(muIdx) >= 10)      return false; 
  if (mus_gfit_validSTAHits().at(muIdx) == 0)                         return false; 
  if (mus_numberOfMatchedStations().at(muIdx) < 2)                    return false;
  if (mus_validPixelHits().at(muIdx) == 0)                            return false;
  if (mus_nlayers().at(muIdx) < 6)                                    return false;
  if (fabs(mus_dxyPV().at(muIdx)) > 0.05)                             return false;
  if (fabs(mus_dzPV().at(muIdx)) > 0.1)                               return false;
  return true;
}

bool isTightMuon(unsigned int muIdx){
  if (!isMuonFO(muIdx)) return false;
  //fixme not applying MIP requirement in calo
    if (fabs(mus_dzPV().at(muIdx)) > 0.1)                               return false;//fixme?
    if (fabs(mus_ip3d().at(muIdx))/mus_ip3derr().at(muIdx) >= 4)        return false;
    return true;
}

bool PassMuonPreSelections(unsigned int muIdx){
  if(mus_p4().at(muIdx).pt() <= 20.) return false;
  if(!isTightMuon(muIdx)) return false;
  return true;
}

float muRelIso03DB(unsigned int muIdx){
  float chiso     = mus_isoR03_pf_ChargedHadronPt().at(muIdx);
  float nhiso     = mus_isoR03_pf_NeutralHadronEt().at(muIdx);
  float emiso     = mus_isoR03_pf_PhotonEt().at(muIdx);
  float deltaBeta = mus_isoR03_pf_PUPt().at(muIdx);
  float absiso = chiso + std::max(0.0, nhiso + emiso - 0.5 * deltaBeta);
  //cout << "chiso=" << chiso << " nhiso=" << nhiso << " emiso=" << emiso << " deltaBeta=" << deltaBeta << " absiso=" << absiso << " relIso=" << absiso/(mus_p4().at(muIdx).pt()) << endl;
  return absiso/(mus_p4().at(muIdx).pt());
}

float muRelIso04DB(unsigned int muIdx){
  float chiso     = mus_isoR04_pf_ChargedHadronPt().at(muIdx);
  float nhiso     = mus_isoR04_pf_NeutralHadronEt().at(muIdx);
  float emiso     = mus_isoR04_pf_PhotonEt().at(muIdx);
  float deltaBeta = mus_isoR04_pf_PUPt().at(muIdx);
  float absiso = chiso + std::max(0.0, nhiso + emiso - 0.5 * deltaBeta);
  return absiso/(mus_p4().at(muIdx).pt());
}

float muRelIso03(unsigned int muIdx){
  return muRelIso03EA(muIdx);
}

float muRelIso03EA(unsigned int muIdx){
  float chiso     = mus_isoR03_pf_ChargedHadronPt().at(muIdx);
  float nhiso     = mus_isoR03_pf_NeutralHadronEt().at(muIdx);
  float emiso     = mus_isoR03_pf_PhotonEt().at(muIdx);
  float ea = 0.;
  if      (fabs(mus_p4().at(muIdx).eta())<=0.800) ea = 0.0913;
  else if (fabs(mus_p4().at(muIdx).eta())<=1.300) ea = 0.0765;
  else if (fabs(mus_p4().at(muIdx).eta())<=2.000) ea = 0.0546;
  else if (fabs(mus_p4().at(muIdx).eta())<=2.200) ea = 0.0728;
  else if (fabs(mus_p4().at(muIdx).eta())<=2.500) ea = 0.1177;
  float absiso = chiso + std::max(float(0.0), nhiso + emiso - evt_fixgrid_all_rho() * ea);
  //cout << "chiso=" << chiso << " nhiso=" << nhiso << " emiso=" << emiso << " deltaBeta=" << deltaBeta << " absiso=" << absiso << " relIso=" << absiso/(mus_p4().at(muIdx).pt()) << endl;
  return absiso/(mus_p4().at(muIdx).pt());
}

bool isGoodVetoMuon(unsigned int muidx){
  if (fabs(mus_p4().at(muidx).eta())>2.4) return false;
  if (mus_p4().at(muidx).pt()<5.) return false;//fixme
  if (isLooseMuon(muidx)==0) return false;
  if (muRelIso03(muidx)>0.5 ) return false;
  if (fabs(mus_dxyPV().at(muidx)) >= 0.05) return false;
  if (fabs(mus_dzPV().at(muidx)) >= 0.1) return false;
  return true;
}
bool isFakableMuon(unsigned int muidx){
  if (isGoodVetoMuon(muidx)==0) return false;
  if (isMuonFO(muidx)==0) return false;
  return true;
}
bool isGoodMuon(unsigned int muidx){
  if (isFakableMuon(muidx)==0) return false;
  if (isTightMuon(muidx)==0) return false;
  if (muRelIso03(muidx)>0.1 ) return false;
  return true;
}
