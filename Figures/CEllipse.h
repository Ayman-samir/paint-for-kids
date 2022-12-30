#pragma once
#define _USE_MATH_DEFINES
#include "CFigure.h"
#include <math.h>

class CEllipse : public CFigure
{
private:
	Point TopLeftCorner;
	Point low;
	Point Center;
	int a;
	int b;
public:
	//CEllipse();
	CEllipse(Point, Point, GfxInfo FigureGfxInfo);
	virtual bool Get(int x, int y) const;
	virtual string ShowFigureDetails() const;
	virtual void DrawMe(GUI* pOut) const;
	
};


