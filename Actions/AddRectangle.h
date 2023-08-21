#ifndef ADD_RECTANGLE_H
#define ADD_RECTANGLE_H

#include "Action.h"

//Add Rectangle Action class
class AddRectangle : public Action
{
private:
	Point P1, P2; //Rectangle Corners
	//Point tempP1, tempP2;
	GfxInfo RectGfxInfo;
public:
	AddRectangle(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute() ;
	
};

#endif