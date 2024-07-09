#pragma once
#include "Actions\Action.h"
class StartRecording : public Action
{public:
	StartRecording(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo( ){};
	~StartRecording(void);
};

