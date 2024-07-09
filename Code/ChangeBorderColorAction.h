#pragma once
#include "Actions\Action.h"
#include "Figures\CFigure.h"
class ChangeBorderColorAction :
	public Action
{
private:
	color brdrcolor;
public:
	ChangeBorderColorAction(ApplicationManager * pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
	void undo( ){};
	~ChangeBorderColorAction(void);
};

