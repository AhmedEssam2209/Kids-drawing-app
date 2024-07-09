#include "DeleteAction.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

DeleteAction::DeleteAction(ApplicationManager *pApp):Action(pApp)
{
}
void DeleteAction::ReadActionParameters() 
{	
}
void DeleteAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	CFigure* Selected = pManager->getSelectedFig();

	if(pManager->getSelectedFig() == NULL)
	{
		pOut->PrintMessage("No Selected Figure");
		return;
	}
	Selected->Delete(pOut);
	pManager->DeleteFigure(Selected);
	Selected->SetSelected(false);
	pManager->setSelectedFig(NULL);



	pOut->PrintMessage("Figure Deleted");
	return;
}
DeleteAction::~DeleteAction(void)
{
}
