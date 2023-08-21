#ifndef CTRI_H
#define CTRI_H

#include "Figures/CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle();
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	void Draw(Output* pOut) const;
	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar

	void Save(ofstream& Outfile);
	void Load(ifstream& Infile);
	virtual bool iswithmeFig(int, int) const;
	virtual string GetFname()const;

};

#endif