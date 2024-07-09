#pragma once
#include "Actions\Action.h"
class SwitchDrawAction : public Action
{
public:
	SwitchDrawAction(ApplicationManager *pApp);
	virtual void Execute();
	virtual void ReadActionParameters();
	void restore();
	virtual void undo( ){};
	~SwitchDrawAction(void);
};

