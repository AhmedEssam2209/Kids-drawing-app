#include "SelectAction.h"
#include "ApplicationManager.h"
#include "GUI/input.h"
#include "GUI/Output.h"
#include "Figures/CFigure.h"
SelectAction::SelectAction(ApplicationManager *pApp):Action(pApp)
{}

void SelectAction::ReadActionParameters() 
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Click at figuire you want selected");
	pIn->GetPointClicked(p.x, p.y);
	pOut->ClearStatusBar();
}

void SelectAction::Execute() 
{
	if(!pManager->getPlaying())
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	if (pManager->GetFigure(p.x,p.y) == NULL)
		return;
	else
		if (pManager->GetFigure(p.x,p.y)->IsSelected())
		{
			pManager->GetFigure(p.x,p.y)->SetSelected(false);
			pManager->GetFigure(p.x,p.y)->ChngDrawClr(pOut->getCrntDrawColor());
			return;
		}
		if(pManager->getSelectedFig() != NULL)
		{
			pManager->getSelectedFig()->SetSelected(false);
			pManager->getSelectedFig()->ChngDrawClr(pOut->getCrntDrawColor());
		}
		pManager->GetFigure(p.x,p.y)->SetSelected(true);
		pManager->GetFigure(p.x,p.y)->ChngDrawClr(pOut->getCrntHighlightColor());
		pOut->PrintMessage(pManager->GetFigure(p.x,p.y)->Info());
		pManager->setSelectedFig(pManager->GetFigure(p.x,p.y));
		return;
}
SelectAction::~SelectAction(void)
{
}
