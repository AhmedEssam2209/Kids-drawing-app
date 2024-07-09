#include "SwitchPlayAction.h"
#include <string>
#include <fstream>
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "GUI\UI_Info.h"
SwitchPlayAction::SwitchPlayAction(	ApplicationManager *pApp):Action(pApp)
{
}
void SwitchPlayAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Switching to play mode...");
}
void SwitchPlayAction::Execute()
{
	backup();
	pManager->setMode(MODE_PLAY);
}
void SwitchPlayAction::backup()
{
	ofstream fout("result_new/backup.fig");
	pManager->SaveAll(fout);
	fout.close();
}
SwitchPlayAction::~SwitchPlayAction(void)
{
}
