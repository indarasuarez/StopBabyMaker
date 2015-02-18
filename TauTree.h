#ifndef TAUTREE_H
#define TAUTREE_H

#include <vector>
#include <string>
#include "Math/LorentzVector.h"

class TTree;

// typedefs
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;
typedef std::vector<LorentzVector> vecLorentzVector;
typedef std::vector<float> vecd;
typedef std::vector<std::string> vecs;
typedef std::vector<int> veci;
typedef std::vector<bool> vecb;

class TauTree
{
public:
    TauTree ();
    virtual ~TauTree () {}

    void Reset ();
    void SetBranches (TTree* tree);
    void SetAliases (TTree* tree) const;
    void FillCommon ();

    vecd tau_charge;
    vecb tau_MedisoCI3hit;
    vecb tau_byDecayModeFinding;
    vecd tau_againstMuonTight;
    vecd tau_againstElectronLoose;
    int ngoodtaus;
    vecLorentzVector tau_p4;

};

#endif
