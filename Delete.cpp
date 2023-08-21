#include"Delete.h"
//#include "..\Figures\CRectangle.h"

#include "ApplicationManager.h"

#include "GUI/Output.h"
#include "GUI/Input.h"

Delete::Delete(ApplicationManager* pApp) :Action(pApp)
{}

void Delete::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Delete figure. ");

}
//Execute the action
void  Delete::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pManager->deleteselected();

}