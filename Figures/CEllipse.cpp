#include "CEllipse.h"

CEllipse::CEllipse(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	low = P2;
	Center.x = (P1.x + P2.x) / 2;
	Center.y = (P1.y + P2.y) / 2;
	a = abs(TopLeftCorner.x - Center.x);
	b = abs(TopLeftCorner.y - Center.y);
}
bool CEllipse::Get(int x, int y) const
{
	// (x - h) ^ 2 / a ^ 2 + (y - k) ^ 2 / b ^ 2 <= 1
	// center(h,k)
	// a is radius x-axis
	// b is radius y-axis
	if (pow(x - Center.x, 2) / pow(a, 2) + pow(y - Center.y, 2) / pow(b, 2) <= 1)
	{
		return true;
	}
	return false;
}

string CEllipse::ShowFigureDetails() const {
	return
		"ID=" + to_string(ID) + " "
		"| start point(" + to_string(TopLeftCorner.x) + "," + to_string(TopLeftCorner.y) + ") "
		"| end point(" + to_string(low.x) + "," + to_string(low.y) + ") "
		"| center point(" + to_string(Center.x) + "," + to_string(Center.y) + ") "
		"| radius x-axis=" + to_string(a) + " "
		"| radius y-axis=" + to_string(b) + " "
		"| area=" + to_string(M_PI * a * b);
}


void CEllipse::DrawMe(GUI* pGUI) const
{
	
	pGUI->DrawEllipse(TopLeftCorner, low, FigGfxInfo, Selected);
	


}


