#include "example.h"
#include <kage2dutil/imstb_textedit.h>

Example::Example() : App(), horizGrid(), vertGrid(), tile()
{
}

Example::~Example()
{
}

Example &Example::inst()
{
	static Example s_instance;
	return s_instance;
}

bool Example::start()
{
	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);
	
	/*
	for (size_t y = 0; y < 10; y++)
	{
		for (size_t x= 0; x < 15; x++)
		{
			int i = x + y * 15;

			if (map[i] == 1)
			{
				//tiles[i].setTexture(*blackTile_01);
			}

			if (map[i] == 2)
			{
				//tiles[i].setTexture(*blueTile_01);
			}

			if (map[i] == 3)
			{
				//tiles[i].setTexture(*blueTile_02);
			}

			if (map[i] == 4)
			{
				//tiles[i].setTexture(*orangeTile_01);
			}

			if (map[i] == 5)
			{
				//tiles[i].setTexture(*orangeTile_02);
			}

			if (map[i] == 6)
			{
				//tiles[i].setTexture(*whiteTile_01);
			}

			if (map[i] == 7)
			{
				//tiles[i].setTexture(*yellowTile_01);
			}

			if (map[i] == 8)
			{
				//tiles[i].setTexture(*yellowTile_02);
			}

			tiles[i].setPosition(sf::Vector2f(gridPosition_X + x * cellLength, gridPosition_Y + y * cellHeight));

		}
	}*/

	tile.load();


	return true;
}

void Example::update(float deltaT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	ImGui::Begin("Kage2D");
	if (ImGui::Button("Exit"))
	{
		m_running = false;
	}

	if (ImGui::ImageButton(*blackTile_01, sf::Vector2f(cellHeight, cellLength)))
	{
		tileIDSelected = 1;
	}
	if (ImGui::ImageButton(*blueTile_01, sf::Vector2f(cellHeight, cellLength)))
	{
		tileIDSelected = 2;
	}
	if (ImGui::ImageButton(*blueTile_02, sf::Vector2f(cellHeight, cellLength)))
	{
		tileIDSelected = 3;
	}
	if (ImGui::ImageButton(*orangeTile_01, sf::Vector2f(cellHeight, cellLength)))
	{
		tileIDSelected = 4;
	}
	if (ImGui::ImageButton(*orangeTile_02, sf::Vector2f(cellHeight, cellLength)))
	{
		tileIDSelected = 5;
	}
	if (ImGui::ImageButton(*whiteTile_01, sf::Vector2f(cellHeight, cellLength)))
	{
		tileIDSelected = 6;
	}
	if (ImGui::ImageButton(*yellowTile_01, sf::Vector2f(cellHeight, cellLength)))
	{
		tileIDSelected = 7;
	}
	if (ImGui::ImageButton(*yellowTile_02, sf::Vector2f(cellHeight, cellLength)))
	{
		tileIDSelected = 8;
	}



	sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) 
		&& mousePos.x >= gridPosition_X && mousePos.x <= gridPosition_X * cellHeight
		&& mousePos.y >= gridPosition_Y && mousePos.y <= gridPosition_Y * cellLength)
	{
		int mouseCell_Pos_X = (mousePos.x - gridPosition_X) / cellHeight;
		int mouseCell_Pos_Y = (mousePos.y - gridPosition_Y) / cellLength;

		int i = mouseCell_Pos_X + mouseCell_Pos_Y * 15;

		if (tileIDSelected == 1)
		{
			tile.tiles[i].setTexture(*blackTile_01);
			
		}

		if (tileIDSelected == 2)
		{
			tile.tiles[i].setTexture(*blueTile_01);
			
		}

		if (tileIDSelected == 3)
		{
			tile.tiles[i].setTexture(*blueTile_02);
			
		}

		if (tileIDSelected == 4)
		{
			tile.tiles[i].setTexture(*orangeTile_01);
			
		}

		if (tileIDSelected == 5)
		{
			tile.tiles[i].setTexture(*orangeTile_02);
			
		}

		if (tileIDSelected == 6)
		{
			tile.tiles[i].setTexture(*whiteTile_01);
			
		}

		if (tileIDSelected == 7)
		{
			tile.tiles[i].setTexture(*yellowTile_01);
			
		}

		if (tileIDSelected == 8)
		{
			tile.tiles[i].setTexture(*yellowTile_02);
			
		}

	}

	ImGui::End();
}

void Example::render()
{
	m_window.draw(*m_backgroundSprite);

	for (size_t i = 0; i < 15; i++)
	{
		m_window.draw(tile.tiles[i]);
	}

	horizGrid.Render(m_window);
	vertGrid.Render(m_window);
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

