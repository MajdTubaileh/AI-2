#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"xo.h"
class file {
public:
	file(const std::string&);
	~file();
	float min();
	float max();
private:
	xoClass xoclass;
	char array[4][4];
	std::string string;
	int size;
};
