// директива препроцессора
#ifndef Figure_h
#define Figure_h
#include <iostream>
#include <iostream>
#include <fstream>
#define PI 3.1415

void cinn(float* _x)
{
	if (_x != nullptr)
		while (true)
		{
			std::cin >> *_x;
			if (std::cin.good() && *_x > 0) //проверка на отсутствие ошибок ввода - вывода
			{
				break;
			}
			std::cout << "invalid input" << std::endl;
			std::cin.clear();
			std::cin.ignore();
		}
}


class figure
{
public:

	static int size; //для подсчета количества фигур
	virtual float area() = 0;
	virtual float perimeter() = 0;
	virtual void set() = 0;
	void sett();
	virtual void printdata() = 0;
	virtual std::ofstream& fileout(std::ofstream& fp) = 0;
};

int figure::size = 0;

class circle : public figure
{
	float R;

public:

	circle()
	{
		R = 0;
	}

	float area() override final
	{
		return PI * R * R;
	}

	float perimeter() override final
	{
		return 2 * PI * R;
	}

	void set()
	{
		std::cout << "Введите радиус: ";
		float _R = 0;
		while (_R <= 0) 
			cinn(&_R);
		R = _R;
	}

	void printdata() override
	{
		std::cout << "R = " << R << std::endl;
	}

	std::ofstream& fileout(std::ofstream& fp) override
	{
		float Area = area();
		float Perimeter = perimeter();
		fp << "Circle R = " << R << " Area = " << Area << " Perimeter = " << Perimeter << std::endl;
		return fp;
	}
};

class rectangle : public figure
{
	float a;
	float b;

public:

	rectangle()
	{
		a = b = 0;
	}

	void set()
	{
		float _a = 0, _b = 0;
		std::cout << "a: ";
		while (_a <= 0) cinn(&_a);
		std::cout << "b: ";
		while (_b <= 0) cinn(&_b);
		a = _a; b = _b;
	}

	void printdata() override
	{
		std::cout << "a = " << a << " b = " << b << std::endl;
	}

	float area() override
	{
		return a * b;
	}

	float perimeter() override
	{
		return (a + b) * 2;
	}

	std::ofstream& fileout(std::ofstream& fp) override
	{
		float Area = area();
		float Perimeter = perimeter();
		fp << "Rectangle a = " << a << " b = " << b << " Area = " << Area << " Perimeter = " << Perimeter << std::endl;
		return fp;
	}
};

class trapezoid : public figure
{
	float a;
	float b;
	float c;
	float h;

public:

	trapezoid()
	{
		a = b = c = h = 0;
	}

	void set()
	{
		std::cout << "Введите стороны и высоту трапеции: \n";
		float _a = 0, _b = 0, _c = 0, _h = 0;
		std::cout << "a: ";
		while (_a <= 0) cinn(&_a);
		std::cout << "b: ";
		while (_b <= 0) cinn(&_b);
		std::cout << "c: ";
		while (_c <= 0) cinn(&_c);
		std::cout << "h: ";
		while (_h <= 0) cinn(&_h);
		a = _a; b = _b; c = _c; h = _h;
	}
	void printdata() override
	{
		std::cout << "a = " << a << " b = " << b << " c = " << c << " h = " << h << std::endl;
	}

	float area() override
	{
		return ((a + b) * h) / 2;
	}

	float perimeter() override
	{
		return a + b + c + c;
	}

	std::ofstream& fileout(std::ofstream& fp) override
	{
		float Area = area();
		float Perimeter = perimeter();
		fp << "Trapezoid a = " << a << " b = " << b << " c = " << c << " h = " << " Area = " << Area << " Perimeter = " << Perimeter << std::endl;
		return fp;
	}
};

class triangle : public figure
{
	float a;
	float h;

public:

	triangle()
	{
		a = h = 0;
	}

	void set()
	{
		std::cout << "Введите сторону и высоту треугольника: \n";
		float _a = 0, _h = 0;
		std::cout << "a: ";
		while (_a <= 0) cinn(&_a);
		std::cout << "h: ";
		while (_h <= 0) cinn(&_h);
		a = _a; h = _h;
	}
	void printdata() override
	{
		std::cout << "a = " << a << " h = " << h << std::endl;
	}

	float area() override
	{
		return h * a / 2;
	}

	float perimeter() override
	{
		return 2 * (sqrt(a*a - h*h)) + 2 * a;
	}

	std::ofstream& fileout(std::ofstream& fp) override
	{
		float Area = area();
		float Perimeter = perimeter();
		fp << "Triangle a = " << a << " h = " << h << " Area = " << Area << " Perimeter = " << Perimeter << std::endl;
		return fp;
	}
};

// Заканчиваем директивой препроцессора
#endif
