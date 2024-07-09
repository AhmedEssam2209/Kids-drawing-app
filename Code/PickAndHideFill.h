#pragma once
#include "Actions\Action.h"
class PickAndHideFill :
	public Action
{
public:
	PickAndHideFill(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
	virtual void undo( ){};
	~PickAndHideFill(void);
};

