#include"DrawColor.h"
//#include "..\Figures\CRectangle.h"

#include "ApplicationManager.h"

#include "GUI/Output.h"
#include "GUI/Input.h"

DrawColor::DrawColor(ApplicationManager* pApp) :Action(pApp)
{}

void DrawColor::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Change drawing color");
	pOut->cleartoolbar();
	pOut->CreateColorToolBar();
	color x;
	pManager->GetColor(x);
	pManager->ChangeDRAWcllo(x);
	pOut->ClearStatusBar();

}
//Execute the action
void DrawColor::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

}
