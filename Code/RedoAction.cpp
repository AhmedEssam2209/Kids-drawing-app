#include "RedoAction.h"


RedoAction::RedoAction(ApplicationManager *pApp):Action(pApp)
{}
RedoAction::~RedoAction(void)
{
}
void RedoAction::ReadActionParameters()
{
}

void RedoAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Redone");
	pManager->getMostRecentAction()->Execute();

}
