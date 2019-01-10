#include "Hare.h"


namespace Engine
{
	Hare::Hare(GameDataRef data) : Animal(data,genetic)
	{

	}

	void Hare::Spawn(int x, int y, Gene gene)
	{
		sf::Sprite sprite(_data->assets.GetTexture("Hare Texture"));
		sprite.setPosition(x, y);
		animalSprites.push_back(sprite);
		genes.push_back(gene);
	}

	void Hare::SpawnRandom()
	{

	}

	

	


	Hare::~Hare()
	{
	}
}