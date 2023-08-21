#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:

	CRectangle();
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar

	void Draw(Output* pOut) const;
	void Save(ofstream& Outfile);
	void Load(ifstream& Infile);
	virtual bool iswithmeFig(int, int) const;
	virtual string GetFname()const;

};

#endif