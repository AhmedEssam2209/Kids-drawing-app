#include "StartRecording.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

StartRecording::StartRecording(ApplicationManager* pApp) :Action(pApp)
{}
void StartRecording::ReadActionParameters()
{}
void StartRecording::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->IsCleared()==0)
	{
	pOut->PrintMessage("Clear And try Again");
	return;
	}
	pOut->PrintMessage("Recording Started!");
	pManager->SetActionCount(0);
	pManager->SetRecordingStat(true);
	
}
StartRecording::~StartRecording(void)
{}