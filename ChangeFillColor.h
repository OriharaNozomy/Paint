#pragma once
#ifndef CHANGE_FILL_COLOR_H
#define CHANGE_FILL_COLOR_H

#include "Actions/Action.h"

#pragma once

class ChangeFillColor : public Action {
	ActionType inputColorAction;
	color FillClr;
	int selectedCount; //number of selected figures
//	CFigure *SelectedFigs[5]; //pointer to selected figures
	//If a figure is selected
	bool IsSelectedFig;
	//If a color was picked in the color toolbar
	bool IsColor;
	//CFigure* t;
public:
	ChangeFillColor(ApplicationManager* pApp);

	//Reads draw color parameters
	virtual void ReadActionParameters();

	//Changes current/selected figure draw color
	virtual void Execute();

};
#endif