// exercises_usual.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

void first_task()
{
	const int number_of_elements = 10;
	int numbers[number_of_elements];

	for (int i = 0; i < number_of_elements; i++)
	{
		do
		{
			cout << "num[" << i << "]=";
			cin >> numbers[i];
		} while (numbers[i] <= -100 || numbers[i] >= 100);
	}

	int sum = 0;
	for (int i = 0; i < number_of_elements; i++)
	{
		cout << "num[" << i << "]=" << numbers[i] << endl;
		sum += numbers[i];
	}

	cout << "Mean value: " << (double)sum / number_of_elements << endl;
}

void second_task()
{
	const int number_of_elements = 10;
	int numbers[number_of_elements];

	for (int i = 0; i < number_of_elements; i++)
	{
		do
		{
			cout << "num[" << i << "]=";
			cin >> numbers[i];
		} while (numbers[i] <= -100 || numbers[i] >= 100);
	}

	int max = numbers[0];
	for (int number : numbers)
	{
		if (max < number)
		{
			max = number;
		}
	}

	cout << "Max value: " << max << endl;
}

void third_task()
{
	const int rows = 2;
	const int cols = 10;
	int numbers[rows][cols] = 
	{
		{0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
		{9, 10, 11, 12, 13, 14, 15, 16, 17, 18}
	};

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << numbers[i][j] << " ";
		}
		cout << endl;
	}
}

void fourth_task()
{
	const int width = 4;
	const int height = 4;
	int space[width][height] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	for (int i = 0; i < width; i++)
	{
		cout << space[i][i] << " ";
	}
	cout << endl;
}

void fifth_task()
{
	const int width = 4;
	const int height = 4;
	int space[width][height] = {
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 },
		{ 13, 14, 15, 16 }
	};

	for (int i = 0; i < width; i++)
	{
		cout << space[i][width - i - 1] << " ";
	}
	cout << endl;
}

int main()
{
	//first_task();
	//second_task();
	//third_task();
	//fourth_task();
	fifth_task();

    return 0;
}