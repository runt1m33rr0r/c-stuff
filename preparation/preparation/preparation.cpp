// preparation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <cmath>
#include <ctime>
#include <string>

using namespace std;

void first_task()
{
	int number = 0, digit = 0, occurences = 0;
	cout << "number: ";
	cin >> number;
	cout << "digit: ";
	cin >> digit;

	number = abs(number);

	while (number)
	{
		if (number % 10 == digit)
			occurences++;
		number /= 10;
	}

	cout << "result: " << occurences << endl << endl;
}

void second_task()
{
	double a1 = 0, d = 0, n = 0, sum = 0;
	cout << "a: ";
	cin >> a1;
	cout << "d: ";
	cin >> d;
	cout << "n: ";
	cin >> n;

	sum = (n / 2) * (2 * a1 + (n - 1) * d);

	cout << "result: " << sum << endl << endl;
}

void third_task()
{
	int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int max = 0;

	for (int num : numbers)
	{
		if (num > max)
			max = num;
	}

	cout << "result: " << max << endl << endl;
}

int random(int min, int max)
{
	static bool first = true;
	if (first)
	{
		srand((unsigned int)time(NULL));
		first = false;
	}
	return min + rand() % (max - min + 1);
}

void fourth_task()
{
	const int length = 50;
	int numbers[length];
	int n = 0, min = 0, max = 0;
	cout << "n: ";
	cin >> n;
	cout << "p: ";
	cin >> min;
	cout << "q: ";
	cin >> max;

	for (int i = 0; i < length; ++i)
	{
		numbers[i] = random(0, 100);
	}

	for (int i = 0; i < n; ++i)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] >= min && numbers[i] < max)
			cout << numbers[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] >= min && numbers[i] < max)
			numbers[i] = numbers[i] * numbers[i];
		else if (numbers[i] < min && numbers[i] >= max)
			numbers[i] += i * i;

		cout << numbers[i] << " ";
	}
	cout << endl << endl;
}

void fifth_task()
{
	const int length = 11;
	int numbers[length] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	int sum = 0;

	for (int i = 0; i < length; i += 2)
	{
		sum += numbers[i];
	}

	cout << "result: " << sum << endl << endl;
}

int index_of(char arr[], const int & arr_len, char & symbol)
{
	int result = 0;
	for (int i = 0; i < arr_len; ++i)
	{
		if (arr[i] == symbol)
			result = i;
	}
	return result;
}

void sixth_task()
{
	const int length = 26;
	char symbols[length] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'X', 'Y', 'Z' };
	char min = 'A';
	char max = 'A';
	int min_index = 0, max_index = 0;
	cout << "N: ";
	cin >> min;
	cout << "K: ";
	cin >> max;

	min_index = index_of(symbols, length, min);
	max_index = index_of(symbols, length, max);

	for (int i = min_index; i <= max_index; ++i)
	{
		cout << symbols[i];
	}
	cout << endl << endl;
}

void seventh_task()
{
	int length = 0, sum = 0;
	double average = 0;
	
	cout << "length: ";
	cin >> length;

	int * arr = new int[length];
	for (int i = 0; i < length; ++i)
	{
		cout << "arr[" << i << "]=";
		cin >> arr[i];
	}

	int min = arr[0], max = arr[0];
	for (int i = 0; i < length; ++i)
	{
		if (arr[i] > max)
			max = arr[i];

		if (arr[i] < min)
			min = arr[i];

		sum += arr[i];
	}

	average = sum / length;
	cout << "min: " << min << endl;
	cout << "max: " << max << endl;
	cout << "average: " << average << endl << endl;
}

void eight_task()
{
	const int length = 26;
	char symbols[length] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'X', 'Y', 'Z' };
	char input = 'A';
	cout << "symbol: ";
	cin >> input;

	int input_index = index_of(symbols, length, input);
	for (int i = 0; i <= input_index; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cout << symbols[j];
		}
		cout << endl;
	}
}

int count_digit(int number, int digit)
{
	int occurences = 0;
	number = abs(number);

	while (number)
	{
		if (number % 10 == digit)
			occurences++;
		number /= 10;
	}

	return occurences;
}

void ninth_task()
{
	const int length = 50;
	int numbers[length];
	int digit = 0, count = 0;
	cout << "digit: ";
	cin >> digit;

	for (int i = 0; i < length; ++i)
	{
		numbers[i] = random(0, 100);

		count += count_digit(numbers[i], digit);
	}

	cout << "result: " << count << endl << endl;
}

