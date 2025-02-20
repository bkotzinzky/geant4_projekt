#ifndef RunAction_h
#define RunAction_h 1

#include "G4UserRunAction.hh"
#include "G4Timer.hh"
#include "Output.hh"
#include <fstream>
class G4Run;

class RunAction : public G4UserRunAction
{
  public:
    RunAction();
    virtual ~RunAction();
    virtual void BeginOfRunAction(const G4Run*);
    virtual void   EndOfRunAction(const G4Run*);
    Output* GetOutput() { return output; }
  private:
    G4Timer* timer;
    std::ofstream outputFile;
    Output* output;
};


#endif

