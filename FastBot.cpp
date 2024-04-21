#include "FastBot.h"

FastBot::FastBot(){
	rSetName("FastBot");
	rSetX(0);
	rSetY(0);
	rSetScore(0);
	rSetRoundCount(0);
	rSetDisabledMovement(false);
	rSetDisabledDigging(false);
	rSetAbilityCount(2);
}

FastBot::FastBot(int x,int y){
	rSetName("FastBot");
	rSetX(x);
	rSetY(y);
	rSetScore(0);
	rSetRoundCount(0);
	rSetDisabledMovement(false);
	rSetDisabledDigging(false);
	rSetAbilityCount(2);
}

void FastBot::ability(std::list<int> matrix[5][5]) {
	for(int i = 0; i < 3; i++){
		if((rGetX() >= 0 && rGetX() < 5 && rGetY() >= 0 && rGetY() < 5) && ( matrix[rGetX()][rGetY()].size() > 0)){
		rChangeScore(matrix[rGetX()][rGetY()].front());
		matrix[rGetX()][rGetY()].pop_front();
		}
	}
}