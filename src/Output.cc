#include "Output.hh"
#include <iostream>
Output::Output(std::string filename)
{
	outputFile = new TFile(filename.c_str(), "RECREATE");
	outputTree = new TTree("outputTree", "outputTree");
	outputTree->Branch("energy_dep", &energy_dep);
	
    hitTree = new TTree("hitTree", "hitTree");
    hitTree->Branch("x", &x);
    hitTree->Branch("y", &y);
    hitTree->Branch("z", &z);
    hitTree->Branch("step_energy_dep", &step_energy_dep);
}

Output:: ~Output()
{
	outputFile->Write();
	outputFile->Close();
	delete outputFile;
}

void Output::AddEdep(double energy_depV)
{
	energy_dep = energy_depV;
	outputTree->Fill();
}

void Output::AddHit(double xV, double yV, double zV, double step_energy_depV)
{
    x = xV;
    y = yV;
    z = zV;
    step_energy_dep = step_energy_depV;
    hitTree->Fill();
}

