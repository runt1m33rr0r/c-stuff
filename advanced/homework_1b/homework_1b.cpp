#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

unsigned CountPrimesInInterval(unsigned start, unsigned end)
{
	if (start == 0)
	{
		return 0;
	}

	vector<bool> prime(end + 1);
	fill(prime.begin(), prime.end(), true);

	for (size_t current = 2; current * current <= end; current++)
	{
		if (prime[current] == true)
		{
			for (size_t multiple = current * 2; multiple <= end; multiple += current)
			{
				prime[multiple] = false;
			}
		}
	}

	unsigned count = 0;
	for (size_t p = start; p < end; p++)
	{
		if (prime[p])
		{
			count++;
		}
	}

	return count;
}

int main()
{
	unsigned b = 0;
	vector<unsigned> inputs {};
	/*while (cin >> b)
	{
		inputs.emplace_back(b);
	}*/

	/*if (inputs.size() == 0)
	{
		cout << 0;
	}*/

	/*for (auto el : inputs)
	{
		cout << CountPrimesInInterval(0, 1000000000) << endl;
	}*/

	cout << CountPrimesInInterval(1, 2001) << endl;

	return 0;
}