#include "Robo.h"
class BombBot : public Robo{
private:

public:
	BombBot();
	BombBot(int x,int y);
	void ability(std::list<int> matrix[5][5]) override;
};