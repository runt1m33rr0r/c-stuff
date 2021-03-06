#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int base, number;
	cout << "base = ";
	cin >> base;

	if (base < 2 || base > 9)
	{
		cout << "Invalid base!" << endl;
		return 1;
	}

	cout << "number = ";
	cin >> number;
	int initial_number = number;

	vector<int> remainders;
	while (number > 0)
	{
		int remainder = number % base;
		remainders.push_back(remainder);
		number /= base;
	}

	reverse(remainders.begin(), remainders.end());

	cout << initial_number << "(10)=";
	for (int i : remainders)
	{
		cout << i;
	}
	cout << "(" << base << ")" << endl;

    return 0;
}