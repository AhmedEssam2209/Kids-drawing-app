#pragma once
#include "Actions\Action.h"
#include "AddSquareAction.h"
#include "AddHexAction.h"
#include "AddTriangleAction.h"
#include "Actions\AddRectAction.h"
#include "DeleteAction.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "MoveFigureAction.h"
#include "AddCircleAction.h"
#include "ApplicationManager.h"
class UndoAction :
	public Action
{
public:
	UndoAction(ApplicationManager *pApp);
	virtual void ReadActionParameters(){};
	virtual void Execute();
	void CanbeUndone(Action* toBeUndone);
	void undo( )
{
	return;
}
	~UndoAction(void);
};

