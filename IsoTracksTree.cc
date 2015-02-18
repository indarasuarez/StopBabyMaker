#include "IsoTracksTree.h"
#include "Math/GenVector/PtEtaPhiE4D.h"
#include "/home/users/isuarez/CORE/CMS3.h"
#include "StopSelections.h"

IsoTracksTree::IsoTracksTree ()
{
}

using namespace tas;

void IsoTracksTree::FillCommon (int idx)
{
 
   //pfcands_particleId()
   //   StopEvt.track_overlep1_idx = getOverlappingTrackIndex(lep1.p4, lep1.pdgid, pfcands_p4() , 0.4);
   //    if(nGoodLeptons>1) StopEvt.track_overlep2_idx = getOverlappingTrackIndex(lep2.p4, lep2.pdgid, pfcands_p4() , 0.4);
       if (idx < 0) return;

     //if electron or muon, iso < 0.2
      isoTracks_charge.push_back    ( pfcands_charge().at(idx)   );
      isoTracks_p4.push_back    ( pfcands_p4().at(idx)   );
      isoTracks_absIso.push_back( TrackIso(idx)                    );
      isoTracks_dz.push_back    ( pfcands_dz().at(idx)        );
      isoTracks_pdgId.push_back ( pfcands_particleId().at(idx));

        //keep special vector of indeces for the boat load of shit
             if(abs(pfcands_particleId().at(idx))!=11 && abs(pfcands_particleId().at(idx))!=13){
                if(pfcands_p4().at(idx).pt() < 10.) return;
                if(TrackIso(idx) >0.1) return;
             }else{
                if(TrackIso(idx) >0.2) return;
             }
             isoTracks_selectedidx.push_back(idx);
}


void IsoTracksTree::Reset()
{
    isoTracks_p4.clear();
    isoTracks_charge.clear();
    isoTracks_absIso.clear();
    isoTracks_dz.clear();
    isoTracks_pdgId.clear();
    isoTracks_selectedidx.clear();
    isoTracks_nselected = -9999;
}

void IsoTracksTree::SetBranches(TTree* tree)
{

    tree->Branch("isoTracks_p4", &isoTracks_p4);
    tree->Branch("isoTracks_charge", &isoTracks_charge);
    tree->Branch("isoTracks_absIso", &isoTracks_absIso);
    tree->Branch("isoTracks_dz", &isoTracks_dz);
    tree->Branch("isoTracks_pdgId", &isoTracks_pdgId);
    tree->Branch("isoTracks_selectedidx", &isoTracks_selectedidx);
    tree->Branch("isoTracks_nselected", &isoTracks_nselected);
}
