#include "CFigure.h"

CFigure::CFigure() {}

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

void CFigure::ChngSelectClr(color Dclr) {

	FigGfxInfo.PreviousClr = Dclr;
}
color CFigure::ChngSelectClr() {
	return FigGfxInfo.PreviousClr;
}

color CFigure::GetCurrentDrawClr() {
	return FigGfxInfo.DrawClr;
}