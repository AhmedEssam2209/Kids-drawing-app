#include "AddTriangleAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "Triangle.h"
#include <windows.h>
#include <mmsystem.h>
AddTriangleAction::AddTriangleAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddTriangleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");
	PlaySound(TEXT("audio/TRIG.wav"), NULL, SND_FILENAME | SND_ASYNC);// - the correct code
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at Third corner");

	//Read 3rd corner and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);

	TriangleGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriangleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriangleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriangleAction::Execute()
{
	//This action needs to read some parameters first
	if(!pManager->getPlaying())
	
	ReadActionParameters();

	//Create a Triangle with the parameters read from the user
	CTriangle* T = new CTriangle(P1, P2, P3, TriangleGfxInfo);

	//Add the Triangle to the list of figures
	pManager->AddFigure(T);
}
void AddTriangleAction :: undo()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pManager->GetFigure(P1.x,P1.y);
	pManager->DeleteFigure(pManager->GetFigure(P1.x,P1.y));
}
AddTriangleAction::~AddTriangleAction(void)
{
}
