#include"PickByColor.h"
//#include "..\Figures\CRectangle.h"
#include<iostream>
#include "ApplicationManager.h"

#include "GUI/Output.h"
#include "GUI/Input.h"

PickByColor::PickByColor(ApplicationManager* pApp) :Action(pApp)
{
}

void PickByColor::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int Count = 0;
	color c = pManager->RandColor();
	pOut->PrintMessage(" Pick Figures with " + NameOfColor(c) + " color.");
	int n = pManager->GetFigCount();

	pManager->creatcopyfiglist();
	pManager->CreatColorList(c);
	int k = pManager->GetColorListCount();
	for (int i = 0; i < n; i++)

	{

		pIn->GetPointClicked(P1.x, P1.y);
		SelectedFig = pManager->GetFigure(P1.x, P1.y);

		while (SelectedFig == NULL)
		{

			pIn->GetPointClicked(P1.x, P1.y);

			pOut->PrintMessage("click on fig");

			SelectedFig = pManager->GetFigure(P1.x, P1.y);

		}


		if (SelectedFig->IsSelected())
		{
			Unselect();
		}


		if (SelectedFig->FigGfxInfo.FillClr == c)
		{
			W++;
			pManager->Pick(SelectedFig);
			pManager->RemoveColorList();
			pOut->PrintMessage("Valid picks : " + to_string(W) + " Invalid picks: " + to_string(L));
		}


		else
		{
			L++;
			pOut->PrintMessage("Valid picks : " + to_string(W) + " Invalid picks: " + to_string(L));
		}


	

		if (pManager->GetColorListCount() == 0)
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

void PickByColor::select() {
	SelectedFig->SetSelected(true); //Sets the figure as "selected"
	pManager->AddSelectedFigure(SelectedFig); //Add the figure to ApplicationManager's SelectedFigs array
}

//Unselect a selected figure
void PickByColor::Unselect() {
	SelectedFig->SetSelected(false); //Sets the figure as "unselected"
	pManager->RemoveSelectedFigure(SelectedFig);	//Removes the figure from ApplicationManager's SelectedFigs array


}

//Execute the action
void  PickByColor::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();


}

