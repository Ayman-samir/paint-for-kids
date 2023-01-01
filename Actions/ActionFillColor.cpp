#include "ActionFillColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "Action.h"
#include "..\Figures\CFigure.h"


ActionFillColor::ActionFillColor(ApplicationManager* pApp) :Action(pApp)
{}


void ActionFillColor::Execute() {
	
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage(" Click at color to fill shape");

	pGUI->CreateColorMenu();

	

	
	COLORSITEM s = pGUI->getcolor();
	if (s != EMPTYY)
	{
		//CFigure *c;
		switch (s)



		{
		case RED1: {
			pGUI->PrintMessage("the fill color set to RED");
			pGUI->isfilled = true;
			pGUI->setFillcolor(RED);
			pManager->fillSelectedFig(RED);


		}

				 break;
		case GREEN2:
		{
			pGUI->PrintMessage("the fill color set to green");
			pGUI->isfilled = true;
			pGUI->setFillcolor(GREEN);
			pManager->fillSelectedFig(GREEN);
		}
		break;
		case YELLOW3:
		{
			pGUI->PrintMessage("the fill color set to YELLOW");
			pGUI->isfilled = true;
			pGUI->setFillcolor(YELLOW);
			pManager->fillSelectedFig(YELLOW);
		}
		break;
		case defaultcolor:
		{
			pGUI->PrintMessage("the fill color set to default");
			pGUI->isfilled = false;
			pManager->fillSelectedFig(UI.BkGrndColor);

		}
		break;
		case BLUE5:
		{
			pGUI->PrintMessage("the fill color set to BLUE");
			pGUI->isfilled = true;
			pGUI->setFillcolor(BLUE);
			pManager->fillSelectedFig(BLUE);
		}
		break;
		case EMPTYY:
			break;
		default:

			break;
		}
		pGUI->ClearColorMenu();
	}
	
	
}


