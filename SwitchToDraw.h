#pragma once
#ifndef SWITCH_TO_DRAW_H
#define SWITCH_TO_DRAW_H

#include "Actions/Action.h"


class  SwitchToDraw : public Action
{
public:
	SwitchToDraw(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};

#endif