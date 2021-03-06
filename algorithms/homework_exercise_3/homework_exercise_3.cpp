#include "pch.h"
#include <iostream>

using namespace std;

unsigned long long Factorial(unsigned long long number)
{
	/*if (number != 0)
	{
		cout << number << (number == 1 ? "" : "*");
	}*/

	unsigned long long result = number == 0 ? 1 : Factorial(number - 1) * number;

	if (number != 0)
	{
		cout << (number == 1 ? "" : "*") << number;
	}

	return result;
}

int BinarySearch(int data[], int left, int right, int searched)
{
	if (right >= left)
	{
		int mid = (left + right) / 2;
 
		if (data[mid] == searched)
		{
			return mid;
		}

		if (data[mid] > searched)
		{
			return BinarySearch(data, left, mid - 1, searched);
		}

		return BinarySearch(data, mid + 1, right, searched);
	}

	// return -1 if not found
	return -1;
}

int main()
{
	unsigned long long number = 9;

	cout << number << " faktoriel e: ";
	unsigned long long result = Factorial(number);
	cout << " i tova pravi " << result << endl;

	/*const int len = 5;
	int arr[len] = { 1, 2, 3, 4, 5 };
	int searched = 5;
	int idx = BinarySearch(arr, 0, len - 1, searched);
	cout << idx << endl;*/

	return 0;
}