#include <list>
#include <vector>
#include <random>
#include <windows.h>
#include <mutex>
#include "Robo.h"

class Map{
private:
	int static const m_X = 5;
	int static const m_Y = 5;
	int static const m_Z = 10;
	int m_roundCount = 0;
	bool m_isEmpty;
	std::list<int> m_Matrix[m_X][m_Y];
public:
	Map();
	void mPrintMap(Robo* robo[5]);
	void mShuffleMap();
	void mAffectRobo(int effect, Robo& robo, int roboNR);
	bool mIsEmpty();
	
	void mSetIsEmpty(bool isEmpty);
	bool mGetIsEmpty() const;
	void mSetRoundCount(int roundCount);
	int mGetRoundCount() const;
	std::list<int> (&mGetMatrix())[5][5];
};