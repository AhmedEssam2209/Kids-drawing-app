#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "SaveAction.h"
#include "LoadAction.h"
#include "SwitchPlayAction.h"
#include "SwitchDrawAction.h"
#include "ExitAction.h"
#include "SelectAction.h"
#include "AddCircleAction.h"
#include "AddHexAction.h"
#include "AddSquareAction.h"
#include "MoveFigureAction.h"
#include "AddTriangleAction.h"
#include "DeleteAction.h"
#include "Circle.h"
#include "Square.h"
#include "Hexagon.h"
#include "Figures\CRectangle.h"
#include "Triangle.h"
#include "CLearAll.h"
#include "StartRecording.h"
#include "StopRecording.h"
#include "PlayRecording.h"
#include "ChangeFillColorAction.h"
#include "ChangeBorderColorAction.h"
#include <iostream>

//Constructor
ApplicationManager::ApplicationManager()
{
	valid=0;
	ActionCount=0;
	Playing=0;
	pOut = new Output;
}
void ApplicationManager::setMode(GUI_MODE MODE)
{//Create Input and output
	pOut->setMode(MODE);
	pIn = pOut->CreateInput();

	FigCount = 0;
	ActCount=0;


	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
	SelectedFig=NULL;
	MostRecentAction=NULL;
}
void ApplicationManager::AddAction(Action* Act)
{

	if (ActionCount < 20)
	{ 
		cout << "Added Action " <<ActionCount<< endl;
		RecActionList[ActionCount] = Act;
		ActionCount++;
	}
}
void ApplicationManager::DeleteFirst()
{

	FigList[0] = FigList[FigCount - 1];
	FigList[FigCount - 1] = NULL;
	FigCount--;

}
int ApplicationManager::Rand()
{
	int k = getFigCount();
	srand(1);
	int randomize = rand() % k - 1;
	CSquare* s = dynamic_cast <CSquare*>(FigList[randomize]);
	if (s != NULL)
	{
		return 1;
	}
	else
	{
		CRectangle* R = dynamic_cast <CRectangle *>(FigList[randomize]);
		if (R != NULL)
		{
			return 2;
		}			
		else
		{
			CTriangle* T = dynamic_cast <CTriangle*>(FigList[randomize]);
			if (T != NULL)
			{
				return 3;
			}
			else
			{
				CCircle* c = dynamic_cast <CCircle*>(FigList[randomize]);
				if (c != NULL)
				{
					return 4;
				}
				else
				{
					return 5;
				}
			}
		}
	}
}

int ApplicationManager::fillcolor(color fill)
{/*
 if (GetFigure()->FigGfxInfo->isFilled)
 {
 if (fill == RED)
 return 1;
 else if (fill == BLUE)
 return 2;
 else if (fill == ORANGE)
 return 3;
 else if (fill == GREEN)
 return 4;
 else if (fill == BLACK)
 return 5;
 else if (fill == YELLOW)
 return 6;
 }
 */
	return 0;
}
int ApplicationManager::getcirccount()
{
	int cc=0;
	for (int i = 0; i < FigCount; i++)
	{
		CCircle* c = dynamic_cast <CCircle*>(FigList[i]);
		if ( c!= NULL)
		{
			cc++;
		}
	}
	return cc;
}
int ApplicationManager::gettricount()
{
	int tc = 0;
	for (int i = 0; i < FigCount; i++)
	{
		CTriangle* t = dynamic_cast <CTriangle*>(FigList[i]);
		if ( t!= NULL)
		{
			tc++;
		}
	}
	return tc;
}
int ApplicationManager::getsqrcount()
{
	int sc = 0;
	for (int i = 0; i < FigCount; i++)
	{
		CSquare* s = dynamic_cast <CSquare*>(FigList[i]);
		if ( s != NULL)
		{
			sc++;
		}
	}
	return sc;
}
int ApplicationManager::getrectcount()
{
	int rc = 0;
	for (int i = 0; i < FigCount; i++)
	{
		CRectangle* r = dynamic_cast <CRectangle*>(FigList[i]);
		if (r != NULL)
		{
			rc++;
		}
	}
	return rc;
}
int ApplicationManager::gethexcount()
{
	int hc = 0;
	for (int i = 0; i < FigCount; i++)
	{
		CHexagon* h = dynamic_cast <CHexagon*>(FigList[i]);
		if ( h != NULL)
		{
			hc++;
		}
	}
	return hc;
}


