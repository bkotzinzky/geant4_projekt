#include "RunAction.hh"
#include "G4Run.hh"
#include "SteppingAction.hh"
#include "EventAction.hh"
#include "G4SystemOfUnits.hh"
#include "Output.hh"
#include <ctime>

RunAction::RunAction(): G4UserRunAction()
{ 
	outputFile.open("../output/stat.txt", std::ios::out);
    	if (!outputFile.is_open()) 
    	{
    		G4cerr << "Error: Failed to open file stat.txt" << G4endl;
    	return;
    	}
    timer = new G4Timer;
    
    output = new Output("../output/data.root");
}


RunAction::~RunAction()
{
	if (outputFile.is_open()) 
	{
    	outputFile.close();
	} 
    delete timer;
	delete output;
}

void RunAction::BeginOfRunAction(const G4Run* run)
{ 
   	G4cout << "### Run " << run->GetRunID() << " start." << G4endl; 
   	timer->Start();	
   	std::time_t start_time_t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	outputFile << "Simulation started at: " << std::ctime(&start_time_t);
}


void RunAction::EndOfRunAction(const G4Run* run)
{
	timer->Stop();
   	G4cout << "number of event = " << run->GetNumberOfEvent() 
    << " " << *timer << G4endl; 
    std::time_t end_time_t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    G4double elapsed_time = timer->GetRealElapsed(); 
	if (outputFile.is_open()) 
	{	
    	outputFile << "Simulation ended at: " << std::ctime(&end_time_t);
   	    outputFile << "Elapsed time: " << elapsed_time << " seconds"<< "\n";		
		outputFile << "Number of events: " << run->GetNumberOfEvent()<< "\n";
    	outputFile << "Number of hits in cells: " << EventAction::hits<< "\n";  
    	outputFile << "Absorbed Dose: " << SteppingAction::ene[1]<< " Gy\n";
    	outputFile << "Deposited Energy: " << SteppingAction::ene[0]<< " MeV\n";    	
   	}
   	SteppingAction::SaveResults();
}



