#pragma once
#include <SFML\Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Animal.h"
#include "Wolf.h"
#include "SheWolf.h"
#include "Hare.h"
#include "Grid.h"
#include "Genetic.h"
namespace Engine {
	class GameState :public State
	{
	public:
		GameState(GameDataRef data);
		void Init();
		void HandleInput();
		void Update(float dt);
		void HandleGridUpdates(float dt);
		void NextGeneration();
		void Draw(float dt);
	private:
		GameDataRef _data;
		int generation = 0;
		sf::Sprite _background;
		Grid *grid;
		bool AddGene=false;
		Grid *chaseGrid;
		Genetic genetic;
		std::vector<GridCell*> collisionCells;
		Wolf *wolf;
		SheWolf *sheWolf;
		Hare *hare;
	};
}