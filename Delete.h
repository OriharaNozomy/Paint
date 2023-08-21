#pragma once
#ifndef DELETE_H
#define DELETE_H

#include "Actions/Action.h"

//Add Rectangle Action class
class  Delete : public Action
{
public:
	Delete(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif

