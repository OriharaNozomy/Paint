#include "PlayWithType.h"
#include "GUI/Input.h"
#include"GUI/Output.h"
#include"ApplicationManager.h"
#include"Figures/CFigure.h"
PlayWithType::PlayWithType(ApplicationManager* pApp) :Action(pApp)
{
	Correct = 0;
	Wrong = 0;
}

void PlayWithType::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pManager->creatcopyfiglist();
	int Count = 0;
	Fig = pManager->RandFig(Count);

	if (Fig != "Empty")
	{
		pOut->PrintMessage("Select all " + Fig);

		while (Count > 0)
		{
			pIn->GetPointClicked(P.x, P.y);
			CFigure* SFig = pManager->GetFigure(P.x, P.y);
			if (SFig != NULL)                                            //to check if user clicked on a figure or not
			{
				if (SFig->GetFname() == Fig)
				{
					Correct++;                                 //if user clicked on the required figure correct ans is increased by 1
					pManager->Pick(SFig);
					Count--;
					pOut->PrintMessage("Correct Ans = " + to_string(Correct) + "worng Ans = " + to_string(Wrong));

				}
				else
				{
					Wrong++;                                 //if user clicked on another figure wrong ans is increased by 1
					pOut->PrintMessage("Correct Ans = " + to_string(Correct) + "worng Ans = " + to_string(Wrong));
				}
			}
		}
	}
	else                                         //if user Click in The Tool or Status Ba
	{
		pOut->PrintMessage("Correct Ans = " + to_string(Correct) + "        "+ "Wrong Ans = " + to_string(Wrong) + "        It's Play Mode : Please select any icon from the tool bar");
		return;

	}
	pManager->backtonormal();
	if (Wrong > 0) {
	pOut->PrintMessage("you loss Correct Ans = " + to_string(Correct) + "worng Ans = " + to_string(Wrong));
	}
	else {
		pOut->PrintMessage(" you win !!! Correct Ans = " + to_string(Correct) + "worng Ans = " + to_string(Wrong));

	}
}
void  PlayWithType::Execute()
{
	ReadActionParameters();


}
