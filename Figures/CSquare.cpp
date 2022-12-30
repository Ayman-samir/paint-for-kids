#include "CSquare.h"

CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
	Center.x = (P1.x + (P1.x + length)) / 2;
	Center.y = (P1.y + (P1.y + length)) / 2;
	
}
	

void CSquare::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
	

}

bool CSquare::Get(int x, int y) const
{
	if (x >= TopLeftCorner.x && x <= TopLeftCorner.x + length &&
		y >= TopLeftCorner.y && TopLeftCorner.y + length)
		return true;
	return false;
}
string CSquare::ShowFigureDetails() const {
	return
		"ID=" + to_string(ID) + " "
		"| start point(" + to_string(TopLeftCorner.x) + "," + to_string(TopLeftCorner.y) + ") "
		"| end point(" + to_string(TopLeftCorner.x + length) + "," + to_string(TopLeftCorner.y + length) + ") "
		"| center point(" + to_string(Center.x) + "," + to_string(Center.y) + ") "
		"| length=" + to_string(length) +
		"| area=" + to_string(pow(length, 2));
}