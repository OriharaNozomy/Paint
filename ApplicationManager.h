#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount=0;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* ColorList[MaxFigCount];
	CFigure* Figlistcopy[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* ColorAndTypeList[MaxFigCount];
	int colorlistcount=0;
	int colorandtypelistcount = 0;

	int selectedFigsCount, Figcountcopy;
	CFigure* SelectedFigs[MaxFigCount];
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	int selectedCount=0;

public:	
	ApplicationManager(); 
	~ApplicationManager();

	string RandFig(int& Count) const;

	void creatcopyfiglist();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	

		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	void UpdateInterfaceplay() const;
	void ClearFigList();
	void RemoveSelects();
	int NO_FIGS() const;
	void SaveAll(ofstream& OutFile);
	void Pick(CFigure* x);


	void backtonormal();
	void AddSelectedFigure(CFigure*);
	int GetSelectedCount() const;					//Returns the number of selected figures
	void RemoveSelectedFigure(CFigure*);			//Removes a figure from the SelectedFigs array
	CFigure* const* GetSelectedFigures() const;		//Returns a pointer to the SelectedFigs array
	void ClearSelectedFigs();
	void deleteselected();
	CFigure* FigerList[200];

	void GetColor(color& inputColor);
	void ChangeDRAWcllo(color x);
	void ChangeFillcllo(color x);
	CFigure* const * newfiglist();

	int GetFigCount() const;
	void CreatColorList(color s);
	int GetColorListCount() const;
	void RemoveColorList();

	void CreatColorAndTypeList(color c, string s);
	int GetColorAndTypeListCount();
	void RemoveColorAndTypeList();
	//CFigure* GetSelectedFigures();
	color RandColor()const;
	color RandColor2(string s);
	//CFigure* drawcol();
};

#endif