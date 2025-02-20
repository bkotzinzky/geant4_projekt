#ifndef Output_H
#define Output_H
#include <string>
#include "TFile.h"
#include "TTree.h"

class Output
{
	public:
		Output(std::string filename);
		~Output();
		void AddEdep(double energy_dep);
		void AddHit(double x, double y, double z, double step_energy_dep);
	private:
		Output* name;
		TFile* outputFile;
		TTree* outputTree;
		TTree* hitTree;
		
		double energy_dep;
		
        double x;
        double y;
        double z;
        double step_energy_dep;
};
#endif
