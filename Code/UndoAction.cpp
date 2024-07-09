#include "UndoAction.h"


UndoAction::UndoAction(ApplicationManager *pApp):Action(pApp)
{}
void UndoAction :: CanbeUndone(Action* toBeUndone)
{
	AddCircleAction*addc=dynamic_cast<AddCircleAction*>(toBeUndone);
	AddRectAction*addr=dynamic_cast<AddRectAction*>(toBeUndone);
	AddSquareAction*adds=dynamic_cast<AddSquareAction*>(toBeUndone);
	AddTriangleAction*addt=dynamic_cast<AddTriangleAction*>(toBeUndone);
	AddHexAction*addh=dynamic_cast<AddHexAction*>(toBeUndone);
	MoveFigureAction*movee=dynamic_cast<MoveFigureAction*>(toBeUndone);
	DeleteAction*dell=dynamic_cast<DeleteAction*>(toBeUndone);
	if (addc || addr || adds || addh || addt || dell || movee   != NULL)
		pManager->AddAction(toBeUndone);
}
void UndoAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("undone");
	pManager->getMostRecentAction()->undo();

}
UndoAction::~UndoAction(void)
{
}
