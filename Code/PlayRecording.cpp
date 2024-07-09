#include "PlayRecording.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include<chrono>
PlayRecording::PlayRecording(ApplicationManager* pApp) :Action(pApp)
{}
void PlayRecording::ReadActionParameters()
{}
void PlayRecording::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetifRecorded() == 0)
	{
		pOut->PrintMessage("No Recorded History");
		return;
	}
	for (int i = 0; i < pManager->getFigCount(); i++)
	{
		CFigure* Selected = pManager->getFigByIndecies(i);
		Selected->Delete(pOut);
		pManager->UpdateInterface();
	}
	Sleep(1000);
	pManager->PlayingRecording();
	pManager->setPlaying(false);
}
PlayRecording::~PlayRecording(void)
{}