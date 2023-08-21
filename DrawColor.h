#pragma once
#ifndef DRAW_COLOR_H
#define DRAW_COLOR_H

#include "Actions/Action.h"

//Add Rectangle Action class
class DrawColor : public Action
{
private:
	ActionType inputColorAction;
	color FillClr;
	int selectedCount;
	//CFigure* const* SelectedFigs; 
	bool IsSelectedFig;
	bool IsColor;
public:
	DrawColor(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif