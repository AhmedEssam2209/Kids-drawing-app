#pragma once
#include "Figures\CFigure.h"
class CHexagon :public CFigure
{
	Point Corner1;	
	GfxInfo gfxInfo;
	Output *out;
public:
	CHexagon(Output *outHexa);
	CHexagon(Point ,GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream &outHex);
	virtual void Load(ifstream &inHex);
	virtual bool IspointInside(int px,int py);
	virtual void Move(Point P, Output* pOut);
	virtual void Delete(Output* Delete);
	virtual string Info();
	~CHexagon(void);
};

