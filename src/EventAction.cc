#include "EventAction.hh"
#include "SteppingAction.hh"
#include "G4SystemOfUnits.hh"
#include "Output.hh"

EventAction::EventAction(Output* output_) : output(output_)
{

}
 
EventAction::~EventAction()
{

}

void EventAction::BeginOfEventAction(const G4Event* anEvent)
{
    
}
 
void EventAction::EndOfEventAction(const G4Event* anEvent)
{
	if (SteppingAction::en_deposited>0)
	{
		output->AddEdep(SteppingAction::en_deposited);
		hits += SteppingAction::hit;
		SteppingAction::en_deposited = 0.0;
		SteppingAction::hit = 0;
	}
}

int EventAction::hits = 0;
