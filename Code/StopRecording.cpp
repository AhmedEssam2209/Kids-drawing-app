#include "StopRecording.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

StopRecording::StopRecording(ApplicationManager* pApp) :Action(pApp)
{}
void StopRecording::ReadActionParameters()
{}
void StopRecording::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetRecordingStat() == 0)
	{
		pOut->PrintMessage("No Recording In Session");
		return;
	}
	pOut->PrintMessage("Recording Stopped!");
	pManager->SetRecordingStat(false);
	pManager->SetifRecorded(true);
}
StopRecording::~StopRecording(void)
{}