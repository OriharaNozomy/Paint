#include "ApplicationManager.h"
#include "Actions/AddRectangle.h"
#include "AddCircle.h"
#include"AddTriangle.h"
#include "AddLine.h"
#include"DrawColor.h"
#include "ChangeFillColor.h"
#include "select.h"
#include "SwitchToPlay.h"
#include "PickByColorAndType.h"
#include"Save.h"
#include "Delete.h"
#include "Load.h"
#include "PickByColor.h"
#include "SwitchToDraw.h"
#include"PlayWithType.h"
#include <iostream>
#include"GUI/Input.h"

using namespace std;

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	FigCount = 0;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectangle(this);
			break;
		case DRAW_CIRC:
			pAct = new AddCircle(this);
			break;
		case DRAW_TRI:
			pAct = new AddTriangle(this);
			break;
		case DRAW_LINE:
			pAct = new  AddLine(this);
			break;
		case CHNG_DRAW_CLR:
			pAct = new DrawColor(this);
			break;
		case CHNG_FILL_CLR:
		pAct = new ChangeFillColor(this);
			break;

		case SELECT:
			pAct = new  Select(this);
			break;
		//case COPY:
		//	pAct = new  Select(this);
		//	break;
		//case PASTE:
		//	pAct = new  Select(this);
		//	break;
		//case CUT:
		//	pAct = new  Select(this);
		//	break;

		case SWITCH_TO_PLAY:
			pAct = new SwitchToPlay(this);
			break;
		case SAVE:
			pAct = new Save(this);
			break;
		case DEL:
			pAct = new Delete(this);
			break;
		case LOAD:
			pAct = new Load(this);
			break;
		case SWITCH_TO_DRAW:
			pAct = new SwitchToDraw(this);
			break;
		case SELECT_BY_COLOR:
			pAct = new PickByColor(this);
			break;
		case EXIT:
			///create ExitAction here	
			break;
		case SELECT_BY_TYPE:
			pAct = new PlayWithType(this);
			break;
		case SELECT_BY_TYPE_AND_COLOR:
			pAct = new PickByColorAndType(this);
			break;
			
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
	{
		FigList[FigCount] = pFig;
		FigCount++;
	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	CFigure* c;
	for (int i = 0; i < FigCount; i++) 
	{
		if (FigList[i]->iswithmeFig(x, y))
		{
			c= FigList[i];
		}

	}
	return c;
}
int ApplicationManager::GetFigCount() const
{
	return FigCount;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
void ApplicationManager::UpdateInterfaceplay() const
{
	for (int i = 0; i < FigCount; i++)
		Figlistcopy[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
 

//Removing ???????????????/////////////////////////

void ApplicationManager::ClearFigList()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
	RemoveSelects();
}

void ApplicationManager::RemoveSelects()
{
	for (int i = 0; i < selectedFigsCount; i++)
	{
		SelectedFigs[i] = NULL;
	}
	selectedFigsCount = 0;
}
//////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

int ApplicationManager::NO_FIGS() const
{
	return FigCount;
}


void ApplicationManager::SaveAll(ofstream& OutFile)
{
	//Loop on each figure ,then saving it 
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(OutFile);
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// For selecting 
void ApplicationManager::AddSelectedFigure(CFigure* s)
{
	SelectedFigs[selectedCount] = s;
	selectedCount++;

}

int ApplicationManager::GetSelectedCount() const {
	return selectedCount;
}

void ApplicationManager::RemoveSelectedFigure(CFigure* sf) {

	for (int i = 0; i < selectedCount; i++) {
		if (SelectedFigs[i] == sf) {
			SelectedFigs[i] = SelectedFigs[selectedCount - 1];
			SelectedFigs[selectedCount - 1] = NULL;
			selectedCount--;
			return;
		}
	}
}



void ApplicationManager::ClearSelectedFigs() {
	for (int i = 0; i < selectedCount; i++)
	{
		SelectedFigs[i] = NULL;
	}
	selectedCount = 0;
}

void ApplicationManager::deleteselected()
{
	int x = 0;
	CFigure* deletedfigures[MaxFigCount];
	for (int j = 0; j < FigCount; j++)
	{
		if (FigList[j]->IsSelected())
		{
			deletedfigures[x++] = FigList[j];
			FigList[j] = NULL;
			for (int i = j; i < FigCount-1; i++) { FigList[i] = FigList[i + 1]; }
			FigList[MaxFigCount] = NULL;
		}
	}
	FigCount -= x;
	pOut->ClearDrawArea();
	UpdateInterface();
	for (int i = 0; i < x; i++) { delete deletedfigures[i]; }
}

//////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
//Reads a color from the color toolbar
void ApplicationManager::GetColor(color& inputColor) {

	bool isColor = true;
	//Creating the color toolbar
	pOut->CreateColorToolBar();
	//inputColor = RED;
	//Inputting draw color action
	int x, y;
	pIn->GetPointClicked(x, y);
	if (y >= 0 && y <= UI.ToolBarHeight)
	{
		int order = x / UI.MenuItemWidth;
		switch (order) {
		case SET_BLACK:
			inputColor = BLACK;
			break;

		case SET_RED:
			inputColor = RED;
			break;

		case SET_GREEN:
			inputColor = GREEN;
			break;

		case SET_BLUE:
			inputColor = BLUE;
			break;

		default:
			inputColor = BLUE;
		}

	}
	//Restoring the draw toolbar
	pOut->CreateDrawToolBar();

}


void ApplicationManager::ChangeDRAWcllo(color x)
{
	UI.DrawColor = x;
}

void ApplicationManager::ChangeFillcllo(color x)
{
	UI.FillColor = x;
}

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
////////////////////////////////////////////////////////////////
///////////////////////play mode fun ////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
string ApplicationManager::RandFig(int& Count)const
{
	Count = 0;
	int Rand;
	string Figure;
	srand(time(NULL));

	if (FigCount != 0)
	{
		if (FigCount != 1)
		{
			//Randomly choose The Figure
			Rand = rand() % FigCount;
			Figure = FigList[Rand]->GetFname();
			for (int i = 0; i < FigCount; i++)
			{
				if (FigList[Rand]->GetFname() == FigList[i]->GetFname()) /// هل فيه ا;تر من شكل ولا لا 
				{
					Count++;  
				}
			}
		}
		else
		{
			Figure = FigList[0]->GetFname();
			Count = 1;
		}
		return Figure;
	}
	return "Empty";
}

color ApplicationManager::RandColor()const
{
	int Rand;
	color Figure;
	srand(time(NULL));

	Rand = rand() % FigCount;
	Figure = FigList[Rand]->FigGfxInfo.FillClr;

	return Figure;

}

color ApplicationManager::RandColor2(string s)
{
	int Rand;
	color Figure;
	string myfig;
	srand(time(NULL));

	Rand = rand() % FigCount;
	myfig = FigList[Rand]->GetFname();
	while (myfig != s)
	{
		Rand = rand() % FigCount;
		myfig = FigList[Rand]->GetFname();
	}
	Figure = FigList[Rand]->FigGfxInfo.FillClr;
	
	return Figure;

}

//CFigure* ApplicationManager::drawcol(){
//
//	CFigure* c;
//	if (SelectedFigs != NULL) {
//		c = SelectedFigs[1];
//		return c;
//	}

	



void ApplicationManager::creatcopyfiglist()
{
	for (int i = 0; i < FigCount; i++)
	{
		Figlistcopy[i] = FigList[i];
	}
	for (int i = FigCount; i < 200; i++)
	{
		Figlistcopy[i] = NULL;
	}
	Figcountcopy = FigCount;
}

void ApplicationManager::Pick(CFigure* x)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (x == FigList[i])
		{
			for (int j = i; j < FigCount-1; j++)
			{
				FigList[j] = FigList[j + 1];
			}
			FigList[FigCount--] = NULL;
			break;
		}
	}
	UpdateInterface();
}

void ApplicationManager::backtonormal()
{
	FigCount = Figcountcopy;
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i] = Figlistcopy[i];
	}
	UpdateInterface();
}

void ApplicationManager::CreatColorList(color s)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->FigGfxInfo.FillClr == s)
		{
			ColorList[i] == FigList[i];
			colorlistcount++;
		}

	}
}
void ApplicationManager::RemoveColorList()
{
	colorlistcount--;
}

int ApplicationManager::GetColorListCount() const
{
	return colorlistcount;
}


void ApplicationManager::CreatColorAndTypeList(color c, string s)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->FigGfxInfo.FillClr == c && FigList[i]->GetFname() == s)
		{
			ColorAndTypeList[i] == FigList[i];
			colorandtypelistcount++;
		}

	}
}

int ApplicationManager::GetColorAndTypeListCount()
{
	return colorandtypelistcount;
}

void ApplicationManager::RemoveColorAndTypeList()
{
	colorandtypelistcount--;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//CFigure* ApplicationManager::GetSelectedFigures() {
//
//	return SelectedFigs[1];
//}