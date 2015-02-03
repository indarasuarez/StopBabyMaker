#include "JetTree.h"
#include "CORE/CMS3.h"
#include "CORE/JetSelections.h"
using namespace tas;
 
JetTree::JetTree () :
    m_ak4_pt_cut(0),
    m_ak8_pt_cut(0)
{
}
 
void JetTree::FillCommon ()
{
    // fill info for ak4pfjets
    int nGoodJets=0;
    for (size_t idx = 0; idx < cms3.pfjets_p4().size(); ++idx)
    {
        if (cms3.pfjets_p4().at(idx).pt() < m_ak4_pt_cut) continue;
 
        ak4pfjets_p4.push_back(cms3.pfjets_p4().at(idx));
        ak4pfjets_btag_disc.push_back(cms3.pfjets_combinedInclusiveSecondaryVertexV2BJetTag().at(idx));
        ak4pfjets_pu_id.push_back(cms3.pfjets_pileupJetId().at(idx));
        ak4pfjets_parton_flavor.push_back(cms3.pfjets_partonFlavour().at(idx));
        ak4pfjets_loose_id.push_back(isLoosePFJet(idx));

        if(cms3.pfjets_p4().at(idx).pt() > 30. && isLoosePFJet(idx)) nGoodJets++;
    }

   ak4GoodPFJets = nGoodJets;
   nGoodJets=0;
 
    // fill info for ak8pfjets
    for (size_t idx = 0; idx < cms3.ak8jets_p4().size(); ++idx)
    {
        if (cms3.ak8jets_p4().at(idx).pt() < m_ak8_pt_cut) continue;
 
        ak8pfjets_p4.push_back(cms3.ak8jets_p4().at(idx));
        ak8pfjets_tau1.push_back(ak8jets_nJettinessTau1().at(idx));
        ak8pfjets_tau2.push_back(ak8jets_nJettinessTau2().at(idx));
        ak8pfjets_tau3.push_back(ak8jets_nJettinessTau3().at(idx));
        ak8pfjets_top_mass.push_back(ak8jets_topJetMass().at(idx));
        ak8pfjets_pruned_mass.push_back(ak8jets_prunedMass().at(idx));
        ak8pfjets_trimmed_mass.push_back(ak8jets_trimmedMass().at(idx));
        ak8pfjets_filtered_mass.push_back(ak8jets_filteredMass().at(idx));
        ak8pfjets_pu_id.push_back(ak8jets_pileupJetId().at(idx));    
        ak8pfjets_parton_flavor.push_back(ak8jets_partonFlavour().at(idx));

        if(cms3.ak8jets_p4().at(idx).pt()>100. && isLoosePFJet(idx)) nGoodJets++;

    }
    ak8GoodPFJets = nGoodJets;
    nGoodJets=0;

    // fill info for genjets
    for (size_t idx = 0; idx < cms3.genjets_p4NoMuNoNu().size(); ++idx)
    {
        if (cms3.genjets_p4NoMuNoNu().at(idx).pt() < m_ak4_pt_cut) continue;
 
        ak4genjets_p4.push_back(cms3.genjets_p4NoMuNoNu().at(idx));
        if(cms3.genjets_p4NoMuNoNu().at(idx).pt() > 20.)  nGoodJets++;
    }
    nGoodGenJets = nGoodJets;
    
}
        
void JetTree::SetJetPtSelection (std::string cone_size, float pt_cut)
{
    if (cone_size == "ak4") m_ak4_pt_cut = pt_cut;
    else if (cone_size == "ak8") m_ak4_pt_cut = pt_cut;
    else {std::cout << "Invalid cone size." << std::endl;}
    return;
}
 
void JetTree::GetJetPtSelections (std::string cone_size)
{
    if (cone_size == "ak4") std::cout << "ak4 jet pt > " << m_ak4_pt_cut << std::endl;
    else if (cone_size == "ak8") std::cout << "ak8 jet pt > " << m_ak8_pt_cut << std::endl;
    else
    {
        std::cout << "ak4 jet pt > " << m_ak4_pt_cut << std::endl;        
        std::cout << "ak8 jet pt > " << m_ak8_pt_cut << std::endl;
    }
}
 
void JetTree::Reset ()
{
    ak4pfjets_p4.clear();
    ak4pfjets_qg_disc.clear();    
    ak4pfjets_btag_disc.clear();
    ak4pfjets_pu_id.clear();
    ak4pfjets_parton_flavor.clear();
    ak4pfjets_loose_id.clear();
 
    ak8pfjets_p4.clear();
    ak8pfjets_tau1.clear();
    ak8pfjets_tau2.clear();
    ak8pfjets_tau3.clear();
    ak8pfjets_top_mass.clear();
    ak8pfjets_pruned_mass.clear();
    ak8pfjets_trimmed_mass.clear();
    ak8pfjets_filtered_mass.clear();
    ak8pfjets_pu_id.clear();    
    ak8pfjets_parton_flavor.clear();
 
    ak4genjets_p4.clear(); 
    
    ak4GoodPFJets = -99999;   
    ak8GoodPFJets = -99999;
    nGoodGenJets = -999999;
}
 
void JetTree::SetBranches (TTree* tree)
{
    tree->Branch("nGoodGenJets", &nGoodGenJets);
    tree->Branch("ak4GoodPFJets", &ak4GoodPFJets);
    tree->Branch("ak8GoodPFJets", &ak8GoodPFJets);
    tree->Branch("ak4pfjets_p4", &ak4pfjets_p4);
    tree->Branch("ak4pfjets_qg_disc", &ak4pfjets_qg_disc);
    tree->Branch("ak4pfjets_btag_disc", &ak4pfjets_btag_disc);
    tree->Branch("ak4pfjets_pu_id", &ak4pfjets_pu_id);
    tree->Branch("ak4pfjets_parton_flavor", &ak4pfjets_parton_flavor);
    tree->Branch("ak4pfjets_loose_id", &ak4pfjets_loose_id);
 
    tree->Branch("ak8pfjets_p4", &ak8pfjets_p4);
    tree->Branch("ak8pfjets_tau1", &ak8pfjets_tau1);
    tree->Branch("ak8pfjets_tau2", &ak8pfjets_tau2);
    tree->Branch("ak8pfjets_tau3", &ak8pfjets_tau3);
    tree->Branch("ak8pfjets_top_mass", &ak8pfjets_top_mass);
    tree->Branch("ak8pfjets_pruned_mass", &ak8pfjets_pruned_mass);
    tree->Branch("ak8pfjets_trimmed_mass", &ak8pfjets_trimmed_mass);
    tree->Branch("ak8pfjets_filtered_mass", &ak8pfjets_filtered_mass);
    tree->Branch("ak8pfjets_pu_id", &ak8pfjets_pu_id);    
    tree->Branch("ak8pfjets_parton_flavor", &ak8pfjets_parton_flavor);
 
    tree->Branch("ak4genjets_p4", &ak4genjets_p4);    
}
