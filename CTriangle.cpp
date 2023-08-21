#include "CTriangle.h"

CTriangle::CTriangle()
{

}
CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTriangle(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}
void CTriangle::PrintInfo(Output* pOut)  {
	//Forming the printed message string then passing it to PrintMessage
	string message = "Triangle, ID: " + to_string(ID) + ", Corner 1: (" + to_string(Corner1.x) + "," + to_string(Corner1.y)
		+ "), Corner 2: (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + "), Corner 3: (" + to_string(Corner3.x)
		+ "," + to_string(Corner3.y) + ")";
	pOut->PrintMessage(message);
}

void CTriangle::Save(ofstream& Outfile)
{

	string DrawColor = NameOfColor(FigGfxInfo.DrawClr);
	Outfile << Tri << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << Corner3.x << " " << Corner3.y << " " << DrawColor << " ";

		string FillColor = NameOfColor(FigGfxInfo.FillClr);
		Outfile << FillColor << endl;
}


void CTriangle::Load(ifstream& Infile)
{

	string DrawColor,FillColor;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y >> DrawColor >> FillColor;
	FigGfxInfo.DrawClr = ReturnColor(DrawColor);

		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = ReturnColor(FillColor);
	FigGfxInfo.BorderWdth = UI.PenWidth;

}

bool CTriangle::iswithmeFig(int x, int y) const
{
	Point P;
	P.x = x;
	P.y = y;

	double area_the_draw_triangle = 0.5 * ((Corner1.x * (Corner2.y - Corner3.y)) + (Corner2.x * (Corner3.y - Corner1.y)) + (Corner3.x * (Corner1.y - Corner2.y)));
	double area_Triangle_one = 0.5 * ((P.x * (Corner2.y - Corner3.y)) + (Corner2.x * (Corner3.y - P.y)) + (Corner3.x * (P.y - Corner2.y)));
	double area_Triangle_two = 0.5 * ((Corner1.x * (P.y - Corner3.y)) + (P.x * (Corner3.y - Corner1.y)) + (Corner3.x * (Corner1.y - P.y)));
	double area_Triangle_three = 0.5 * ((Corner1.x * (Corner2.y - P.y)) + (Corner2.x * (P.y - Corner1.y)) + (P.x * (Corner1.y - Corner2.y)));

	if (abs(area_the_draw_triangle) == (abs(area_Triangle_one) + abs(area_Triangle_two) + abs(area_Triangle_three))) return true;
	else
		return false;
}

string CTriangle::GetFname() const
{
	return "triangle";
}
