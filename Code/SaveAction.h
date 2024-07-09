#include "Actions\Action.h"
#include <fstream>
class SaveAction : public Action
{
private:
	string createFile();
	virtual string browseFile();
public:
	SaveAction(ApplicationManager *pApp);
	virtual void Execute();
	virtual void ReadActionParameters();
	virtual void undo( ){};
	~SaveAction(void);
};

