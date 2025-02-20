#include "DetectorConstruction.hh"
#include "G4PVPlacement.hh" 
#include "G4SystemOfUnits.hh" 
#include "G4VisAttributes.hh" 

#include "G4Box.hh" 
#include "G4Tubs.hh" 
#include "G4ThreeVector.hh" 
#include "globals.hh"
#include "G4SubtractionSolid.hh"

DetectorConstruction::DetectorConstruction()
{
    worldLogic = 0L;
    petriLogVol=0L;
    man = G4NistManager::Instance();
}



DetectorConstruction::~DetectorConstruction()
{
    if(worldLogic != 0L)
        delete worldLogic;
    if(petriLogVol != 0L)
        delete petriLogVol;        

}


G4VPhysicalVolume* DetectorConstruction::Construct()
{
    G4VPhysicalVolume* worldPhys = ConstructWorld();
    ConstructDish();
   
    return worldPhys;
}


G4VPhysicalVolume* DetectorConstruction::ConstructWorld()
{

    G4double worldX = 20*cm;
    G4double worldY = 20*cm;
    G4double worldZ = 20*cm;
    G4Box* worldSolid = new G4Box("worldSolid",worldX,worldY,worldZ);
   
    G4Material* vaccum = new G4Material("GalacticVacuum", 1., 1.01*g/mole,
                           CLHEP::universe_mean_density,
                           kStateGas, 3.e-18*pascal, 2.73*kelvin);
                           
    worldLogic = new G4LogicalVolume(worldSolid, vaccum,"worldLogic", 0,0,0);
    G4VPhysicalVolume* worldPhys = new G4PVPlacement(0, G4ThreeVector(), worldLogic, "world", 0, false, 0);
    return worldPhys;

}


G4Material* DetectorConstruction::MakeResin()
{
    G4Element* H = man->FindOrBuildElement("H");
    G4Element* O = man->FindOrBuildElement("O");
    G4Element* C = man->FindOrBuildElement("C");
    G4Element* Cl = man->FindOrBuildElement("C");
    G4Material* resin = new G4Material("resin", 1.25*g/cm3, 4);
    resin->AddElement(H, 25);
    resin->AddElement(O, 5);
    resin->AddElement(C, 21);
    resin->AddElement(Cl, 1);
    return resin;
}

void DetectorConstruction::ConstructDish()
{  
//Szalka Petriego
    G4Tubs* cylinder1 = new G4Tubs("cylinder1", 0, 5.15*cm, 0.75*cm, 0*deg, 360*deg);
    G4Tubs* cylinder2 = new G4Tubs("cylinder2", 0, 5.00*cm, 0.675*cm, 0*deg, 360*deg);
    G4ThreeVector zTrans(0*cm, 0*cm, 0.075*cm);
    G4SubtractionSolid* petriSolid = new G4SubtractionSolid("PetriDish",cylinder1,cylinder2,0,zTrans);
    
    G4NistManager* man = G4NistManager::Instance();
    G4Material* poli = man->FindOrBuildMaterial("G4_POLYSTYRENE"); 
    G4LogicalVolume* petriLogVol = new G4LogicalVolume(petriSolid, poli, "petriLogVol"); 
    
    G4VisAttributes* petriVisAtt = new G4VisAttributes( G4Colour(1, 1, 1, 0.3));
    petriVisAtt->SetForceSolid(true);
	petriLogVol->SetVisAttributes(petriVisAtt);

	G4ThreeVector posPetri(0,0,0*cm);    
	new G4PVPlacement(0, posPetri, petriLogVol, "Petri", worldLogic, 0, 0);

//Komorki	
	G4Tubs* cellSolid = new G4Tubs("cellSolid", 0, 5*cm, 0.075*cm, 0*deg, 360*deg);
    G4Material* water = man->FindOrBuildMaterial("G4_WATER"); 
    G4LogicalVolume* cellLogVol = new G4LogicalVolume(cellSolid, water, "cellLogVol"); 
    
    G4VisAttributes* cellVisAtt = new G4VisAttributes( G4Colour(0.61, 0.81, 1));
	cellVisAtt->SetForceSolid(true);
	cellLogVol->SetVisAttributes(cellVisAtt);

	G4ThreeVector posCell(0,0,0.-0.525*cm);    
	new G4PVPlacement(0, posCell, cellLogVol, "Cell", worldLogic, 0, 0);


//Źródło
	G4Tubs* sourceSolid = new G4Tubs("sourceSolid", 0, 6*cm, 0.75*cm, 0*deg, 360*deg);
    G4Material* resin = man->FindOrBuildMaterial("G4_WATER");
    G4LogicalVolume* sourceLogVol = new G4LogicalVolume(sourceSolid, resin, "sourceLogVol"); 
    
    G4VisAttributes* sourceVisAtt = new G4VisAttributes( G4Colour(0.36, 0.125, 0.125));
	sourceVisAtt->SetForceSolid(true);
	sourceLogVol->SetVisAttributes(sourceVisAtt);
	
	G4ThreeVector posSource(0,0,-1.5*cm);    
	new G4PVPlacement(0, posSource, sourceLogVol, "Source", worldLogic, 0, 0);
}
void DetectorConstruction::ConstructSDandField()
{



}
