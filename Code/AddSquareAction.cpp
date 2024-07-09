#include "AddSquareAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "Square.h"
#include <windows.h>
#include <mmsystem.h>

AddSquareAction::AddSquareAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddSquareAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at center");
	PlaySound(TEXT("audio/SQUR.wav"), NULL, SND_FILENAME | SND_ASYNC);// - the correct code
	//Read the midpoint and store in point P1
	pIn->GetPointClicked(P.x, P.y);

	SquareGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquareGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddSquareAction::Execute()
{
	//This action needs to read some parameters first
	if(!pManager->getPlaying())
	
	ReadActionParameters();

	//Create a Square with the parameters read from the user
	CSquare* S = new CSquare(P, SquareGfxInfo);

	//Add the Square to the list of figures
	pManager->AddFigure(S);
}
void AddSquareAction :: undo(void)
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pManager->GetFigure(P.x,P.y);
	pManager->DeleteFigure(pManager->GetFigure(P.x,P.y));
}
AddSquareAction::~AddSquareAction(void)
{
}
