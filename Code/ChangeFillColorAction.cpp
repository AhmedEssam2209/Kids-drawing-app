#include "ChangeFillColorAction.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "ApplicationManager.h"

ChangeFillColorAction::ChangeFillColorAction(ApplicationManager* pApp) :Action(pApp)
{
}
void ChangeFillColorAction::ReadActionParameters()
{
	//Get a Pointer both input and output interfaces
	Output* pout = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pout->PrintMessage("Choose your desired fill colour: ");
	ActionType store;
	store = pIn->GetUserAction();
	switch (store)
	{
	case YYELLOW:
		fillcolor = YELLOW;
		break;
	case BBLACK:
		fillcolor = BLACK;
		break;
	case RRED:
		fillcolor = RED;
		break;
	case GGREEN:
		fillcolor = GREEN;
		break;
	case OORANGE:
		fillcolor = ORANGE;
		break;
	case BBLUE:
		fillcolor = BLUE;
		break;
	default: break;

	}
}
void ChangeFillColorAction::Execute()
{
	ReadActionParameters();
	Output* pout = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure* fig = pManager->getSelectedFig();
	if(fig==NULL)
		{
			pout->PrintMessage("please select a figure first:");
			ReadActionParameters();
			return;
	}
	fig->ChngFillClr(fillcolor);
	fig->SetSelected(false);
	pManager->setSelectedFig(NULL);
}

ChangeFillColorAction::~ChangeFillColorAction(void)
{
}
