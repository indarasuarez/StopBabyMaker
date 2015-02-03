#ifndef EVENTTREE_H
#define EVENTTREE_H
 
#include <string>
#include <vector>
#include "CORE/EventSelections.h"
 
// forward declarations
class TTree;
 
// typedefs
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;
typedef std::vector<LorentzVector> vecLorentzVector;
typedef std::vector<float> vecd;
typedef std::vector<std::string> vecs;
 
class EventTree
{
public:
    // constructor/destructor
    EventTree ();
    EventTree (const std::string &prefix);
    virtual ~EventTree (){}
 
    void Reset ();
    void SetBranches (TTree* tree);
    void SetAliases (TTree* tree) const;
    void FillCommon (const std::string &root_file_name = "");
 
private:
    std::string prefix_;
 
public:
    // branch objects
    unsigned int run;
    unsigned int ls;
    unsigned int evt;

    unsigned int nEvents;
    unsigned int nEvents_goodvtx;
    unsigned int nEvents_MET30;
    unsigned int nEvents_1goodlep;
    unsigned int nEvents_2goodjets;    

    int ngoodlep;
     
    int nvtxs;
    int pu_nvtxs;
    int gen_nleps;
    int gen_nels;
    int gen_nmus;
    int gen_ntaus;
    int gen_nleps_fromtau;
    int gen_nels_fromtau;
    int gen_nmus_fromtau;
    int gen_ntaus_fromtau;
     
    float pfmet;
    float pfmet_phi;
    float genmet;
    float genmet_phi;
    float scale1fb;
    float xsec;
    float kfactor;
    float pu_ntrue;
     
    bool is_data;
 
    std::string dataset;
    std::string filename;    
    std::string cms3tag;
     
    vecd sparm_values;
    vecs sparm_names;
    vecd tau_charge;
    vector<bool> tau_MedisoCI3hit;
    vecd tau_againstMuonTight;
    vecd tau_againstElectronLoose;
    int Ntaus;
    vecLorentzVector tau_p4;

      vecd isoTrack_pt;   
      vecd isoTrack_eta;                                         
      vecd isoTrack_phi;                                         
      vecd isoTrack_mass;                                        
      vecd isoTrack_absIso;                                      
      vecd isoTrack_dz;                                          
      vector<int> isoTrack_pdgId;

};
 
#endif
