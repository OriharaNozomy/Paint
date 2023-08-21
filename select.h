#ifndef SELECT_H
#define SELECT_H

#include "Actions/Action.h"
#include"Figures/CFigure.h"
class Select : public Action
{

private:
	Point P;  //Clicked point
	CFigure* SelectedFig; //Clicked figure (NULL if no figure is clicked)
public:
	Select(ApplicationManager* pApp);

	//Reads select parameters
	virtual void ReadActionParameters();

	//Executes the select action
	virtual void Execute();
	void select();
	void Unselect();
};
#endif