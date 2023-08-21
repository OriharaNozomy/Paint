#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	
	DRAW_RECT,		//Draw Rectangle
	DRAW_CIRC,		//Draw Circle
	DRAW_TRI,		//Draw Triangle
	DRAW_LINE,		//Draw Line
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	DEL,			//Delete a figure(s)
	SWITCH_TO_PLAY,		//Bring a figure to the front of all figures
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application
	SELECT,
	COPY,
	PASTE,
	CUT,
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY	,		//Switch interface to Play mode
	SELECT_BY_TYPE,
	SELECT_BY_COLOR,
	SELECT_BY_TYPE_AND_COLOR,
	SWITCH_TO_DRAW


	///TODO: Add more action types (if needed)
};

struct Point	//To be used for figures points
{ int x,y,z; };
struct Point1	//To be used for figures points
{
	int x, y,z;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

enum fig
{
	Rect,
	Line,
	Tri,
	Circ

};

enum chosencolor
{
	SET_BLACK,
	SET_RED,
	SET_GREEN,
	SET_BLUE
};


#endif