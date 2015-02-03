#include "EventTree.h"
#include "LeptonTree.h"
#include "JetTree.h"
#include "CORE/CMS3.h"
#include "TFile.h"
#include "TTree.h"
#include "TRandom.h"
#include "TF1.h"
#include "Math/VectorUtil.h"
#include "TChain.h"
#include "Math/LorentzVector.h"

// // typedefs
 typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

#ifndef LOOPER_H
#define LOOPER_H

#pragma GCC diagnostic ignored "-Wwrite-strings"

using namespace std;

class babyMaker {

  public:
    //constructor/destructor
    babyMaker ();
    babyMaker (const std::string &prefix);
    virtual ~babyMaker (){}

    void MakeBabyNtuple(const char* output_name);
    void InitBabyNtuple();
    int looper(TChain* chain, char* output_name, int nEvents = -1, string signal_in = "");

  protected:
    TFile* BabyFile;
    TTree* BabyTree;

  private:

    //for tree
    EventTree StopEvt;
    LeptonTree lep1;
    LeptonTree lep2;
    JetTree jets;

// = new EventTree(); //dont make a pointer
};

struct val_err_t { float value; float error; };

#endif
