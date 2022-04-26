// lr3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include "Figure.h"
#include <iostream>
#include <fstream>
#include <ostream> 

figure** setAdd(figure** Array, figure* add)
{
	figure** res = new figure * [figure::size];

	if (Array != nullptr)
	{
		for (int i = 0; i < figure::size; i++)
		{
			res[i] = Array[i];
			Array[i] = nullptr;
		}
	}
	res[figure::size] = add;
	res[figure::size]->set();

	figure::size++;

	return res;
}

void cin(int* _x)
{
	while (true)
	{
		std::cin >> *_x;
		if (std::cin.good())
		{
			break;
		}
		std::cout << "invalid input" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	figure** Figures = nullptr;
	int N = 0;

	while (N == 0)
	{
		std::cout << "Меню: ";
		std::cout << "\n11 – Добавить круг";
		std::cout << "\n22 – Добавить прямоугольник";
		std::cout << "\n33 – Добавить трапецию";
		std::cout << "\n44 – Добавить треугольник";
		std::cout << "\n1 – Изменить фигуру";
		std::cout << "\n2 – Удалить фигуру";
		std::cout << "\n3 – Найти площадь";
		std::cout << "\n4 – Найти периметр";
		std::cout << "\n5 – Вывод в файл";
		std::cout << "\n6 – Вывод на консоль";
		std::cout << "\n0 – Выход из программы\n";
		cin(&N);

		switch (N)
		{

		case 0: // Выход
			return 0;

		case 11: 
		{
			Figures = setAdd(Figures, new circle);
		}
		break;

		case 22: 
		{
			Figures = setAdd(Figures, new rectangle);
		}
		break;

		case 33: 
		{
			Figures = setAdd(Figures, new trapezoid);
		}
		break;

		case 44:
		{
			Figures = setAdd(Figures, new triangle);
		}
		break;

		case 1: // Изменение параметров фигуры
		{
			if (figure::size == 0)
			{
				std::cout << "array size is zero!\n";
				break;
			}
			std::cout << "size = " << figure::size << " enter index: " << std::endl;
			int enter = -1;

			while (enter - 1 < 0 || enter - 1 > figure::size - 1)
				cin(&enter);
			enter--;

			Figures[enter]->set();
		}
		break;

		case 2: // Удаление фигуры
		{
			if (figure::size == 0)
			{
				std::cout << "array size is zero!\n";
				break;
			}

			std::cout << "size = " << figure::size << " enter index: " << std::endl;

			int enter = -1;
			while (enter - 1 < 0 || enter - 1 > figure::size - 1)
				cin(&enter);
			enter--;

			delete Figures[enter];
			for (int i = enter; i < figure::size; i++)
			{
				Figures[i] = Figures[i + 1];
			}

			Figures[figure::size] = nullptr;
			figure::size--;


		}
		break;

		case 3: // Нахождение площади фигуры
		{
			if (figure::size == 0)
			{
				std::cout << "array size is zero!\n";
				break;
			}

			std::cout << "size = " << figure::size << " enter index: " << std::endl;

			int enter = -1;
			while (enter - 1 < 0 || enter - 1 > figure::size - 1)
				cin(&enter);
			enter--;

			int n = -1;

			std::cout << "area = " << Figures[enter]->area() << std::endl;
		}
		break;

		case 4: // Нахождение периметра фигуры
		{
			if (figure::size == 0)
			{
				std::cout << "array size is zero!\n";
				break;
			}

			std::cout << "size = " << figure::size << " enter index: " << std::endl;

			int enter = -1;
			while (enter - 1 < 0 || enter - 1 > figure::size - 1)
				cin(&enter);
			enter--;

			int n = -1;

			std::cout << "perimeter = " << Figures[enter]->perimeter() << std::endl;
		}
		break;

		case 5: // Запись данных в файл
		{
			if (figure::size == 0)
			{
				std::cout << "array size is zero!\n";
				break;
			}

			std::ofstream myfile;
			myfile.open("ouput.txt");

			for (int i = 0; i < figure::size; i++)
				Figures[i]->fileout(myfile);

			myfile.close();
		}
		break;

		case 6: // Вывод данных на консоль
		{
			if (figure::size == 0)
			{
				std::cout << "array size is zero!\n";
				break;
			}

			for (int i = 0; i < figure::size; i++)
			{
				std::cout << i + 1 << ") ";
				Figures[i]->printdata();
			}
		}
		break;

		default:
			N = 0;
		}

		N = 0;
	}

	delete[] Figures;
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
