
#ifndef ADD_TRIANGLE_H
#define ADD_TRIANGLE_H

#include "Actions/Action.h"

//Add Rectangle Action class
class AddTriangle : public Action
{
private:
	Point P1, P2, P3;//Rectangle Corners
	GfxInfo TGfxInfo;
public:
	AddTriangle(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif

