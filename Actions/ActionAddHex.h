#pragma once

#include "Action.h"
#include "..\ApplicationManager.h"

class ActionAddHex :public Action
{
public:
	 ActionAddHex(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();
};

