#pragma once
#ifndef PICK_BY_COLOR_AND_TYPE_H
#define PICK_BY_COLOR_AND_TYPE_H
#include "Actions/Action.h"
#include "Select.h"

//Add Rectangle Action class
class  PickByColorAndType : public Action
{
private:
	Point P; //Rectangle Corners
	CFigure* SelectedFig;
	string Fig;
	int W = 0, L = 0;
public:
	PickByColorAndType(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	void select();
	void Unselect();
	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif