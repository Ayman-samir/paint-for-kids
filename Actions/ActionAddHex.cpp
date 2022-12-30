#include "ActionAddHex.h"
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CHex.h"
ActionAddHex::ActionAddHex(ApplicationManager* pApp) :Action(pApp)
{}

void ActionAddHex::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();




	GfxInfo ElipGfxInfo;

	
	if (pGUI->isfilled)
	
		ElipGfxInfo.isFilled = true;
	else
		ElipGfxInfo.isFilled = false;


		//default is not filled
	//get drawing, filling colors and pen width from the interface
	ElipGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	ElipGfxInfo.FillClr = pGUI->getCrntFillColor();
	ElipGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	

	pGUI->PrintMessage("New Hexagon: Click at first point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Hexagon: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);


	pGUI->ClearStatusBar();


	if (P1.y < UI.ToolBarHeight || P2.y < UI.ToolBarHeight || P1.y>(UI.height - UI.StatusBarHeight) || P2.y>(UI.height - UI.StatusBarHeight))
	{
		pGUI->PrintMessage("draw inside drawing area");
	}
	else
	{
		//Step 2 - prepare Hex Data
		//User has entered two points P1&P2
		//2.1- Identify the Top left corner of the Hex
		Point TopLeft;
		TopLeft.x = P1.x < P2.x ? P1.x : P2.x;
		TopLeft.y = P1.y < P2.y ? P1.y : P2.y;

		//2.2- Calcuate Hex side legnth
		int Llen = abs(TopLeft.x - P2.x);

		//2.3- Calculate Hex R lengh:
		int R = sqrt(pow(Llen, 2) - pow((0.5 * Llen), 2));


		//Step 3 - Create a Hex with the parameters read from the user
		CHex* H = new CHex(TopLeft, Llen, R, ElipGfxInfo);


		//Step 4 - Add the hex to the list of figures
		pManager->AddFigure(H);



	}
}


