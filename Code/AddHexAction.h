#pragma once
#include "Actions\Action.h"
class AddHexAction : public Action
{
private:
	Point P; //Hexagon Midpoint
	GfxInfo HexGfxInfo;
public:
	AddHexAction(ApplicationManager* pApp);

	//Reads Hexagon parameters
	virtual void ReadActionParameters();

	//Add Hexagon to the ApplicationManager
	virtual void Execute();
	void undo( );
	~AddHexAction(void);
};

