#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "tile.h"

class LoadLevel
{
public:

/*--------------------------------------------------
				Class Functions
--------------------------------------------------*/

	static void LoadFile(std::string filename, int* buffer, int x_Count, int y_Count);

/*--------------------------------------------------
				Class Variable
--------------------------------------------------*/
	tile map;
};

