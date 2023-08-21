#include "SwitchToDraw.h"

#include "ApplicationManager.h"

#include "GUI/Output.h"
#include "GUI/Input.h"

SwitchToDraw::SwitchToDraw(ApplicationManager* pApp) :Action(pApp)
{}

void SwitchToDraw::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage(" Switch to play mode.");

	pOut->CreateDrawToolBar();

	pOut->ClearStatusBar();

}
//Execute the action
void  SwitchToDraw::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

}
