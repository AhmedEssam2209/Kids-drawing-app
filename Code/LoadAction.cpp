#include "LoadAction.h"
#include <iostream>
#include <string>
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "Circle.h"
#include "Figures\CRectangle.h"
#include "Figures\CFigure.h"
#include "Hexagon.h"
#include "Square.h"
#include "Triangle.h"
LoadAction::LoadAction(ApplicationManager *pApp):Action(pApp)
{
}
void LoadAction::ReadActionParameters() 
{	
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Loading the file...");

}
void LoadAction::Execute()
{
	ReadActionParameters();
	string filePath=openFile();
	ifstream fin(filePath);
	if(!fin.is_open())
	{
		cout<<"Couldn't Open Input File"<<endl;
		fin.close();
		return ;
	}
	string drw,fil;
	pManager->GetOutput()->ClearDrawArea();
	fin>>drw;fin>>fil;
	UI.DrawColor=pManager->GetOutput()->getColor(drw);
	UI.FillColor=pManager->GetOutput()->getColor(fil);
	loadFigures(fin);
	fin.close();
	pManager->GetOutput()->ClearStatusBar();
}
void LoadAction::loadFigures(ifstream &fin)
{
	CFigure *fig=NULL;
	string typeOfShp;
	int noOfshps;
	fin>>noOfshps;
	cout<<noOfshps<<endl;
	for(int i=0;i<noOfshps;i++){
		fin>>typeOfShp;
		cout<<typeOfShp<<endl;
		if(typeOfShp=="RECT"){
			fig = new CRectangle(pManager->GetOutput());
		}
		else if(typeOfShp=="HEXA"){
			fig = new CHexagon(pManager->GetOutput());
		}
		else if(typeOfShp=="TRIG"){
			fig = new CTriangle(pManager->GetOutput());
		}
		else if(typeOfShp=="CIRC"){
			fig = new CCircle(pManager->GetOutput());
		}
		else if(typeOfShp=="SQUR"){
			fig = new CSquare(pManager->GetOutput());
		}
		fig->Load(fin);
		pManager->AddFigure(fig);
	}
}
string LoadAction::openFile()
{
	string filename;
	filename=browseFile();
	return filename;
}
string LoadAction::browseFile()
{
	 char filename[ MAX_PATH ];

  OPENFILENAME ofn;
    ZeroMemory( &filename, sizeof( filename ) );
    ZeroMemory( &ofn,      sizeof( ofn ) );
    ofn.lStructSize  = sizeof( ofn );
    ofn.hwndOwner    = NULL;  // If you have a window to center over, put its HANDLE here
    ofn.lpstrFilter  = "Figure Files\0*.fig\0Any File\0*.*\0";
    ofn.lpstrFile    = filename;
    ofn.nMaxFile     = MAX_PATH;
    ofn.lpstrTitle   = "Select a Figure File";
    ofn.Flags        = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;
  
  GetOpenFileNameA( &ofn );
  cout << "You chose the file \"" << filename << "\"\n";
  return filename;
}
LoadAction::~LoadAction(void)
{
}
