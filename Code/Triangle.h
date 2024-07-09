#pragma once
#include "Triangle.h"
#include "Figures\CFigure.h"
class CTriangle : public CFigure
{
	Point Corner1;	
	Point Corner2;
	Point Corner3;
	GfxInfo gfxInfo;
	Output *out;
public:
	CTriangle(Output *outTrig);
	CTriangle(Point,Point,Point,GfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream &outtri);
	virtual void Load(ifstream &intri);
	virtual bool IspointInside(int px,int py);
	virtual void Move(Point P, Output* pOut);
	virtual void Delete(Output* Delete);
	virtual string Info();
	~CTriangle(void);
};

