#include "Gene.h"





Gene::Gene(int hp, float speed, int reproduceChance): hp(hp), speed(speed), reproduceChance(reproduceChance)
{
	fitness = 0;
	for (int i = 0; i < 5; i++)
	{
		int random = rand() % 4;
		AddStepToVector(random);
	}
}

Gene::Gene(int hp, float speed, int reproduceChance, std::vector<int> steps) : hp(hp), speed(speed), reproduceChance(reproduceChance)
{
	fitness = 0;
	std::copy(steps.begin(),steps.end(), back_inserter(this->steps));
}




int Gene::GetHp()
{
	return hp;
}

float Gene::GetSpeed()
{
	return speed;
}

int Gene::GetReproduceChance()
{
	return reproduceChance;
}

std::vector<int> Gene::GetStepsVector()
{
	return steps;
}

void Gene::AddStepToVector(int step)
{
	if (steps.size() > 10)
	{
		steps.clear();
	}
	steps.push_back(step);
}

void Gene::AddHp(int hp)
{
	this->hp += hp;
}

void Gene::SetHp(int hp)
{
	this->hp = hp;
}

void Gene::SetSpeed(float speed)
{
	this->speed = speed;
}

void Gene::AddReproductionChance(int repChance)
{
	this->reproduceChance += repChance;
}

void Gene::SetReproductionChance(int repChance)
{
	reproduceChance = repChance;
}

int Gene::GetFitness()
{
	return fitness;
}

void Gene::SetFitness(int fitness)
{
	this->fitness += fitness;
}

Gene::~Gene()
{
}
