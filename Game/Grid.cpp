#include "Grid.h"

namespace Engine
{
	Grid::Grid(GameDataRef data, Genetic &genetic): _data(data), genetic(genetic)
	{

	}

	void Grid::InitializeCells(unsigned int x, unsigned int y)
	{
		for (unsigned int i = 0; i < x; i++) {
			for (unsigned int j = 0; j < y; j++) {
				GridCell* c = new GridCell(j, i, false, _data);
				cells.push_back(c);
			}
		}
	}

	void Grid::SetBoundaryCells(unsigned int x, unsigned int y)
	{
		for (int i = 0; i < cells.size(); i++)
		{
			if (i < y)
			{
				cells[i]->ChangeTextureToBrick();
			}
			else if (i > (y*(x-2)) && i < (x*y))
			{
				cells[i]->ChangeTextureToBrick();
			}
			else if (i % y == 0)
			{
				cells[i]->ChangeTextureToBrick();
			}
			else if (i % y == (y-1))
			{
				cells[i]->ChangeTextureToBrick();
			}
		}
	}

	void Grid::DrawCells()
	{
		for (unsigned int i = 0; i < cells.size(); i++)
		{
			_data->window.draw(cells[i]->GetCellSprite());
		}
	}

	std::vector<GridCell*> Grid::GetGridCells()
	{
		return cells;
	}

	void Grid::Insert(Animal* wolf, Animal* sheWolf, Animal* hare, int resX, int resY, int rows)
	{
		std::vector<sf::Sprite> *wolfSprite = &(wolf->GetSprite());
		std::vector<sf::Sprite> *sheWolfSprite = &(sheWolf->GetSprite());
		std::vector<sf::Sprite> *hareSprite = &(hare->GetSprite());
		Collision collision;
		for (int i = 0; i < wolfSprite->size(); i++)
		{
			int indexes[4] = { 0, 0, 0, 0};
			int x = wolfSprite->at(i).getPosition().x/resX;
			int y = wolfSprite->at(i).getPosition().y / resY;
			indexes[0] = x * rows + y;
			if(cells.size() - 1 >= indexes[0])
			{
			cells.at(indexes[0])->AddWolf(i);
			}
			x = (wolfSprite->at(i).getPosition().x +16)/ resX;
			y = wolfSprite->at(i).getPosition().y / resY;
			indexes[1] = x * rows + y;
			if (indexes[1] != indexes[0] && cells.size() - 1 >= indexes[1]) {
				cells.at(indexes[1])->AddWolf(i);
			}
			x = (wolfSprite->at(i).getPosition().x ) / resX;
			y = (wolfSprite->at(i).getPosition().y + 16)/ resY;
			indexes[2] = x * rows + y;
			if (indexes[2] != indexes[0] && indexes[2] != indexes[1] && cells.size() - 1 >= indexes[2]) {
				cells.at(indexes[2])->AddWolf(i);
			}
			x = (wolfSprite->at(i).getPosition().x + 16) / resX;
			y = (wolfSprite->at(i).getPosition().y + 16) /	resY;
			indexes[3] = x * rows + y;
			if (indexes[3] != indexes[0] && indexes[3] != indexes[1] && indexes[3] != indexes[2] && cells.size() - 1 >= indexes[3]) {
				cells.at(indexes[3])->AddWolf(i);
			}
		//	delete[] indexes;
		}
		for (int i = 0; i < sheWolfSprite->size(); i++)
		{
			int indexes[4] = { 0, 0, 0, 0 };
			int x = sheWolfSprite->at(i).getPosition().x / resX;
			int y = sheWolfSprite->at(i).getPosition().y / resY;
			indexes[0] = x * rows + y;
			if (cells.size() - 1 >= indexes[0])
			{
			cells.at(indexes[0])->AddSheWolf(i);
			}
			x = (sheWolfSprite->at(i).getPosition().x + 16) / resX;
			y = sheWolfSprite->at(i).getPosition().y / resY;
			indexes[1] = x * rows + y;
			if (indexes[1] != indexes[0] && cells.size() - 1 >= indexes[1]) {
				cells.at(indexes[1])->AddSheWolf(i);
			}
			x = (sheWolfSprite->at(i).getPosition().x) / resX;
			y = (sheWolfSprite->at(i).getPosition().y + 16) / resY;
			indexes[2] = x * rows + y;
			if (indexes[2] != indexes[0] && indexes[2] != indexes[1] && cells.size() - 1 >= indexes[2]) {
				cells.at(indexes[2])->AddSheWolf(i);
			}
			x = (sheWolfSprite->at(i).getPosition().x + 16) / resX;
			y = (sheWolfSprite->at(i).getPosition().y + 16) / resY;
			indexes[3] = x * rows + y;
			if (indexes[3] != indexes[0] && indexes[3] != indexes[1] && indexes[3] != indexes[2] && cells.size() - 1 >= indexes[3]) {
				cells.at(indexes[3])->AddSheWolf(i);
			}
			//	delete[] indexes;
		}
		for (int i = 0; i < hareSprite->size(); i++)
		{
			int indexes[4] = { 0, 0, 0, 0 };
			int x = hareSprite->at(i).getPosition().x / resX;
			int y = hareSprite->at(i).getPosition().y / resY;
			indexes[0] = x * rows + y;
			if (cells.size() - 1 >= indexes[0])
			{
			cells.at(indexes[0])->AddHare(i);
			}
			x = (hareSprite->at(i).getPosition().x + 16) / resX;
			y = hareSprite->at(i).getPosition().y / resY;
			indexes[1] = x * rows + y;
			if (indexes[1] != indexes[0] && cells.size() - 1 >= indexes[1]) {
				cells.at(indexes[1])->AddHare(i);
			}
			x = (hareSprite->at(i).getPosition().x) / resX;
			y = (hareSprite->at(i).getPosition().y + 16) / resY;
			indexes[2] = x * rows + y;
			if (indexes[2] != indexes[0] && indexes[2] != indexes[1] && cells.size() - 1 >= indexes[2]) {
				cells.at(indexes[2])->AddHare(i);
			}
			x = (hareSprite->at(i).getPosition().x + 16) / resX;
			y = (hareSprite->at(i).getPosition().y + 16) / resY;
			indexes[3] = x * rows + y;
			if (indexes[3] != indexes[0] && indexes[3] != indexes[1] && indexes[3] != indexes[2] && cells.size()-1>=indexes[3]) {
				cells.at(indexes[3])->AddHare(i);
			}
			//	delete[] indexes;
		}
		

	}

