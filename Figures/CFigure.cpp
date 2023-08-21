#include "CFigure.h"

CFigure::CFigure()
{

}
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected=s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

string CFigure::NameOfColor(color c)const
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

color CFigure::ReturnColor(string c)const
{
	if (c == "RED")
		return RED;
	else if (c == "GREEN")
		return GREEN;
	else if (c == "BLUE")
		return BLUE;
	else if (c == "BLACK")
		return BLACK;
	else if (c=="NONE")
		return UI.BkGrndColor;
}
double CFigure::CalcDistance(Point A, Point B) const {
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}