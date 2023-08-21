#pragma once
#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "Figures/CFigure.h"

class CCircle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	double Radius;

public:
	CCircle();
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar

	void Draw(Output* pOut) const;
	void Save(ofstream& Outfile);
	void Load(ifstream& Infile);
	virtual bool iswithmeFig(int, int) const;
	virtual string GetFname()const;


};

#endif
