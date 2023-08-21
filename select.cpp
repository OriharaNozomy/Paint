#include"select.h"
//#include "..\Figures\CRectangle.h"

#include "ApplicationManager.h"
#include <iostream>
using namespace std;
#include "GUI/Output.h"
#include "GUI/Input.h"

Select::Select(ApplicationManager* pApp) :Action(pApp)
{}

void  Select::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage(" Select Figure");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P.x, P.y);
	pOut->ClearStatusBar();
	pOut->PrintMessage("123 ebraaaaaaa");

	SelectedFig = pManager->GetFigure(P.x, P.y);


	pOut->PrintMessage("click on fig");

	SelectedFig = pManager->GetFigure(P.x, P.y);



	//Checks if a figure was clicked, and whether the clicked figure is already selected
	if (SelectedFig != NULL) {
		if (SelectedFig->IsSelected())
			Unselect();
		else
			select();

	}
	pManager->UpdateInterface();
}

//Selected an unselected figure
void Select::select() {
	SelectedFig->SetSelected(true); //Sets the figure as "selected"
	pManager->AddSelectedFigure(SelectedFig); //Add the figure to ApplicationManager's SelectedFigs array
	Output* pOut = pManager->GetOutput(); //Get a Pointer to the Output Interface

	SelectedFig->PrintInfo(pOut); //Print the selected figure info on the status bar

}

//Unselect a selected figure
void Select::Unselect() {
	SelectedFig->SetSelected(false); //Sets the figure as "unselected"
	pManager->RemoveSelectedFigure(SelectedFig);	//Removes the figure from ApplicationManager's SelectedFigs array


}
//Execute the action
void Select::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

}

