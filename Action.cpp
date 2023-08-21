#include "Actions/Action.h"
#include "CMUgraphicsLib/colors.h"
#include "DEFS.h"
#include "GUI/Output.h"
string Action::NameOfColor(color c)const
{

	if (c == RED)
		return "RED";
	else if (c == GREEN)
		return "GREEN";
	else if (c == BLUE)
		return "BLUE";
	else if (c == BLACK)
		return "BLACK";
	else
		return "NONE";
}

color Action::ReturnColor(string c)const
{
	if (c == "RED")
		return RED;
	else if (c == "GREEN")
		return GREEN;
	else if (c == "BLUE")
		return BLUE;
	else if (c == "BLACK")
		return BLACK;
	else if (c == "NONE")
		return UI.BkGrndColor;
}