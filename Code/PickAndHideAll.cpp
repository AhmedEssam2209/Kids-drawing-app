#include "PickAndHideAll.h"
#include "Circle.h"
#include "Square.h"
#include "Hexagon.h"
#include "Figures\CRectangle.h"
#include "Triangle.h"
#include "SelectAction.h"
#include "ChangeFillColorAction.h"
#include "ChangeBorderColorAction.h"
#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "AddCircleAction.h"
#include "AddHexAction.h"
#include "AddSquareAction.h"
#include "AddTriangleAction.h"


PickAndHideAll::PickAndHideAll(ApplicationManager* pApp): Action(pApp)
{

}
void PickAndHideAll::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pInt = pManager->GetInput();

}

void PickAndHideAll::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pInt = pManager->GetInput();

}
PickAndHideAll::~PickAndHideAll(void)
{
}
