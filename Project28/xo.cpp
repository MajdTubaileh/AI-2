#include "xo.h"
#include "file.h"
#include <iostream>

using namespace std;

xoClass::xoClass() :
	turn(true)
{
}

xoClass::xoClass(char board[4][4])
{
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			array[i][j] = board[i][j];
		}
	}
}
xoClass::~xoClass()
{
}
int xoClass::minmax(bool turn)
{
	int result = checkWin();
	if (result != (int)xoState::NONE)
	{
		return result;
	}
	if (turn)
	{
		int bestScore = -50000;
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				if (array[i][j] == '-')
				{
					array[i][j] = xOro;
					int score = minmax(false);
					array[i][j] = '-';
					if (score > bestScore)
					{
						bestScore = score;
					}
					
					

				}
			}
		}
		return bestScore;
	}
	else
	{
		int bestScore = 50000;
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				if (array[i][j] == '-')
				{
					array[i][j] = operator!();
					int score = minmax(true);
					array[i][j] = '-';
					if (score < bestScore)
					{
						bestScore = score;
					}
					

				}
			}
		}
		return bestScore;
	}
}
int xoClass::play()
{
	char end;
	int bestScore = -9000;
	if (xOro != toWin)
		bestScore = 9000;
	std::pair<int, int> best_move;
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (array[i][j] == '-')
			{
				array[i][j] = xOro;
				int score = minmax(false);
				array[i][j] = '-';
				if (xOro == toWin) {
					if (score > bestScore)
					{
						bestScore = score;
						best_move.first = i;
						best_move.second = j;
					}
				}
				else {
					if (score < bestScore)
					{
						bestScore = score;
						best_move.first = i;
						best_move.second = j;
					}
				}
			}
		}
	}
	
	array[best_move.first][best_move.second] = xOro;
	std::cout << "--------------------- " << xOro << " Will be placed at position : ("<<best_move.first<< " , " << best_move.second <<")" << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		std::cout << "{ | ";
		for (size_t j = 0; j < 4; j++)
		{
			std::cout << array[i][j] << " | ";
		}std::cout <<"}" ; std::cout << std::endl;
	}
	std::cout << "---------------" << std::endl;
	std::cout << "---------------------------------------------------------------------\n";

	int v = checkWin();
	if (v != (int)xoState::NONE)
	{
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				array[i][j] = '-';
			}
		}
		if (v == 10)
		{
			std::cout << "--------=================| " << xOro << " | Wins! =================--------" << std::endl;
			std::cout << "Over!, Enter Any Key to exit." << std::endl;
			std::cin >> end;
			exit(0);
			
		}
		else
			if (v == -10)
			{
				std::cout << "--------=================| " << operator!() << "| Wins !=================--------" << std::endl;
				std::cout << "Over!, Enter Any Key to exit." << std::endl;
				std::cin >> end;
				exit(0);
				
			}
			else
				if (v == 0)
				{
					std::cout << "--------=================|  TIE HITS ! |=================--------" << std::endl;
					std::cout << "Over!, Enter Any Key to exit." << std::endl;
					std::cin >> end;
					exit(0);
					
				}
	}
	return v;

}
int xoClass::wins(char x)
{
	if (x == xOro)
		return 10;
	else
		return -10;
}
bool xoClass::is_Over()
{
	int Available = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (array[i][j] == '-') {
				Available++;
			}
		}
	}
	return Available == 0 ? true : false;
}
int xoClass::checkWin()
{

	int result = (int)xoState::NONE;
	for (int i = 0; i < 4; i++) {
		if (array[i][0] != '-' && array[i][0] == array[i][1] &&array[i][0] == array[i][2] &&array[i][0] == array[i][3])
			result = wins(array[i][0]);
	}
	for (int i = 0; i < 4; i++) {
		if (array[0][i] != '-' && array[0][i] == array[1][i] &&array[0][i] == array[2][i] &&array[0][i] == array[3][i])
			result = wins(array[0][i]);
	}
	if (array[0][0] != '-' && array[0][0] == array[1][1] &&array[1][1] == array[2][2] &&array[2][2] == array[3][3])
		result = wins(array[0][0]);
	if (array[0][3] != '-' && array[0][3] == array[1][2] &&array[1][2] == array[2][1] &&array[2][1] == array[3][0])
		result = wins(array[0][3]);

	int Available = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (array[i][j] == '-') {
				Available++;
			}
		}
	}
	if (result == (int)xoState::NONE && Available == 0) {
		return 0;
	}
	else {
		return result;
	}
}

void xoClass::setWinning(char xoro)
{
	xOro = xoro;
}
void xoClass::setWinningFinal(char xoro)
{
	toWin = xoro;
}