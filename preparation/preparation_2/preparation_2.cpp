// preparation_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <ctime>

using namespace std;

#define COLS 4

void left_diag(int [][COLS], int);

void right_diag(int [][COLS], int);

void left_upper_diag(int [][COLS], int);

void left_lower_diag(int [][COLS], int);

void right_upper_diag(int [][COLS], int);

void right_lower_diag(int [][COLS], int);

void print_matr(int [][COLS], int);

void rotate_matr(int[][COLS], int);

int min(int, int);

void matr_task()
{
	int matr[][COLS] = 
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16},
		{17, 18, 19, 20}
	};

	/*
	main diagonal: i == j: for (i = 0; i < N; i++) A[i][i];

	secondary diagonal: i+j == n-1: for (i = 0; i < N; i++) A[i][N-i-1];

	elements above main diagonal: i < j: for (i = 0; i < N; i++) for (j = i + 1; j < N; j++) A[i][j];

	elements below main diagonal: i > j: for (i = 0; i < N; i++) for (j = 0; j < i; j++) A[i][j];

	elements above secondary diagonal: i+j < n-1: for (i = 0; i < N; i++) for (j = 0; j < N-i-1; j++) A[i][j];

	elements below secondary diagonal: i+j > n-1: for (i = 0; i < N; i++) for (j = N-i; j < N; j++) A[i][j];
	*/

	int rows = 5;
	int n = min(rows, COLS);

	/*print_matr(matr, n);
	cout << endl;
	left_diag(matr, n);
	cout << endl;
	right_diag(matr, n);
	cout << endl;
	left_upper_diag(matr, n);
	cout << endl;
	left_lower_diag(matr, n);
	cout << endl;
	right_upper_diag(matr, n);
	cout << endl;
	right_lower_diag(matr, n);
	cout << endl;*/
	
	rotate_matr(matr, rows);
	print_matr(matr, n);
	cout << endl;
}

int get_rand(int min, int max)
{
	return min + (rand() % (max - min + 1));
}

void rand_task()
{
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
		cout << get_rand(1, 5) << endl;
	cout << endl;
}

bool is_prime(int number)
{
	for (int i = 2; i < number; i++)
		if (number % i == 0)
			return false;
	return true;
}

void prime_task()
{
	cout << is_prime(3) << endl;
}

