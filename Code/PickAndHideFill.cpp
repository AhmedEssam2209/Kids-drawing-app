#include "PickAndHideFill.h"
#include "Circle.h"
#include "Square.h"
#include "Hexagon.h"
#include "Figures\CRectangle.h"
#include "Triangle.h"
#include "Figures\CFigure.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

PickAndHideFill::PickAndHideFill(ApplicationManager * pApp) : Action(pApp)
{


}
void PickAndHideFill::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pInt = pManager->GetInput();
}

void PickAndHideFill::Execute()
{/*
	Output* pOut = pManager->GetOutput();
	Input* pInt = pManager->GetInput();
	int k = pManager->getFigCount();
	if (k == 0)
	{
		pOut->PrintMessage("There are currently no available figures to choose from");
		return;
	}
	else
	{
		int rd = pManager->fillcolor(fill);
		if (rd == 1)
		{
			pOut->PrintMessage("Please Select All RED figures");
		}
		else if (rd == 2)
		{
			pOut->PrintMessage("Please Select All BLUE figures");
		}
		else if (rd == 3)
		{
			pOut->PrintMessage("Please Select All ORANGE figures");
		}
		else if (rd == 4)
		{
			pOut->PrintMessage("Please Select All GREEN figures");
		}
		else if (rd ==5)
		{
			pOut->PrintMessage("Please Select All BLACK figures");
		}
		else 
		{
			pOut->PrintMessage("Please Select All YELLOW figures");
		}
	}
	*/
}
PickAndHideFill::~PickAndHideFill(void)
{
}
