#include "ChangeBorderColorAction.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "ApplicationManager.h"

ChangeBorderColorAction::ChangeBorderColorAction(ApplicationManager* pApp) :Action(pApp)
{
}
void ChangeBorderColorAction::ReadActionParameters()
{
	//Get a Pointer both input and output interfaces
	Output* pout = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pout->PrintMessage("Choose your desired border colour: ");
	ActionType store;
	store = pIn->GetUserAction();
	switch (store)
	{
	case YYELLOW:
		brdrcolor = YELLOW;
		break;
	case BBLACK:
		brdrcolor = BLACK;
		break;
	case RRED:
		brdrcolor = RED;
		break;
	case GGREEN:
		brdrcolor = GREEN;
		break;
	case OORANGE:
		brdrcolor = ORANGE;
		break;
	case BBLUE:
		brdrcolor = BLUE;
		break;
	default: break;

	}
}
void ChangeBorderColorAction::Execute()
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
	fig->ChngDrawClr(brdrcolor);
	fig->SetSelected(false);
	pManager->setSelectedFig(NULL);
}

ChangeBorderColorAction::~ChangeBorderColorAction(void)
{
}
