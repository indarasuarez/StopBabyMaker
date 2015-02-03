#include "LeptonTree.h"
#include "CORE/CMS3.h"
#include "CORE/EventSelections.h"
#include "CORE/ElectronSelections.h"
#include "CORE/MuonSelections.h"
#include <algorithm>
#include <cmath>
#include "Math/GenVector/PtEtaPhiE4D.h"

LeptonTree::LeptonTree ()
{
}

LeptonTree::LeptonTree (const std::string &prefix)
  : prefix_(prefix)
{
}


//********************************************************//
//
// NOTE: This function only fills information that is
//       expected to be common to all analyses.
//
// The following information will need to be filled
// by the user for his specific analysis:
//
//      bool passes_id;
//      bool passes_iso;
//      bool is_num;
//      bool is_den;
//      bool is_fo;
//      float corpfiso, cordetiso, corpfiso04, cordetiso04;
//      float effarea, effarea04;
//      float sf_lepeff; (t&p scale factor)
//      float sf_trig; (trigger scale factor)
//      bool is_conv;
//      
//********************************************************//

void LeptonTree::FillCommon (int id, int idx)
{
    if (idx < 0) return;

    int vtxidx = firstGoodVertex();
    is_fromw = not cms3.evt_isRealData() ? leptonIsFromW(idx, id, true) : -999999;

//general stuff
    //p4		= abs(id)==11 ? cms3.els_p4().at(idx) : cms3.mus_p4().at(idx);
    charge	= abs(id)==11 ? cms3.els_charge().at(idx) : abs(id)==13 ? cms3.mus_charge().at(idx) : -999999;
    pdgid	= charge * -1 * abs(id);
    pt 		= abs(id)==11 ? cms3.els_p4().at(idx).pt() : abs(id)==13 ? cms3.mus_p4().at(idx).pt() : -9999999.99;
    eta		= abs(id)==11 ? cms3.els_p4().at(idx).eta() : abs(id)==13 ? cms3.mus_p4().at(idx).eta() : -9999999.99;     
    type	= abs(id)==11 ? cms3.els_type().at(idx) : abs(id)==13 ? cms3.mus_type().at(idx) : -999999;

//mc stuff
    if (!cms3.evt_isRealData()) {
      //      mcp4      = abs(id)==11 ? cms3.els_mc_p4().at(idx) : cms3.mus_mc_p4().at(idx);
            mcid      = abs(id)==11 ? cms3.els_mc_id().at(idx) : abs(id)==13 ? cms3.mus_mc_id().at(idx) : -999999 ;
 //           mcstatus  = cms3.genps_status().at(idx); // PLACEHOLDER, NEEDS FIXING vector<int> &genps_status()??? double check

            mcidx       = abs(id)==11 ? cms3.els_mcidx().at(idx) : abs(id)==13 ? cms3.mus_mcidx().at(idx) : -999999;
            mc_motherid = abs(id)==11 ? cms3.els_mc_motherid().at(idx) : abs(id)==13 ? cms3.mus_mc_motherid().at(idx) : -999999;
   }
    
//electrons
    if (abs(id) == 11)
    {
        is_el  		= true;
        p4           	= cms3.els_p4().at(idx);
        if (!cms3.evt_isRealData()) mcp4	= cms3.els_mc_p4().at(idx);

	//d0 and dz
    	int gsfidx  = cms3.els_gsftrkidx().at(idx);
	if (gsfidx >= 0 && vtxidx >= 0) {
           /* std::pair<float, float> cord0 = gsftrks_d0_pv(gsfidx, vtxidx); NEED TO UPDATE:  gsf track info (p4) not stored so these functions not available
            std::pair<float, float> cordz = gsftrks_dz_pv(gsfidx, vtxidx);
            d0 = cord0.first;
            dz = cordz.first;
            d0err = cord0.second;
            dzerr = cordz.second;
	*/
            
            d0 = cms3.els_d0().at(idx);
            dz = cms3.els_dzPV().at(idx);
            d0err = cms3.els_d0Err().at(idx);
           // dzerr = // els_z0Err
    	}

	//ID 
        //is_eleid_loose= isLooseElectron(idx);
        is_eleid_medium	= isMediumElectron(idx);
        is_eleid_tight  = isTightElectron(idx);
        eoverpin        = cms3.els_eOverPIn().at(idx); 
        
	//ISO
        if (vtxidx >= 0) { //check deltabeta
            pfiso04 = (cms3.els_iso04_pf2012_ch().at(idx) + cms3.els_iso04_pf2012_em().at(idx) + cms3.els_iso04_pf2012_nh().at(idx)) / p4.pt();
	    pfiso03 = (cms3.els_iso03_pf2012_ch().at(idx) + cms3.els_iso03_pf2012_em().at(idx) + cms3.els_iso03_pf2012_nh().at(idx)) / p4.pt();
        }
	//FROM SS CODE
	relIso03 = eleRelIso03(idx);

    } // end electron block

//and now muons....
    if (abs(id) == 13)
    {
        is_mu = true;
        p4 = cms3.mus_p4().at(idx);

        
        int trkidx = cms3.mus_trkidx().at(idx);
        if (trkidx >= 0 && vtxidx >= 0) {
/*NOT WORKING            std::pair<float, float> cord0 = trks_d0_pv(trkidx, vtxidx); //need to check
            std::pair<float, float> cordz = trks_dz_pv(trkidx, vtxidx);
            d0 = cord0.first;
            dz = cordz.first;
            d0err = cord0.second;
            dzerr = cordz.second;*/
	    d0 = cms3.mus_d0().at(idx);
            dz = cms3.mus_dzPV().at(idx);
            d0err = cms3.mus_d0Err().at(idx);
        }
        ip3d    = cms3.mus_ip3d().at(idx);;
        ip3derr = cms3.mus_ip3derr().at(idx);;

        if (!cms3.evt_isRealData()) mcp4      = cms3.mus_mc_p4().at(idx);

        is_pfmu    = ((cms3.mus_type().at(idx) & (1<<5)) != 0);

        if (vtxidx >= 0) {
            is_muoid_tight = isTightMuon(idx);
        }
//muon iso only 03 and 05 no 04
//        pfiso04 = (cms3.mus_iso04_pf2012_ch().at(idx) + cms3.mus_iso04_pf2012_em().at(idx) + cms3.mus_iso04_pf2012_nh().at(idx)) / p4.pt();
// (chiso04 + emiso04 + nhiso04) / p4.pt();        
  //      dbeta04 = cms3.mus_isoR04_pf_PUPt().at(idx);

   //from Same Sign
    relIso03 = muRelIso03(idx);

    } // end muon block
}

