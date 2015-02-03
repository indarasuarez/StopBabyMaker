#ifndef EVENTSELECTIONS_H
#define EVENTSELECTIONS_H
#include "CMS3.h"
#include "TString.h"

//vertices & pileup
bool isGoodVertex(size_t ivtx);
int numberOfGoodVertices();
int firstGoodVertex();

//gen functions
int leptonGenpCount(int& nele, int& nmuon, int& ntau);
int leptonGenpCount_lepTauDecays(int& nele, int& nmuon, int& ntau);
int leptonIsFromW(int idx, int id, bool alsoSusy);
bool idIsCharm(int id);
bool idIsBeauty(int id);
//TString triggerName(TString);
//bool passHLTTriggerPattern(const char*);
float TrackIso(int);
//bool isFromW(Lep lep);
//bool isFromZ(Lep lep);

void passesBaselineCuts(int njets, int nbtag, float met, float ht, int ngoodlep, int ngoodvertex);

//void passesBaselineCuts(int njets, int nbtag, float met, float ht, unsigned int& analysisBitMask);

//  float met;
//  float metphi;
//  float metx;
//  float mety;
//  float sumet;

#endif
