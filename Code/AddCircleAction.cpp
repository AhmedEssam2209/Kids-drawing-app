#include "AddCircleAction.h"
#include "Circle.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include <windows.h>
#include <mmsystem.h>

AddCircleAction::AddCircleAction(ApplicationManager* pApp) :Action(pApp)
{}
void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	PlaySound(TEXT("audio/CIRC.wav"), NULL, SND_FILENAME | SND_ASYNC);// - the correct code
	pOut->PrintMessage("New Circle: Click at the center");

	//Read 1st pt and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at Circumference");

	//Read 2nd pt and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	CircleGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}
//Execute the action
void AddCircleAction::Execute()
{
	//This action needs to read some parameters first
	if(!pManager->getPlaying())
	ReadActionParameters();

	//Create a Circle with the parameters read from the user
	CCircle* C = new CCircle(P1, P2, CircleGfxInfo);

	//Add the Circle to the list of figures
	pManager->AddFigure(C);
}
void AddCircleAction :: undo( )
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pManager->GetFigure(P1.x,P1.y);
	pManager->DeleteFigure(pManager->GetFigure(P1.x,P1.y));
}
AddCircleAction::~AddCircleAction(void)
{
}
