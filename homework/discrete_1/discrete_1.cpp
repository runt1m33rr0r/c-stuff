// discrete_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

int parse_roman_one(string digit)
{
	if (digit == "I")
		return 1;
	else if (digit == "V")
		return 5;
	else if (digit == "X")
		return 10;
	else if (digit == "L")
		return 50;
	else if (digit == "C")
		return 100;
	else if (digit == "D")
		return 500;
	else if (digit == "M")
		return 1000;
	else
		return 0;
}

int parse_roman_two(string digit)
{
	if (digit == "IV")
		return 4;
	else if (digit == "IX")
		return 9;
	else if (digit == "XL")
		return 40;
	else if (digit == "XC")
		return 90;
	else if (digit == "CD")
		return 400;
	else if (digit == "CM")
		return 900;
	else
		return 0;
}

void first_task()
{
	string input = "";
	unsigned int result = 0;
	unsigned int current_parsed = 0;

	cout << "roman number: ";
	cin >> input;

	for (int i = 0; i < input.length(); ++i)
	{
		// if we do not exceed the input length, then we try to parse the digit
		if (i <= input.length() - 2 && parse_roman_two(input.substr(i, 2)) != 0)
		{
			result += parse_roman_two(input.substr(i, 2));
			// increment i once more because we parsed by 2
			++i;
		}
		else if (i <= input.length() - 1 && parse_roman_one(input.substr(i, 1)) != 0)
		{
			result += parse_roman_one(input.substr(i, 1));
		}
	}

	cout << "result: " << result << endl << endl;
}

int get_biggest_subtractable(int comparable, int roman_nums[], int nums_length)
{
	int biggest = 0;

	for (int i = 0; i < nums_length; ++i)
	{
		int current_num = roman_nums[i];

		if (current_num <= comparable && current_num > biggest)
		{
			biggest = current_num;
		}
	}

	return biggest;
}

void second_task()
{
	int number = 0;

	cout << "integer: ";
	cin >> number;

	while (number < 1 || number > 3999)
	{
		cout << "The number must be between 1 and 3999!" << endl;
		cout << "integer: ";
		cin >> number;
	}

	const int numbers_count = 13;
	int roman_numbers[numbers_count] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };

	while (number > 0)
	{
		int biggest = get_biggest_subtractable(number, roman_numbers, numbers_count);

		switch (biggest)
		{
		case 1: cout << "I"; break;
		case 4: cout << "IV"; break;
		case 5: cout << "V"; break;
		case 9: cout << "IX"; break;
		case 10: cout << "X"; break;
		case 40: cout << "XL"; break;
		case 50: cout << "L"; break;
		case 90: cout << "XC"; break;
		case 100: cout << "C"; break;
		case 400: cout << "CD"; break;
		case 500: cout << "D"; break;
		case 900: cout << "CM"; break;
		default: cout << "M"; break;
		}

		number -= biggest;
	}
	cout << endl << endl;
}

void third_task()
{
	int to_base = 0, remainder = 0, input = 0, input_saved = 0;
	char symbols[]{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	string output = "";

	cout << "to base: ";
	cin >> to_base;
	cout << "number: ";
	cin >> input;
	input_saved = input;

	if (to_base > 16 || to_base < 2)
	{
		cout << "Invalid to base!" << endl;
		return;
	}

	// converts from base 10 to specified
	do
	{
		remainder = input % to_base;
		output = symbols[remainder] + output;
		input /= to_base;
	} while (input > 0);

	cout << input_saved << "(10)=" << output << "(" << to_base << ")" << endl << endl;
}

int gcd(int a, int b)
{
	while (true)
	{
		if (a == 0)
			return b;
		b %= a;
		if (b == 0)
			return a;
		a %= b;
	}
}

void fourth_task()
{
	int a = 0, b = 0, c = 0;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "c=";
	cin >> c;

	b = gcd(a, b);

	cout << "result: " << gcd(b, c) << endl << endl;
}

int lcm(int a, int b)
{
	int temp = gcd(a, b);

	return temp ? (a / temp * b) : 0;
}

void fifth_task()
{
	int a = 0, b = 0, c = 0;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "c=";
	cin >> c;

	b = lcm(a, b);

	cout << "result: " << lcm(b, c) << endl;
}

int main()
{
	first_task();
	second_task();
	third_task();
	fourth_task();
	fifth_task();

	return 0;
}