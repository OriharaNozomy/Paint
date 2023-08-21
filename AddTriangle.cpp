#include "AddTriangle.h"
#include "CTriangle.h"

#include "ApplicationManager.h"

#include "GUI/Output.h"
#include "GUI/Input.h"


AddTriangle::AddTriangle(ApplicationManager* pApp) :Action(pApp)
{}

void AddTriangle::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Draw a triangle");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	//pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);

	TGfxInfo.isFilled = true;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TGfxInfo.FillClr = pOut->getCrntFillColor();
	TGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}
//Execute the action
void AddTriangle::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CTriangle *R=new CTriangle(P1,P2,P3,TGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}
