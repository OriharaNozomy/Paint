#include "SwitchToPlay.h"
#include "ApplicationManager.h"
#include "GUI/Output.h"
#include "GUI/Input.h"

SwitchToPlay::SwitchToPlay(ApplicationManager* pApp) :Action(pApp)
{}

void SwitchToPlay::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage(" Switch to play mode.");

	pOut->CreatePlayToolBar();

	pOut->ClearStatusBar();

}
//Execute the action
void  SwitchToPlay::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

}
