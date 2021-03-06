#include "stdafx.h"

#include <iostream>

using namespace std;

void remove_element(unsigned * arr, const unsigned len, unsigned element)
{
	unsigned end_pos = len - 1;
	for (unsigned i = 0; i < len; ++i)
	{
		if (arr[i] == 0)
		{
			end_pos = i;
			break;
		}
	}

	unsigned del_pos = 0;
	for (unsigned i = 0; i <= end_pos; ++i)
	{
		if (arr[i] == element)
		{
			arr[i] = 0;
			del_pos = i;
			break;
		}
	}

	// relocate
	for (unsigned i = del_pos; i <= end_pos; ++i)
	{
		arr[i] = arr[i + 1];
	}
	arr[end_pos] = 0;
}

void add_element(unsigned * arr, const unsigned len, unsigned element)
{
	unsigned end_pos = len - 1;
	for (unsigned i = 0; i < len; ++i)
	{
		if (arr[i] == 0)
		{
			end_pos = i;
			break;
		}
	}

	arr[end_pos] = element;
}

void add_element_at(unsigned * arr, const unsigned len, unsigned element, unsigned pos)
{
	if (pos < 0 && pos > len)
		return;

	if (arr[pos] == 0)
		arr[pos] = element;
}

void change_element_at(unsigned * arr, unsigned pos, unsigned value)
{
	arr[pos] = value;
}

void change_element(unsigned * arr, unsigned len, unsigned search, unsigned value)
{
	for (int i = 0; i < len; ++i)
	{
		if (arr[i] == search)
		{
			arr[i] = value;
			break;
		}
	}
}

void faculty()
{
	unsigned students_count = 1;
	cout << "how many students: ";
	cin >> students_count;

	int * fac_numbers = new int[students_count];
}

int main()
{
	const unsigned len = 10;
	unsigned nums[len] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	remove_element(nums, len, 4);
	remove_element(nums, len, 2);
	add_element(nums, len, 1);

	for (unsigned num : nums)
		cout << num << endl;

	return 0;
}