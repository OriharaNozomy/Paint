#pragma once
#include <fstream>
#include "Actions/Action.h"
#include"CMUgraphicsLib/colors.h"


//Add Rectangle Action class
class  Save : public Action
{
private:
	ofstream Outfile;
	string Name;
	
	
public:
	Save(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