	void Grid::ClearGrid()
	{
		for (unsigned int i = 0; i < cells.size(); i++)
		{
			cells[i]->ClearCell();
		}
	}

	void Grid::WolfCollideWithHare(Animal *wolf, Animal *hare)
	{
		std::vector<Gene> *hareGene = &(hare->GetGeneVector());
		std::vector<Gene> *wolfGene = &(wolf->GetGeneVector());
		std::vector<sf::Sprite> *wolfSprite = &(wolf->GetSprite());
		std::vector<sf::Sprite> *hareSprite = &(hare->GetSprite());
		Collision collision;
		int k = 0;
		k += genetic.DeleteEntitiesWithNegativeHp(hareSprite, hareGene);
		

		for (int i = 0; i < cells.size(); i++)
		{
		
			for (int j = 0; j < cells[i]->GetWolfSprites().size(); j++)
			{
				for (int z = 0; z < cells[i]->GetHareSprites().size(); z++)
				{
					//zamien to na wektor z numerami indeksow
					if (hareSprite->size() > z-k) {
						if (collision.CheckCollision(&(*wolfSprite).at(cells[i]->GetWolfSprites()[j]), &(*hareSprite).at(cells[i]->GetHareSprites()[z-k])))
						{
							(*hareSprite).erase(hareSprite->begin() + cells[i]->GetHareSprites()[z-k]);
							(*hareGene).erase(hareGene->begin() + cells[i]->GetHareSprites()[z-k]);
							(*wolfGene).at(cells[i]->GetWolfSprites()[j]).AddHp(WOLF_FOOD_VALUE);
							//cells[i]->GetHareSprites().erase(cells[i]->GetHareSprites().begin() + z);
							if ((*wolfSprite).at(cells[i]->GetWolfSprites()[j]).getScale().x < 2.0f && (*wolfSprite).at(cells[i]->GetWolfSprites()[j]).getScale().y < 2.0f)
							{
							(*wolfSprite).at(cells[i]->GetWolfSprites()[j]).scale(1.03f, 1.03f);
							}
							k++;			
							
						}
					}
					
				}
			}
		}
	}

