#include"PickByColorAndType.h"
//#include "..\Figures\CRectangle.h"
#include<iostream>
#include "ApplicationManager.h"

#include "GUI/Output.h"
#include "GUI/Input.h"

PickByColorAndType::PickByColorAndType(ApplicationManager* pApp) :Action(pApp)
{
}

void PickByColorAndType::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	int Count = 0;
	Fig = pManager->RandFig(Count);
	color c = pManager->RandColor2(Fig);
	pOut->PrintMessage(" Pick Figures with " + NameOfColor(c) + " color and shape "+ Fig );
	int n = pManager->GetFigCount();

	pManager->creatcopyfiglist();
	pManager->CreatColorAndTypeList(c,Fig);
	int k = pManager->GetColorAndTypeListCount();
	for (int i = 0; i < n; i++)

	{

		pIn->GetPointClicked(P.x, P.y);
		SelectedFig = pManager->GetFigure(P.x, P.y);

		while (SelectedFig == NULL)
		{

			pIn->GetPointClicked(P.x, P.y);

			pOut->PrintMessage("click on fig");

			SelectedFig = pManager->GetFigure(P.x, P.y);

		}


		if (SelectedFig->IsSelected())
		{
			Unselect();
		}




		if (SelectedFig->FigGfxInfo.FillClr == c && SelectedFig->GetFname() ==Fig)
		{
			W++;
			pManager->Pick(SelectedFig);
			pManager->RemoveColorAndTypeList();
			pOut->PrintMessage("Valid picks : " + to_string(W) + " Invalid picks: " + to_string(L));
		}


		else
		{
			L++;
			pOut->PrintMessage("Valid picks : " + to_string(W) + " Invalid picks: " + to_string(L));
		}




		if (pManager->GetColorAndTypeListCount() == 0)
			break;

	}
	if (W == k && L == 0)
	{
		pOut->PrintMessage("You Won!  Valid picks : " + to_string(W) + " Invalid picks: " + to_string(L));
	}
	else
	{
		pOut->PrintMessage("You Lost.  Valid picks : " + to_string(W) + " Invalid picks: " + to_string(L));
	}
	pManager->backtonormal();


}

void PickByColorAndType::select() {
	SelectedFig->SetSelected(true); //Sets the figure as "selected"
	pManager->AddSelectedFigure(SelectedFig); //Add the figure to ApplicationManager's SelectedFigs array
}

//Unselect a selected figure
void PickByColorAndType::Unselect() {
	SelectedFig->SetSelected(false); //Sets the figure as "unselected"
	pManager->RemoveSelectedFigure(SelectedFig);	//Removes the figure from ApplicationManager's SelectedFigs array


}

//Execute the action
void  PickByColorAndType::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();


}

