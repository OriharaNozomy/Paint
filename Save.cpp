#include"Save.h"
#include "ApplicationManager.h"
#include "GUI/Output.h"
#include "GUI/Input.h"
#include "CMUgraphicsLib/colors.h"

Save::Save(ApplicationManager* pApp) :Action(pApp)
{}

void Save::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("What do you want to name the file? ");

	Name = pIn->GetSrting(pOut) + ".text";

	Outfile.open(Name);

	if (Outfile.is_open())
		pOut->PrintMessage("File has been Saved");
	else 
		pOut->PrintMessage("Cannot save file");

}


//Execute the action
void  Save::Execute()
{
	ReadActionParameters();

	if (Outfile.is_open())
	{
		int NO_FIGS = pManager->NO_FIGS();
		string DrawClr = NameOfColor(UI.DrawColor);
		string FillClr = NameOfColor(UI.FillColor);
		Outfile << DrawClr << " " << FillClr << " " << NO_FIGS << endl;
		pManager->SaveAll(Outfile);
		Outfile.close();
	}
}

