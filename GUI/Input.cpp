#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

bool Input::GetMouseCoord(int& x, int& y) const
{
	pWind->GetMouseCoord(x, y);
	return true;
}


void Input::GetPointClicked(int& x, int& y, int& z) const
{
	pWind->WaitMouseClick(x, y,z);	//Wait for mouse click
}


string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if(Key == 8 )	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label+= Key;
		pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
	
	if(y >= 0 && y < UI.ToolBarHeight)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (UI.InterfaceMode == MODE_DRAW)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_TRI: return DRAW_TRI;
			case ITM_LINE: return DRAW_LINE;
			case ITM_CHNG_DRAW_CLR: return CHNG_DRAW_CLR;
			case ITM_CHNG_FILL_CLR: return CHNG_FILL_CLR;
			case ITM_SELECT: return SELECT;
			case ITM_COPY: return COPY;
			case ITM_PASTE: return PASTE;
			case ITM_CUT: return CUT;
			case ITM_SWITCH_TO_PLAY: return SWITCH_TO_PLAY;
			case ITM_SAVE: return SAVE;
			case ITM_DEL: return DEL;
			case ITM_LOAD: return LOAD;


			case ITM_EXIT: return EXIT;	
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		else if (UI.InterfaceMode == MODE_PLAY)//GUI is in PLAY mode
		{
			///TODO:
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_SELECT_BY_TYPE: return SELECT_BY_TYPE;
			case ITM_SELECT_BY_COLOR: return SELECT_BY_COLOR;
			case ITM_SELECT_BY_TYPE_AND_COLOR: return SELECT_BY_TYPE_AND_COLOR;
			case ITM_SWITCH_TO_DRAW: return SWITCH_TO_DRAW;

			default: return EMPTY;
			}
		}
		
		//[3] User clicks on the status bar
	}

	else if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
	{
		return DRAWING_AREA;
	}
	
	return STATUS;
}
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		//just for now. This should be updated
	


/////////////////////////////////
	
Input::~Input()
{
}
