// discrete_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

void first_task()
{
	const unsigned int length = 256;
	unsigned int prime_count = 0;
	int arr[length] = { 0 };

	for (int i = 2, j = 1; i < length; i++)
	{
		if (arr[i] == 0)
		{
			// mark it
			arr[i] = i;
			prime_count++;

			// delete over it
			for (int j = i * i; j < length; j += i)
			{
				arr[j] = 1;
			}
		}
	}
	cout << "calculated prime numbers count: " << prime_count << endl;

	int n;
	cout << "n: ";
	cin >> n;
	unsigned int cnt_pow = 0, tmp = n;
	for (int i = 2; i < length; i++)
	{
		if (arr[i] != 1 && n % arr[i] == 0)
		{
			while (tmp % i == 0)
			{
				cnt_pow++;
				tmp /= i;
			}
		}
	}

	cout << "Number of prime numbers that divide " << n << ": " << cnt_pow << endl << endl;
}

void find_combinations_until(int arr[], int index, int num, int reduced_num)
{
	if (reduced_num < 0)
		return;

	if (reduced_num == 0)
	{
		for (int i = 0; i < index; i++)
		{
			if (i == index - 1)
				cout << arr[i];
			else
				cout << arr[i] << "+";
		}
		cout << endl;
		return;
	}

	int prev = (index == 0) ? 1 : arr[index - 1];

	for (int k = prev; k <= num; k++)
	{
		arr[index] = k;

		find_combinations_until(arr, index + 1, num, reduced_num - k);
	}
}

void second_task()
{
	int n = 0;
	cout << "n: ";
	cin >> n;

	int * arr = new int[n];
	find_combinations_until(arr, 0, n, n);
	delete[] arr;
	arr = NULL;

	cout << endl;
}

void third_task()
{
	const unsigned int length = 2000;
	unsigned int prime_count = 0;
	int arr[length] = { 0 };

	for (int i = 2, j = 1; i < length; i++)
	{
		if (arr[i] == 0)
		{
			// mark it
			arr[i] = i;
			prime_count++;

			// delete over it
			for (int j = i * i; j < length; j += i)
			{
				arr[j] = 1;
			}
		}
	}
	cout << "calculated prime numbers count: " << prime_count << endl;

	int n, pow, div;
	cout << "n: ";
	cin >> n;
	unsigned int cnt_pow = 0, tmp = n;

	cout << "canonical decomposition of " << n << " = ";
	// not using any additional arrays
	for (int i = 2; i < length; i++)
	{
		cnt_pow = 0;
		if (arr[i] != 1 && n % arr[i] == 0)
		{
			div = i;
			while (tmp % i == 0)
			{
				cnt_pow++;
				tmp /= i;
			}
			pow = cnt_pow;

			cout << div << " ^ " << pow << " * ";
		}
	}
	cout << endl;
}

int main()
{
	//first_task();
	//second_task();
	third_task();

	return 0;
}