bool is_letter(char symbol)
{
	return (symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z');
}

bool is_upper(char letter)
{
	return is_letter(letter) && letter >= 'A' && letter <= 'Z';
}

void uppercase(char &letter)
{
	letter = letter - 32;
}

void string_task()
{
	char text[] = "deez  nutz";
	int len = strlen(text);

	bool in_word = false;
	for (int i = 0; i < len; i++)
	{
		char &let = text[i];
		if (is_letter(let))
		{
			if (in_word == false && is_upper(let) == false)
			{
				uppercase(let);
			}
			in_word = true;
		}
		else
			in_word = false;
	}

	cout << text << endl;
}

void print_num_triangle(int start, int end) 
{
	static int row = 0;

	cout << start + row;
	int empty_spaces = row - 1;

	if (empty_spaces < 0)
	{
		empty_spaces = 0;
	}

	for (int i = 0; i < empty_spaces; i++)
	{
		cout << " ";
	}

	if (row > 0)
	{
		cout << start + row;
	}
	cout << endl;

	if (row < end - start)
	{
		++row;
		print_num_triangle(start, end);
	}
}

int recursive_sum(int arr[][COLS], int rows)
{
	static int row = 0;
	static int sum = 0;

	if (row > rows - 1)
		return sum;

	for (int col = 0; col < COLS; col++)
		sum += arr[row][col];

	if (row < rows)
		row++;

	return recursive_sum(arr, rows);
}

void print_alpha_triangle(char beg, char end)
{
	static int row = 0;

	for (int i = 0; i < end - beg + 1 - row; i++) 
		cout << ' ';
	for (int i = 0; i < 2 * row + 1; i++)
		cout << (char)(beg + row);
	cout << endl;

	if (row < end - beg) 
	{
		row++;
		print_alpha_triangle(beg, end);
	}
}

void recursion_tasks()
{
	print_alpha_triangle('A', 'D');
	// print_num_triangle(2, 6);

	/*int matr[][COLS] =
	{
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 },
		{ 13, 14, 15, 16 },
		{ 17, 18, 19, 20 }
	};
	int rows = 5;
	cout << recursive_sum(matr, 5) << endl;*/
}

void histogram_task()
{
	const int max_nums = 50;
	char nums[max_nums + 1] = "";
	
	do
	{
		cout << "numbers: ";
		cin.getline(nums, max_nums + 1);
	} while (strlen(nums) < 10 && strlen(nums) > max_nums);

	int histogram[10] = { 0 };
	int len = strlen(nums);
	for (int i = 0; i < len; i++)
		if (nums[i] >= '0' && nums[i] < '9')
			histogram[nums[i] - '0']++;

	for (int i = 0; i < 10; i++)
		cout << i << " : " << histogram[i] << endl;
}

char * string_gen() 
{
	srand(time(NULL));

	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ";
	int length = rand() % 271 + 30; // text length [30, 300]
	char * tmp = new char[length + 1];

	for (int i = 0; i < length; i++) 
	{
		tmp[i] = alphabet[rand() % 54];
	}

	tmp[length] = '\0';
	return tmp;
}

void rand_str_task()
{
	char * str = string_gen();
	cout << str << endl;
	delete[] str;
	str = nullptr;
}

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void bsort(int * arr, int len)
{
	for (int i = 1; i < len; i++)
		for (int j = 0; j < len - i; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}

int main()
{
	const int len = 5;
	int arr[len] = { 1, 8, 4, 2, 20 };
	bsort(arr, len);
	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;
	// matr_task();
	// rand_task();
	// prime_task();
	// string_task();
	// recursion_tasks();
	// histogram_task();
	// rand_str_task();

    return 0;
}

void rotate_matr(int arr[][COLS], int rows) 
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = i; j < COLS; j++)
		{
			int tmp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = tmp;
		}
	}
}


void left_diag(int mat[][COLS], int n)
{
	// for (i = 0; i < N; i++) A[i][i];
	for (int i = 0; i < n; i++)
		cout << mat[i][i] << " ";
	cout << endl;
}

void right_diag(int mat[][COLS], int n)
{
	// for (i = 0; i < N; i++) A[i][N-i-1];
	for (int i = 0; i < n; i++)
		cout << mat[i][n - i - 1] << " ";
	cout << endl;
}

void left_upper_diag(int mat[][COLS], int n)
{
	// for (i = 0; i < N; i++) for (j = i + 1; j < N; j++) A[i][j];
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			cout << mat[i][j] << " ";
	cout << endl;
}

void left_lower_diag(int mat[][COLS], int n)
{
	// for (i = 0; i < N; i++) for (j = 0; j < i; j++) A[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			cout << mat[i][j] << " ";
	cout << endl;
}

void right_upper_diag(int mat[][COLS], int n)
{
	// for (i = 0; i < N; i++) for (j = 0; j < N-i-1; j++) A[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
			cout << mat[i][j] << " ";
	cout << endl;
}

void right_lower_diag(int mat[][COLS], int n)
{
	// for (i = 0; i < N; i++) for (j = N-i; j < N; j++) A[i][j];
	for (int i = 0; i < n; i++)
		for (int j = n - i; j < n; j++)
			cout << mat[i][j] << " ";
	cout << endl;
}

void print_matr(int mat[][COLS], int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < COLS; j++)
			cout << mat[i][j] << "\t";
		cout << endl;
	}
}

int min(int a, int b)
{
	return a > b ? b : a;
}