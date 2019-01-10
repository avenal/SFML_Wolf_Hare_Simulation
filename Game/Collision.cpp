#include "Collision.h"


namespace Engine
{
	Collision::Collision()
	{
	}

	bool Collision::CheckCollision(sf::Sprite *sprite1, sf::Sprite *sprite2)
	{
		sf::Rect<float> rect1 = sprite1->getGlobalBounds();
		sf::Rect<float> rect2 = sprite2->getGlobalBounds();

		if (rect1.intersects(rect2))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int Collision::CheckBorderCollision(sf::Sprite sprite)
	{

		//left border
		if (sprite.getPosition().x <= BOUNDARY)
		{
			
			return 1;
		}
		//top
		else if (sprite.getPosition().y <= BOUNDARY)
		{
			
			return 2;
		}
		//bot
		else if (sprite.getPosition().y + sprite.getLocalBounds().height >= SCREEN_HEIGHT- BOUNDARY)
		{
			
			return 3;
		}
		//right
		else if (sprite.getPosition().x + sprite.getLocalBounds().width >= SCREEN_WIDTH- BOUNDARY)
		{
		
			return 4;
		}
		//top left
		else if(sprite.getPosition().y <= BOUNDARY && sprite.getPosition().x <= BOUNDARY)
		{
			
			return 5;
		}
		//top right
		else if (sprite.getPosition().y <= BOUNDARY && sprite.getPosition().x + sprite.getLocalBounds().width >= SCREEN_WIDTH - BOUNDARY)
		{
			
			return 6;
		}
		//bottom left
		else if (sprite.getPosition().y + sprite.getLocalBounds().height >= SCREEN_HEIGHT - BOUNDARY && sprite.getPosition().x <= BOUNDARY)
		{
			
			return 7;
		}
		//bottom right
		else if (sprite.getPosition().x + sprite.getLocalBounds().width >= SCREEN_WIDTH - BOUNDARY && sprite.getPosition().y + sprite.getLocalBounds().height >= SCREEN_HEIGHT - BOUNDARY)
		{
			
			return 8;
		}
		else
		{
			return 0;
		}

	}


	Collision::~Collision()
	{
	}
}

