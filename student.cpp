#include "student.h"
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>

STUDENT::STUDENT(std::ifstream& file)
{
	file.getline(FIO, m);
	file >> course >> group;
	for (int i{}; i < 5; ++i)
		file >> mars[i];
	file.ignore();
	if (!file.eof())
	{
		char delim_line[255];
		file.getline(delim_line, 255);
	}
}

void STUDENT::print()
{
	std::cout << FIO << '\n';
	std::cout << course << ' ' << group << '\n';
	for (int i{}; i < 5; ++i)
		std::cout << mars[i] << ' ';
	std::cout << '\n';
	std::cout << "------------------\n";
}

int STUDENT::compare(const STUDENT& student)//сортировка по 3 полям 
{
	int result{ -1 };
	if (course > student.course || course == student.course && group > student.group ||
		course == student.course && group == student.group && strcmp(FIO, student.FIO) > 0)
		result = 1;
	else
		if (course == student.course && group == student.group && strcmp(FIO, student.FIO) == 0)
			result = 0;

	return result;
}


int STUDENT::kind()
{
	int min{ mars[0] };
	for (int i{ 1 }; i < 5; ++i)
		if (mars[i] < min)
			min = mars[i];
	return min;
}