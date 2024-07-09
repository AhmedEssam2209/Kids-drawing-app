#pragma once
#include "Actions\Action.h"
class ExitAction :
	public Action
{
public:
	ExitAction(ApplicationManager *pApp);
	virtual void Execute();
	virtual void ReadActionParameters();
	virtual void undo( ){};
	~ExitAction(void);
};

