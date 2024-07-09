#pragma once
#include "Actions\Action.h"
class DeleteAction : public Action
{
public:
	DeleteAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo( ){};
	~DeleteAction(void);
};

