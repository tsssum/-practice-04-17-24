#pragma once
#include <iostream>
#include <fstream>
#include <cstring>

using MARKS = int[5];
const int m = 35;
struct STUDENT
{
private:
	char FIO[m];
	int course, group;
	MARKS mars;
public:
	STUDENT() {}
	STUDENT(std::ifstream& file);
	void print();
	int compare(const STUDENT& student);
	int kind();
	int get_course()
	{
		return course;
	}
	void set_FIO(char FIO[])
	{
		strcpy_s(this->FIO, m, FIO);
	}
	STUDENT& operator++()
	{
		course += 1;
		return *this;
	}
	void inc_course()
	{
		course += 1;
	}
	// friend void vasya();
	friend std::ostream& operator << (std::ostream& out, const STUDENT& student);
};

std::ostream& operator << (std::ostream& out, const STUDENT& student)
{
	out << student.FIO << '\n';
	out << student.course << student.group << '\n';
	for (int i{}; i < 5; ++i)
		out << student.mars[i] << ' ';
	out << '\n';
	out << "--------------------------------\n";
	return out;
}