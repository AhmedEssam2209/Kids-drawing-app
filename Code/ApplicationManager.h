#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include "Actions\Action.h"
#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures
	enum { undolistSize= 5      };

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	bool RecordingStatus;
	int ActionCount;
	Action* RecActionList[20];
	bool valid;
	bool Recorded;
	bool Playing;

public:	
	ApplicationManager(); 
	void setMode(GUI_MODE);
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);   //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void DeleteFigure(CFigure * fig);
	int ActCount;
	Action* undoList[undolistSize];
	Action* MostRecentAction;
	Action* getMostRecentAction();
	void AddAction(Action* pAct);



	CFigure* getSelectedFig() const; 
	void setSelectedFig(CFigure* selFig) ;
	void setFigCount(int count);
	int getFigCount();
	void AddAchtion(Action* Act);
	bool GetRecordingStat();
	void SetRecordingStat(bool stats);
	bool GetifRecorded();
	void SetifRecorded(bool x);
	void DeleteFirst();
	CFigure* getFigByIndecies(int i);
	void SetActionCount(int i);
	int GetActionCount();
	Action* GetActionByIndecies(int i);
	void setPlaying(bool PlayingStats);
	bool getPlaying();
	void PlayingRecording();
	bool IsCleared();
	int getcirccount(); 
	int getrectcount();
	int gethexcount();
	int gettricount();
	int getsqrcount();
	int Rand();
	int fillcolor(color fill);


	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void SaveAll(ofstream &out);
};

#endif