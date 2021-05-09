#pragma once
#include <string>
#include <kage2dutil/texture_manager.h>

//#include <tile.h>

class TileAnimator
{

/*--------------------------------------------------
				Private Variables
--------------------------------------------------*/
private:

	sf::Texture* texture_SpriteSheet;
	sf::Clock anim_Clock;

	sf::Vector2i currentanim_Frame;
	sf::Vector2i startanim_Frame;
	sf::Vector2i endanim_Frame;
	int animSpeed;
	bool animStart = false;


/*--------------------------------------------------
				Public Functions
--------------------------------------------------*/
public:

	sf::Sprite spritesheet;

	TileAnimator();
	~TileAnimator();

	void Init();
	void Load(std::string filename);
	void Update();
	void Render(sf::RenderWindow& window);
	void StartAnim(sf::Vector2i startFrame, sf::Vector2i endFrame, int speed);
};

