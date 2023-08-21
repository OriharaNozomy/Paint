#include "CRectangle.h"
#include <iostream>
#include "CFigure.h"
using namespace std;
CRectangle::CRectangle()
{

}

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
void CRectangle::PrintInfo(Output* pOut){
	//Forming the printed message string then passing it to PrintMessage
	string message = "Rectangle, ID: " + to_string(ID) + ", Corner 1: (" + to_string(Corner1.x) + "," + to_string(Corner1.y)
		+ "), Corner 2: (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + "), Length: "
		+ to_string(abs(Corner1.x - Corner2.x)) + ", Width: " + to_string(abs(Corner1.y - Corner2.y));
	pOut->PrintMessage(message);
}

void CRectangle::Save(ofstream &Outfile)
{
	string DrawColor = NameOfColor(FigGfxInfo.DrawClr);
	Outfile << Rect << " " << ID << " " << Corner1.x << " " << Corner1.y << " " 
		<< Corner2.x << " " << Corner2.y << " " << DrawColor << " ";

		string FillColor = NameOfColor(FigGfxInfo.FillClr);
		Outfile << FillColor << endl;

}


void CRectangle::Load(ifstream& Infile)
{

	string DrawColor, FillColor;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> DrawColor >> FillColor;
	FigGfxInfo.DrawClr = ReturnColor(DrawColor);

		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = ReturnColor(FillColor);
	FigGfxInfo.BorderWdth = UI.PenWidth;

}


bool CRectangle::iswithmeFig(int x, int y) const 
{
	return ((x >= Corner1.x && x <= Corner2.x) || (x <= Corner1.x && x >= Corner2.x)) 
		&& ((y >= Corner1.y && y <= Corner2.y) || (y <= Corner1.y && y >= Corner2.y));
}

string CRectangle::GetFname() const
{
	return "rectangle";
}
