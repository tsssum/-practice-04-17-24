﻿#include <string>
#include <Windows.h>
#include "student.h"

//лаба 9
//юзать для хранения си строку а не стрингу. 
//1 вар. инициализирующий конструктор сразу вычитывающий информацию.
//2 вар. неиниц. конструктор (всегда вообще писать впринципе совсем всегда (правило хорошего тона)) и отдельно метод рид
//3 вар. (посмотрим) перегрузить операцию ">>" 
// ключ сортировки: мы можем менять но щас она даст. напишем компоратор (сравнение). просто сравнивать структуры нельзя. 
//1. структура 2. описание контейнера как вектора (будет хранить массив структур + методы) 
//на экзе будут её библиотеки. (там будет всё. не найдём значит тупые.будем писать сами). учимся создавать и подключать
// мейн и две библиотеки: раьота со стьюдентом и с массивом. ток функция создания бинфайла и таска. 
// пользовательсие библиотеки это всегда с кавычками и .h
// рекомендация по созданию: в проекте описываем  структуру и проверяем что всё работает. потом перетаскиваем сущность в библиотеку и подключаем + снова проверем.
//моульное программирование: 1 файл .х(хедер) сначала описание/интерфейс 2 файл .спп реализация

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//STUDENT st;
	//st.inc_course();
	//++st;
	//std::cout << (st) << '\n';// << функция возвращает поток
	std::ifstream file_txt("students.txt");
	if (file_txt)
	{
		int size{};
		file_txt >> size;
		file_txt.ignore();
		STUDENT stud1(file_txt), stud2(file_txt);
		stud1.print();
		std::cout << stud2;
		std::cout << stud1.compare(stud2) << '\n';
		std::cout << stud1.kind() << '\n';
	}
	std::cin.get();
	return 0;
}

//шаблоном написать структуру пейр. медоды кроме конструктора не над. решить задачу: я не поняла какую.ну то что ниже
//шаблоном написать структуру пейр. медоды кроме конструктора не над. решить задачу: я не поняла какую.ну то что ниже
//на экзе нужно вывести частотный словарь нужен пейр фёрст слово секонд частота встречаемости. в файле е более ста слов.