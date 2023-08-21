#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <fstream>

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	
	
	/// Add more parameters if needed.

public:
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	GfxInfo FigGfxInfo;	//Figure graphis info

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual void PrintInfo(Output* pOut)= 0;	//print all figure info on the status bar

	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual bool iswithmeFig(int, int) const = 0;
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	

	//virtual void Rotate() = 0;	//Rotate the figure
	//virtual void Resize() = 0;	//Resize the figure
	//virtual void Move() = 0;		//Move the figure


	string NameOfColor(color c)const;// return string of the color 
	color ReturnColor(string c)const;
	double CalcDistance(Point A, Point B) const;
	virtual void Save(ofstream &Outfile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	virtual string GetFname()const=0;


	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif