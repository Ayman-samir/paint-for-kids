#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point TopLeftCorner;	
	int length;
	Point Center;
public:
	//CSquare();
	CSquare(Point , int, GfxInfo FigureGfxInfo );
	virtual void DrawMe(GUI* pOut) const;
	virtual bool Get(int x, int y) const;
	virtual string ShowFigureDetails() const;
};

#endif