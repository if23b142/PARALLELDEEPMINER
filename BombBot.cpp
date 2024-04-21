#include "BombBot.h"

BombBot::BombBot(){
	rSetName("BombBot");
	rSetX(0);
	rSetY(0);
	rSetScore(0);
	rSetRoundCount(0);
	rSetDisabledMovement(false);
	rSetDisabledDigging(false);
	rSetAbilityCount(1);
}

BombBot::BombBot(int x,int y){
	rSetName("BombBot");
	rSetX(x);
	rSetY(y);
	rSetScore(0);
	rSetRoundCount(0);
	rSetDisabledMovement(false);
	rSetDisabledDigging(false);
	rSetAbilityCount(1);
}
	
void BombBot::ability(std::list<int> matrix[5][5]) {
	if((rGetX() >= 0 && rGetX() < 5 && rGetY() >= 0 && rGetY() < 5) && ( matrix[rGetX()][rGetY()].size() > 0)){
		rChangeScore(matrix[rGetX()][rGetY()].front());
		matrix[rGetX()][rGetY()].pop_front();
	}
	if((rGetX() + 1 >= 0 && rGetX() + 1 < 5 && rGetY() >= 0 && rGetY() < 5) && ( matrix[rGetX() + 1][rGetY()].size() > 0)){
		rChangeScore(matrix[rGetX() + 1][rGetY()].front());
		matrix[rGetX() + 1][rGetY()].pop_front();
	}
	if((rGetX() >= 0 && rGetX() < 5 && rGetY() + 1 >= 0 && rGetY() + 1 < 5) && ( matrix[rGetX()][rGetY() + 1].size() > 0)){
		rChangeScore(matrix[rGetX()][rGetY() + 1].front());
		matrix[rGetX()][rGetY() + 1].pop_front();
	}
	if((rGetX() - 1 >= 0 && rGetX() - 1 < 5 && rGetY() >= 0 && rGetY() < 5) && ( matrix[rGetX() - 1][rGetY()].size() > 0)){
		rChangeScore(matrix[rGetX() - 1][rGetY()].front());
		matrix[rGetX() - 1][rGetY()].pop_front();
	}
	if((rGetX() >= 0 && rGetX() < 5 && rGetY() - 1 >= 0 && rGetY() - 1 < 5) && ( matrix[rGetX()][rGetY() - 1].size() > 0)){
		rChangeScore(matrix[rGetX()][rGetY() - 1].front());
		matrix[rGetX()][rGetY() - 1].pop_front();
	}
}