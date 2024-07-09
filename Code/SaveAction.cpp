#include "SaveAction.h"
#include <iostream>
#include <string>
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

SaveAction::SaveAction(ApplicationManager *pApp):Action(pApp)
{
}
void SaveAction::ReadActionParameters() 
{	
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Saving the file...");
}
void SaveAction::Execute()
{
	ReadActionParameters();
	string filePath=createFile();
	ofstream fout(filePath);
	pManager->setSelectedFig(NULL);
	fout<<pManager->GetOutput()->getColor(UI.DrawColor)<<" "
		<<pManager->GetOutput()->getColor(UI.FillColor)<<endl;
	pManager->SaveAll(fout);
	fout.close();
}
string SaveAction::createFile()
{
	string filename;
	filename=browseFile()+".fig";
	return filename;
}
string SaveAction::browseFile()
{
	 char filename[ MAX_PATH ];

  OPENFILENAME ofn;
    ZeroMemory( &filename, sizeof( filename ) );
    ZeroMemory( &ofn,      sizeof( ofn ) );
    ofn.lStructSize  = sizeof( ofn );
    //ofn.hwndOwner    = NULL;  // If you have a window to center over, put its HANDLE here
    ofn.lpstrFilter  = "Figure Files\0*.fig\0Any File\0*.*\0";
    ofn.lpstrFile    = filename;
    ofn.nMaxFile     = MAX_PATH;
    ofn.lpstrTitle   = "Save the Figure File";
    ofn.Flags        = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;
  
  GetSaveFileNameA( &ofn );
  cout << "You saved the file \"" << filename << "\"\n";
  return filename;
}
SaveAction::~SaveAction(void)
{
}
