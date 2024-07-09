#include "AddHexAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "Hexagon.h"
#include <windows.h>
#include <mmsystem.h>
AddHexAction::AddHexAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddHexAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	PlaySound(TEXT("audio/HEXA.wav"), NULL, SND_FILENAME | SND_ASYNC);// - the correct code
	pOut->PrintMessage("New Hexagon: Click at the center");

	//Read the midpoint and store in point P
	pIn->GetPointClicked(P.x, P.y);


	HexGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexAction::Execute()
{
	//This action needs to read some parameters first
	if(!pManager->getPlaying())	
	ReadActionParameters();

	//Create a Hexagon with the parameters read from the user
	CHexagon* H = new CHexagon(P, HexGfxInfo);

	//Add the Hexagon to the list of figures
	pManager->AddFigure(H);
}
void AddHexAction :: undo()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pManager->GetFigure(P.x,P.y);
	pManager->DeleteFigure(pManager->GetFigure(P.x,P.y));
}
AddHexAction::~AddHexAction(void)
{
}
