#pragma once
#include "Action.h"

//Add Select Action class
class ActionSelect : public Action
{
public:
	static int selectedSquares;
	static int selectedEllipses;
	static int selectedHexagons;
	ActionSelect(ApplicationManager* pApp);

	//Add Select to the ApplicationManager
	virtual void Execute();
};

