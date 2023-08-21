#include"ChangeFillColor.h"
//#include "..\Figures\CRectangle.h"

#include "ApplicationManager.h"

#include "GUI/Output.h"
#include "GUI/Input.h"


ChangeFillColor::ChangeFillColor(ApplicationManager* pApp) :Action(pApp)
{}

void ChangeFillColor::ReadActionParameters() 
{

	//Output* pOut = pManager->GetOutput();
	//Input* pIn = pManager->GetInput();
	//t = pManager->drawcol();
	//if (t != NULL) {

	//	pOut->cleartoolbar();
	//	pOut->CreateColorToolBar();
	//	color x;
	//	pManager->GetColor(x);
	//	t->ChngFillClr(x);

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->cleartoolbar();
	pOut->CreateColorToolBar();
	color x;
	pManager->GetColor(x);
	pManager->ChangeFillcllo(x);

	}


void ChangeFillColor::Execute()
{
	ReadActionParameters();
}
