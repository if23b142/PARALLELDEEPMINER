#include "SortBot.h"

SortBot::SortBot(){
	rSetName("SortBot");
	rSetX(0);
	rSetY(0);
	rSetScore(0);
	rSetRoundCount(0);
	rSetDisabledMovement(false);
	rSetDisabledDigging(false);
	rSetAbilityCount(3);
}
	
SortBot::SortBot(int x,int y){
	rSetName("SortBot");
	rSetX(x);
	rSetY(y);
	rSetScore(0);
	rSetRoundCount(0);
	rSetDisabledMovement(false);
	rSetDisabledDigging(false);
	rSetAbilityCount(3);
}

void SortBot::ability(std::list<int> matrix[5][5]) {
	matrix[rGetX()][rGetY()].sort(std::greater<int>());
	rChangeScore(matrix[rGetX()][rGetY()].front());
	matrix[rGetX()][rGetY()].pop_front();
}