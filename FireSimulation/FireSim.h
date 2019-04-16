#include <string>
#include <iostream>
#include<time.h>

using namespace std;

//Declaring constants to be used when print out the cells in the map
const char Empty = '.';
const char Tree = '&';
const char Burning = 'X';
//These constants define the maximum size of the grid
const int MAXWIDTH = 21;
const int MAXHEIGHT = 21;

//This is the definition of the cell class which maintains the state of each cell in the forest map
class Cell
{
	private:
		char currentState;
	//public setter and getter methods for the current state
	public:
		Cell()
		{
			//Constructor for the cell class
		}
		~Cell()
		{
			//Deconstructor for the cell class
		}
		void SetState(char c);
		char GetState();
};

//Holds the array of cells in the forest
class Forest 
{
	public:
		Cell forest[MAXWIDTH][MAXHEIGHT];

		Forest()
		{
			//this is the constructor for the forest class
		}
		~Forest()
		{
			//this is the deconstructor for the forest class
		}
};

//This is the definition which is to be output to the screen
//this gets updated with the next state for each cell in the forest
//and is then copied back to the forest cell array
class Grid {
private:
	char map[MAXWIDTH][MAXHEIGHT];	//The array which holds the characters for each element of the map

public:
	bool bNoBurningTrees = true;	//Indicates whether there are any burning trees left

	Grid()
	{
		//Constructor for the Grid class
	}
	~Grid()
	{
		//Deconstructor for the Grid class
	}
	void Initialise();				//Called at the start to set the default values for the output map
	void OutputMap();				//Writes the map to the screen
	Forest copyMapToForest(Forest f);	//copies the map contents to the forest array of cells
	void updateMap(Forest f);	//Updates the map with the next state of each cell for each time period that is triggered
};