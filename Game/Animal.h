#pragma once
#include <SFML\Graphics.hpp>
#include "Game.h"
#include <vector>
#include "Collision.h"
#include"Gene.h"
#include "Genetic.h"

namespace Engine 
{
	class Animal
	{
	public:
		
		Animal(GameDataRef data, Genetic &genetic);
		void DrawAnimals();
		void Move(float dt);
		 std::vector<sf::Sprite> &GetSprite();
		 std::vector<Gene> &GetGeneVector();
		 void MoveUsingGeneVector(float dt);
		 ~Animal();
	protected:
		GameDataRef _data;
		std::vector<sf::Sprite> animalSprites;
		std::vector<Gene> genes;
		Genetic genetic;
	};
}



