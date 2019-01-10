#pragma once
#include "Gene.h"
#include <vector>
#include <algorithm>
#include "SFML/Graphics.hpp"
class Genetic
{
	std::vector<Gene> bestHareGenes;
	std::vector<Gene> bestWolfGenes;
	std::vector<Gene> bestSheWolfGenes;


public:
	Genetic();
	void AddBestHareGene(Gene gene);
	void AddBestWolfGene(Gene gene);
	void AddBestSheWolfGene(Gene gene);
	void MixHareGenes();
	void MixWolfGenes();
	void MixSheWolfGenes();
	void AddHareBestGenes(std::vector<Gene> sortedVec);
	void AddWolfBestGenes(std::vector<Gene> sortedVec);
	void AddSheWolfBestGenes(std::vector<Gene> sortedVec);
	Gene GetRandomHareGene();
	Gene GetRandomWolfGene();
	Gene GetRandomSheWolfGene();
	std::vector<Gene> *GetBestHareGenesVector();
	std::vector<Gene> *GetBestWolfGenesVector();
	std::vector<Gene> *GetBestSheWolfGenesVector();
	
	int DeleteEntitiesWithNegativeHp(std::vector<sf::Sprite> *animalSprite ,std::vector<Gene> *animalGene);
	~Genetic();
};

