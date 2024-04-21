#include "Robo.h"
class FastBot : public Robo{
private:

public:
	FastBot();
	FastBot(int x,int y);
	void ability(std::list<int> matrix[5][5]) override;
};