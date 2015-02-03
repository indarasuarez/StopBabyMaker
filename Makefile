ROOTCFLAGS    = $(shell $(ROOTSYS)/bin/root-config --cflags)
ROOTLIBS      = $(shell $(ROOTSYS)/bin/root-config --libs)
ROOTGLIBS     = $(shell $(ROOTSYS)/bin/root-config --glibs)

#######################################
# -- DEFINE ARCH to something sensible!
#######################################
 
#
CXX           = g++
CXXFLAGS      = -g -Wall -fPIC
LD            = g++
LDFLAGS       = -g
SOFLAGS       = -shared


CXXFLAGS      += $(ROOTCFLAGS)
LIBS           = $(ROOTLIBS) 

NGLIBS         = $(ROOTGLIBS) 
NGLIBS        += -lMinuit
GLIBS          = $(filter-out -lNew, $(NGLIBS))

FWLIB	       = /home/users/isuarez/stop/StopBaby/Tools/MiniFWLite/libMiniFWLite.so 

runBabyMaker: runBabyMaker.o looper.o EventTree.o LeptonTree.o JetTree.o CORE/CMS3.o CORE/EventSelections.o CORE/JetSelections.o CORE/ElectronSelections.o CORE/MuonSelections.o
	$(CXX) $(CXXFLAGS) -c $<
	$(LD) $(LDFLAGS)  -o runBabyMaker runBabyMaker.o looper.o EventTree.o JetTree.o LeptonTree.o CORE/CMS3.o CORE/EventSelections.o CORE/JetSelections.o CORE/ElectronSelections.o CORE/MuonSelections.o $(FWLIB) $(GLIBS) 

runBabyMaker.o: runBabyMaker.C looper.h 
	$(CXX) $(CXXFLAGS) -c runBabyMaker.C

looper.o: looper.C looper.h CORE/CMS3.h EventTree.h LeptonTree.h
	$(CXX) $(CXXFLAGS) -c looper.C

EventTree.o: EventTree.cc EventTree.h CORE/CMS3.h CORE/EventSelections.h
	$(CXX) $(CXXFLAGS) -c EventTree.cc

LeptonTree.o: LeptonTree.cc LeptonTree.h CORE/CMS3.h CORE/EventSelections.h CORE/ElectronSelections.h CORE/MuonSelections.h
	$(CXX) $(CXXFLAGS) -c LeptonTree.cc
JetTree.o: JetTree.cc JetTree.h CORE/CMS3.h CORE/EventSelections.h CORE/JetSelections.h
	$(CXX) $(CXXFLAGS) -c JetTree.cc

#CMS3.o: CMS3.cc CMS3.h
#	$(CXX) $(CXXFLAGS) -c CMS3.cc

.PHONY: clean
clean:  
	rm -v -f \
	runBabyMaker \
	*o *d *.so; echo "Done"
