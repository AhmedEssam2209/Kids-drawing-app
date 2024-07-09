#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	GfxInfo gfxInfo;
	Output *out;
public:
	CRectangle(Output *outRec);
	CRectangle(Point , Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream &outrect);
	virtual void Load(ifstream &inrect);
	virtual bool IspointInside(int px,int py);
	virtual void Move(Point P, Output* pOut);
	virtual void Delete(Output* Delete);
	virtual string Info();
	~CRectangle();
};

#endif