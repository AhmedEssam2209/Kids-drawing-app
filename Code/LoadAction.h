#pragma once
#include "Actions\Action.h"
#include <fstream>
class LoadAction : public Action
{
private:
	string openFile();
	virtual string browseFile();
public:
	LoadAction(ApplicationManager *pApp);
	virtual void Execute();
	void loadFigures(ifstream &fin);
	virtual void ReadActionParameters();
	virtual void undo( ){};
	~LoadAction(void);
};

