#include "example.h"
#include <kage2dutil/imstb_textedit.h>
#include "Save_And_Load.h"

/*--------------------------------------------------
				Main Constructor
--------------------------------------------------*/

Example::Example() : App(), horizGrid(), vertGrid(), tile()
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

	return true;
}

/*--------------------------------------------------
				Update Function
--------------------------------------------------*/

char saveFileName[30] = { 0 };  //Array that will store the Savefile Name

void Example::update(float deltaT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	ImGui::Begin("Select A Tile");

/*----------------------------------------------------------
	Setting Up The Tile IDs For The Tile Selection Buttons
------------------------------------------------------------*/

	if (ImGui::ImageButton(*tile.blackTile_01, sf::Vector2f(cell_X_OFFSET, cell_Y_OFFSET)))
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

	ImGui::End();

/*-----------------------------------------------------
				Options UI Menu
-----------------------------------------------------*/

	ImGui::Begin("Options");

/*-----------------------------------------------------
				Input Save File Name
-----------------------------------------------------*/

	//ImGui::InputText("Enter File Name", saveFileName, IM_ARRAYSIZE(saveFileName));		//Doesn't work with the Load Function at the moment.

/*-----------------------------------------------------
					Save Button
-----------------------------------------------------*/

	if (ImGui::Button("Save"))
	{
		Save_And_Load::SaveFile("data/MapSaves/MapTiles.txt", tile.tileMapArray, total_X_CELLCOUNT, total_Y_CELLCOUNT);
	}

/*-----------------------------------------------------
					Load Button
-----------------------------------------------------*/

	if (ImGui::Button("Load"))
	{
		Save_And_Load::LoadFile("data/MapSaves/MapTiles.txt");			//Enter argument here
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

		if (tileIDSelected == 1)
		{
			tile.tileTexture[i].setTexture(*tile.blackTile_01);
			tile.tileMapArray[i] = 1;
		}

		if (tileIDSelected == 2)
		{
			tile.tileTexture[i].setTexture(*tile.blueTile_01);
			tile.tileMapArray[i] = 2;
		}

		if (tileIDSelected == 3)
		{
			tile.tileTexture[i].setTexture(*tile.blueTile_02);
			tile.tileMapArray[i] = 3;
		}

		if (tileIDSelected == 4)
		{
			tile.tileTexture[i].setTexture(*tile.orangeTile_01);
			tile.tileMapArray[i] = 4;
		}

		if (tileIDSelected == 5)
		{
			tile.tileTexture[i].setTexture(*tile.orangeTile_02);
			tile.tileMapArray[i] = 5;
		}

		if (tileIDSelected == 6)
		{
			tile.tileTexture[i].setTexture(*tile.whiteTile_01);
			tile.tileMapArray[i] = 6;
		}

		if (tileIDSelected == 7)
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
	}

}

/*--------------------------------------------------
				Render Function
--------------------------------------------------*/

void Example::render()
{
	m_window.draw(*m_backgroundSprite);			//Draws the Background for the window
	
//For-Loop that draws the tiles on the grid

	for (size_t i = 0; i < total_CELLCOUNT; i++)			
	{
		m_window.draw(tile.tileTexture[i]);		 
	}

	horizGrid.Render(m_window);					//Draws the Horizontal Lines in the window for the grid
	vertGrid.Render(m_window);					//Draws the Verticla Lines in the window for the grid
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

