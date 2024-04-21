#include "Map.h"
#include <iostream>
#include <algorithm>

Map::Map(){
	for (int i = 0; i < m_X; ++i) {
		for (int j = 0; j < m_Y; ++j) {
			for (int k = 0; k < m_Z; ++k) {
				int randomNumber = rand() % 13 - 3;
				m_Matrix[i][j].push_back(randomNumber);
			}
		}
	}
	m_isEmpty = false;
}
	
void Map::mPrintMap(HANDLE hConsole, Robo& robo1, Robo& robo2) {
	std::cout << "+-------------------+" << std::endl;
	for (int i = 0; i < 5; ++i) {
		std::cout << "|";
		for (int j = 0; j < 5; ++j) {
			if(m_Matrix[i][j].front() < 0)
			{
				
			}
			else
			if(i == robo1.rGetX() && j == robo1.rGetY()){
				std::cout << "+";
			}
			else
			if(i == robo2.rGetX() && j == robo2.rGetY()){
				std::cout << "-";
			}
			else
			{
				std::cout << " ";
			}
			
			std::cout << m_Matrix[i][j].front();
			if(i == robo1.rGetX() && j == robo1.rGetY()){
				std::cout << "+";
			}
			else
			if(i == robo2.rGetX() && j == robo2.rGetY()){
				std::cout << "-";
			}
			else
			{
				std::cout << " ";
			}
			std::cout << "|";
		}
		
		std::cout << std::endl << "+-------------------+" << std::endl;
	}
	std::cout << "Robo1(" << robo1.rGetName() << ") Score:" << robo1.rGetScore() << std::endl;
	std::cout << "Robo2(" << robo2.rGetName() << ") Score:" << robo2.rGetScore() << std::endl;
}

void Map::mShuffleMap(){
	for (int i = 0; i < m_X; ++i) {
		for (int j = 0; j < m_Y; ++j) {
			int randomNumber = rand() % 3;
			switch(randomNumber){
				case 0:
					m_Matrix[i][j].sort();
				break;
				case 1:
					m_Matrix[i][j].sort(std::greater<int>());
				break;
				case 2:
					std::vector<int> Shuffler(m_Matrix[i][j].begin(), m_Matrix[i][j].end());
					auto rng = std::default_random_engine {};
					std::shuffle(std::begin(Shuffler), std::end(Shuffler), rng);
					m_Matrix[i][j].clear();
					std::copy(Shuffler.begin(), Shuffler.end(), std::back_inserter(m_Matrix[i][j]));
				break;
			}
		}
	}
}

void Map::mAffectRobo(int effect, Robo& robo, int roboNR){
	int minX = 0;
	int minY = 0;
	int min = 0;
	switch(effect){
		case -1:
			std::cout << "Robo" << roboNR << "(";
			std::cout << robo.rGetName() << ")'s drill was damaged" << std::endl;
			robo.rSetDisabledDigging(true);
		break;
		case -2:
			std::cout << "Robo" << roboNR << "(";
			std::cout << robo.rGetName() << ") was teleported" << std::endl;
			for (int i = 0; i < m_X; ++i) {
				for (int j = 0; j < m_Y; ++j) {
					if(!(m_Matrix[i][j].empty()) && (m_Matrix[i][j].back() < min)){
						min = m_Matrix[i][j].back();
						minX = i;
						minY = j;
					}
				}
			}
			robo.rSetX(minX);
			robo.rSetY(minY);
		break;
		case -3:
			std::cout << "Robo" << roboNR << "(";
			std::cout << robo.rGetName() << ")'s engin was damaged" << std::endl;
			robo.rSetDisabledMovement(true);
		break;
	}
}

bool Map::mIsEmpty(){
	m_isEmpty = true;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(!m_Matrix[i][j].empty())
			{
				m_isEmpty = false;
				break;
			}
		}
	}
	return m_isEmpty;
}

void Map::mSetIsEmpty(bool isEmpty){
	m_isEmpty = isEmpty;
}

bool Map::mGetIsEmpty() const{
	return m_isEmpty;
}

std::list<int> (&Map::mGetMatrix())[5][5] {
	return m_Matrix;
}