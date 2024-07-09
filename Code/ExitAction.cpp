#include "ExitAction.h"
#include <iostream>
#include <string>
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

ExitAction::ExitAction(ApplicationManager *pApp):Action(pApp)
{
}
void ExitAction::ReadActionParameters() 
{	
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("GOODBYE!!!");
}
void ExitAction::Execute()
{
	Output *out= pManager->GetOutput();
	out->ClearDrawArea();
	out->ClearStatusBar();
}
ExitAction::~ExitAction(void)
{
}
