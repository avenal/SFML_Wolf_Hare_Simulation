#include "SheWolf.h"


namespace Engine
{
	SheWolf::SheWolf(GameDataRef data) : Animal(data,genetic)
	{

	}

	sf::Vector2f SheWolf::normalize(const sf::Vector2f & source)
	{
		float length = sqrt((source.x * source.x) + (source.y * source.y));
		if (length != 0)
			return sf::Vector2f(source.x / length, source.y / length);
		else
			return source;
	}
	void SheWolf::Move(float dt, Grid * chaseGrid, std::vector<GridCell*> collisionCells, std::vector<sf::Sprite>* hare)
	{
		AvoidColliders(dt, collisionCells);
		ChaseHare(dt, chaseGrid, hare);
		AvoidBoundaryAndMoveRandomly(dt);
		
	}

	void SheWolf::ChaseHare(float dt, Grid * chaseGrid, std::vector<sf::Sprite>* hare)
	{
		float movement = ANIMAL_MOVEMENT_SPEED * dt*CHASE_MULTIPLICATOR;
		for (int z = 0; z < (chaseGrid->GetGridCells().size()); z++)
		{
			if (chaseGrid->GetGridCells()[z]->GetHareSprites().size() > 0 && chaseGrid->GetGridCells()[z]->GetSheWolfSprites().size() > 0)
			{

				for (int y = 0; y < chaseGrid->GetGridCells()[z]->GetSheWolfSprites().size(); y++)
				{
					int randomChase = rand() % chaseGrid->GetGridCells()[z]->GetSheWolfSprites().size();
						sf::Vector2f dir = normalize(animalSprites.at(chaseGrid->GetGridCells()[z]
							->GetSheWolfSprites().at(y)).getPosition()
							- hare->at(chaseGrid->GetGridCells()[z]
							->GetHareSprites().at(0)).getPosition());
						animalSprites.at(chaseGrid->GetGridCells()[z]->GetSheWolfSprites().at(randomChase)).move(-movement * dir);
				}
			}
		}


	}

	void SheWolf::AvoidColliders(float dt, std::vector<GridCell*> collisionCells)
	{
		float movement = ANIMAL_MOVEMENT_SPEED * dt;
		if (collisionCells.size() > 0)
		{
			for (int i = 0; i < animalSprites.size(); i++)
			{
				for (int h = 0; h < collisionCells.size(); h++)
				{
					if ((&animalSprites[i])->getGlobalBounds().intersects(collisionCells[h]->GetCellSprite().getGlobalBounds()))
					{
						sf::Vector2f dir = normalize((&animalSprites[i])->getPosition() - collisionCells[h]->GetCellSprite().getPosition());
						animalSprites[i].move(movement*dir*5.0f);
					}
				}
			}
		}
	}

	void SheWolf::AvoidBoundaryAndMoveRandomly(float dt)
	{
		Collision collision;
		
		for (int i = 0; i < animalSprites.size(); i++)
		{
			float movement = ANIMAL_MOVEMENT_SPEED * dt*genes[i].GetSpeed();
			int random = rand() % 4;
			if (collision.CheckBorderCollision(animalSprites[i]) > 0)
			{
				animalSprites[i].move(movement * BOUNCE_SPEED, 0);
			}
			else if (collision.CheckBorderCollision(animalSprites[i]) == 2)
			{
				animalSprites[i].move(0, movement *  BOUNCE_SPEED);
			}
			else if (collision.CheckBorderCollision(animalSprites[i]) == 3)
			{
				animalSprites[i].move(0, -movement * BOUNCE_SPEED);
			}
			else if (collision.CheckBorderCollision(animalSprites[i]) == 4)
			{
				animalSprites[i].move(-movement * BOUNCE_SPEED, 0);
			}
			else if (collision.CheckBorderCollision(animalSprites[i]) == 5)
			{
				animalSprites[i].move(movement *  BOUNCE_SPEED, movement *  BOUNCE_SPEED);
			}
			else if (collision.CheckBorderCollision(animalSprites[i]) == 6)
			{
				animalSprites[i].move(-movement * BOUNCE_SPEED, movement * BOUNCE_SPEED);
			}
			else if (collision.CheckBorderCollision(animalSprites[i]) == 7)
			{
				animalSprites[i].move(movement * BOUNCE_SPEED, -movement * BOUNCE_SPEED);
			}
			else if (collision.CheckBorderCollision(animalSprites[i]) == 8)
			{
				animalSprites[i].move(-movement * BOUNCE_SPEED, -movement * BOUNCE_SPEED);
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
		}

	}


	void SheWolf::Spawn(int x, int y, Gene gene)
	{
		sf::Sprite sprite(_data->assets.GetTexture("She Wolf Texture"));
		sprite.setPosition(x, y);
		genes.push_back(gene);
		animalSprites.push_back(sprite);
	}

	void SheWolf::SpawnRandom()
	{

	}

	SheWolf::~SheWolf()
	{
	}
}