void tenth_task()
{
	int n = 0, b = 0, sum = 0;
	cout << "n: ";
	cin >> n;
	cout << "b: ";
	cin >> b;
	int * numbers = new int[n];

	for (int i = 0; i < n; ++i)
	{
		numbers[i] = random(-34, 45);
	}

	for (int i = 0; i < n; ++i)
	{
		int a = numbers[i];
		sum += (5 - n) * a * pow(b, n - i);
	}

	cout << "result: " << sum << endl << endl;
}

void eleventh_task()
{
	const int length = 11;
	int numbers[length] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	bool is_monotonous = false;
	int current = 0, next = 0;

	for (int i = 0; i < length - 1; ++i)
	{
		current = numbers[i];
		next = numbers[i + 1];
		if (current >= next)
		{
			is_monotonous = true;
			break;
		}
		else
		{
			is_monotonous = false;
			break;
		}
	}

	if (is_monotonous)
		cout << "is monotonously decreasing" << endl << endl;
	else
		cout << "is not monotonously decreasing" << endl << endl;
}

void twelveth_task()
{
	const int length = 3;
	int numbers[length] = { 8, 7, 6 };
	bool is_increasing = false;
	int current = 0, next = 0;

	for (int i = 0; i < length - 1; ++i)
	{
		current = numbers[i];
		next = numbers[i + 1];
		if (current <= next)
		{
			is_increasing = true;
			break;
		}
		else
		{
			is_increasing = false;
			break;
		}
	}

	if (is_increasing)
		cout << "is increasing" << endl << endl;
	else
		cout << "is not increasing" << endl << endl;
}

int get_digits_count(int input)
{
	int count = 0;
	input = abs(input);

	while (input)
	{
		input /= 10;
		count++;
	}
	return count;
}

int get_sum_of_digits(int input)
{
	int sum = 0;
	input = abs(input);

	while (input)
	{
		sum += input % 10;
		input /= 10;
	}
	return sum;
}

bool has_digit(int input, int digit)
{
	input = abs(input);

	while (input)
	{
		if (input % 10 == digit)
			return true;
		input /= 10;
	}

	return false;
}

void thirteenth_task()
{
	int input = 0;
	int digits_count = 0;
	int sum_digits_count = 0;
	bool input_has_digit = false;

	do 
	{
		cout << "input: ";
		cin >> input;

		digits_count = get_digits_count(input);
		sum_digits_count = get_digits_count(get_sum_of_digits(input));
	} while (digits_count != 4 || sum_digits_count > 1);

	input_has_digit = has_digit(input, sum_digits_count);
	if (input_has_digit)
		cout << "true" << endl << endl;
	else
		cout << "false" << endl << endl;
}

bool calc_bulls(int question, int input)
{
	string question_str = to_string(question);
	string input_str = to_string(input);
	int bulls = 0;

	for (int i = 0; i < question_str.length() && i < input_str.length(); ++i)
	{
		if (question_str[i] == input_str[i])
			bulls++;
	}
	return bulls;
}

void fourteenth_task()
{
	int bulls = 0, cows = 0, input = 0, input_saved = 0;
	int question = random(1000, 9999);
	//int question = 4271;

	cout << "input: ";
	cin >> input;

	input_saved = input;
	while (input_saved)
	{
		int current = input_saved % 10;
		input_saved /= 10;

		cows += count_digit(question, current);
	}

	bulls = calc_bulls(question, input);

	cout << "bulls: " << bulls << endl << endl;
	cout << "cows: " << cows - bulls << endl << endl;
}

void fifteenth_task()
{
	const int length = 50;
	int numbers[length];

	for (int i = 0; i < length; ++i)
	{
		numbers[i] = random(98, 999);

		cout << numbers[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < length; ++i)
	{
		int num = numbers[i];
		int new_num = 0;
		while (num > 0)
		{
			new_num = new_num * 10 + (num % 10);
			num = num / 10;
		}
		numbers[i] = new_num;
		cout << numbers[i] << " ";
	}
	cout << endl;
}

int main()
{
	//first_task();
	//second_task();
	//third_task();
	//fourth_task();
	//fifth_task();
	//sixth_task();
	//seventh_task();
	//eight_task();
	//ninth_task();
	//tenth_task();
	//eleventh_task();
	//twelveth_task();
	//thirteenth_task();
	//fourteenth_task();
	fifteenth_task();

    return 0;
}