#pragma once
#include "Actions\Action.h"
#include "Figures\CFigure.h"
class PickAndHideType :
	public Action
{
	CFigure* MausKlick;
	Point pt;
	int correct , wrong;
public:
	PickAndHideType(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
	virtual void undo( ){};
	~PickAndHideType(void);
};

