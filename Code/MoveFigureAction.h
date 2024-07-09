#pragma once
#include "Actions\Action.h"
class MoveFigureAction :
	public Action
{
private:
	Point P;
public:
	MoveFigureAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void undo( ){};
	~MoveFigureAction(void);
};

