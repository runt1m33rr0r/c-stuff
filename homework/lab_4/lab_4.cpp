#include "stdafx.h"

#include <iostream>

using namespace std;

void first_task()
{
	double first, second, third;

	cout << "a=";
	cin >> first;
	cout << "b=";
	cin >> second;
	cout << "c=";
	cin >> third;

	double min = first, max = first, mid = first;

	if (second < min)
		min = second;

	if (third < min)
		min = third;

	if (second > max)
		max = second;

	if (third > max)
		max = third;

	if ((first == min && second == max) ||
		(second == min || first == max))
		mid = third;

	if ((second == min && third == max) ||
		(third == min && second == max))
		mid = first;

	if ((first == min && third == max) ||
		(third == min && first == max))
		mid = second;

	cout << max << endl << mid << endl << min << endl << endl;
}

void second_task()
{
	double product = 1;
	for (int i = 50; i <= 101; ++i)
	{
		cout << product * i << endl;
		product *= i;
	}

	cout << "product: " << product << endl << endl;
}

void third_task()
{
	int start = 0, counter = 0, current = 0;

	cout << "start: ";
	cin >> start;
	current = start;

	while (counter < 10)
	{
		if (current % 2 == 0 || current % 3 == 0 || current % 5 == 0)
		{
			counter++;
			cout << counter << ":" << current << ((counter < 10) ? ", " : "");
		}

		current++;
	}
	cout << endl << endl;
}

void fourth_task()
{
	int month;
	cout << "month number: ";
	cin >> month;

	switch (month)
	{
		case 1: cout << "31, January" << endl; break;
		case 2: cout << "28, February" << endl; break;
		case 3: cout << "31, March" << endl; break;
		case 4: cout << "30, April" << endl; break;
		case 5: cout << "31, May" << endl; break;
		case 6: cout << "30, June" << endl; break;
		case 7: cout << "31, July" << endl; break;
		case 8: cout << "31, August" << endl; break;
		case 9: cout << "30, September" << endl; break;
		case 10: cout << "31, October" << endl; break;
		case 11: cout << "30, November" << endl; break;
		case 12: cout << "31, December" << endl; break;
		default: cout << "Invalid month!" << endl; break;
	}
}

int main()
{
	first_task();
	second_task();
	third_task();
	fourth_task();

	return 0;
}