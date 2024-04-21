#include "arr.h"

ARRAY::ARRAY(std::ifstream& file)
{
	file >> size;
	file.ignore();
	arr = new ptrSTUDENT[size];
	for (size_t i{}; i < size; ++i)
		arr[i] = new STUDENT(file);
	file.close();
}

void ARRAY::print()
{
	for (size_t i{}; i < size; ++i)
		arr[i]->print();

	//std::cout << *arr[i];
}

void ARRAY::sorting()
{
	for (size_t cnt{ size }; cnt >= 2; --cnt)
	{
		for (size_t i{}; i < cnt - 1; ++i)
			if (arr[i]->compare(*arr[i + 1]) > 0)
				std::swap(arr[i], arr[i + 1]);
	}
}

bool ARRAY::to_binary(const char* file_name)
{
	bool res{ 1 };
	std::ofstream file_bin(file_name, std::ios::binary);
	if (!file_bin.is_open())
		res = 0;
	else
	{
		for (size_t i{}; i < size; ++i)
			file_bin.write((char*)arr[i], sizeof(STUDENT)); //ток потому что арр итое само по себе адрес иначе ставить &
		file_bin.close();
	}
	return res;
}

