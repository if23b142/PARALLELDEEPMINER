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

std::mutex mtx;

int main() {
	srand(time(0));
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Map* map = new Map;
	
	int roundCount = 0;
	
	Robo* robo[5];
	
	int ammountOfBots = 0;
	bool wrongInput = false;
	
	for(int i = 0; i < 5; i++)
	{
		switch(inputCreation){
			case '0':
				robo[i] = new SortBot(i,i);
			break;
			case '1':
				robo[i] = new FastBot(i,i);
			break;
			case '2':
				robo[i] = new BombBot(i,i);
			break;
		}
		std::cout << robo[i]->rGetAbilityCount() << std::endl;
	}

	//GAMES BEGIN
	while(1){
		//robos(CPU) move
		//TODO: ROBO MOVE
		for(int i = 0; i < 5; i++)
		{
			mtx.lock();
			
			robo[i].move();
			
			mtx.unlock();
		}
		
		//robos(CPU/PLAYER) get affected by negative values
		for(int i = 0; i < 5; i++){
			for(int & num : map->mGetMatrix()[robo1->rGetX()][robo1->rGetY()])
			{
				if(num < 0){
					map->mAffectRobo(num, *robo1, 1);
					num = 0;
					break;
				}
			}
		}
		
		//robos(CPU/PLAYER) Dig
		if(robo1->rGetDisabledDigging()){
			robo1->rSetDisabledDigging(false);
		}
		else
		{
			if(robo1->rGetAbilityCount() > 0){
				int randomNr = rand() % 2;
				switch(inputDigging){
					case '0':
						robo1->dig(map->mGetMatrix());
					break;
					case '1':
						robo1->ability(map->mGetMatrix());
						robo1->rChangeAbilityCount(-1);
					break;
				}
			}
			else
			{
				robo1->dig(map->mGetMatrix());
			}
		}
		
		//Display Milestones(50,100,150) for each Robo
		map->mPrintMap(hConsole, *robo1, *robo2);
		if(robo1->rGetScore() >= 50*(robo1->rGetRoundCount()+1)){
			robo1->rChangeRoundCount(1);
			map->mShuffleMap();
		}
		if(robo2->rGetScore() >= 50*(robo2->rGetRoundCount()+1)){
			robo2->rChangeRoundCount(1);
			map->mShuffleMap();
		}
		
		//Check if Map is empty
		//if so, we break the while(1)-Loop
		map->mSetIsEmpty(map->mIsEmpty());
		if(map->mGetIsEmpty()){
			break;
		}
		roundCount++;
	}
	
	//Display the winner
	if(robo1->rGetScore() > robo2->rGetScore()){
		std::cout << "Robo1(" << robo1->rGetName() << ") won!" << std::endl;
	}
	else
	if(robo1->rGetScore() < robo2->rGetScore()){
		std::cout << "Robo2(" << robo2->rGetName() << ") won!" << std::endl;
	}
	else
	{
		std::cout << "Its a draw!";
	}

	//Display some other Stats
	std::cout << std::endl << "Rounds played:" << roundCount;
	map->mPrintMap();
	for(int i = 0; i < 5; i++)
	{
		delete robo[i];
	}
    return 0;
}