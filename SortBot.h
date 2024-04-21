#include "Robo.h"
class SortBot : public Robo{
private:
	
public:
	SortBot();
	SortBot(int x,int y);
	void ability(std::list<int> matrix[5][5]) override;
};