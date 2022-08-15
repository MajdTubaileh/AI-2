#include"file.h"

file::file(const std::string& string) :
	string(string), size(4)
{
	std::ifstream ifstream;
	ifstream.open(string);
	std::string line;
	int y = 0;
	int X = 0;
	int O = 0;
	
	while (std::getline(ifstream, line))
	{
		for (size_t i = 0; i < size; i++)
		{
			array[y][i] = line[i];
			if (line[i]=='X')
				X++;
			else if (line[i] == 'O')
				O++;
		}
		y++;
	}

	std::cout << "Please enter who to play ! X or O ? -> ";
	char xOro;
	char endend;
	std::cin >> xOro;
	if (xOro == 'x' || xOro == 'o')
	{
		xOro = toupper(xOro);
	}
	xoclass = xoClass(array);
	xoclass.setWinning(xOro);
	xoclass.setWinningFinal(xOro);

	if ((O - X > 1) ||(X-O>1))
	{
		std::cout << "Difference is more than 2 inbetween!"<< std::endl<<" Enter any Key to exit." << std::endl;
		std::cin >> endend;
		exit(0);

	}
	if (O > X)
		xoclass.setWinning('X');
	else if(O < X)
		xoclass.setWinning('O');
	
	while (!xoclass.is_Over())
	{
		xoclass.play();
		xoclass.setWinning(xoclass.operator!());
	}

}

file::~file()
{
}

float file::min()
{
	return 0.0f;
}

float file::max()
{
	return 0.0f;
}
