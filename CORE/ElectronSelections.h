#ifndef ELECTRONSELECTIONS_H
#define ELECTRONSELECTIONS_H
#include "CMS3.h"
#include "TString.h"

bool isFakableElectron(unsigned int, int);
bool isGoodElectron(unsigned int);        
bool isGoodVetoElectron(unsigned int);
bool isVetoElectron(unsigned int);
bool isLooseElectron(unsigned int);
bool isMediumElectron(unsigned int);                                                                                                                                                       
bool isElectronFO(unsigned int);
int  isElectronFO_debug(unsigned int);
bool isTightElectron(unsigned int);
float eleRelIso03DB(unsigned int);
float eleRelIso03(unsigned int);

bool PassElectronPreSelections(unsigned int elIdx);

float eleRelIso03EA(unsigned int);
bool threeChargeAgree(unsigned int);


#endif
