#pragma once

#include "Actions/Action.h"
#include <fstream>

//Add Rectangle Action class
class  Load : public Action
{
private:
	string Name;
	ifstream Infile;
public:
	Load(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};


