#include "Genetic.h"



Genetic::Genetic()
{
	
}

void Genetic::AddBestHareGene(Gene gene)
{
	if (bestHareGenes.size() > 30)
	{
		bestHareGenes.clear();
	}
	bestHareGenes.push_back(gene);			
}

void Genetic::AddBestWolfGene(Gene gene)
{
	if (bestWolfGenes.size() > 30)
	{
		bestWolfGenes.clear();
	}
	bestWolfGenes.push_back(gene);
}

void Genetic::AddBestSheWolfGene(Gene gene)
{
	if (bestSheWolfGenes.size() > 30);
	{
		bestSheWolfGenes.clear();
	}
		bestSheWolfGenes.push_back(gene);
		
}

void Genetic::MixHareGenes()
{
	int _hp;
	float _speed;
	int _repChance;
	
	for (int i = 0; i < bestHareGenes.size(); i++)
	{
		for (int j = i + 1; j < bestHareGenes.size() - 1; j++)
		{
			_hp = bestHareGenes[i].GetHp();
			_speed = bestHareGenes[i].GetSpeed();
			_repChance = bestHareGenes[i].GetReproduceChance();
			int random = rand() % 3;
			switch (random)
			{
			case 0:
				bestHareGenes[i].SetHp((bestHareGenes.at(j).GetHp() + _hp) / 2);
				for (int s = 0; s < bestHareGenes.at(j).GetStepsVector().size(); s++)
				{
					int step = rand() % bestHareGenes.at(j).GetStepsVector().size();
					bestHareGenes[i].AddStepToVector(bestHareGenes.at(j).GetStepsVector().at(step));
				}
				break;
			case 1:
				bestHareGenes[i].SetSpeed((bestHareGenes.at(j).GetSpeed() + _speed) / 2);
				for (int s = 0; s < bestHareGenes.at(j).GetStepsVector().size(); s++)
				{
					int step = rand() % bestHareGenes.at(j).GetStepsVector().size();
					bestHareGenes[i].AddStepToVector(bestHareGenes.at(j).GetStepsVector().at(step));
				}
				break;
			case 2:
				bestHareGenes[i].AddReproductionChance((bestHareGenes.at(j).GetReproduceChance() + _repChance) / 2);
				break;
			}
		}
	}
}

void Genetic::MixWolfGenes()
{
	int _hp;
	float _speed;
	int _repChance;
	for (int i = 0; i < bestWolfGenes.size(); i++)
	{
		for (int j = i + 1; j < bestWolfGenes.size() - 1; j++)
		{
			_hp = bestWolfGenes[i].GetHp();
			_speed = bestWolfGenes[i].GetSpeed();
			_repChance = bestWolfGenes[i].GetReproduceChance();
			int random = rand() % 3;
			switch (random)
			{
			case 0:
				bestWolfGenes[i].SetHp((bestWolfGenes.at(j).GetHp() + _hp) / 2);
				break;
			case 1:
				bestWolfGenes[i].SetSpeed((bestWolfGenes.at(j).GetSpeed() + _speed) / 2);
				break;
			case 2:
				bestWolfGenes[i].AddReproductionChance((bestWolfGenes.at(j).GetReproduceChance() + _repChance) / 2);
				break;
			}
		}
	}
}

void Genetic::MixSheWolfGenes()
{
	int _hp;
	float _speed;
	int _repChance;
	for (int i = 0; i < bestSheWolfGenes.size(); i++)
	{
		for (int j = i + 1; j < bestSheWolfGenes.size() - 1; j++)
		{
			_hp = bestSheWolfGenes[i].GetHp();
			_speed = bestSheWolfGenes[i].GetSpeed();
			_repChance = bestSheWolfGenes[i].GetReproduceChance();
			int random = rand() % 3;
			switch (random)
			{
			case 0:
				bestSheWolfGenes[i].SetHp((bestSheWolfGenes.at(j).GetHp() + _hp) / 2);
				break;
			case 1:
				bestSheWolfGenes[i].SetSpeed((bestSheWolfGenes.at(j).GetSpeed() + _speed) / 2);
				break;
			case 2:
				bestSheWolfGenes[i].AddReproductionChance((bestSheWolfGenes.at(j).GetReproduceChance() + _repChance) / 2);
				break;
			}
		}
	}
}

void Genetic::AddHareBestGenes(std::vector<Gene> sortedVec)
{
	for (int i = 0; i < sortedVec.size(); i++)
	{

		Gene g((sortedVec[i].GetHp() + sortedVec[i].GetFitness() / 2), (sortedVec[i].GetSpeed()+(sortedVec[i].GetFitness()/1500)), sortedVec[i].GetReproduceChance(),sortedVec[i].GetStepsVector());
		AddBestHareGene(g);
		
	}
}

void Genetic::AddWolfBestGenes(std::vector<Gene> sortedVec)
{
	
	for (int i = 0; i < sortedVec.size(); i++)
	{
		Gene g((sortedVec[i].GetHp() + sortedVec[i].GetFitness() / 2), sortedVec[i].GetSpeed(), sortedVec[i].GetReproduceChance());
		AddBestWolfGene(g);
	}
}

void Genetic::AddSheWolfBestGenes(std::vector<Gene> sortedVec)
{
		
	for (int i = 0; i < sortedVec.size(); i++)
	{
		Gene g((sortedVec[i].GetHp() + sortedVec[i].GetFitness() / 2), sortedVec[i].GetSpeed(), sortedVec[i].GetReproduceChance());
		AddBestSheWolfGene(g);
	
	}
}



Gene Genetic::GetRandomHareGene()
{
	if (bestHareGenes.size() > 0)
	{
	int random = rand() % bestHareGenes.size();
	return bestHareGenes.at(random);
	}
	else
	{
		Gene *g = new Gene(500, 1.5f, 20);
		return *g;
	}
}

Gene Genetic::GetRandomWolfGene()
{
	if (bestWolfGenes.size() > 0)
	{
		int random = rand() % bestWolfGenes.size();
		return bestWolfGenes.at(random);
	}
	else
	{
		Gene *g = new Gene(500, 1.0f, 3);
		return *g;
	}
}

Gene Genetic::GetRandomSheWolfGene()
{
	if (bestSheWolfGenes.size() > 0)
	{
		int random = rand() % bestSheWolfGenes.size();
		return bestSheWolfGenes.at(random);
	}
	else
	{
		Gene *g = new Gene(500, 1.0f, 3);
		return *g;
	}
}

std::vector<Gene>* Genetic::GetBestHareGenesVector()
{
	return &bestHareGenes;	
}

std::vector<Gene>* Genetic::GetBestWolfGenesVector()
{
	return &bestWolfGenes;
}

std::vector<Gene>* Genetic::GetBestSheWolfGenesVector()
{
	return &bestSheWolfGenes;
}


int Genetic::DeleteEntitiesWithNegativeHp(std::vector<sf::Sprite>* animalSprite, std::vector<Gene>* animalGene)
{
	int k = 0;
	for (int i = 0; i < animalGene->size(); i++)
	{
		if (animalGene->at(i).GetHp() < 0)
		{
			(animalSprite)->erase(animalSprite->begin() + (i - k));
			(animalGene)->erase(animalGene->begin() + (i - k));
			k++;
		}
	}
	return k;
}




Genetic::~Genetic()
{
}
