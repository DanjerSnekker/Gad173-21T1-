#include "example.h"
#include "example.h"
#include "SaveLoad.h"

/*--------------------------------------------------
				Main Constructor
--------------------------------------------------*/
Example::Example(): App()
{
}

/*--------------------------------------------------
				Main Deconstructor
--------------------------------------------------*/
Example::~Example()
{
}

Example &Example::inst()
{
	static Example s_instance;
	return s_instance;
}

/*--------------------------------------------------
				Start Function
--------------------------------------------------*/
bool Example::start()
{

/*--------------------------------------------------
			Loadding Up The Background
--------------------------------------------------*/
	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);
	
/*--------------------------------------------------
				Tile & Map Load Functions
--------------------------------------------------*/

	tile.load();
	tile.LoadMap();
	
	for (size_t i = 0; i < total_CELLCOUNT; i++)
	{
		tile.animated_Tiles[i].Init();
		tile.animated_Tiles[i].Load("data/GAD173 - AnimTile_SpriteSheet v3.png");
	}	

	return true;
}

/*--------------------------------------------------
				Update Function
--------------------------------------------------*/

//char saveFileName[30] = { 0 };  //Array that will store the Savefile Name

void Example::update(float deltaT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	ImGui::Begin("Select A Tile");

/*------------------------------------------------------------
	Setting Up The Tile IDs For The Tile Selection Buttons
------------------------------------------------------------*/

	//Used to set up the buttons for the Static Tiles
	/*if (ImGui::ImageButton(*tile.blackTile_01, sf::Vector2f(cell_X_OFFSET, cell_Y_OFFSET)))
	{
		tileIDSelected = 1;
	}
	
	if (ImGui::ImageButton(*tile.blueTile_01, sf::Vector2f(cell_X_OFFSET, cell_Y_OFFSET)))
	{
		tileIDSelected = 2;
	}
	
	if (ImGui::ImageButton(*tile.blueTile_02, sf::Vector2f(cell_X_OFFSET, cell_Y_OFFSET)))
	{
		tileIDSelected = 3;
	}
	
	if (ImGui::ImageButton(*tile.orangeTile_01, sf::Vector2f(cell_X_OFFSET, cell_Y_OFFSET)))
	{
		tileIDSelected = 4;
	}
	
	if (ImGui::ImageButton(*tile.orangeTile_02, sf::Vector2f(cell_X_OFFSET, cell_Y_OFFSET)))
	{
		tileIDSelected = 5;
	}
	
	if (ImGui::ImageButton(*tile.whiteTile_01, sf::Vector2f(cell_X_OFFSET, cell_Y_OFFSET)))
	{
		tileIDSelected = 6;
	}
	
	if (ImGui::ImageButton(*tile.yellowTile_01, sf::Vector2f(cell_X_OFFSET, cell_Y_OFFSET)))
	{
		tileIDSelected = 7;
	}
	
	if (ImGui::ImageButton(*tile.yellowTile_02, sf::Vector2f(cell_X_OFFSET, cell_Y_OFFSET)))
	{
		tileIDSelected = 8;
	}
	
	if (ImGui::ImageButton(*tile.greenTile_01, sf::Vector2f(cell_X_OFFSET, cell_Y_OFFSET)))
	{
		tileIDSelected = 9;
	}
	
	if (ImGui::ImageButton(*tile.greenTile_02, sf::Vector2f(cell_X_OFFSET, cell_Y_OFFSET)))
	{
		tileIDSelected = 10;
	}
	
	if (ImGui::ImageButton(*tile.greyTile_01, sf::Vector2f(cell_X_OFFSET, cell_Y_OFFSET)))
	{
		tileIDSelected = 11;
	}
	
	if (ImGui::ImageButton(*tile.pinkTile_01, sf::Vector2f(cell_X_OFFSET, cell_Y_OFFSET)))
	{
		tileIDSelected = 12;
	}
	
	if (ImGui::ImageButton(*tile.pinkTile_02, sf::Vector2f(cell_X_OFFSET, cell_Y_OFFSET)))
	{
		tileIDSelected = 13;
	}
	
	if (ImGui::ImageButton(*tile.redTile_01, sf::Vector2f(cell_X_OFFSET, cell_Y_OFFSET)))
	{
		tileIDSelected = 14;
	}
	
	if (ImGui::ImageButton(*tile.redTile_02, sf::Vector2f(cell_X_OFFSET, cell_Y_OFFSET)))
	{
		tileIDSelected = 15;
	}

	if (ImGui::ImageButton(*tile.redEye_Tile, sf::Vector2f(cell_X_OFFSET, cell_Y_OFFSET)))
	{
		tileIDSelected = 16;
	}

	if (ImGui::ImageButton(*tile.blueScreen_Tile, sf::Vector2f(cell_X_OFFSET, cell_Y_OFFSET))) 
	{
		tileIDSelected = 17;
	}

	if (ImGui::ImageButton(*tile.greenCore_Tile, sf::Vector2f(cell_X_OFFSET, cell_Y_OFFSET))) 
	{
		tileIDSelected = 18;
	}*/

	//Used to set up static image buttons for the animated tiles.

	if (ImGui::Button("Erase")) 
	{
		tileIDSelected = 0;
	}

	if (ImGui::ImageButton(*tile.redEye_Tile))
	{
		tileIDSelected = 1;
	}

	if (ImGui::ImageButton(*tile.blueScreen_Tile))
	{
		tileIDSelected = 2;
	}

	if (ImGui::ImageButton(*tile.greenCore_Tile)) 
	{
		tileIDSelected = 3;
	}

	if (ImGui::ImageButton(*tile.pinkCable_Tile)) 
	{
		tileIDSelected = 4;
	}

	if (ImGui::ImageButton(*tile.yellowCable_Tile))
	{
		tileIDSelected = 5;
	}

	if (ImGui::ImageButton(*tile.orangeCable_Tile))
	{
		tileIDSelected = 6;
	}


	ImGui::End();

/*-----------------------------------------------------
				Options UI Menu
-----------------------------------------------------*/

	ImGui::Begin("Options");

/*-----------------------------------------------------
				Input Save File Name
-----------------------------------------------------*/

	//ImGui::InputText("Enter File Name", saveFileName, IM_ARRAYSIZE(saveFileName));		
	
	//Doesn't work with the Load Function at the moment.

/*-----------------------------------------------------
					Save Button
-----------------------------------------------------*/

	if (ImGui::Button("Save"))
	{
		SaveLoad::SaveFile("data/MapSaves/MapTiles.txt", tile.tileMapArray, total_X_CELLCOUNT, total_Y_CELLCOUNT);
	}

/*-----------------------------------------------------
					Load Button
-----------------------------------------------------*/

	if (ImGui::Button("Load"))
	{
		SaveLoad::LoadFile("data/MapSaves/MapTiles.txt", tile.tileMapArray, total_X_CELLCOUNT, total_Y_CELLCOUNT);
		tile.LoadMap();
	}

/*-----------------------------------------------------
					Exit Button
-----------------------------------------------------*/

	if (ImGui::Button("Exit"))
	{
		m_running = false;
	}

	ImGui::End(); 

/*-------------------------------------------------------------------------------------------------
		Tracking Mouse Position Formula & Tile Placement [What Else Am I supposed to call it?]
--------------------------------------------------------------------------------------------------*/

	sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) 
		&& mousePos.x >= gridOFFSET_X && mousePos.x <= gridOFFSET_X + cell_X_OFFSET * total_X_CELLCOUNT
		&& mousePos.y >= gridOFFSET_Y && mousePos.y <= gridOFFSET_Y + cell_Y_OFFSET * total_Y_CELLCOUNT)
	{
		int mouseCell_Pos_X = (mousePos.x - gridOFFSET_X) / cell_X_OFFSET;
		int mouseCell_Pos_Y = (mousePos.y - gridOFFSET_Y) / cell_Y_OFFSET;

		int i = mouseCell_Pos_X + mouseCell_Pos_Y * total_X_CELLCOUNT;

		std::cout << i << std::endl;

/*----------------------------------------------------------------------------------------
		If-Condition that will place the selected tile on the corresponding cell 
----------------------------------------------------------------------------------------*/
		tile.tileMapArray[i] = tileIDSelected;

		if (tileIDSelected == 1)
		{
			tile.tileMapArray[i] = 1;
			tile.animated_Tiles[i].StartAnim(sf::Vector2i(0, 0), sf::Vector2i(8, 0), 155);
		}

		if (tileIDSelected == 2)
		{
			tile.tileMapArray[i] = 2;
			tile.animated_Tiles[i].StartAnim(sf::Vector2i(0, 1), sf::Vector2i(4, 1), 155);
		}

		if (tileIDSelected == 3)
		{
			tile.tileMapArray[i] = 3;
			tile.animated_Tiles[i].StartAnim(sf::Vector2i(0, 2), sf::Vector2i(6, 2), 155);
		}

		if (tileIDSelected == 4)
		{
			tile.tileMapArray[i] = 4;
			tile.animated_Tiles[i].StartAnim(sf::Vector2i(0, 3), sf::Vector2i(0, 3), 155);
		}

		if (tileIDSelected == 5)
		{
			tile.tileMapArray[i] = 5;
			tile.animated_Tiles[i].StartAnim(sf::Vector2i(0, 4), sf::Vector2i(0, 4), 155);
		}

		if (tileIDSelected == 6)
		{
			tile.tileMapArray[i] = 6;
			tile.animated_Tiles[i].StartAnim(sf::Vector2i(0, 5), sf::Vector2i(0, 5), 155);
		}

		//The conditions that would be used to place the static tiles on the grid cell.
		/*if (tileIDSelected == 7)
		{
			tile.tileTexture[i].setTexture(*tile.yellowTile_01);
			tile.tileMapArray[i] = 7;
		}

		if (tileIDSelected == 8)
		{
			tile.tileTexture[i].setTexture(*tile.yellowTile_02);
			tile.tileMapArray[i] = 8;
		}

		if (tileIDSelected == 9)
		{
			tile.tileTexture[i].setTexture(*tile.greenTile_01);
			tile.tileMapArray[i] = 9;
		}

		if (tileIDSelected == 10)
		{
			tile.tileTexture[i].setTexture(*tile.greenTile_02);
			tile.tileMapArray[i] = 10;
		}

		if (tileIDSelected == 11)
		{
			tile.tileTexture[i].setTexture(*tile.greyTile_01);
			tile.tileMapArray[i] = 11;
		}

		if (tileIDSelected == 12)
		{
			tile.tileTexture[i].setTexture(*tile.pinkTile_01);
			tile.tileMapArray[i] = 12;
		}

		if (tileIDSelected == 13)
		{
			tile.tileTexture[i].setTexture(*tile.pinkTile_02);
			tile.tileMapArray[i] = 13;
		}

		if (tileIDSelected == 14)
		{
			tile.tileTexture[i].setTexture(*tile.redTile_01);
			tile.tileMapArray[i] = 14;
		}

		if (tileIDSelected == 15)
		{
			tile.tileTexture[i].setTexture(*tile.redTile_02);
			tile.tileMapArray[i] = 15;
		}

		if (tileIDSelected == 1)
		{
			tile.tileMapArray[i] = 16;
			tile.animated_Tiles[i].StartAnim(sf::Vector2i(0, 0), sf::Vector2i(9, 0), 155);
		}

		if (tileIDSelected == 17)
		{
			tile.tileMapArray[i] = 17;
			tile.animated_Tiles[i].StartAnim(sf::Vector2i(0, 1), sf::Vector2i(5, 1), 155);
		}

		if (tileIDSelected == 18)
		{
			tile.tileMapArray[i] = 18;
			tile.animated_Tiles[i].StartAnim(sf::Vector2i(0, 2), sf::Vector2i(7, 2), 155);
		}*/
	}
	
	//Updates the animated tiles every frame by looping through each tile
	for (size_t i = 0; i < total_CELLCOUNT; i++)
	{
		tile.animated_Tiles[i].Update();
	}
}

/*--------------------------------------------------
				Render Function
--------------------------------------------------*/
void Example::render()
{
	m_window.draw(*m_backgroundSprite);

	horizGrid.Render(m_window);					//Draws the Horizontal Lines in the window for the grid
	vertGrid.Render(m_window);					//Draws the Verticla Lines in the window for the grid

//For-Loop that draws the tiles on the grid
	for (size_t i = 0; i < total_CELLCOUNT; i++)
	{
		if(tile.tileMapArray[i]>0)
		{
			tile.animated_Tiles[i].Render(m_window);
		}
	}

}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

