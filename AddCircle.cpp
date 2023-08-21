#include "AddCircle.h"
//#include "..\Figures\CRectangle.h"

#include "ApplicationManager.h"

#include "GUI/Output.h"
#include "GUI/Input.h"


AddCircle::AddCircle(ApplicationManager* pApp) :Action(pApp)
{}

void AddCircle::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select the first corner");

	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("Select the second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	CircGfxInfo.isFilled = true;	//default is not filled
	/*get drawing, filling colors and pen width from the interface*/
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();
	CircGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircle::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CCircle *R=new CCircle(P1, P2, CircGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}
