#pragma once
#include "Actions\Action.h"
class StopRecording : public Action
{public:
	StopRecording(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo( ){};
	~StopRecording(void);
};

