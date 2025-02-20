#ifndef SteppingAction_H
#define SteppingACtion_H 1
#include <vector>
#include "G4UserSteppingAction.hh"
#include "Output.hh"


class SteppingAction : public G4UserSteppingAction
{
  public:
	SteppingAction(Output* output_);
    virtual ~SteppingAction();
    virtual void UserSteppingAction(const G4Step*); 
    static std::vector<double> ene;
    static bool hit;    
    static double en_deposited;
    static std::vector<std::vector<double>> energy_matrix;
    static int grid_size;
    static void SaveResults();
  private:
    Output* output;
};

#endif
