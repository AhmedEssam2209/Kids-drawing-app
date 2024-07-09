#include "PickAndHideType.h"
#include "Figures\CFigure.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "Circle.h"
#include "Square.h"
#include "Hexagon.h"
#include "Figures\CRectangle.h"
#include "Triangle.h"

PickAndHideType::PickAndHideType(ApplicationManager* pApp) : Action(pApp)
{
	wrong=0;
	correct=0;

}
void PickAndHideType :: ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pInt = pManager->GetInput();

}

void PickAndHideType::Execute()
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
		int rd = pManager->Rand();
		if (rd == 1)
		{
			pOut->PrintMessage("Please Select All square figures");
		}
		else if (rd == 2)
		{
			pOut->PrintMessage("Please Select All rectangle figures");
		}
		else if (rd == 3)
		{
			pOut->PrintMessage("Please Select All Triangle figures");
		}
		else if (rd == 4)
		{
			pOut->PrintMessage("Please Select All Circle figures");
		}
		else
		{
			pOut->PrintMessage("Please Select All Hexagon figures");
		}
	}

	pManager->Rand();

	MausKlick = pManager->GetFigure(pt.x, pt.y);
	if (!MausKlick)
		return;
	else 
	{
		if (pManager->Rand() == 4 )
		{
			while (correct < pManager->getcirccount())
			{
				MausKlick = pManager->GetFigure(pt.x, pt.y);
				for (int i = 0; i < FigCount; i++)
				{
					CCircle* c = dynamic_cast <CCircle*>(FigList[i]);
					if (c != NULL)
					{
						correct++;
						pManager->DeleteFigure(MausKlick);
					}
					else
					{
						wrong++;
						pManager->DeleteFigure(MausKlick);
					}
				}
			}
		}
		if (pManager->Rand() == 2)
		{
			while (correct < pManager->getrectcount())
			{
				MausKlick = pManager->GetFigure(pt.x, pt.y);
				for (int i = 0; i < FigCount; i++)
				{
					CRectangle* r = dynamic_cast <CRectangle*>(FigList[i]);
					if (r != NULL)
					{
						correct++;
						pManager->DeleteFigure(MausKlick);
					}
					else
					{
						wrong++;
						pManager->DeleteFigure(MausKlick);
					}
				}
			}
		}
		if (pManager->Rand() == 3)
		{
			while (correct < pManager->gettricount())
			{
				MausKlick = pManager->GetFigure(pt.x, pt.y);
				for (int i = 0; i < FigCount; i++)
				{
					CTriangle* t = dynamic_cast <CTriangle*>(FigList[i]);
					if (t != NULL)
					{
						correct++;
						pManager->DeleteFigure(MausKlick);
					}
					else
					{
						wrong++;
						pManager->DeleteFigure(MausKlick);
					}
				}
			}
		}
		if (pManager->Rand() == 5)
		{
			while (correct < pManager->gethexcount())
			{
				MausKlick = pManager->GetFigure(pt.x, pt.y);
				for (int i = 0; i < FigCount; i++)
				{
					CHex* h = dynamic_cast <CHex*>(FigList[i]);
					if (h != NULL)
					{
						correct++;
						pManager->DeleteFigure(MausKlick);
					}
					else
					{
						wrong++;
						pManager->DeleteFigure(MausKlick);
					}
				}
			}
		}
		if (pManager->Rand() == 1)
		{
			while (correct < pManager->getcirccount())
			{
				MausKlick = pManager->GetFigure(pt.x, pt.y);
				for (int i = 0; i < FigCount; i++)
				{
					CSquare* s = dynamic_cast <CSquare*>(FigList[i]);
					if (s != NULL)
					{
						correct++;
						pManager->DeleteFigure(MausKlick);
					}
					else
					{
						wrong++;
						pManager->DeleteFigure(MausKlick);
					}
				}
			}
		}

	}*/
}
PickAndHideType::~PickAndHideType(void)
{
}
