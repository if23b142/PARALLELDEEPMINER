#ifndef ROBO_H
#define ROBO_H

#include <string>
#include <list>
class Robo{
private:
	std::string m_Name;
	int m_X;
	int m_Y;
	int m_Score;
	int m_RoundCount;
	int m_AbilityCount;
	bool m_DisabledMovement;
	bool m_DisabledDigging;
	std::mutex m_mtx;
public:
	//Destructor
	virtual ~Robo(){}
	
	//Getters
	int rGetAbilityCount() const;
	int rGetRoundCount() const;
	int rGetScore() const;
	std::string rGetName() const;
	int rGetX() const;
	int rGetY() const;
	int rGetDisabledMovement() const;
	int rGetDisabledDigging() const;
	
	//Setters/Changers
	void rSetAbilityCount(int AbilityCount);
	void rSetRoundCount(int RoundCount);
	void rSetScore(int score);
	void rSetName(std::string name);
	void rSetX(int x);
	void rSetY(int y);
	void rSetDisabledMovement(bool disabledMovement);
	void rSetDisabledDigging(bool disabledDigging);
	void rChangeAbilityCount(int changeAbilityCount);
	void rChangeRoundCount(int changeRoundCount);
	void rChangeScore(int changeScore);
	void rChangeX(int changeX);
	void rChangeY(int changeY);
	
	//functionality
	void botDoesThings(Map map, Robo* robo);
	void Robo::dig(std::list<int> matrix[5][5]);
	virtual void ability(std::list<int> matrix[5][5]) = 0;
};

#endif