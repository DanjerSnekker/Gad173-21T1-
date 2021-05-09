#include "TileAnimator.h"

#define sprite_WIDTH 60
#define sprite_HEIGHT 40

using namespace sf;

/*--------------------------------------------------
				Main Constructor
--------------------------------------------------*/
TileAnimator::TileAnimator()
{
}

/*--------------------------------------------------
				Main Deconstructor
--------------------------------------------------*/
TileAnimator::~TileAnimator()
{
}

/*--------------------------------------------------
				Initializer
--------------------------------------------------*/
void TileAnimator::Init()
{
}

/*--------------------------------------------------
				Load Function
--------------------------------------------------*/
void TileAnimator::Load(std::string filename)
{
	texture_SpriteSheet = kage::TextureManager::getTexture(filename);

	spritesheet.setTexture(*texture_SpriteSheet);
	spritesheet.setTextureRect(IntRect(0, 0, sprite_WIDTH, sprite_HEIGHT));
}

/*--------------------------------------------------
				Update Function
--------------------------------------------------*/
void TileAnimator::Update()
{
	if (animStart)
	{
		Time anim_Timer = anim_Clock.getElapsedTime();

		if (anim_Timer.asMilliseconds() > animSpeed)
		{
			int tileSprite_x = sprite_WIDTH * currentanim_Frame.x;
			int tileSprite_y = sprite_HEIGHT * currentanim_Frame.y;

			spritesheet.setTextureRect(IntRect(tileSprite_x, tileSprite_y, sprite_WIDTH, sprite_HEIGHT));

			currentanim_Frame.x++;

			if (currentanim_Frame.x > endanim_Frame.x)
			{
				currentanim_Frame = startanim_Frame;
			}
			anim_Clock.restart();
		}
	}
}

/*--------------------------------------------------
				Render Anim
--------------------------------------------------*/
void TileAnimator::Render(RenderWindow& window)
{
	window.draw(spritesheet);
}

/*--------------------------------------------------
				Start Animation
--------------------------------------------------*/
void TileAnimator::StartAnim(sf::Vector2i startFrame, sf::Vector2i endFrame, int speed)
{
	this->startanim_Frame = startFrame;
	this->endanim_Frame = endFrame;
	this->animSpeed = speed;

	animStart = true;
	currentanim_Frame = startFrame;
}