#include "Hexagon.h"

CHexagon::CHexagon(Output *outHexa)
{
	out=outHexa;
}
CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1=P1;
	gfxInfo=FigureGfxInfo;
}
void CHexagon::Move(Point P, Output* pOut)
{
	pOut->DelHex(Corner1, FigGfxInfo, Selected);
	Point Transition = { P.x - Corner1.x,P.y - Corner1.y };
	Corner1.x = Corner1.x + Transition.x;Corner1.y=Corner1.y + Transition.y;
	pOut->DrawHex(Corner1, FigGfxInfo, Selected);
}
void CHexagon::Delete(Output* Delete)
{
	Delete->DelHex(Corner1, FigGfxInfo, Selected);
}
void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawHex(Corner1,FigGfxInfo,Selected);
}
bool CHexagon::IspointInside(int px,int py)
{

	int Px[6];
	int Py[6];
	Px[0] = Corner1.x-25;
	Py[0] = Corner1.y-25;
	Px[1] = Px[0] + 50;
	Py[1] = Py[0];
	Px[2] = Px[1] + 25 * sqrt(2);
	Py[2] = Py[1] + 25 * sqrt(2);
	Px[3] = Px[2] - 25 * sqrt(2);
	Py[3] = Py[2] + 25 * sqrt(2);
	Px[4] = Px[3] - 50;
	Py[4] = Py[3];
	Px[5] = Px[4] - 25 * sqrt(2);
	Py[5] = Py[4] - 25 * sqrt(2);
	bool isInTriInHex;

	if(px>Px[1])
	{
	int area1=abs(Px[0]*(Px[4]-Px[5])+Px[4]*(Px[5]-Py[0])+Px[5]*(Py[0]-Px[4]))/2;
	int area2=abs(Px[0]*(Px[4]-py)+Px[4]*(py-Py[0])+px*(Py[0]-Px[4]))/2;
	int area3=abs(Px[0]*(py-Px[5])+px*(Px[5]-Py[0])+Px[5]*(Py[0]-py))/2;
	int areap=abs(px*(Px[4]-Px[5])+Px[4]*(Px[5]-py)+Px[5]*(py-Px[4]))/2;
	int d1=area1-area2-area3-areap; 
	isInTriInHex = (abs(d1) <10);
	}
	else
	{
	int area123=abs(Px[1]*(Px[3]-Px[2])+Px[3]*(Px[2]-Py[1])+Px[2]*(Py[1]-Px[3]))/2;
	int area12p=abs(Px[1]*(Px[3]-py)+Px[3]*(py-Py[1])+px*(Py[1]-Px[3]))/2;
	int area1p3=abs(Px[1]*(py-Px[2])+px*(Px[2]-Py[1])+Px[2]*(Py[1]-py))/2;
	int areap23=abs(px*(Px[3]-Px[2])+Px[3]*(Px[2]-py)+Px[2]*(py-Px[3]))/2;
	int d2=area123-area12p-area1p3-areap23; 
	isInTriInHex = (abs(d2) <10);

	}
	bool isInsquareOFHex= (((  px >= Corner1.x+25 && px <=Corner1.x-25  )  ||   (px >= Corner1.x-25 && px <=Corner1.x+25  )   )    &&  (  (  py >= Corner1.y+25 && py <=Corner1.y-25  )  ||   ( (  py >= Corner1.y-25 && py <=Corner1.y+25  )   )    )) ;

	return (isInTriInHex || isInTriInHex || isInsquareOFHex);
}
string CHexagon::Info()
{
return "ID: " + to_string(ID) + "   Center point: (" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")";
}
void CHexagon::Save(ofstream &fout)
{
	string separetor=" ";
	fout <<"HEXA"
		<<separetor<<ID++
		<<separetor<<Corner1.x<<separetor<<Corner1.y
		<<separetor<<out->getColor(gfxInfo.DrawClr)
		<<separetor<<out->getColor(gfxInfo.FillClr)
		<<endl;
}
void CHexagon::Load(ifstream &fin)
{
	string drw,fil;
	fin>>ID;
	fin>>Corner1.x;fin>>Corner1.y;
	fin>>drw;fin>>fil;
	ChngDrawClr(out->getColor(drw));
	ChngFillClr(out->getColor(fil));
	out->DrawHex(Corner1,FigGfxInfo,Selected);
}
CHexagon::~CHexagon(void)
{
}
