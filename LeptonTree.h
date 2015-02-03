#ifndef LEPTONTREE_H
#define LEPTONTREE_H

#include <string>
#include "Math/LorentzVector.h"

// forward declaration
class TTree;

// typedefs
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

class LeptonTree
{
public:
    LeptonTree ();
    LeptonTree (const std::string &prefix);
    virtual ~LeptonTree () {}

    void Reset ();
    void SetBranches (TTree* tree);
    void SetAliases (TTree* tree) const;
    void FillCommon (int id, int idx);

protected:

    std::string prefix_; //what is this for?

public:    

    //
    // lepton reco info
    //
    LorentzVector p4;
    LorentzVector pfp4;
    float pt;
    float eta; 
    bool is_mu;
    bool is_el;
    int is_fromw;
    int charge;
    int pdgid;
    int type;
    float d0;
    float d0err;
    float dz;
    float dzerr;

    float pfiso04;  //2012 only available for electrons
    float pfiso03;  //2012 only available for electrons
    float relIso03; //ss

    float ip3d;
    float ip3derr;
    bool is_pfmu;

    //
    // lepton gen info
    //
    LorentzVector mcp4;
    int mcid;
    int mcstatus;
    int mcidx;
    int mc_motherid;
    int mc_motheridx;
    //
    // electron specific info
    //
    bool is_eleid_medium;
    bool is_eleid_tight;
    float eoverpin; 

    //
    // muon specific info
    //
    bool is_muoid_tight;
 
};

#endif
