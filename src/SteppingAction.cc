#include "SteppingAction.hh"
#include "G4SteppingManager.hh"
#include "G4Step.hh"
#include "G4LogicalVolume.hh"
#include "G4SystemOfUnits.hh"
#include "Output.hh"
#include <iostream>
#include <cmath>
#include <vector>

SteppingAction::SteppingAction(Output* output_) : output(output_)
{

}

SteppingAction::~SteppingAction()
{

}

void SteppingAction::UserSteppingAction(const G4Step* theStep)
{
	G4Track* track = theStep->GetTrack();
	G4String volumeName = theStep->GetPreStepPoint()->GetPhysicalVolume()->GetName();
	G4double edep = theStep->GetTotalEnergyDeposit();
	G4double mass = theStep->GetPreStepPoint()->GetPhysicalVolume()->GetLogicalVolume()->GetMass();
	G4ThreeVector pos = theStep->GetPreStepPoint()->GetPosition();
	
	double pixel_size = 10*cm/grid_size;
	if (volumeName == "Cell")
	{
		if (edep > 0)
		{
			output->AddHit(pos.x(), pos.y(), pos.z(), edep);			
			ene[0] += edep;
			ene[1] += (edep/joule)/(mass/kg);
			en_deposited += edep;
			hit = 1;
			int xIndex = floor(pos.x()/pixel_size)+grid_size/2;
			int yIndex = floor(pos.y()/pixel_size)+grid_size/2;
			if (xIndex >= 0 && xIndex < grid_size && yIndex >= 0 && yIndex < grid_size) 
			{
            	energy_matrix[xIndex][yIndex] += edep;
        	}
		}
	}
}


void SteppingAction::SaveResults() 
{
    std::ofstream outFile("../output/energy_distribution.txt", std::ios::out);

    if (!outFile) 
    {
        G4cerr << "Error opening file for writing!" << G4endl;
        return;
    }

    for (const auto& row : energy_matrix) 
    {
        for (double energy : row) 
        {
            outFile << energy << " ";
        }
        outFile << "\n"; 
    }
    outFile.close();
}

std::vector<double> SteppingAction::ene=std::vector<double>(2,0);

bool SteppingAction::hit = 0;

double SteppingAction::en_deposited = 0.0;

std::vector<std::vector<double>> SteppingAction::energy_matrix=
							std::vector<std::vector<double>>(grid_size,std::vector<double>(grid_size, 0.0));
										
int SteppingAction::grid_size = 200;

