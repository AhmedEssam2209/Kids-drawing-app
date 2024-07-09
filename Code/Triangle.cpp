#include "Triangle.h"

CTriangle::CTriangle(Output *outTrig)
{
	out=outTrig;
}
CTriangle::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	gfxInfo =FigureGfxInfo;
}
void CTriangle::Move(Point P, Output* pOut)
{
	pOut->DelTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
	Point Transition = { P.x - Corner1.x,P.y - Corner1.y };
	Corner1.x = Corner1.x + Transition.x;Corner1.y=Corner1.y + Transition.y;
	Corner2.x = Corner2.x + Transition.x;Corner2.y=Corner2.y + Transition.y;
	Corner3.x = Corner3.x + Transition.x;Corner3.y=Corner3.y + Transition.y;
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}
void CTriangle::Delete(Output* Delete)
{
	Delete->DelTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTri(Corner1, Corner2,Corner3,FigGfxInfo, Selected);
}
bool CTriangle::IspointInside(int px,int py)
{
	int area123=abs(Corner1.x*(Corner2.y-Corner3.y)+Corner2.x*(Corner3.y-Corner1.y)+Corner3.x*(Corner1.y-Corner2.y))/2;
	int area12p=abs(Corner1.x*(Corner2.y-py)+Corner2.x*(py-Corner1.y)+px*(Corner1.y-Corner2.y))/2;
	int area1p3=abs(Corner1.x*(py-Corner3.y)+px*(Corner3.y-Corner1.y)+Corner3.x*(Corner1.y-py))/2;
	int areap23=abs(px*(Corner2.y-Corner3.y)+Corner2.x*(Corner3.y-py)+Corner3.x*(py-Corner2.y))/2;
	int d=area123-area12p-area1p3-areap23; 
	if(abs(d) < 10)
		return 1;
	else 
		return 0;
}
string CTriangle::Info()
{
	return "ID: " + to_string(ID) + "    First corner point: (" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")    Second corner point: ("+ to_string(Corner2.x) + "," + to_string(Corner2.y) + ")    Third corner point: ("+ to_string(Corner3.x) + "," + to_string(Corner3.y) + ")";    
}
void CTriangle::Save(ofstream &fout)
{
	string separetor=" ";
	fout <<"TRIG"
		<<separetor<<ID++
		<<separetor<<Corner1.x<<separetor<<Corner1.y
		<<separetor<<Corner2.x<<separetor<<Corner2.y
		<<separetor<<Corner3.x<<separetor<<Corner3.y
		<<separetor<<out->getColor(gfxInfo.DrawClr)
		<<separetor<<out->getColor(gfxInfo.FillClr)
		<<endl;
}
void CTriangle::Load(ifstream &fin)
{
	string drw,fil;
	fin>>ID;
	fin>>Corner1.x;fin>>Corner1.y;
	fin>>Corner2.x;fin>>Corner2.y;
	fin>>Corner3.x;fin>>Corner3.y;
	fin>>drw;fin>>fil;
	ChngDrawClr(out->getColor(drw));
	ChngFillClr(out->getColor(fil));
	out->DrawTri(Corner1,Corner2,Corner3,FigGfxInfo,Selected);
}
CTriangle::~CTriangle(void)
{
}
