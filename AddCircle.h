#pragma once
#ifndef ADD_CIRCLE_H
#define ADD_CIRCLE_H

#include "Actions/Action.h"
#include "CCircle.h"

class AddCircle : public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo CircGfxInfo;
public:
	AddCircle(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif

