#pragma once
#include"Actions/Action.h"
class PlayWithType : public Action 
{
private:
Point P;
int Correct;
int Wrong;
string Fig;
public :
	PlayWithType(ApplicationManager* pApp);

	void ReadActionParameters();

	//Reads Figure parameters

	//pick and hide the figure
	virtual void Execute();





};

