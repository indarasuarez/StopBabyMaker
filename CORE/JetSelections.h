#ifndef JETSELECTIONS_H                                                                                                                                                                             
#define JETSELECTIONS_H
#include "CMS3.h"
#include "TString.h"

bool isLoosePFJet(unsigned int pfJetIdx);
bool isMediumPFJet(unsigned int pfJetIdx);
bool isTightPFJet(unsigned int pfJetIdx);

bool passesPFJetPreSelections(unsigned int pfJetIdx);
bool passesPFJetID(unsigned int pfJetIdx);

bool JetIsElectron(LorentzVector);
bool JetIsMuon(LorentzVector);

#endif
