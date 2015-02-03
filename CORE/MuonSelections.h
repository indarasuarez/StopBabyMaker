#ifndef MUONSELECTIONS_H
#define MUONSELECTIONS_H
#include "CMS3.h"
#include "TString.h"


float muRelIso03(unsigned int);
float muRelIso03EA(unsigned int);
float muRelIso03DB(unsigned int);
float muRelIso04DB(unsigned int);

bool isGoodVetoMuon(unsigned int);
bool isFakableMuon(unsigned int);
bool isGoodMuon(unsigned int);

bool isLooseMuon(unsigned int);
bool isTightMuon(unsigned int);
bool isMuonFO(unsigned int);

bool PassMuonPreSelections(unsigned int);

#endif
