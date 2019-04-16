#include "FireSim.h"

//Sets the current state of a cell
void Cell::SetState(char c)
{
	currentState = c;
}
//gets the current state of a cell
char Cell::GetState()
{
	return currentState;
}
//Sets up the initial output map
void Grid::Initialise()
{
	//For every column and row, set the initial value to tree except for the centre value of burning
	//and the perimeter empty
	for (int h = 0; h < MAXHEIGHT; h++)
	{
		for (int w = 0; w < MAXWIDTH; w++)
		{
			if (w == 0 || h == 0 || w == (MAXWIDTH - 1) || h == (MAXHEIGHT - 1))
			{
				map[w][h] = Empty;
			}
			else
			{
				if (w == (MAXWIDTH / 2) && h == (MAXHEIGHT / 2))
				{
					map[w][h]=Burning;
				}
				else
				{
					map[w][h]=Tree;
				}
			}
		}
	}
}
//Displays the output map to the console
void Grid::OutputMap()
{
	//Outputs each map element for every column and row
	for (int h = 0; h < MAXHEIGHT; h++)
	{
		for (int w = 0; w < MAXWIDTH; w++)
		{
			char c;
			c = map[w][h];
			cout << c;
			if (w == (MAXWIDTH - 1))
			{
				cout << "\n";
			}
		}
	}
}
//Overwrites the current state of cells in the forest array with the new state
//of cells in the current output map
Forest Grid::copyMapToForest(Forest f)
{
	for (int h = 0; h < MAXHEIGHT; h++)
	{
		for (int w = 0; w < MAXWIDTH; w++)
		{
			char c;
			c = map[w][h];
			f.forest[w][h].SetState(c);
		}
	}
	return f;
}
//Triggerd each time the user presses a key for the next time slot
//reads the curent state from the forest array of cells and calculates the future state
//of cells in the new output map
void Grid::updateMap(Forest f)
{
	//Sets no burning trees to true to initialise it
	bNoBurningTrees = true;
	//Processes all cells in the forest object except for the perimeter and changes their
	//future state in the output map depending on its neighbours
	for (int h = 1; h < MAXHEIGHT - 1; h++)
	{
		for (int w = 1; w < MAXWIDTH - 1; w++)
		{
			//If a cell is empty it stays empty
			if ((f.forest[w][h].GetState() == Empty) || (f.forest[w][h].GetState() == Burning))
			{
				map[w][h] = Empty;
			}
			else
			{
				//Gets the state of the current immediate neighbours and if any are burning
				char cNorth = f.forest[w][h - 1].GetState();
				char cSouth = f.forest[w][h + 1].GetState();
				char cEast = f.forest[w + 1][h].GetState();
				char cWest = f.forest[w - 1][h].GetState();

				//applies probability of burning to the output
				if (cNorth == Burning || cSouth == Burning || cEast == Burning || cWest == Burning)
				{
					int iProb = rand() % 100 + 1;	//generates random number from 1-100 based on srand output from main
					if (iProb > 50)
					{
						map[w][h] = Burning;
						bNoBurningTrees = false;
					}
					//If a cell fails to burn it remains a tree in the future state
					else
					{
						map[w][h] = Tree;
					}
				}
			}
		}
	}
}


