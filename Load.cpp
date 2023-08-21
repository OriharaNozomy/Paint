#include"Load.h"
#include "ApplicationManager.h"
#include "CTriangle.h"
#include "CCircle.h"
#include "Cline.h"
#include "Figures/CRectangle.h"
#include "GUI/Output.h"
#include "GUI/Input.h"


Load::Load(ApplicationManager* pApp) :Action(pApp)
{}

void Load::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("What is the name of the file?");
	Name = pIn->GetSrting(pOut) + ".text";

	Infile.open(Name);
	pOut->ClearDrawArea();

	if (Infile.is_open())
		pOut->PrintMessage("File has been opened");
	else 
		pOut->PrintMessage("No file with this name"); 

}
//Execute the action
void  Load::Execute()
{
	ReadActionParameters();

	if (Infile.is_open())
	{

		CFigure* newfig;
		int count_of_figs;
		string DrawColor, FillColor;
		Infile >> DrawColor >> FillColor >> count_of_figs;
		UI.DrawColor = ReturnColor(DrawColor);
		UI.FillColor = ReturnColor(FillColor);
		

		pManager->ClearFigList();
		
		for (int j = 0; j < count_of_figs; j++)
		{
			int figure;
			Infile >> figure;
			if (figure==Rect)
				newfig = new CRectangle;
			else if (figure == Line)
				newfig = new CLine;
			else if (figure == Tri)
				newfig = new CTriangle;
			else if (figure == Circ)
				newfig = new CCircle;


			newfig->Load(Infile);

			pManager->AddFigure(newfig);
		}
		Infile.close();
	}
}

