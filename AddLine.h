#pragma once
#ifndef ADD_LINE_H
#define ADD_LINE_H

#include "Actions/Action.h"
#include "Cline.h"

//Add Rectangle Action class
class AddLine : public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo LineGfxInfo;
public:
	AddLine(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif
