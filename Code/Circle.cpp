#include "Circle.h"

CCircle::CCircle(Output *outCirc)
{
	out=outCirc;
			 
}
CCircle::CCircle(Point c, Point r, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center=c;
	Radius=r;
	gfxInfo=FigureGfxInfo;
}
void CCircle::Move(Point P, Output* pOut)
{
	pOut->DelCir(Center, Radius, FigGfxInfo, Selected);
	Point Transition = { P.x - Center.x,P.y - Center.y };
	Center.x = Center.x + Transition.x;Center.y=Center.y + Transition.y;
	Radius.x = Radius.x + Transition.x;Radius.y=Radius.y + Transition.y;
	pOut->DrawCir(Center, Radius, FigGfxInfo, Selected);

}
void CCircle::Delete(Output* Delete)
{
Delete->DelCir(Center, Radius, FigGfxInfo, Selected);
}
void CCircle::Draw(Output* pOut) const
{
	pOut->DrawCir(Center, Radius, FigGfxInfo, Selected);
}
bool CCircle::IspointInside(int px,int py)
{
	return sqrt((Center.x - px)*(Center.x - px) + (Center.y - py)*(Center.y - py)) <= sqrt((Center.x - Radius.x)*(Center.x - Radius.x) + (Center.y - Radius.y)*(Center.y - Radius.y));
}
string CCircle::Info()
{
	return "ID: " + to_string(ID) + "   Centre point: (" + to_string(Center.x) + "," + to_string(Center.y) + ")     Radius: " + to_string(sqrt((Center.x - Radius.x)*(Center.x - Radius.x) + (Center.y - Radius.y)*(Center.y - Radius.y))) ;
}
void CCircle::Save(ofstream &fout)
{
	string separetor=" ";
	fout <<"CIRC"
		<<separetor<<ID++
		<<separetor<<Center.x<<separetor<<Center.y
		<<separetor<<Radius.x<<separetor<<Radius.y
		<<separetor<<out->getColor(out->getCrntDrawColor())
		<<separetor<<out->getColor(out->getCrntFillColor())
		<<endl;
	
}
void CCircle::Load(ifstream &fin)
{
	string drw,fil;
	fin>>ID;
	fin>>Center.x;fin>>Center.y;
	fin>>Radius.x;fin>>Radius.y;
	fin>>drw;fin>>fil;
	ChngDrawClr(out->getColor(drw));
	ChngFillClr(out->getColor(fil));
	out->DrawCir(Center,Radius,FigGfxInfo,Selected);
}
CCircle::~CCircle(void)
{
}
