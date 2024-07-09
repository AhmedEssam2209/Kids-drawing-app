#pragma once
#include "Actions\Action.h"
class ClearAll : public Action
{
	public:
	ClearAll(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	void undo( ){};
	~ClearAll(void);

};

