#include "EventSelections.h"
#include "Math/LorentzVector.h"
#include "Math/VectorUtil.h"

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
	//there is a corresponding lepton and that it comes from
	// a leptonic tau decay. You can get electrons from converted photons
	//which are radiated by charged pions from the tau decay but thats
	//hadronic and we don't care for those 
	if( daughter == 12 || daughter == 14)
	  ntau++; 
      }//daughter loop
    }//if tau
  }//genps loop
  
  return nele + nmuon + ntau;
}
 
//--------------------------------------------------------
// Determines if the lepton in question is from W/Z
// and if its charge is correct
//
// Note that if we have
//     W->lepton->lepton gamma
// where the gamma is at large angles and it is the
// gamma that gives the lepton signature in the detector,
// then this returns "not from W/Z".  This is by design.
//
// Note W->tau->lepton is tagged as "from W"
//
// Inputs:  idx   = index in the els or mus block
//          id    = lepton ID (11 or 13 or -11 or -13)
//
// Output:  2 = from W/Z incorrect charge
//          1 = from W/Z   correct charge
//          0 = not matched to a lepton (= fake)
//         -1 = lepton from b decay
//         -2 = lepton from c decay
//         -3 = lepton from some other source
//        
// Authors: Claudio in consultation with fkw 22-july-09    
//
// 22-nov-2010...by "accident" this code returns "fromW" (1 or 2)
// in many of the cases where the lepton is from a susy particle,
// because it looks at whether or not it is matched to a status==3
// lepton.  By this procedure is not 100% efficient.  We have now
// added a flag to try to do this more systematically.
//    Claudio & Derek
//---------------------------------------------------------
int leptonIsFromW(int idx, int id, bool alsoSusy) {

  // get the matches to status=1 and status=3
  int st1_id = 0;
  int st3_id = 0;
  int st1_motherid = 0;
  if (abs(id) == 11) {
    st1_id = els_mc_id()[idx];
    st3_id = els_mc3_id()[idx];
    st1_motherid = els_mc_motherid()[idx];
    //a true lepton from a W will have it's motherid==24
    //if the lepton comes from a tau decay that comes from a W, 
    //we have to do some work to trace the parentage
    //to do this, we have to go to the status==3 block because 
    //the daughter info is not in status==1
    if(abs(st1_motherid)==15) {
      bool foundelectronneutrino = false; //ensures that the matched electron from a tau really came from a W
      for(unsigned int i = 0; i < genps_id().size(); i++) {//status 3 loop
	if(abs(genps_id()[i]) == 15 ) { //make sure we get the right tau!
	  genps_lepdaughter_id()[i].size(); 
	  for(unsigned int j = 0; j < genps_lepdaughter_id()[i].size(); j++) { //loop over the tau's status1 daughters
	    if(abs(genps_lepdaughter_id()[i][j]) == 12)
	      foundelectronneutrino = true;
	    float dr = ROOT::Math::VectorUtil::DeltaR(els_mc_p4()[idx], genps_lepdaughter_p4()[i][j]);
	    if (dr < 0.0001) { //should be the same exact status==1 gen particle!
	      st1_motherid = genps_id_mother()[i];
	      continue;
	    }//if (dr < 0.0001)
	  }//loop over the tau's daughters
	  if(!foundelectronneutrino)
	    st1_motherid = -9999;
	}//tau
      }//status 3 loop
    }//if(abs(st1_motherid)==15) {
  } else if (abs(id) == 13) {
    st1_id = mus_mc_id()[idx];
    st3_id = mus_mc3_id()[idx];
    st1_motherid = mus_mc_motherid()[idx];
    //a true lepton from a W will have it's motherid==24
    //if the lepton comes from a tau decay that comes from a W, 
    //we have to do some work to trace the parentage
    //to do this, we have to go to the status==3 block because 
    //the daughter info is not in status==1
    if(abs(st1_motherid)==15) {
      bool foundmuonneutrino = false;
      for(unsigned int i = 0; i < genps_id().size(); i++) {//status 3 loop
	if(abs(genps_id()[i]) == 15 ) { //make sure we get the right tau!
	  genps_lepdaughter_id()[i].size();
	  for(unsigned int j = 0; j < genps_lepdaughter_id()[i].size(); j++) {//loop over the tau's status1 daughters
	    if(abs(genps_lepdaughter_id()[i][j]) == 14)
	      foundmuonneutrino = true;
	    float dr = ROOT::Math::VectorUtil::DeltaR(mus_mc_p4()[idx], genps_lepdaughter_p4()[i][j]);
	    if (dr < 0.0001) { //should be the same exact status==1 gen particle!
 	      st1_motherid = genps_id_mother()[i];
	      continue;
	    }//if (dr < 0.0001)
	  }//loop over the tau's daughters
	  if(!foundmuonneutrino)
	    st1_motherid = -9999;
	}//tau
      }//status 3 loop
    }//if(abs(st1_motherid)==15) {
  } else {
    std::cout << "You fool.  Give me +/- 11 or +/- 13 please" << std::endl;
    return false;
  }


  // debug
  // std::cout << "id=" << id << " st1_id=" << st1_id;
  // std::cout << " st3_id=" << st3_id;
  // std::cout << " st1_motherid=" << st1_motherid << std::endl;

  // Step 1
  // Look at status 1 match, it should be either a lepton or
  // a photon if it comes from W/Z.
  // The photon case takes care of collinear FSR
  if ( !(abs(st1_id) == abs(id) || st1_id == 22)) return 0;

  // Step 2
  // If the status 1 match is a photon, its mother must be
  // a lepton.  Otherwise it is not FSR
  if (st1_id == 22) {
    if (abs(st1_motherid) != abs(id)) return 0;
  }

  // At this point we are matched (perhaps via FSR) to
  // a status 1 lepton.  This means that we are left with
  // leptons from W, taus, bottom, charm, as well as dalitz decays

  // Step 3
  // A no-brainer: pick up vanilla W->lepton decays
  // (should probably add Higgs, SUSY, W' etc...not for now)
  if (st1_id ==  id && abs(st1_motherid) == 24) return 1; // W
  if (st1_id == -id && abs(st1_motherid) == 24) return 2; // W
  if (st1_id ==  id &&   st1_motherid    == 23) return 1; // Z
  if (st1_id == -id &&   st1_motherid    == 23) return 2; // Z
  if ( alsoSusy ) {
    if (st1_id ==  id && abs(st1_motherid) > 1e6) return 1; // exotica
    if (st1_id == -id && abs(st1_motherid) > 1e6) return 2; // exotica
  }

  // Step 4
  // Another no-brainer: pick up leptons matched to status=3
  // leptons.  This should take care of collinear FSR
  // This also picks up a bunch of SUSY decays
  if (st3_id ==  id) return 1;
  if (st3_id == -id) return 2;
 
  // Step 5
  // Now we need to go after the W->tau->lepton.  
  // We exploit the fact that in t->W->tau the tau shows up
  // at status=3.  We also use the fact that the tau decay products
  // are highly boosted, so the direction of the status=3 tau and
  // the lepton from tau decays are about the same
  //
  // We do not use the status=1 links because there is not
  // enough information to distinguish
  // W->tau->lepton  or W->tau->lepton gamma
  //  from
  // B->tau->lepton or B->tau->lepton gamma
  //if (abs(st3_id) == 15 && id*st3_id > 0) return 1;
  //if (abs(st3_id) == 15 && id*st3_id < 0) return 2;
  if(abs(st3_id) == 15) {
    //have to find the index of the status3 particle by dR
    //because the indices are buggy
    unsigned int mc3idx = 999999;
    LorentzVector lepp4 =  abs(id)==11 ? els_p4()[idx] : mus_p4()[idx];
    double mindR = 9999;
    for(unsigned int i = 0; i < genps_id().size(); i++) {
      float dr = ROOT::Math::VectorUtil::DeltaR(lepp4, genps_p4()[i]);
      if(dr < mindR) {
	mindR = dr;
	mc3idx = i;
      }
    }
    bool foundElOrMuNu = false;    
    for(unsigned int i = 0; i < genps_lepdaughter_p4()[mc3idx].size(); i++) {
      if(abs(genps_lepdaughter_id()[mc3idx][i]) == 12 || abs(genps_lepdaughter_id()[mc3idx][i]) == 14)
	foundElOrMuNu = true;
    }
    if(!foundElOrMuNu) //comes from a hadronic decay of the tau
      return -3;
    if(id*st3_id > 0) 
      return 1;
    else return 2;
  }
  
  
  // Step 6
  // If we get here, we have a non-W lepton
  // Now we figure out if it is from b, c, or "other"
  // There are a couple of caveats
  // (a) b/c --> lepton --> lepton gamma (ie FSR) is labelled as "other"
  // (b) b   --> tau --> lepton is labelled as "other"
  if ( abs(st1_id) == abs(id) && idIsBeauty(st1_motherid)) return -1;
  if ( abs(st1_id) == abs(id) && idIsCharm(st1_motherid))  return -2;
  return -3;
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

bool idIsCharm(int id) {
  id = abs(id);
  if (
      id == 4       ||
      id == 411     ||
      id == 421     ||
      id == 10411   ||
      id == 10421   ||
      id == 413     ||
      id == 423     ||
      id == 10413   ||
      id == 10423   ||
      id == 20413   ||
      id == 20423   ||
      id == 415     ||
      id == 425     ||
      id == 431     ||
      id == 10431   ||
      id == 433     ||
      id == 10433   ||
      id == 20433   ||
      id == 435     ||
      id == 441     ||
      id == 10441   ||
      id == 100441  ||
      id == 443     ||
      id == 10443   ||
      id == 20443   ||
      id == 100443  ||
      id == 30443   ||
      id == 9000443 ||
      id == 9010443 ||
      id == 9020443 ||
      id == 445     ||
      id == 9000445 ||
      id == 4122    ||
      id == 4222    ||
      id == 4212    ||
      id == 4112    ||
      id == 4224    ||
      id == 4214    ||
      id == 4114    ||
      id == 4232    ||
      id == 4132    ||
      id == 4322    ||
      id == 4312    ||
      id == 4324    ||
      id == 4314    ||
      id == 4332    ||
      id == 4334    ||
      id == 4412    ||
      id == 4422    ||
      id == 4414    ||
      id == 4424    ||
      id == 4432    ||
      id == 4434    ||
      id == 4444
      ) {
    return true;
  }
  else return false;
}

bool idIsBeauty(int id) {
  id = abs(id);
  if (
      id == 5       ||
      id == 511     ||
      id == 521     ||
      id == 10511   ||
      id == 10521   ||
      id == 513     ||
      id == 523     ||
      id == 10513   ||
      id == 10523   ||
      id == 20513   ||
      id == 20523   ||
      id == 515     ||
      id == 525     ||
      id == 531     ||
      id == 10531   ||
      id == 533     ||
      id == 10533   ||
      id == 20533   ||
      id == 535     ||
      id == 541     ||
      id == 10541   ||
      id == 543     ||
      id == 10543   ||
      id == 20543   ||
      id == 545     ||
      id == 551     ||
      id == 10551   ||
      id == 100551  ||
      id == 110551  ||
      id == 200551  ||
      id == 210551  ||
      id == 553     ||
      id == 10553   ||
      id == 20553   ||
      id == 30553   ||
      id == 100553  ||
      id == 110553  ||
      id == 120553  ||
      id == 130553  ||
      id == 200553  ||
      id == 210553  ||
      id == 220553  ||
      id == 300553  ||
      id == 9000553 ||
      id == 9010553 ||
      id == 555     ||
      id == 10555   ||
      id == 20555   ||
      id == 100555  ||
      id == 110555  ||
      id == 120555  ||
      id == 200555  ||
      id == 557     ||
      id == 100557  ||
      id == 5122    || 
      id == 5112    ||
      id == 5212    ||
      id == 5222    ||
      id == 5114    ||
      id == 5214    ||
      id == 5224    ||
      id == 5132    ||
      id == 5232    ||
      id == 5312    ||
      id == 5322    ||
      id == 5314    ||
      id == 5324    ||
      id == 5332    ||
      id == 5334    ||
      id == 5142    ||
      id == 5242    ||
      id == 5412    ||
      id == 5422    ||
      id == 5414    ||
      id == 5424    ||
      id == 5342    ||
      id == 5432    ||
      id == 5434    ||
      id == 5442    ||
      id == 5444    ||
      id == 5512    ||
      id == 5522    ||
      id == 5514    ||
      id == 5524    ||
      id == 5532    ||
      id == 5534    ||
      id == 5542    ||
      id == 5544    ||
      id == 5554 
      ) {
    return true;
  }
  else return false;
}


//---------------------------------------------------------

/*bool isFromZ(Lep lep) {
  //status 1 leptons with mother W or with mother tau whose mother is W
  if ( (abs(lep.mc_id())==11 || abs(lep.mc_id())==13) && (abs(lep.mc_motherid())==23 || (abs(lep.mc_motherid())==15 && abs(genps_id_mother()[lep.mc3_motheridx()])==23) ) ) return true;
  //status 1 photons whose mother is a lepton, matching status 3 leptons whose mother is W
  if ( abs(lep.mc_id())==22 && abs(lep.mc_motherid())==abs(lep.pdgId()) && abs(lep.mc3_id())==abs(lep.pdgId()) && abs(lep.mc3_motherid())==23 ) return true;
  //everything else
  return false;
}

bool isFromW(Lep lep) {
  //status 1 leptons with mother W or with mother tau whose mother is W
  if ( (abs(lep.mc_id())==11 || abs(lep.mc_id())==13) && (abs(lep.mc_motherid())==24 || (abs(lep.mc_motherid())==15 && abs(genps_id_mother()[lep.mc3_motheridx()])==24) ) ) return true;
  //status 1 photons whose mother is a lepton, matching status 3 leptons whose mother is W
  if ( abs(lep.mc_id())==22 && abs(lep.mc_motherid())==abs(lep.pdgId()) && abs(lep.mc3_id())==abs(lep.pdgId()) && abs(lep.mc3_motherid())==24 ) return true;
  //everything else
  return false;
}
*/
void passesBaselineCuts(int njets, int nbtag, float met, float ht, int ngoodlep, int ngoodvertex){
//Baseline cuts from discussion
//=> 1 vertex
//gen jets pT>20
//=>1 good lepton
//=>2 jets
//>30GeV Met
}


/*
//-------------------------------------------------------
// get exact trigger name corresponding to given pattern
//-------------------------------------------------------
TString triggerName(TString triggerPattern){

  bool    foundTrigger  = false;
  TString exact_hltname = "";

  for( unsigned int itrig = 0 ; itrig < hlt_trigNames().size() ; ++itrig ){
    if( TString( hlt_trigNames().at(itrig) ).Contains( triggerPattern ) ){
      foundTrigger  = true;
      exact_hltname = hlt_trigNames().at(itrig);
      break;
    }
  }

  if( !foundTrigger) return "TRIGGER_NOT_FOUND";

  return exact_hltname;

}
//---------------------------------------------
// Check if trigger passes
//---------------------------------------------
bool passHLTTriggerPattern(const char* arg){

  TString HLTTriggerPattern(arg);
  TString HLTTrigger = triggerName( HLTTriggerPattern );

  if( HLTTrigger.Contains("TRIGGER_NOT_FOUND")){
    return false;
  }
  return passHLTTrigger( HLTTrigger );
}*/
