#ifndef JETTREE_H
#define JETTREE_H
 
#include <string>
#include <vector>
#include "Math/LorentzVector.h"
 
// forward declarations
class TTree;
 
// typedefs
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;
typedef std::vector<LorentzVector> vecLorentzVector;
typedef std::vector<float> vecd;
typedef std::vector<bool> vecb;
typedef std::vector<int> veci;
typedef std::vector<std::vector<int> > vecii;
 
class JetTree
{
public:
    // constructor/destructor
    JetTree ();
    virtual ~JetTree () {}
 
    void Reset ();
    void SetBranches (TTree* tree);
    void SetAliases (TTree* tree);
    void FillCommon ();
    void SetJetPtSelection (std::string cone_size, float pt_cut);
    void GetJetPtSelections (std::string cone_size = "");
     
    // branch objects
 
    // ak4 PF jets
    int ak4GoodPFJets;
    int ak8GoodPFJets;
    int nGoodGenJets;

    vecLorentzVector ak4pfjets_p4;
    vecd ak4pfjets_qg_disc;    
    vecd ak4pfjets_btag_disc;
    vecd ak4pfjets_pu_id;
    veci ak4pfjets_parton_flavor;
    vecb ak4pfjets_loose_id;
     
    // ak8 PF jets
    vecLorentzVector ak8pfjets_p4;
    vecd ak8pfjets_tau1;
    vecd ak8pfjets_tau2;
    vecd ak8pfjets_tau3;
    vecd ak8pfjets_top_mass;
    vecd ak8pfjets_pruned_mass;
    vecd ak8pfjets_trimmed_mass;
    vecd ak8pfjets_filtered_mass;
    vecd ak8pfjets_pu_id;    
    veci ak8pfjets_parton_flavor;
     
    // genjets    
    vecLorentzVector ak4genjets_p4;    
 
private:
    float m_ak4_pt_cut;
    float m_ak8_pt_cut;
};
 
#endif
