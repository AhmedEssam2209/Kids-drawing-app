#pragma once
#include "Actions\Action.h"
#include "ApplicationManager.h"
class SwitchPlayAction :
	public Action
{
public:
	SwitchPlayAction(ApplicationManager *pApp);
	virtual void Execute();
	virtual void ReadActionParameters();
	void backup();
	virtual void undo( ){};
	~SwitchPlayAction(void);
};

