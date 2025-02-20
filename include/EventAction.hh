#ifndef EventAction_h
#define EventAction_h 1

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "Output.hh"
#include <fstream>

class EventAction : public G4UserEventAction
{
  public:
    EventAction(Output* output_);
    virtual ~EventAction();
    virtual void BeginOfEventAction(const G4Event*);
   	virtual void   EndOfEventAction(const G4Event*) override;
   	static int hits;   
    
  private:
    std::ofstream outputFile;
    Output* output;

};

#endif
