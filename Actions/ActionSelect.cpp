#include "ActionSelect.h"
#include "..\ApplicationManager.h"
#include <string>
#include <string>
#include <iostream>

int ActionSelect::selectedEllipses = 0;
int ActionSelect::selectedHexagons = 0;
int ActionSelect::selectedSquares = 0;


ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp) ///constructor chaining
{

}
void ActionSelect::Execute()
{
	int* selectedFigCount = pManager->getSelectedFigCount();
	if (UI.InterfaceMode == MODE_DRAW ) {
		int cx;
		int cy;

		GUI* pGUI = pManager->GetGUI();

		pGUI->GetPointClicked(cx, cy);

		CFigure* fig = pManager->GetFigure(cx, cy);




		if (fig != NULL) {

			if (fig->IsSelected()) {
				fig->ChngDrawClr(fig->ChngSelectClr());
				fig->SetSelected(false);
				*selectedFigCount = *selectedFigCount - 1;
				pGUI->ClearStatusBar();
			}
			else {
				fig->ChngSelectClr(fig->GetCurrentDrawClr());
				fig->ChngDrawClr(CADETBLUE);
				fig->SetSelected(true);
				*selectedFigCount = *selectedFigCount + 1;
				pGUI->PrintMessage(fig->ShowFigureDetails());


			}
		}
		else {

			CFigure* selectedFiguer = pManager->GetSelectedFigure();
			if (selectedFiguer != NULL) {
				selectedFiguer->ChngDrawClr(selectedFiguer->ChngSelectClr());
				selectedFiguer->SetSelected(false);
				pGUI->ClearStatusBar();
			}
		}
	}
	

}