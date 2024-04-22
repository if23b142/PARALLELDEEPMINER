#include <iostream> 
#include <list>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random>
#include <thread>
#include <mutex>

#include "Robo.h"
#include "SortBot.h"
#include "FastBot.h"
#include "BombBot.h"
#include "Map.h"

int main()
{
	srand(time(0));
	Map* map = new Map;
	
	int randomNr = 0;
	Robo* robos[5];
	std::thread Threads[5];
	
	for(int i = 0; i < 5; i++)
	{
		randomNr = rand() % 3;
		switch(randomNr)
		{
			case 0:
				robos[i] = new SortBot(i,i);
			break;
			case 1:
				robos[i] = new FastBot(i,i);
			break;
			case 2:
				robos[i] = new BombBot(i,i);
			break;
		}
		std::cout << robos[i]->rGetAbilityCount() << std::endl;
	}

	//GAMES BEGIN
	while(1)
	{
		//robos(CPU) move
		//TODO: ROBO MOVE
		for(int i = 0; i < 5; i++)
		{
			//Threads[i](robos[i]->botDoesThings);
			Threads[i] = std::thread(&Robo::botDoesThings, robos[i]);
		}
		
		//Display Milestones(50,100,150) for each Robo
		for(int i = 0; i < 5; i++)
		{
			
			if(robos[i]->rGetScore() >= 50*(robos[i]->rGetRoundCount()+1))
			{
				robos[i]->rChangeRoundCount(1);
				map->mShuffleMap();
			}
			
		}
		
		//Check if Map is empty
		//if so, we break the while(1)-Loop
		map->mSetIsEmpty(map->mIsEmpty());
		if(map->mGetIsEmpty())
		{
			break;
		}
	}
	
	//TODO: WINNER

	//Display some other Stats
	map->mPrintMap(robos, );
	std::cout << std::endl << "Rounds played:" << map->mGetRoundCount();
	for(int i = 0; i < 5; i++)
	{
		delete robos[i];
	}
    return 0;
}