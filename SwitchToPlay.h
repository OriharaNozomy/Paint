#pragma once
#ifndef SWITCH_TO_PLAY_H
#define SWITCH_TO_PLAY_H

#include "Actions/Action.h"


class  SwitchToPlay : public Action
{
public:
	SwitchToPlay(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};

#endif