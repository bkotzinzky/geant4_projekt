#include "G4String.hh"
#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include <ctime>

#include "PhysicsList.hh"
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"

int main(int argc, char** argv)
{

  G4RunManager * runManager = new G4RunManager; 
  runManager->SetUserInitialization(new DetectorConstruction());
  runManager->SetUserInitialization(new PhysicsList());
  runManager->SetUserAction(new PrimaryGeneratorAction());
  RunAction* runAction = new RunAction();
  Output* output = runAction->GetOutput();
  runManager->SetUserAction(runAction);
  runManager->SetUserAction(new EventAction(output));
  runManager->SetUserAction(new SteppingAction(output));
  runManager->Initialize();
  
  //wizualizacja 
  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();  
    
  G4UImanager* UImanager = G4UImanager::GetUIpointer();
  
  if(argc == 1)
  {
    //ui - terminal do wpisywania komend
      G4UIExecutive* ui = new G4UIExecutive(argc, argv);
      UImanager->ApplyCommand("/control/execute ../vis.mac");
      ui->SessionStart(); 
      delete ui;
  }
  else
  {
     G4String filename = argv[1];
     UImanager->ApplyCommand("/control/execute " + filename);
   }
  
   
  delete runManager;
  return 0;
}


