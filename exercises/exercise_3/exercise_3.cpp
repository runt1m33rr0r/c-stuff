// exercise_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

#define ROWS 4

using namespace std;

void first_task()
{
	int number = 0, number_saved = 0, counter = 0;
	cout << "number: ";
	cin >> number;
	number_saved = number;

	/*do
	{
		number_saved /= 10;
		counter++;
	} while (number_saved > 0);*/
	number = abs(number);
	counter = to_string(number).length();

	unsigned short * arr = new unsigned short[counter];

	for (int i = 0; i < counter; ++i, number /= 10)
		arr[i] = number % 10;

	for (int i = 0; i < counter; ++i)
		cout << arr[counter - i - 1] << " ";
	cout << endl;

	delete[] arr;
}

void second_task()
{
	int a, b, x, y, tmp;
	unsigned int counter = 2;

	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;

	x = abs(a);
	y = abs(b);

	if (x < y)
	{
		x ^= y;
		y ^= x;
		x ^= y;
	}

	tmp = x % y;

	while (tmp)
	{
		x = (tmp > y) ? tmp : y;
		y = (tmp < y) ? tmp : y;
		counter++;
		tmp = x % y;
	}

	unsigned int ** arr = new unsigned int *[ROWS];

	for (unsigned int i = 0; i < ROWS; i++)
	{
		arr[i] = new unsigned int[counter];
	}

	x = abs(a);
	y = abs(b);

	if (x < y)
	{
		x ^= y;
		y ^= x;
		x ^= y;
	}

	arr[0][0] = x;
	arr[0][1] = y;
	arr[1][0] = 0;
	arr[2][0] = 1;
	arr[2][1] = 0;
	arr[3][0] = 0;
	arr[3][1] = 1;

	tmp = x % y;
	unsigned int i = 0;
	while (tmp)
	{
		arr[0][i] = tmp;
		arr[1][i - 1] = x / y;

		x = (tmp > y) ? tmp : y;
		y = (tmp < y) ? tmp : y;
		tmp = x % y;
	}

	for (unsigned int i = 0; i < ROWS; i++)
	{
		for (unsigned int j = 0; j < ROWS; j++)
		{
			cout << arr[i][j] << "\t";
		}
	}

	for (unsigned int i = 0; i < ROWS; i++)
		delete[] arr[i];
	delete[] arr;
} 

int main()
{
	//first_task();
	second_task();
	
    return 0;
}

