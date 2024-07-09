#include "SwitchDrawAction.h"
#include <string>
#include <fstream>
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "LoadAction.h"

SwitchDrawAction::SwitchDrawAction(ApplicationManager *pApp):Action(pApp)
{
}
void SwitchDrawAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Switching to draw mode...");
	
}
void SwitchDrawAction::Execute()
{
	pManager->setMode(MODE_DRAW);
	restore();
}
void SwitchDrawAction::restore()
{
	LoadAction lact(pManager);
	ifstream fin("result_new/backup.fig");
	lact.loadFigures(fin);
	fin.close();
}
SwitchDrawAction::~SwitchDrawAction(void)
{
}
