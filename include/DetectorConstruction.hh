#ifndef DetectorConstruction_H
#define DetectorConstruction_H 1

#include "G4VUserDetectorConstruction.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4NistManager.hh"  
#include "G4Material.hh" 

class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:

    DetectorConstruction(); 
    virtual ~DetectorConstruction();
    virtual G4VPhysicalVolume* Construct(); 
    virtual void ConstructSDandField(); 

  private:
    G4LogicalVolume* worldLogic; 
    G4LogicalVolume* petriLogVol;
    G4NistManager* man;
    
    G4VPhysicalVolume* ConstructWorld(); 
    void ConstructDish();

    G4Material* MakeResin();
    
 
};

#endif
