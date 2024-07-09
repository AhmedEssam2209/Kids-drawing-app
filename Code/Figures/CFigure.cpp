#include "CFigure.h"

CFigure::CFigure(){}
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }
GfxInfo CFigure::getFigGfxInfo()
{
	return FigGfxInfo;
}
bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	
	FigGfxInfo.DrawClr = Dclr;
	UI.DrawColor=Dclr;
}

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
	UI.FillColor=Fclr;
}
void CFigure::setID(int id)
{
	ID=id;
}
void CFigure::Save(ofstream &out)
{
	out<<ID<<endl;
}
CFigure::~CFigure()
{
}