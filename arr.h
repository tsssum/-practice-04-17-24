#pragma once
#include "student.h"
using ptrSTUDENT = STUDENT*;

struct ARRAY
{
	ptrSTUDENT* arr;
	size_t size;
	ARRAY() {}
	ARRAY(std::ifstream& file);
	void print();
	void sorting();
	bool to_binary(const char* file_name);
	~ARRAY()//деструктор
	{
		for (size_t i{}; i < size; ++i)
			delete arr[i];
		delete[] arr;
	}
};