#pragma once
#ifndef PICK_BY_COLOR_H
#define PICK_BY_COLOR_H
#include "Actions/Action.h"
#include "Select.h"

//Add Rectangle Action class
class  PickByColor : public Action
{
private:
	Point P1, P2; //Rectangle Corners
	CFigure* SelectedFig;
	int L=0, W=0;
public:
	PickByColor(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	void select();
	void Unselect();
	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif