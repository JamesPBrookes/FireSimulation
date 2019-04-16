#include "FireSim.h"

int main(void)
{
	Forest* f = new Forest();	//Decalres a new forest object
	string s;					//Declares string to be used to capture user input
	bool bContinue = true;		//Declares boolean to tell the program when to quit
	Grid* g1 = new Grid();		//Declares a new grid object
	g1->Initialise();			//Initialises the grid
	*f = g1->copyMapToForest(*f);	//Copies the grid contents to the forest cells
	g1->OutputMap();			//Output the grid
	cout << endl;
	
	//Prompts the user for input and captures input
	cout << "Press Any Key to start the simulation or Q to quit:";
	getline(cin, s);
	//Gives the user the option to quit straight away
	if (s=="Q") 
	{
		bContinue = false;
	}

	//Main loop to spread the fire and update the map
	while (bContinue)
	{
		srand(time(NULL));	//Seeds the random number generator with a unique value based on current time
		g1->updateMap(*f);	//Generates the next state of the output map from the existing forest object
		g1->OutputMap();	//Displays the updated map
		*f = g1->copyMapToForest(*f);	//Copies the new map to the forest object
		cout << "Press Any key to continue the simulation or Q to quit:";	//Asks the user if they want to continue
		getline(cin, s);	//Gets the responce
		if (s == "Q"||g1->bNoBurningTrees)	//If the user quits or there are no more burning trees
		{
			bContinue = false;	//Set continue to false and end the while loop
		}
	}

	cout << "Simulation Ended" << endl;
	//Delete objects to free up memory
	delete f;
	delete g1;

	system("PAUSE");
	return 0;
}