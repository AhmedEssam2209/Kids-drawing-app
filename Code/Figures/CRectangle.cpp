#include "CRectangle.h"
CRectangle::CRectangle(Output *outrec)
{
	out=outrec;
}
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	gfxInfo =FigureGfxInfo;
}
void CRectangle::Move(Point P, Output* pOut)
{
	pOut->DelRect(Corner1, Corner2, FigGfxInfo, Selected);
	Point Transition = { P.x - Corner1.x,P.y - Corner1.y };
	Corner1.x = Corner1.x + Transition.x;Corner1.y=Corner1.y + Transition.y;
	Corner2.x = Corner2.x + Transition.x;Corner2.y=Corner2.y + Transition.y;
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}	
void CRectangle::Delete(Output* Delete)
{
	Delete->DelRect(Corner1, Corner2, FigGfxInfo, Selected);
}
void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::IspointInside(int px,int py)
{
	if ( (  (  px >= Corner1.x && px <=Corner2.x  )  ||   ( px >= Corner2.x && px<=Corner1.x  )   )    &&  (  (  py >= Corner1.y && py <=Corner2.y  )  ||   ( (py >= Corner2.y && py <=Corner1.y  )   )  )  )
		return 1;
	else
		return 0;
}

string CRectangle::Info()
{
	int width= abs(Corner1.x-Corner2.x);
	int height= abs(Corner1.y-Corner2.y);
	return "ID: " + to_string(ID) + "   Start point: (" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")    End point: ("+ to_string(Corner2.x) + "," + to_string(Corner2.y) + ")    Width: " + to_string(width) + "     Height : " + to_string(height) ;									
}
void CRectangle::Save(ofstream &fout)
{
	string separetor=" ";
	fout <<"RECT"
		<<separetor<<ID++
		<<separetor<<Corner1.x<<separetor<<Corner1.y
		<<separetor<<Corner2.x<<separetor<<Corner2.y
		<<separetor<<out->getColor(gfxInfo.DrawClr)
		<<separetor<<out->getColor(gfxInfo.FillClr)
		<<endl;
	
}

void CRectangle::Load(ifstream &fin)
{
	string drw,fil;
	fin>>ID;
	fin>>Corner1.x;fin>>Corner1.y;
	fin>>Corner2.x;fin>>Corner2.y;
	fin>>drw;fin>>fil;
	ChngDrawClr(out->getColor(drw));
	ChngFillClr(out->getColor(fil));
	out->DrawRect(Corner1,Corner2,FigGfxInfo,Selected);
}
CRectangle::~CRectangle()
{
}