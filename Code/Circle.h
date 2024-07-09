#pragma once
#include "Figures\CFigure.h"

class CCircle : public CFigure
{
	Point Center;	
	Point Radius;
	GfxInfo gfxInfo;
	Output *out;
public:
	CCircle(Output *outCirc);
	CCircle(Point , Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream &outrect);
	virtual void Load(ifstream &inCirc);
	virtual bool IspointInside(int px,int py);
	virtual void Move(Point P, Output* pOut);
	virtual void Delete(Output* Delete);
	virtual string Info();
	~CCircle(void);
};

