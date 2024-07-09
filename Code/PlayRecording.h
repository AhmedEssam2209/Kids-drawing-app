#pragma once
#include "Actions\Action.h"
class PlayRecording : public Action
{

	public:
		PlayRecording(ApplicationManager* pApp);
		virtual void ReadActionParameters();
		virtual void Execute();
	virtual void undo( ){};
		~PlayRecording(void);
	};




