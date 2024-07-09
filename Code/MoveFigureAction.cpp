#include "MoveFigureAction.h"
#include "DeleteAction.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

MoveFigureAction::MoveFigureAction(ApplicationManager* pApp) : Action(pApp){}

void MoveFigureAction::ReadActionParameters(){}

void MoveFigureAction::Execute()
{
	CFigure* Selected = pManager->getSelectedFig();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (!Selected)
	{
		pOut->PrintMessage("No Figure Selected");
		return;
	}
	//

	//Delete old Selected here

	//
	pOut->PrintMessage("Click New Position");
	pIn->GetPointClicked(P.x, P.y);
	Selected->Move(P, pOut);
	pManager->AddFigure(Selected);
	pManager->getSelectedFig()->SetSelected(false);
	pOut->PrintMessage(" ");

	return;


}
MoveFigureAction::~MoveFigureAction(void)
{
}
