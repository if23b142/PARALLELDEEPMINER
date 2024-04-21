#include "Robo.h"

int Robo::rGetAbilityCount() const {
	return m_AbilityCount;
}
int Robo::rGetRoundCount() const {
	return m_RoundCount;
}
int Robo::rGetScore() const{
	return m_Score;
}
std::string Robo::rGetName() const{
	return m_Name;
}
int Robo::rGetX() const{
	return m_X;
}
int Robo::rGetY() const{
	return m_Y;
}
int Robo::rGetDisabledMovement() const{
	return m_DisabledMovement;
}
int Robo::rGetDisabledDigging() const{
	return m_DisabledDigging;
}

void Robo::rSetAbilityCount(int AbilityCount){
	m_AbilityCount = AbilityCount;
}
void Robo::rSetRoundCount(int RoundCount){
	m_RoundCount = RoundCount;
}
void Robo::rSetScore(int score){
	m_Score = score;
}
void Robo::rSetName(std::string name){
	m_Name = name;
}
void Robo::rSetX(int x){
	m_X = x;
}
void Robo::rSetY(int y){
	m_Y = y;
}
void Robo::rSetDisabledMovement(bool disabledMovement){
	m_DisabledMovement = disabledMovement;
}
void Robo::rSetDisabledDigging(bool disabledDigging){
	m_DisabledDigging = disabledDigging;
}
void Robo::rChangeAbilityCount(int changeAbilityCount){
	m_AbilityCount += changeAbilityCount;
}
void Robo::rChangeRoundCount(int changeRoundCount){
	m_RoundCount += changeRoundCount;
}
void Robo::rChangeScore(int changeScore){
	m_Score += changeScore;
}
void Robo::rChangeX(int changeX){
	if(rGetX() + changeX >= 0 && rGetX() + changeX < 5 && rGetY() >= 0 && rGetY() < 5)
		m_X += changeX;
}
void Robo::rChangeY(int changeY){
	if(rGetX() >= 0 && rGetX() < 5 && rGetY() + changeY >= 0 && rGetY() + changeY < 5)
		m_Y += changeY;
}
void Robo::move(){
	if(this->rGetDisabledMovement()){
		this->rSetDisabledMovement(false);
	}
	else
	{
		int inputMovementRand = rand() % 4;
		switch(inputMovementRand){
			case 0:
				this->rChangeX(-1);
			break;
			case 1:
				this->rChangeY(-1);
			break;
			case 2:
				this->rChangeX(1);
			break;
			case 3:
				this->rChangeY(1);
			break;
		}
	}
}
void Robo::dig(std::list<int> matrix[5][5]){
	if(matrix[m_X][m_Y].size() == 0){
		return;
	}
	rChangeScore(matrix[m_X][m_Y].front());
	matrix[m_X][m_Y].pop_front();
}