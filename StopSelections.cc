#include "StopSelections.h"
#include "Math/LorentzVector.h"
#include "Math/VectorUtil.h"
#include "/home/users/isuarez/CORE/CMS3.h"
#include "/home/users/isuarez/CORE/ElectronSelections.h"
#include "/home/users/isuarez/CORE/MuonSelections.h"
#include "/home/users/isuarez/CORE/JetSelections.h"

using namespace tas;

bool isGoodVertex(size_t ivtx) {
  if (vtxs_isFake()[ivtx]) return false;
  if (vtxs_ndof()[ivtx] <= 4.) return false;
  if (vtxs_position()[ivtx].Rho() > 2.0) return false;
  if (fabs(vtxs_position()[ivtx].Z()) > 24.0) return false;
  return true;
}

int numberOfGoodVertices() {
  int ngv = 0;
  for (unsigned int vidx = 0; vidx < vtxs_position().size(); vidx++) {
    if (isGoodVertex(vidx)) ++ngv;
  }
  return ngv;
}

int firstGoodVertex(){
    for (unsigned int vidx = 0; vidx < vtxs_position().size(); vidx++) {
        if (isGoodVertex(vidx))
            return vidx;
    }

    return -1;
}

bool PassElectronPreSelections(unsigned int elIdx){
  if(els_p4().at(elIdx).pt() <= 20.) return false;
  if(!electronID(elIdx, STOP_loose_v1)) return false;
  return true;
}

bool PassMuonPreSelections(unsigned int muIdx){
  if(mus_p4().at(muIdx).pt() <= 20.) return false;
  if(!muonID(muIdx, STOP_loose_v1)) return false;
  if(muRelIso03(muIdx, STOP) > 0.15) return false; 
  return true;
}

bool PassJetPreSelections(unsigned int jetIdx){
  if(pfjets_p4().at(jetIdx).pt() < 30.) return false;
  if(pfjets_p4().at(jetIdx).eta() > 2.4) return false;
  if(!isLoosePFJet(jetIdx)) return false;
//doing overlap removal seperately
 // if(JetIsElectron(pfjets_p4().at(jetIdx))) return false;
 // if(JetIsMuon(pfjets_p4().at(jetIdx))) return false;
  return true;
}

//overlap removal
int getOverlappingJetIndex(LorentzVector& lep_, vector<LorentzVector> jets_, double dR){
  float DR_lep_jet1 = 0.;
  float DR_lep_jet2 = 0.;
  int closestjet_idx = 0;

	for(unsigned int iJet=1; iJet<jets_.size(); iJet++){
            DR_lep_jet1 = ROOT::Math::VectorUtil::DeltaR(jets_.at(closestjet_idx), lep_);
            DR_lep_jet2 = ROOT::Math::VectorUtil::DeltaR(jets_.at(iJet), lep_);
            if(DR_lep_jet1 > DR_lep_jet2) closestjet_idx = iJet;
	}

	if(ROOT::Math::VectorUtil::DeltaR(jets_.at(closestjet_idx), lep_) > dR){
          cout<<"No overlapping jet found"<<endl;
          return -9999;
        }else return closestjet_idx;
}

int getOverlappingTrackIndex(LorentzVector& lep_, int pdgid_, vector<LorentzVector> tracks_, double dR){
  float DR_lep_track1 = 0.;
  float DR_lep_track2 = 0.;
  int closesttrack_idx = 0;
  
        for(unsigned int iTrk=1; iTrk<tracks_.size(); iTrk++){
            if(pfcands_particleId().at(iTrk) != pdgid_) continue;
        //    cout<<"Track PDG-id = "<<pfcands_particleId().at(iTrk)<<endl;
            if(pfcands_charge().at(iTrk) == 0) continue;
      	    if(pfcands_p4().at(iTrk).pt() < 5) continue;
      	    if(fabs(pfcands_dz().at(iTrk)) > 0.1) continue;
            DR_lep_track1 = ROOT::Math::VectorUtil::DeltaR(tracks_.at(closesttrack_idx), lep_);
            DR_lep_track2 = ROOT::Math::VectorUtil::DeltaR(tracks_.at(iTrk), lep_);
            if(DR_lep_track1 > DR_lep_track2) closesttrack_idx = iTrk;
        }

        if(ROOT::Math::VectorUtil::DeltaR(tracks_.at(closesttrack_idx), lep_) > dR){
          cout<<"No overlapping track found"<<endl;
          return -9999;
        }else return closesttrack_idx;
}


