#pragma once
#include "Actions\Action.h"

class AddCircleAction : public Action
{
private:
	Point P1, P2; //Circle Corners
	GfxInfo CircleGfxInfo;
public:
	AddCircleAction(ApplicationManager* pApp);

	//Reads Circle parameters
	virtual void ReadActionParameters();

	//Add Circle to the ApplicationManager
	virtual void Execute();
	void undo( );

	~AddCircleAction(void);
};

