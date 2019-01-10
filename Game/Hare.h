#pragma once
#include "Animal.h"
#include <stdlib.h>    
#include <time.h>  

namespace Engine
{
	class Hare : public Animal
	{
	public:
		Hare(GameDataRef data);

		void Spawn(int x, int y, Gene gene);
		void SpawnRandom();
	
		~Hare();
	private:
		

	};

}