// discrete_4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

void first_task()
{
	const unsigned int size = 300;
	char text[size];
	int shift = 3;
	cout << "text: ";
	cin.getline(text, size - 1);
	cout << "shift: ";
	cin >> shift;

	for (int i = 0; i < size; i++)
	{
		if (text[i] == '\0')
			break;

		if (!isalpha(text[i]))
			continue;

		char offset = isupper(text[i]) ? 'A' : 'a';
		text[i] = (char)((((text[i] + shift) - offset) % 26) + offset);
	}

	cout << text << endl << endl;
}

void second_task()
{
	const unsigned len = 11;
	char input[len] = { 0 };
	cout << "egn: ";
	cin >> input;

	unsigned x1 = input[0] - '0';
	unsigned x2 = input[1] - '0';
	unsigned x3 = input[2] - '0';
	unsigned x4 = input[3] - '0';
	unsigned x5 = input[4] - '0';
	unsigned x6 = input[5] - '0';
	unsigned x7 = input[6] - '0';
	unsigned x8 = input[7] - '0';
	unsigned x9 = input[8] - '0';
	unsigned x10 = input[9] - '0';

	unsigned ctrl = (2 * x1 + 4 * x2 + 8 * x3 + 5 * x4 + 10 * x5 + 9 * x6 + 7 * x7 + 3 * x8 + 6 * x9) % 11;
	if (ctrl == 10)
		ctrl = 0;

	if (ctrl == x10)
		cout << "valid" << endl;
	else
		cout << "invalid" << endl;
	cout << endl;
}

float random_float(float min, float max) 
{
	return min + ((float)rand() / (float)RAND_MAX) * (max - min);
}

int random_int(int min, int max)
{
	return min + rand() % (max - min + 1);
}

int main()
{
	/*first_task();
	second_task();*/
	/*srand(time(NULL));
	int min = 10;
	int max = 11;
	
	for (int i = 0; i < 10; i++)
	{
		cout << random_float(10, 11) << endl;
	}*/
	//cout << min + rand() % (max - min + 1) << endl;

	/*int len = 5;
	int ** arr = new int *[len];
	for (int i = 0; i < len; i++)
		arr[i] = new int[len];

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			arr[i][j] = j;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	for (int i = 0; i < len; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	const int rows2 = 2, cols2 = 2;
	int arr2[rows2][cols2] = 
	{
		{0, 1},
		{2, 3} 
	};

	const int rows3 = 2, cols3 = 2;
	int arr3[rows3][cols3] =
	{
		{0, 1},
		{2, 3},
	};

	for (int i = 0; i < rows3; i++)
	{
		cout << arr3[rows3 - i - 1][i] << " ";
	}
	cout << endl;

	int arr4[rows2][cols3] = {0};

	for (int i = 0; i < rows2; ++i)
	{
		for (int j = 0; j < cols3; ++j)
		{
			for (int k = 0; k < cols2; ++k)
			{
				arr4[i][j] += arr2[i][k] * arr3[k][j];
			}
		}
	}*/

	/*for (int i = 0; i < rows2; i++)
	{
		for (int j = 0; j < cols3; j++)
		{
			cout << arr4[i][j] << " ";
		}
		cout << endl;
	}*/

	// [i][i] diagon1 <
	// [len - i - 1][len - i - 1] diagon1 >
	// [len - i - 1] diagon2 >
	// [i][len - i - 1] diagon2 <

	// i j if j >= i [i][j] diagon1 up full
	// i j if i >= j [i][j] diagon1 down full
	// i j if i + j <= len - 1 [i][j] diagon2 up full
	// i j if i + j >= len - 1 [i][j] diagon2 down full

	// cols1 == rows2
	// matr3 = rows1 x cols2

	/*for (int i = 0; i < rows2; i++)
	{
		for (int j = 0; j < cols2; j++)
		{
			cout << arr2[j][i] << " ";
		}
		cout << endl;
	}*/
	enum status { pass, fail, absent };

	enum status stud1, stud2, stud3;

	stud1 = pass;

	stud2 = absent;

	stud3 = fail;

	cout << stud1 << " " << stud2 << " " << stud3 << "\n";

	return 0;
}