#include "CLearAll.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

ClearAll::ClearAll(ApplicationManager* pApp):Action(pApp)
{

}

void ClearAll::ReadActionParameters()
 {
 
 }

 void ClearAll::Execute()
{
	 Output* pOut = pManager->GetOutput();
	 int count = pManager->getFigCount();
	 for (int i = 0; i < count; i++)
	 {
		 CFigure* Selected = pManager->getFigByIndecies(0);
		 Selected->Delete(pOut);
		 pManager->DeleteFirst();
		 pOut->PrintMessage("Clear Done!");
	 }
}

ClearAll::~ClearAll(void) {}