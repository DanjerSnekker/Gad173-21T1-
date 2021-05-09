#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "tile.h"

class SaveLoad
{
public:

/*--------------------------------------------------
				Class Functions
--------------------------------------------------*/

	//enum DataType { INT, STRING }; Letting this stay here, cos I wanted to try it out in my own time later.


	static void SaveFile(std::string filename, int* buffer, /*DataType dataType,*/ int x_Count, int y_Count);
	static void LoadFile(std::string filename, int* buffer, int x_Count, int y_Count);

	tile map;
};