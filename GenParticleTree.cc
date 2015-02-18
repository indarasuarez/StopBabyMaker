#include "GenParticleTree.h"
#include "Math/GenVector/PtEtaPhiE4D.h"
#include "/home/users/isuarez/CORE/CMS3.h"
#include "StopSelections.h"

GenParticleTree::GenParticleTree ()
{
}

GenParticleTree::GenParticleTree (const std::string &prefix)
  : prefix_(prefix)
{
}

using namespace tas;

void GenParticleTree::FillCommon (int idx, int pdgid_=0, int pdgmotherid_=0, int status_=0)
{
	if (idx < 0) return;
        
        if(pdgid_ != 0 || abs(pdgid_) != abs(genps_id().at(idx))) return;
        if(pdgmotherid_ != 0 || abs(pdgmotherid_) != abs(genps_id_mother().at(idx))) return;
        if(status_ != 0 || status_ != genps_status().at(idx)) return;

        isfromt.push_back(abs(genps_id_mother().at(genps_idx_mother().at(idx))) == pdg_t);
 
	  p4.push_back(genps_p4().at(idx));
          charge.push_back(genps_charge().at(idx));
  	  iso.push_back(genps_iso().at(idx));
          mass.push_back(genps_mass().at(idx));
          id.push_back(genps_id().at(idx));
 	  id_mother.push_back(genps_id_mother().at(idx));          
 	  status.push_back(genps_status().at(idx));
          lepdaughter_id.push_back(genps_lepdaughter_id().at(idx));

	//if gen taus
	if(abs(genps_id().at(idx)) != 15){
	 gentaudecay.push_back(NoTau); 
	  return;
	}
        //flag for tau decay leptonic (e, mu), hadronic (1, 3 prongs)
        int nprongs = 0;
	bool leptonic = false;

        //find daughters
        for(unsigned int genx = 0; genx < genps_p4().size() ; genx++){
	  if(genps_idx_mother().at(genx) != idx) continue;
	  if(genps_status().at(genx) != 1 && genps_status().at(genx) != 2) continue;
	  //rhos and pions show up as status 2
//          cout<<"Daughter particle  "<<abs(genps_id().at(genx))<<"  status "<<genps_status().at(genx)<<endl;
	  if(abs(genps_id().at(genx)) ==12 || abs(genps_id().at(genx)) ==14 || abs(genps_id().at(genx)) ==16) continue; //skip neutrinos
          //for now no continues in case theres something funky going on
	  if(abs(genps_id().at(genx)) == 11){
		 gentaudecay.push_back(Lep_e); // tau decaying to electron
	 	 leptonic = true;
	  }
          if(abs(genps_id().at(genx)) == 13){
		gentaudecay.push_back(Lep_mu); // tau decaying to muon
                 leptonic = true;
          }
          if(abs(genps_id().at(genx)) !=11 && abs(genps_id().at(genx)) !=13 && genps_charge().at(genx) !=0){
	    nprongs++;
          }
 	}
	if(nprongs == 1) gentaudecay.push_back(Had_1prong);
        if(nprongs == 3) gentaudecay.push_back(Had_3prong);
        if((nprongs != 1 && nprongs != 3) && leptonic==false){
		 gentaudecay.push_back(other);
        }
        
}

void GenParticleTree::Reset()
{
	p4.clear();
	charge.clear();
	iso.clear();
        mass.clear();
	id.clear();
	id_mother.clear();
	status.clear();
	lepdaughter_id.clear();
	gentaudecay.clear();
        gen_n = -9999;
}

void GenParticleTree::SetBranches(TTree* tree)
{

	tree->Branch(Form("gen%sp4"      , prefix_.c_str()) , "LorentzVector" , &p4      );
	tree->Branch(Form("gen%scharge"  , prefix_.c_str()) , 	     &charge          );
        tree->Branch(Form("gen%siso"  , prefix_.c_str()) ,           &iso          );
        tree->Branch(Form("gen%smass"  , prefix_.c_str()) ,           &mass          );
        tree->Branch(Form("gen%sid"  , prefix_.c_str()) ,           &id          );
        tree->Branch(Form("gen%sid_mother"  , prefix_.c_str()) ,           &id_mother          );
        tree->Branch(Form("gen%sstatus"  , prefix_.c_str()) ,           &status          );
        tree->Branch(Form("gen%slepdaughter_id"  , prefix_.c_str()) ,           &lepdaughter_id          );
        tree->Branch(Form("gen%sgentaudecay"  , prefix_.c_str()) ,           &gentaudecay          );
        tree->Branch(Form("gen_n%s"  , prefix_.c_str()) ,           &gen_n);
}
