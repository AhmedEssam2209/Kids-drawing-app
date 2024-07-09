#pragma once
#include "Figures\CFigure.h"
class CSquare :public CFigure
{
	Point Corner1;	
	GfxInfo gfxInfo;
	Output *out;
public:
	CSquare(Output *outSqur);
	CSquare(Point ,GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream &outSqr);
	virtual void Load(ifstream &inSqr);
	virtual bool IspointInside(int px,int py);
	virtual void Move(Point P, Output* pOut);
	virtual void Delete(Output* Delete);
	virtual string Info();
	~CSquare(void);
};

