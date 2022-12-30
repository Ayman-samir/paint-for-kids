#pragma once
#include "Action.h"

class ActionFillColor :public Action
{
public:
	ActionFillColor(ApplicationManager* pApp);

	virtual void Execute();

};

