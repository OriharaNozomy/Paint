#include "AddLine.h"
//#include "..\Figures\CRectangle.h"

#include "ApplicationManager.h"

#include "GUI/Output.h"
#include "GUI/Input.h"

AddLine::AddLine(ApplicationManager* pApp) :Action(pApp)
{
}

void  AddLine::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select the first point");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("Select the second point");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	LineGfxInfo.isFilled = true;	//default is not filled
	
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.FillClr = pOut->getCrntFillColor();
	LineGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
}
//Execute the action
void  AddLine::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CLine *R=new CLine(P1, P2, LineGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}
