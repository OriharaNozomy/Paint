#include "CCircle.h"

CCircle::CCircle()
{

}
CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Radius = CalcDistance(Corner1, Corner2);

}
void CCircle::PrintInfo(Output* pOut)  {
	//Forming the printed message string then passing it to PrintMessage
	string message = "Circle, ID: " + to_string(ID) 
		+ "), Radius: " + to_string(int(Radius));
	pOut->PrintMessage(message);
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawCircle(Corner1, Corner2, FigGfxInfo, Selected);
}

void CCircle::Save(ofstream& Outfile)
{

	string DrawColor = NameOfColor(FigGfxInfo.DrawClr);
	Outfile << Circ << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y <<" " << DrawColor << " ";

		string FillColor = NameOfColor(FigGfxInfo.FillClr);
		Outfile << FillColor << endl;

}


void CCircle::Load(ifstream& Infile)
{

	string DrawColor, FillColor;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> DrawColor >> FillColor;
	FigGfxInfo.DrawClr = ReturnColor(DrawColor);


		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = ReturnColor(FillColor);

	FigGfxInfo.BorderWdth = UI.PenWidth;

}
bool CCircle::iswithmeFig(int x, int y) const
{
	//Creates a point P(x,y) to use in CalcDistance
	Point P;
	P.x = x;
	P.y = y;
	//to check if the point in the circle wa check the distance between center and the point if it is within the range
	return (Radius >= CalcDistance(Corner1, P));
}

string CCircle::GetFname() const
{
	return "circle";
}
