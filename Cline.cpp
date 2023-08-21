#include "Cline.h"

CLine::CLine()
{

}
CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}


void CLine::Draw(Output* pOut) const
{
	pOut->DrawLine(Corner1, Corner2, FigGfxInfo, Selected);
}
void CLine::PrintInfo(Output* pOut) {
	//Forming the printed message string then passing it to PrintMessage
	string message = "Line, ID: " + to_string(ID) + ", Corner 1: (" + to_string(Corner1.x) + "," + to_string(Corner1.y)
		+ "), Corner 2: (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + "), Length: "
		+ to_string(int(CalcDistance(Corner2, Corner2)));
	pOut->PrintMessage(message);
}
void CLine::Save(ofstream& Outfile)
{
	string DrawColor = NameOfColor(FigGfxInfo.DrawClr);
	Outfile << Line << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << DrawColor << " ";

}


void CLine::Load(ifstream& Infile)
{
	string DrawColor;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> DrawColor;
	FigGfxInfo.DrawClr = ReturnColor(DrawColor);
	FigGfxInfo.BorderWdth = UI.PenWidth;
}

bool CLine::iswithmeFig(int x, int y) const
{
	//Creates a point P(x,y) to use in CalcDistance
	Point P;
	P.x = x;
	P.y = y;
	//Calculate distances AB, AP, and PB, where A and B are the start and the end respectively
	double line = CalcDistance(Corner1, Corner2);
	double AP = CalcDistance(Corner1, P);
	double PB = CalcDistance(Corner2, P);
	return (abs(line - (AP + PB)) <= 0.25);

}

string CLine::GetFname() const
{
	return "line";
}
