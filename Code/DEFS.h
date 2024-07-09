#ifndef DEFS_H
#define DEFS_H
#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	SELECT,
	BBLACK,
	YYELLOW,
	OORANGE,
	RRED,
	GGREEN,
	BBLUE,
	DRAW_RECT,		//Draw Rectangle
	DRAW_SQUARE,
	DRAW_CIRCLE,
	DRAW_HEX,
	DRAW_TRIANGLE,
	CHANGE_FILL,
	CHANGE_BORD,
	DELETE_SHAPE,
	MOVE,
	UNDO,
	REDO,
	CLEAR,
	START_REC,
	STOP_REC,
	PLAY_REC,
	SAVE,
	LOAD,
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	EXIT,
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS	,		//A click on the status bar
	FIGURE_T,
	FIGURE_TC,
	FIGURE_C


	///TODO: Add the other action types of the two moher action types of the two modes
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	string drwClrs;
	color FillClr;	//Fill color of the figure
	string fillClrs;
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders
};

#endif