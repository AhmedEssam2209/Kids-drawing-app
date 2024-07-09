#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void setMode(GUI_MODE MODE);
	string getColor(color c);
	color getColor(string c);

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	window* getpWind();
	
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	void DrawTri(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo, bool selected) const;
	void DrawCir(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected) const;
	void DrawSqr(Point P1, GfxInfo SqrGfxInfo, bool selected) const;
	void DrawHex(Point P1, GfxInfo HexGfxInfo, bool selected) const;
	///Make similar functions for drawing all other figure types.
	void DelRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle
	void DelTri(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo, bool selected) const;
	void DelCir(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected) const;
	void DelSqr(Point P1, GfxInfo SqrGfxInfo, bool selected) const;
	void DelHex(Point P1, GfxInfo HexGfxInfo, bool selected) const;
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color Output::getCrntHighlightColor() const;
	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	
	~Output();
};

#endif