	void Grid::SheWolfCollideWithHare(Animal* sheWolf, Animal* hare)
	{
		std::vector<Gene> *sheWolfGene = &(sheWolf->GetGeneVector());
		std::vector<Gene> *hareGene = &(hare->GetGeneVector());
		std::vector<sf::Sprite> *sheWolfSprite = &(sheWolf->GetSprite());
		std::vector<sf::Sprite> *hareSprite = &(hare->GetSprite());
		Collision collision;
		int k = 0;
		k += genetic.DeleteEntitiesWithNegativeHp(hareSprite, hareGene);
		for (int i = 0; i < cells.size(); i++)
		{

			for (int j = 0; j < cells[i]->GetSheWolfSprites().size(); j++)
			{
				for (int z = 0; z < cells[i]->GetHareSprites().size(); z++)
				{
					//zamien to na wektor z numerami indeksow
					if (hareSprite->size() > z - k) {
						if (collision.CheckCollision(&(*sheWolfSprite).at(cells[i]->GetSheWolfSprites()[j]), &(*hareSprite).at(cells[i]->GetHareSprites()[z-k])))
						{
							(*hareSprite).erase(hareSprite->begin() + cells[i]->GetHareSprites()[z-k]);
							(*hareGene).erase(hareGene->begin() + cells[i]->GetHareSprites()[z-k]);
							(*sheWolfGene).at(cells[i]->GetSheWolfSprites()[j]).AddHp(WOLF_FOOD_VALUE);
							//cells[i]->GetHareSprites().erase(cells[i]->GetHareSprites().begin() + z);
							k++;
							if ((*sheWolfSprite).at(cells[i]->GetSheWolfSprites()[j]).getScale().x < 2.0f && (*sheWolfSprite).at(cells[i]->GetSheWolfSprites()[j]).getScale().y < 2.0f)
							{
							(*sheWolfSprite).at(cells[i]->GetSheWolfSprites()[j]).scale(1.03f, 1.03f);
							}
						}
					}

				}
			}
		}
	}


	void Grid::WolfCollideWithSheWolf(Animal* wolf, Animal* sheWolf)
	{
		std::vector<sf::Sprite> *wolfSprite = &(wolf->GetSprite());
		std::vector<sf::Sprite> *sheWolfSprite = &(sheWolf->GetSprite());
		std::vector<Gene> *wolfGene = &(wolf->GetGeneVector());
		Collision collision;
		for (int i = 0; i < cells.size(); i++)
			if (cells[i]->GetWolfSprites().size() > 0 && (cells[i]->GetWolfSprites().size()+ cells[i]->GetSheWolfSprites().size()) < 4 && (wolfSprite->size()+sheWolfSprite->size())  < MAX_WOLF)
			{
				for (int a = 0; a < cells[i]->GetWolfSprites().size(); a++)
				{
					for (int b = 0; b < cells[i]->GetSheWolfSprites().size(); b++)
					{

						int random = rand() % MAX_WOLF;
						if (random < (*wolfGene).at(cells[i]->GetWolfSprites()[a]).GetReproduceChance())
						{
							if (a < wolfSprite->size() && b < sheWolfSprite->size() && a < cells[i]->GetWolfSprites().size() && b < cells[i]->GetSheWolfSprites().size()) {

								if (collision.CheckCollision(&(*wolfSprite).at(cells[i]->GetWolfSprites()[a]), &(*sheWolfSprite).at(cells[i]->GetSheWolfSprites()[b])))
								{
									Gene g = genetic.GetRandomWolfGene();
									if ((*wolfGene).at(cells[i]->GetWolfSprites()[a]).GetReproduceChance() < MAX_REPRODUCTION_CHANCE_WOLF)
									{
									(*wolfGene).at(cells[i]->GetWolfSprites()[a]).AddReproductionChance(1);
									}
									else
									{
										(*wolfGene).at(cells[i]->GetWolfSprites()[a]).SetReproductionChance(MAX_REPRODUCTION_CHANCE_WOLF);
									}
									sf::Sprite sprite(_data->assets.GetTexture("Wolf Texture"));
									sprite.setPosition((*wolfSprite).at(cells[i]->GetWolfSprites()[a]).getPosition().x + 10, (*wolfSprite).at(cells[i]->GetWolfSprites()[a]).getPosition().y - 10);
									wolfSprite->push_back(sprite);
									wolfGene->push_back(g);
									random = (rand() + i) % MAX_WOLF;
									break;
								}
							}

						}
					}
				}
			}
	}

