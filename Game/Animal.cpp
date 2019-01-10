#include "Animal.h"

namespace Engine
{
	Animal::Animal(GameDataRef data, Genetic &genetic) : _data(data), genetic(genetic)
	{

	}
	void Animal::DrawAnimals()
	{
		for (unsigned int i = 0; i < animalSprites.size(); i++)
		{
			_data->window.draw(animalSprites[i]);
		}
	}
	void Animal::Move(float dt)
	{
		int k = 0;
		Collision collision;
		std::srand(std::time(NULL));
		for (unsigned int i = 0; i < animalSprites.size(); i++)
		{
			int random = rand() % 8;
			sf::Vector2f position = animalSprites[i].getPosition();
			float movement = ANIMAL_MOVEMENT_SPEED * dt*genes[i].GetSpeed();
			if (collision.CheckBorderCollision(animalSprites[i]) == 1)
			{
				animalSprites[i].move(movement * BOUNCE_SPEED, 0);
				movement *= -1;
			}
			else if (collision.CheckBorderCollision(animalSprites[i]) == 2)
			{
				animalSprites[i].move(0, movement *  BOUNCE_SPEED);
				movement *= -1;
			}
			else if (collision.CheckBorderCollision(animalSprites[i]) == 3)
			{
				animalSprites[i].move(0, -movement * BOUNCE_SPEED);
				movement *= -1;
			}
			else if (collision.CheckBorderCollision(animalSprites[i]) == 4)
			{
				animalSprites[i].move(-movement * BOUNCE_SPEED, 0);
				movement *= -1;
			}
			else if (collision.CheckBorderCollision(animalSprites[i]) == 5)
			{
				animalSprites[i].move(movement *  BOUNCE_SPEED, movement *  BOUNCE_SPEED);
				movement *= -1;
			}
			else if (collision.CheckBorderCollision(animalSprites[i]) == 6)
			{
				animalSprites[i].move(-movement * BOUNCE_SPEED, movement * BOUNCE_SPEED);
				movement *= -1;
			}
			else if (collision.CheckBorderCollision(animalSprites[i]) == 7)
			{
				animalSprites[i].move(movement * BOUNCE_SPEED, -movement * BOUNCE_SPEED);
				movement *= -1;
			}
			else if (collision.CheckBorderCollision(animalSprites[i]) == 8)
			{
				animalSprites[i].move(-movement * BOUNCE_SPEED, -movement * BOUNCE_SPEED);
				movement *= -1;
			}
			else if (random == 0)//up
			{
				animalSprites[i].move(0, -movement);
			}//down
			else if (random == 1)
			{
				animalSprites[i].move(0, movement);
			}//left
			else if (random == 2)
			{
				animalSprites[i].move(-movement, 0);
			}
			else if (random == 3)
			{
				animalSprites[i].move(movement, 0);
			}
			genes[i].SetFitness(1);
			genes[i].AddHp(-1);
			genes[i].AddStepToVector(random);
		}
	}
	std::vector<sf::Sprite>& Animal::GetSprite()
	{
		return animalSprites;
	}

	std::vector<Gene>& Animal::GetGeneVector()
	{
		return genes;
	}

	void Animal::MoveUsingGeneVector(float dt)
	{
		for (int i = 0; i < animalSprites.size(); i++)
		{
			if (genes[i].GetStepsVector().size() > 0)
			{
				for (int j = 0; j < genes[i].GetStepsVector().size(); j++)
				{
					float movement = (ANIMAL_MOVEMENT_SPEED * dt*genes[i].GetSpeed()) / 2;
					int step = genes[i].GetStepsVector().at(j);
					switch (i)
					{
					case 0:
						animalSprites[i].move(0, -movement);
						break;
					case 1:
						animalSprites[i].move(0, movement);
						break;
					case 2:
						animalSprites[i].move(-movement, 0);
						break;
					case 3:
						animalSprites[i].move(movement, 0);
						break;
					}
					int random = rand() % 10;
					if (random < 5)
					{
						genes[i].AddStepToVector((step + 1) % 4);
					}
				}
			}

		}
	}


			 
			 	



	Animal::~Animal()
	{
		delete [] &animalSprites;
		delete [] &genes;
	}
}