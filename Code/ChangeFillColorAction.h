#pragma once
#include "Actions\Action.h"
#include "Figures\CFigure.h"
class ChangeFillColorAction :
	public Action
{
	    color fillcolor;
public:
	ChangeFillColorAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
	void undo( ){};
	~ChangeFillColorAction(void);
};