	void Grid::HareCollideWithHare(Animal *hare)
	{
		std::vector<Gene> *hareGene = &(hare->GetGeneVector());
		std::vector<sf::Sprite> *hareSprite = &(hare->GetSprite());
		Collision collision;
		for (int i = 0; i < cells.size(); i++)
		if (cells[i]->GetHareSprites().size() > 1 && cells[i]->GetHareSprites().size() < 4 && hareSprite->size() < MAX_HARE)
		{
			for (int a = 0; a < cells[i]->GetHareSprites().size() - 1; a++)
			{
				for (int b = a + 1; b < cells[i]->GetHareSprites().size(); b++)
				{

					int random = rand() % MAX_HARE;
					if (random < (*hareGene).at(cells[i]->GetHareSprites()[a]).GetReproduceChance()*2)
					{
						if (a < hareSprite->size() && b < hareSprite->size() && a < cells[i]->GetHareSprites().size() && b < cells[i]->GetHareSprites().size()) {

							if (collision.CheckCollision(&(*hareSprite).at(cells[i]->GetHareSprites()[a]), &(*hareSprite).at(cells[i]->GetHareSprites()[b])))
							{
								(*hareGene).at(cells[i]->GetHareSprites()[a]).AddHp(HARE_FOOD_VALUE);
								if ((*hareGene).at(cells[i]->GetHareSprites()[a]).GetReproduceChance() < MAX_REPRODUCTION_CHANCE_HARE)
								{
								(*hareGene).at(cells[i]->GetHareSprites()[a]).AddReproductionChance(1);
								}
								else
								{
									(*hareGene).at(cells[i]->GetHareSprites()[a]).SetReproductionChance(MAX_REPRODUCTION_CHANCE_HARE);
								}
								(*hareGene).at(cells[i]->GetHareSprites()[b]).AddHp(HARE_FOOD_VALUE);
								Gene gene = genetic.GetRandomHareGene();
								sf::Sprite sprite(_data->assets.GetTexture("Hare Texture"));
								sprite.setPosition((*hareSprite).at(cells[i]->GetHareSprites()[a]).getPosition().x + 10, (*hareSprite).at(cells[i]->GetHareSprites()[a]).getPosition().y - 10);
								hareSprite->push_back(sprite);
								hareGene->push_back(gene);
								random = (rand() + i) % MAX_HARE;
								break;
							}
						}

					}
				}
			}
		}
		
	}
	std::vector<GridCell*> Grid::GetColliderCells()
	{
		std::vector<GridCell*> colliderCells;
		for (int i = 0; i < cells.size(); i++)
		{
			if (cells[i]->IsCollider())
			{
				colliderCells.push_back(cells[i]);
			}
		}
		return colliderCells;
	}
	Grid::~Grid()
	{
	}

}
	
	


