#pragma once
#include<vector>
class Gene
{
	int hp;
	float speed;
	int reproduceChance;
	std::vector<int> steps;
	int fitness;
public:
	Gene(int hp, float speed, int reproduceChance);
	Gene(int hp, float speed, int reproduceChance, std::vector<int> steps);
	int GetHp();
	float GetSpeed();
	int GetReproduceChance();
	std::vector<int> GetStepsVector();
	void AddStepToVector(int step);
	void AddHp(int hp);
	void SetHp(int hp);
	void SetSpeed(float speed);
	void AddReproductionChance(int repChance);
	void SetReproductionChance(int repChance);
	int GetFitness();
	void SetFitness(int fitness);
	~Gene();
};

