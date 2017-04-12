// lab_02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class ArrayNumbers
{
protected:
	int array[10];

	void rndArray()
	{
		for (int i = 0; i < 10; i++)
		{
			array[i] = rand() % 201 - 100;
		}
	}

public:
	ArrayNumbers()
	{
		rndArray();
	}
	
	void printArray()
	{
		cout << "Массив: ";
		for (int i = 0; i < 10; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}

	virtual void printFormatArray() = 0;
};

class Even : public ArrayNumbers
{
public:
	void printFormatArray()
	{
		cout << "Вывод четных чисел: ";
		for (int i = 0; i < 10; i++)
		{
			if (array[i]%2 == 0)
			{
				cout << array[i] << " ";
			}
		}
		cout << endl;
	}
};

class Odd : public ArrayNumbers
{
public:
	void printFormatArray()
	{
		cout << "Вывод нечетных чисел: ";
		for (int i = 0; i < 10; i++)
		{
			if (abs(array[i] % 2) == 1)
			{
				cout << array[i] << " ";
			}
		}
		cout << endl;
	}
};

class Positive : public ArrayNumbers
{
public:
	void printFormatArray()
	{
		cout << "Вывод положительных чисел: ";
		for (int i = 0; i < 10; i++)
		{
			if (array[i] >= 0)
			{
				cout << array[i] << " ";
			}
		}
		cout << endl;
	}
};

class Negative : public ArrayNumbers
{
public:
	void printFormatArray()
	{
		cout << "Вывод отрицательных чисел: ";
		for (int i = 0; i < 10; i++)
		{
			if (array[i] < 0)
			{
				cout << array[i] << " ";
			}
		}
		cout << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	ArrayNumbers *an[4];
	an[0] = new Even;
	an[1] = new Odd;
	an[2] = new Positive;
	an[3] = new Negative;

	int num = rand() % 4;

	an[num]->printArray();
	an[num]->printFormatArray();
		
	cout << endl;
	return 0;
}