void LeptonTree::Reset()
{
    is_mu           = false;
    is_el           = false;
    is_fromw        = -999999;
    charge          = -999999;
    pdgid           = -999999;
    type            = -999999;
    d0              = -999999.;
    d0err           = -999999.;
    dz              = -999999.;
    dzerr           = -999999.;

    pfiso04         = -999999.;
    pfiso03         = -999999.;
    relIso03        = -999999.;
    
    mcid            = -999999;
    mcstatus        = -999999;

    is_eleid_medium = false;
    is_eleid_tight  = false;
    eoverpin        = -999999.;

    is_muoid_tight  = false;
    ip3d            = -999999.;
    ip3derr         = -999999.;
    is_pfmu         = false;

    p4           = LorentzVector(0, 0, 0, 0);
    mcp4         = LorentzVector(0, 0, 0, 0);
    pfp4         = LorentzVector(0, 0, 0, 0);

    pt		= -999999.;
    eta		= -999999.;

   
}

void LeptonTree::SetBranches(TTree* tree)
{
    tree->Branch(Form("%sis_mu"           , prefix_.c_str()) , &is_mu           ); 
    tree->Branch(Form("%sis_el"           , prefix_.c_str()) , &is_el           ); 
    tree->Branch(Form("%sis_fromw"        , prefix_.c_str()) , &is_fromw        ); 
    tree->Branch(Form("%scharge"          , prefix_.c_str()) , &charge          ); 
    tree->Branch(Form("%spdgid"           , prefix_.c_str()) , &pdgid           ); 
    tree->Branch(Form("%stype"            , prefix_.c_str()) , &type            ); 
    tree->Branch(Form("%sd0"              , prefix_.c_str()) , &d0              ); 
    tree->Branch(Form("%sd0err"           , prefix_.c_str()) , &d0err           ); 
    tree->Branch(Form("%sdz"              , prefix_.c_str()) , &dz              ); 
    tree->Branch(Form("%sdzerr"           , prefix_.c_str()) , &dzerr           ); 

     tree->Branch(Form("%spfiso04"	 , prefix_.c_str()) , &pfiso04         );
     tree->Branch(Form("%spfiso03"        , prefix_.c_str()) , &pfiso03         );
     tree->Branch(Form("%srelIso03"       , prefix_.c_str()) , &relIso03       );

    tree->Branch(Form("%smcid"            , prefix_.c_str()) , &mcid            ); 
    tree->Branch(Form("%smcstatus"        , prefix_.c_str()) , &mcstatus        ); 
    
    tree->Branch(Form("%sis_eleid_medium" , prefix_.c_str()) , &is_eleid_medium ); 
    tree->Branch(Form("%sis_eleid_tight"  , prefix_.c_str()) , &is_eleid_tight  ); 
    tree->Branch(Form("%seoverpin"        , prefix_.c_str()) , &eoverpin        ); 

    tree->Branch(Form("%sis_muoid_tight"  , prefix_.c_str()) , &is_muoid_tight  ); 
    tree->Branch(Form("%sip3d"  		 , prefix_.c_str()) , &ip3d);
    tree->Branch(Form("%sip3derr"	 , prefix_.c_str()) , &ip3derr);
    tree->Branch(Form("%sis_pfmu"	 , prefix_.c_str()) , &is_pfmu);

    tree->Branch(Form("%sp4"      , prefix_.c_str()) , "LorentzVector" , &p4      );
    tree->Branch(Form("%smcp4"    , prefix_.c_str()) , "LorentzVector" , &mcp4    );
    tree->Branch(Form("%spfp4"    , prefix_.c_str()) , "LorentzVector" , &pfp4   );

   tree->Branch(Form("%spt"	 , prefix_.c_str()) , &pt);
   tree->Branch(Form("%seta"      , prefix_.c_str()) , &eta);
}
