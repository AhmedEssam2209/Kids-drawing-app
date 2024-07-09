#pragma once
#include "Actions\Action.h"
class PickAndHideAll :
	public Action
{
public:
	PickAndHideAll(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo( ){};
	~PickAndHideAll(void);
};

