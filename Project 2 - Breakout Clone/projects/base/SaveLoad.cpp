#include "SaveLoad.h"

using namespace std;

/*--------------------------------------------------
				Save Function
--------------------------------------------------*/

void SaveLoad::SaveFile(string filename, int* buffer, int x_Count, int y_Count)
{
	ofstream myfile;
	myfile.open(filename);


	for (size_t y = 0; y < y_Count; y++)					//for loop that repeats itself after a row of tileIDs have been saved.
	{
		for (size_t x = 0; x < x_Count; x++)				//for loop that saves each tileID in a row.
		{
			int i = x + y * x_Count;
			myfile << buffer[i] << ", ";					//Adds a comma and a space between each tileID
		}

		myfile << std::endl;
	}

	myfile.close();
}

/*--------------------------------------------------
				Load Function
--------------------------------------------------*/

void SaveLoad::LoadFile(string filename, int* buffer, int x_Count, int y_Count)
{
	string mapline;
	ifstream myfile(filename);

	int i = 0;

	if (myfile.is_open())
	{
		int commaIndex = -1;							//This is so that the cutStart will be set to 0 during the first instance of the loop.

		while (getline(myfile, mapline))
		{
			while (true)
			{
				int cutString = commaIndex + 1;			//sets the cutStart to 0.
				commaIndex = mapline.find(',', commaIndex + 1);

				//Locates the second comma. This thing will then cut everything between the first comma and second comma and then print that.
				string numStr = mapline.substr(cutString, commaIndex - cutString);

				//When the commaIndex reaches the end of the string, it will return with a value of -1, which is less than 0
				if (commaIndex < 0)
				{
					break;								//"IF" that happens, break the loop [see what I did there?]
				}

				buffer[i] = stoi(numStr);					//Puts the cut string into the buffer array. 
				i++;

				cout << buffer[i] << " ";						//Prints the numbers without the commas in the console window.
			}

			std::cout << std::endl;
		}
		myfile.close();
	}
	else cout << "Unable to open file";					//Boohoo too bad so sad.
}