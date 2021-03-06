// exercise_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

void first_task()
{
	bool is_prime = true;
	int input = 0;
	cout << "integer: ";
	cin >> input;

	if (input < 2)
		is_prime = false;

	for (int i = 2; i <= sqrt(input); ++i)
	{
		if (input % i == 0)
		{
			is_prime = false;
			break;
		}
	}

	if (is_prime)
		cout << "is prime" << endl;
	else
		cout << "is not prime" << endl;
}

void second_task()
{
	const unsigned int length = 255;
	int arr[length + 1]{0};
	
	for (int i = 2, j = 1; i < length + 1; i++)
	{
		if (arr[i] == 0)
		{
			// mark it
			arr[i] = i;

			// delete over i
			for (int j = i * i; j < length + 1; j += i)
			{
				arr[j] = 1;
			}
		}
	}

	for (int i = 2; i < length + 1; i++)
	{
		if (arr[i] > 1)
			cout << arr[i] << ((i == length + 1) ? "" : "\t");
	}
}

void third_task()
{
	int n, p;
	unsigned int counter = 0;
	cin >> n >> p;

	while (n % p == 0)
	{
		counter++;
		n /= p;
	}

	cout << counter << endl;
}

void fourth_task()
{
	int n;
	cin >> n;

	while (n != 0)
	{

	}
}

int main()
{
	//first_task();
	second_task();
	//third_task();
	//fourth_task();

    return 0;
}