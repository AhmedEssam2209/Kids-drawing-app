#pragma once
#include "Actions\Action.h"
class AddSquareAction : public Action
{
private:
	Point P; //Square Corner
	GfxInfo SquareGfxInfo;
public:
	AddSquareAction(ApplicationManager* pApp);

	//Reads Square parameters
	virtual void ReadActionParameters();

	//Add Square to the ApplicationManager
	virtual void Execute();
	void undo( );

	~AddSquareAction(void);
};

