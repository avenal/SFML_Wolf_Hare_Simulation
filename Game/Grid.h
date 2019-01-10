#pragma once
#include<vector>
#include<SFML\Graphics.hpp>
#include"GridCell.h"
#include"Game.h"
#include "Collision.h"
#include "Animal.h"
#include "Gene.h"
#include "Genetic.h"
#include <vector>
#include<iostream>
namespace Engine
{
	class Grid
	{
	public:
		Grid(GameDataRef data, Genetic &genetic);
		void InitializeCells(unsigned int x, unsigned int y);
		void SetBoundaryCells(unsigned int x, unsigned int y);
		void DrawCells();
		std::vector<GridCell*> GetGridCells();
		void Insert(Animal* wolf, Animal* sheWolf, Animal* hare, int resX, int resY, int rows);
		void ClearGrid();
		void WolfCollideWithHare(Animal *wolf, Animal *hare);
		void SheWolfCollideWithHare(Animal *sheWolf, Animal *hare);
		void WolfCollideWithSheWolf(Animal *wolf, Animal *sheWolf);
		void HareCollideWithHare(Animal *hare);
		std::vector<GridCell*> GetColliderCells();
		~Grid();
	private:
		GameDataRef _data;
		std::vector<GridCell*> cells;
		Genetic genetic;
	};
}

