#include "TileAnimator.h"
#include <iostream>

#define sprite_WIDTH 60		//Add a value once you've made a sprite sheet
#define sprite_HEIGHT 40		//Add a value once you've made a sprite sheet

using namespace sf;

TileAnimator::TileAnimator()
{
}

TileAnimator::~TileAnimator()
{
}

void TileAnimator::Init()
{
}

void TileAnimator::Load(std::string filename)
{
	texture_SpriteSheet = kage::TextureManager::getTexture(filename);

	spritesheet.setTexture(*texture_SpriteSheet);
	spritesheet.setTextureRect(IntRect(0, 0, sprite_WIDTH, sprite_HEIGHT));
}

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

void TileAnimator::Render(RenderWindow& window)
{
	if(animStart)
		window.draw(spritesheet);
}

void TileAnimator::StartAnim(sf::Vector2i startFrame, sf::Vector2i endFrame, int speed)
{
	this->startanim_Frame = startFrame;
	this->endanim_Frame = endFrame;
	this->animSpeed = speed;

	animStart = true;
	currentanim_Frame = startFrame;
}