#pragma once
#include "Actions/Action.h"
class SelectAction : public Action
{
private:
	Point p;
public:
	SelectAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute() ;
	virtual void undo( ){};
	~SelectAction(void);
};