int leptonGenpCount(int& nele, int& nmuon, int& ntau) {
  nele=0;
  nmuon=0;
  ntau=0;
  int size = genps_id().size();
  for (int jj=0; jj<size; jj++) {
    if (abs(genps_id().at(jj)) == 11) nele++;
    if (abs(genps_id().at(jj)) == 13) nmuon++;
    if (abs(genps_id().at(jj)) == 15) ntau++;
  }

  return nele + nmuon + ntau;

}

int leptonGenpCount_lepTauDecays(int& nele, int& nmuon, int& ntau) {
  nele=0;
  nmuon=0;
  ntau=0;
  int size = genps_id().size();
  for (int jj=0; jj<size; jj++) {
    if (abs(genps_id().at(jj)) == 11) nele++;
    if (abs(genps_id().at(jj)) == 13) nmuon++;
    if (abs(genps_id().at(jj)) == 15) {
      for(unsigned int kk = 0; kk < genps_lepdaughter_id()[jj].size(); kk++) {
        int daughter = abs(genps_lepdaughter_id()[jj][kk]);
        //we count neutrino's because that guarantees that 
        //        //there is a corresponding lepton and that it comes from
        //                // a leptonic tau decay. You can get electrons from converted photons
        //                        //which are radiated by charged pions from the tau decay but thats
        //                                //hadronic and we don't care for those 
        if( daughter == 12 || daughter == 14)
          ntau++;
      }//daughter loop
    }//if tau
  }//genps loop

  return nele + nmuon + ntau;
}

float TrackIso(int thisPf){

  double coneR=0.3;
  float absIso = 0.0;

  for (int ipf = 0; ipf < (int)pfcands_p4().size(); ipf++) {

    if( ipf == thisPf ) continue; // skip this PFCandidate
    if(pfcands_charge().at(ipf) == 0 ) continue; // skip neutrals                                                                                                                          
    double dr=ROOT::Math::VectorUtil::DeltaR( pfcands_p4().at(ipf) , pfcands_p4().at(thisPf) );
    if( dr > coneR ) continue; // skip pfcands outside the cone                                     
    if( pfcands_p4().at(ipf).pt()>=0.0 && fabs(pfcands_dz().at(ipf)) <= 0.1) absIso += pfcands_p4().at(ipf).pt();

  }

  return absIso;

}

struct sortbypt{
  bool operator () (const pair<int, LorentzVector> &v1, const pair<int,LorentzVector> &v2)
  {
        return v1.second.pt() > v2.second.pt();
  }
};

vector<pair <int, LorentzVector>> sort_pt( vector<LorentzVector> p4_, float pt_){
  vector<pair <int, LorentzVector>> sorted_;
  for(unsigned int iObj=0; iObj<p4_.size(); iObj++){
   if(p4_.at(iObj).pt()<pt_) continue;
   sorted_.push_back(make_pair(iObj,p4_.at(iObj)));
  }
  sort(sorted_.begin(),sorted_.end(),sortbypt());
  return sorted_;
}

vector< LorentzVector> getsortedp4(vector<pair <int, LorentzVector>> index_){
  vector<LorentzVector> sorted_p4;
  for(unsigned int iObj=0; iObj<index_.size(); iObj++){
   sorted_p4.push_back(index_.at(iObj).second);
  }
  return sorted_p4;
}

float getMinDphi(float metPhi, LorentzVector& vec1, LorentzVector& vec2 ) {                                                                                                    
  float dphimj1_    = getdphi(metPhi, vec1.phi() );
  float dphimj2_    = getdphi(metPhi, vec2.phi() );
  float dphimjmin_  = TMath::Min( dphimj1_ , dphimj2_ );

  return dphimjmin_;

}

float getdphi( float phi1 , float phi2 ){                                                                                                                                      
  float dphi = fabs( phi1 - phi2 );
  if( dphi > TMath::Pi() ) dphi = TMath::TwoPi() - dphi;
  return dphi;
}

float dRbetweenVectors(LorentzVector& vec1,LorentzVector& vec2 ){                                                                                                              
  float dphi = std::min(::fabs(vec1.Phi() - vec2.Phi()), 2 * M_PI - fabs(vec1.Phi() - vec2.Phi()));
  float deta = vec1.Eta() - vec2.Eta();

  return sqrt(dphi*dphi + deta*deta);
}

float calculateMt(const LorentzVector p4, double met, double met_phi){
  float phi1 = p4.Phi();
  float phi2 = met_phi;
  float Et1  = p4.Et();
  float Et2  = met;

  return sqrt(2*Et1*Et2*(1.0 - cos(phi1-phi2)));
}
