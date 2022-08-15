#include"file.h"

int main()
{
	std::cout << "Enter file name :-> ";
	std::string string;
	std::cin >> string;
	file fil = file(string);
	system("pause");
}