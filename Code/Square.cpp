#include "Square.h"

CSquare::CSquare(Output *outSqur)
{
	out=outSqur;
}
CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1=P1;
	gfxInfo=FigureGfxInfo;
}
void CSquare::Move(Point P, Output* pOut)
{
	pOut->DelSqr(Corner1, FigGfxInfo, Selected);
	Point Transition = { P.x - Corner1.x,P.y - Corner1.y };
	Corner1.x = Corner1.x + Transition.x;Corner1.y=Corner1.y + Transition.y;
	pOut->DrawSqr(Corner1, FigGfxInfo, Selected);
}
void CSquare::Delete(Output* Delete)

{
	Delete->DelSqr(Corner1, FigGfxInfo, Selected);
		
}
void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawSqr(Corner1,FigGfxInfo,Selected);
}
bool CSquare::IspointInside(int px,int py)
{
	int sl=100;
	if ( (  (  px >= Corner1.x+sl/2 && px <=Corner1.x-sl/2  )  ||   (px >= Corner1.x-sl/2 && px <=Corner1.x+sl/2  )   )    &&  (  (  py >= Corner1.y+sl/2 && py <=Corner1.y-sl/2  )  ||   ( (  py >= Corner1.y-sl/2 && py <=Corner1.y+sl/2  )   )  )  )
		return 1;
	else
		return 0;
}
string CSquare::Info()
{
	int sideLength =100;
	return "ID: " + to_string(ID) + "   Center point: (" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")     Side length: " + to_string(sideLength) ;
}
void CSquare::Save(ofstream &fout)
{
	string separetor=" ";
	fout <<"SQUR"
		<<separetor<<ID++
		<<separetor<<Corner1.x<<separetor<<Corner1.y
		<<separetor<<out->getColor(gfxInfo.DrawClr)
		<<separetor<<out->getColor(gfxInfo.FillClr)
		<<endl;
}
void CSquare::Load(ifstream &fin)
{
	string drw,fil;
	fin>>ID;
	fin>>Corner1.x;fin>>Corner1.y;
	fin>>drw;fin>>fil;
	ChngDrawClr(out->getColor(drw));
	ChngFillClr(out->getColor(fil));
	out->DrawSqr(Corner1,FigGfxInfo,Selected);
}
CSquare::~CSquare(void)
{
}
