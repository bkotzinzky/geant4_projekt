#include "PrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "G4GeneralParticleSource.hh"
#include <cmath>


PrimaryGeneratorAction::PrimaryGeneratorAction()
{
	particleSource = new G4GeneralParticleSource();
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
	delete particleSource;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  particleSource->GeneratePrimaryVertex(anEvent);
} 




