#include "GameState.h"
#include <sstream>
#include <iostream>
#include "DEFINITIONS.h"

namespace Engine {
	GameState::GameState(GameDataRef data) :_data(data)
	{

	}
	void GameState::Init()
	{
		this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
		this->_data->assets.LoadTexture("Wolf Texture", WOLF_FILEPATH);
		
		this->_data->assets.LoadTexture("She Wolf Texture", SHE_WOLF_FILEPATH);
		
		this->_data->assets.LoadTexture("Hare Texture", HARE_FILEPATH);
		
		this->_data->assets.LoadTexture("Grass Texture", GRASS_FILEPATH);
		this->_data->assets.LoadTexture("Brick Texture", BRICK_FILEPATH);
		grid = new Grid(_data, genetic);
		grid->InitializeCells(20,25);
		grid->SetBoundaryCells(20, 25);
		chaseGrid = new Grid(_data, genetic);
		chaseGrid->InitializeCells(6, 8);
		wolf = new Wolf(_data);
		sheWolf = new SheWolf(_data);
		hare = new Hare(_data);
		grid->Insert(wolf, sheWolf, hare,32,32,20);
		chaseGrid->Insert(wolf, sheWolf, hare, 100, 100, 6);
		collisionCells = grid->GetColliderCells();
		
	}
	void GameState::HandleInput()
	{
		sf::Event event;
		Gene g(700, 1.0f, 10);
		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (this->_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window))
			{
				
				wolf->Spawn(sf::Mouse::getPosition(_data->window).x, sf::Mouse::getPosition(_data->window).y,genetic.GetRandomWolfGene());
			}
			else if (this->_data->input.IsSpriteClicked(_background, sf::Keyboard::A, _data->window))
			{
				sheWolf->Spawn(sf::Mouse::getPosition(_data->window).x, sf::Mouse::getPosition(_data->window).y,genetic.GetRandomSheWolfGene());
			}
			else if (this->_data->input.IsSpriteClicked(_background, sf::Mouse::Right, _data->window))
			{
				
				hare->Spawn(sf::Mouse::getPosition(_data->window).x, sf::Mouse::getPosition(_data->window).y,genetic.GetRandomHareGene());
				grid->ClearGrid();
				chaseGrid->ClearGrid();
				grid->Insert(wolf, sheWolf, hare, 32, 32, 20);
				chaseGrid->Insert(wolf, sheWolf, hare, 50, 50, 12);
			}
			for (int i = 0; i < grid->GetGridCells().size(); i++)
			{
				
				if (this->_data->input.IsSpriteClicked(grid->GetGridCells().at(i)->GetCellSprite(), sf::Keyboard::S, _data->window))
				{
					grid->GetGridCells().at(i)->ChangeTextureToBrick();
				}
				else if (this->_data->input.IsSpriteClicked(grid->GetGridCells().at(i)->GetCellSprite(), sf::Keyboard::D, _data->window))
				{
					grid->GetGridCells().at(i)->ChangeTextureToGrass();
				}
				collisionCells.clear();
			    collisionCells = grid->GetColliderCells();
			}
		}
	}
	void GameState::Update(float dt)
	{
		if (hare->GetSprite().size() == 0 && wolf->GetSprite().size() == 0 && sheWolf->GetSprite().size() == 0)
		{
			genetic.MixHareGenes();
			genetic.MixWolfGenes();
			genetic.MixSheWolfGenes();
			NextGeneration();
		}
		else if (hare->GetSprite().size() <15 && wolf->GetSprite().size() <15 && sheWolf->GetSprite().size() <15 && !AddGene)
		{
			AddGene = true;
			genetic.AddHareBestGenes(hare->GetGeneVector());
			genetic.AddWolfBestGenes(wolf->GetGeneVector());
			genetic.AddSheWolfBestGenes(sheWolf->GetGeneVector());
		}
		else
		{
			HandleGridUpdates(dt);
		}
		
	}
	void GameState::HandleGridUpdates(float dt)
	{
		wolf->Move(dt, chaseGrid, collisionCells, &sheWolf->GetSprite(), &hare->GetSprite());
		sheWolf->Move(dt, chaseGrid, collisionCells, &hare->GetSprite());
		hare->MoveUsingGeneVector(dt);
		hare->Move(dt);
		grid->WolfCollideWithHare(wolf, hare);
		grid->ClearGrid();
		chaseGrid->ClearGrid();
		genetic.DeleteEntitiesWithNegativeHp(&wolf->GetSprite(), &wolf->GetGeneVector());
		genetic.DeleteEntitiesWithNegativeHp(&sheWolf->GetSprite(), &sheWolf->GetGeneVector());
		grid->Insert(wolf, sheWolf, hare, 32, 32, 20);
		chaseGrid->Insert(wolf, sheWolf, hare, 100, 100, 6);
		grid->SheWolfCollideWithHare(sheWolf, hare);
		grid->ClearGrid();
		chaseGrid->ClearGrid();
		grid->Insert(wolf, sheWolf, hare, 32, 32, 20);
		chaseGrid->Insert(wolf, sheWolf, hare, 100, 100, 6);
		grid->WolfCollideWithSheWolf(wolf, sheWolf);
		grid->ClearGrid();
		chaseGrid->ClearGrid();
		grid->Insert(wolf, sheWolf, hare, 32, 32, 20);
		chaseGrid->Insert(wolf, sheWolf, hare, 100, 100, 6);
		grid->HareCollideWithHare(hare);
		grid->ClearGrid();
		chaseGrid->ClearGrid();
		grid->Insert(wolf, sheWolf, hare, 32, 32, 20);
		chaseGrid->Insert(wolf, sheWolf, hare, 100, 100, 6);
	}
	void GameState::NextGeneration()
	{
		if (generation ==0)
		{
			AddGene = false;
			int _hpH = rand() % 400 + 400;
			float _speedH = (rand() % 300) / 100 + 1.0f;
			int _repChH = rand() % 10 + 15;
			int _hpW = rand() % 200 + 400;
			float _speedW = (rand() % 200) / 100 + 0.5f;
			int _repChW = rand() % 5 + 2;
			int _hpS = rand() % 200 + 400;
			float _speedS = (rand() % 200) / 100 + 0.5f;
			int _repChS = rand() % 5 + 2;
			Gene gH(_hpH, _speedH, _repChH);
			Gene gW(_hpW, _speedW, _repChW);
			Gene gS(_hpS, _speedS, _repChS);
			genetic.AddBestHareGene(gH);
			genetic.AddBestWolfGene(gW);
			genetic.AddBestSheWolfGene(gS);
			generation++;
		}
		else {
			AddGene = false;
			for (int i = 0; i < 2670; i++)
			{
				int X = rand() % 800;
				int Y = rand() % 600;
				hare->Spawn(X, Y, genetic.GetRandomHareGene());
			}
			for (int j = 0; j < 5; j++)
			{
				int X = rand() % 800;
				int Y = rand() % 600;
				wolf->Spawn(X, Y, genetic.GetRandomWolfGene());
			}
			for (int k = 0; k < 5; k++)
			{
				int X = rand() % 800;
				int Y = rand() % 600;
				sheWolf->Spawn(X, Y, genetic.GetRandomSheWolfGene());
			}
			generation++;
		}
		
	}

	void GameState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);
		this->_data->window.draw(this->_background);
		grid->DrawCells();
		wolf->DrawAnimals();
		sheWolf->DrawAnimals();
		hare->DrawAnimals();
		this->_data->window.display();
	}
}

