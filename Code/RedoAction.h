#pragma once
#include "Actions\Action.h"
#include "AddSquareAction.h"
#include "AddHexAction.h"
#include "AddTriangleAction.h"
#include "DeleteAction.h"
#include "GUI\Input.h"
#include "UndoAction.h"
#include "GUI\Output.h"
#include "MoveFigureAction.h"
#include "AddCircleAction.h"
#include "ApplicationManager.h"


class RedoAction :
	public Action
{
public:
	RedoAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	void undo( )
{
	return;
}
	~RedoAction(void);
};

