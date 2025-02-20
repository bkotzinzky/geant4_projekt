#include "PhysicsList.hh"
#include "G4SystemOfUnits.hh"
#include "G4EmDNAPhysics_option4.hh"
#include "G4EmStandardPhysics_option4.hh"

PhysicsList::PhysicsList() : G4VModularPhysicsList()
{
  	SetDefaultCutValue(0.001 * millimeter);
  	SetVerboseLevel(1);
    RegisterPhysics(new G4EmStandardPhysics_option4());
}


PhysicsList::~PhysicsList() {}


void PhysicsList::SetCuts(){


  SetCutsWithDefault();
}




