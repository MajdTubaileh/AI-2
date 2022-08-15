#pragma once
#include<climits>
#include <utility>
#include<iostream>
class xoClass {
public:
	xoClass();
	xoClass(char board[4][4]);
	~xoClass();
	int checkWin();
	void setWinning(char xOro);
	int play();
	int minmax(bool);
	int wins(char);
	bool is_Over();
	void setWinningFinal(char);
	char operator!()
	{
		if (xOro == 'X')
			return 'O';
		else return 'X';
	}
private:
	char array[4][4];
	char xOro;
	bool turn;
	char toWin;
	enum class xoState { NONE = -2, TIE = 0, WIN, NOTWIN = -1 };
};