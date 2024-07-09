#include "Output.h"
#include <iostream>

Output::Output(){}
void Output::setMode(GUI_MODE MODE)
{
	UI.InterfaceMode = MODE;
	cout<<MODE;
	UI.width = 1650;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 52;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	if(MODE==MODE_DRAW)
		CreateDrawToolBar();
	else
		CreatePlayToolBar();
	CreateStatusBar();
}

Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	cout<<"Draw mode\n";
	for(int i=0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage("images\\MenuItems\\white.jpg", i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\cursor.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\black.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\yellow.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\orange.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\blue.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Rectangle.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\Square.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\Circle.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\Hexagon.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Triangle.jpg";
	MenuItemImages[ITM_CHANGFILL] = "images\\MenuItems\\fill.jpg";
	MenuItemImages[ITM_CHANGBORD] = "images\\MenuItems\\bord.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\delete.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\move.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\redo.jpg";
	MenuItemImages[ITM_CLEAR] = "images\\MenuItems\\clear.jpg";
	MenuItemImages[ITM_STARTREC] = "images\\MenuItems\\rec.jpg";
	MenuItemImages[ITM_STOPREC] = "images\\MenuItems\\stop.jpg";
	MenuItemImages[ITM_PLAYREC] = "images\\MenuItems\\play.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\MenuItems\\switch.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Exit.jpg";
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	cout<<"Play mode\n";
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage("images\\MenuItems\\white.jpg", i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	UI.InterfaceMode = MODE_PLAY;
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[PITM_SWITCH] = "images\\MenuItems\\switch.jpg";
	MenuItemImages[PITM_EXIT] = "images\\MenuItems\\Exit.jpg";
	MenuItemImages[PITM_FIGURETYPE] = "images\\MenuItems\\FigureT.jpg";
	MenuItemImages[PITM_FIGURETYPECOL] = "images\\MenuItems\\FigureTC.jpg";
	MenuItemImages[PITM_FIGURECOLOR] = "images\\MenuItems\\fill.jpg";

	for(int i=0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntHighlightColor() const	//get highlight drawing color
{	return UI.HighlightColor;	}

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
string Output::getColor(color c)
{
	if(c==BLACK) return "BLACK";
	if(c==YELLOW) return "YELLOW";
	if(c==ORANGE) return "ORANGE";
	if(c==RED) return "RED";
	if(c==GREEN) return "GREEN";
	if(c==BLUE) return "BLUE";
}
color Output::getColor(string c)
{
	if(c=="BLACK") return BLACK;
	if(c=="YELLOW") return YELLOW;
	if(c=="ORANGE") return ORANGE;
	if(c=="RED") return RED;
	if(c=="GREEN") return GREEN;
	if(c=="BLUE") return BLUE;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);


}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawHex(Point P1, GfxInfo HexGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int Px[6];
	int Py[6];
	Px[0] = P1.x-25;
	Py[0] = P1.y-25;
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

	pWind->DrawPolygon(Px, Py, 6, style);


}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawSqr(Point P1, GfxInfo SqrGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = SqrGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (SqrGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SqrGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int sl = 100;

	pWind->DrawRectangle(P1.x-sl/2, P1.y-sl/2, P1.x+sl/2, P1.y+sl/2, style);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawTri(Point P1, Point P2, Point P3 , GfxInfo TriangleGfxInfo, bool selected = false) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriangleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriangleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriangleGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawCir(Point P1,Point P2, GfxInfo CircGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;

	const int Radius = sqrt((P1.x - P2.x)*(P1.x - P2.x) + (P1.y - P2.y)*(P1.y - P2.y));

	pWind->DrawCircle(P1.x, P1.y,Radius, style);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::DelCir(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected) const
{
	
	color DrawingClr;

	DrawingClr = UI.BkGrndColor; //Figure should be drawn highlighted


	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(UI.BkGrndColor);
	}
	else
		style = FRAME;

	const int Radius = sqrt((P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y));

	pWind->DrawCircle(P1.x, P1.y, Radius, style);


}
window* Output::getpWind()
{
	return pWind;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DelRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;

	DrawingClr = UI.BkGrndColor; //Figure should be drawn highlighted


	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(UI.BkGrndColor);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);


}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DelHex(Point P1, GfxInfo HexGfxInfo, bool selected) const
{
	color DrawingClr;

	DrawingClr = UI.BkGrndColor; //Figure should be drawn highlighted


	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(UI.BkGrndColor);
	}
	else
		style = FRAME;

	int Px[6];
	int Py[6];
	Px[0] = P1.x - 25;
	Py[0] = P1.y - 25;
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

	pWind->DrawPolygon(Px, Py, 6, style);


}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DelSqr(Point P1, GfxInfo SqrGfxInfo, bool selected) const
{
	color DrawingClr;

	DrawingClr = UI.BkGrndColor; //Figure should be drawn highlighted


	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (SqrGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(UI.BkGrndColor);
	}
	else
		style = FRAME;
	int sl = 100;

	pWind->DrawRectangle(P1.x - sl / 2, P1.y - sl / 2, P1.x + sl / 2, P1.y + sl / 2, style);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DelTri(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo, bool selected = false) const
{
	color DrawingClr;

	DrawingClr = UI.BkGrndColor; //Figure should be drawn highlighted


	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriangleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(UI.BkGrndColor);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

