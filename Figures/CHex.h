#pragma once
#include "CFigure.h"

class CHex :public CFigure
{
	Point TopLeft;
	int Llen;
	int Rlen;
	int length;
	Point Center;
	static int hexCount;

public:

	CHex(Point,int,int, GfxInfo GfxInfo);

	virtual void DrawMe(GUI* pOut) const;
	virtual string ShowFigureDetails() const;
	virtual bool Get(int x, int y) const;
};