CFigure* ApplicationManager::getFigByIndecies(int i)
{
	return FigList[i];
}
bool ApplicationManager::IsCleared()
{
	if (FigCount == 0)
	{
		ActionCount = 0;
		return 1;
	}
	else
		return 0;
}
bool ApplicationManager::GetRecordingStat()
{
	return RecordingStatus;
}
void ApplicationManager::SetRecordingStat(bool stats)
{
	RecordingStatus = stats;

}
bool ApplicationManager::GetifRecorded()
{
	return Recorded;
}
void ApplicationManager::SetifRecorded(bool x)
{
	Recorded = x;
}
int ApplicationManager::GetActionCount()
{
	return ActionCount;
}
Action* ApplicationManager::GetActionByIndecies(int i) 
{
	return RecActionList[i];
}
int ApplicationManager::getFigCount() 
{
	return FigCount;
}
void ApplicationManager::SetActionCount(int i) { ActionCount = i; }

void ApplicationManager::setPlaying(bool PlayingStats)
{
	Playing = PlayingStats;
}
bool ApplicationManager::getPlaying() { return Playing; }

void ApplicationManager::PlayingRecording() {
	for (int i = 1; i < 20; i++)
	{

		Playing = 1;

		if (!RecActionList[i] == NULL)
		{
			RecActionList[i]->Execute();
			UpdateInterface();
			Sleep(1000);
		}


	}
}
//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////

//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		valid = 1;
		break;

	case EXIT:
		///create ExitAction here
		pAct = new ExitAction(this);
		break;

	case CLEAR:
		pAct = new ClearAll(this);
		valid = 1;
		break;

	case SAVE:
		pAct = new SaveAction(this);
		valid = 1;

		break;

	case LOAD:
		pAct = new LoadAction(this);

		break;

	case PLAY_REC:
		pAct = new PlayRecording(this);
		valid = 0;
		break;

	case START_REC:
		pAct = new StartRecording(this);
		valid = 0;
		break;

	case STOP_REC:
		pAct = new StopRecording(this);
		valid = 0;
		break;

	case TO_PLAY:
		pAct = new SwitchPlayAction(this);
		valid = 1;

		break;

	case TO_DRAW:
		pAct = new SwitchDrawAction(this);
		valid = 1;

		break;
	case DRAW_HEX:
		valid = 1;

		pAct = new AddHexAction(this);
		break;

	case DRAW_SQUARE:
		pAct = new AddSquareAction(this);
		valid = 1;

		break;

	case DRAW_CIRCLE:
		valid = 1;

		pAct = new AddCircleAction(this);
		break;

	case DRAW_TRIANGLE:
		valid = 1;

		pAct = new AddTriangleAction(this);
		break;

	case SELECT:
		valid = 1;

		pAct = new SelectAction(this);
		break;

	case DELETE_SHAPE:
		valid = 1;

		pAct = new DeleteAction(this);
		break;

	case MOVE:
		pAct = new MoveFigureAction(this);
		valid = 1;

		break;

	case CHANGE_FILL:
		valid = 1;

		pAct = new ChangeFillColorAction(this);
		break;

	case CHANGE_BORD:
		valid = 1;

		pAct = new ChangeBorderColorAction(this);
		break;

	case STATUS:
		valid = 0;
		//a click on the status bar ==> no action
		return;
	}

	//Execute the created action
	if(pAct != NULL)
	{

		pAct->Execute();//Execute

		if (GetRecordingStat() && valid == 1)
			AddAction(pAct);

		if (GetRecordingStat()==0)
		{
			delete pAct;
			pAct = NULL;

		}

	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	cout<<"Inside ApplicationManager::AddFigure"<<endl;
	if(FigCount < MaxFigCount )
	{
		FigList[FigCount++] = pFig;
		pFig->setID(FigCount);
	}
}
void ApplicationManager:: AddAchtion(Action* pAct)
{
	if(ActCount < 5 )
	{
		undoList[ActCount++] = pAct;
	}
	else
	{

		for(int i=0;i<4;i++)
		{
			undoList[i]=undoList[i+1];
		}
		undoList[4]=pAct;
	}

}
Action* ApplicationManager :: getMostRecentAction()
{
	return undoList[ActCount-1];
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for(int i=0; i<FigCount; i++)
	{
		if (FigList[i]->IspointInside(x,y)==1)
			return FigList[i];

	}

	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::DeleteFigure(CFigure * figToDelete)
{
	for(int i=0; i<FigCount; i++)
	{
		if (FigList[i]==figToDelete)
		{
			FigList[i]= FigList[FigCount-1];
			FigList[FigCount-1]=NULL;
			FigCount--;
			break;
		}
	}
}
CFigure* ApplicationManager::getSelectedFig() const
{
	return SelectedFig;
}
void ApplicationManager::setSelectedFig(CFigure* selFig) 
{
	SelectedFig=selFig;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		if(FigList[i]!=NULL)
			FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
//save all
void ApplicationManager::SaveAll(ofstream &fout)
{
	fout<<FigCount<<endl;
	for(int i=0;i<FigCount;i++)
	{
		FigList[i]->SetSelected(false);
		FigList[i]->Save(fout);
	}
	setSelectedFig(NULL);
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}
