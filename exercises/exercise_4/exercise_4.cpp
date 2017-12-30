// exercise_4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <cmath>

using namespace std;

void first_task()
{
	const unsigned int size = 300;
	char name[size];
	cout << "name: ";
	cin.getline(name, size - 1);

	// encoding
	for (int i = 0; i < size; i++)
	{
		if (name[i] == '/0')
			break;

		bool is_upper = name[i] >= 65 && name[i] <= 87;
		bool is_lower = name[i] >= 97 && name[i] <= 119;
		bool is_last_upper = name[i] >= 88 && name[i] <= 90;
		bool is_last_lower = name[i] >= 120 && name[i] <= 122;

		if (is_upper || is_lower)
		{
			name[i] = name[i] + 3;
		}
		else if (is_last_upper)
		{
			name[i] = 65 + abs(88 - name[i]);
		}
		else if (is_last_lower)
		{
			name[i] = 97 + abs(120 - name[i]);
		}
	}

	cout << name << endl;
}

int main()
{
	//first_task();

	/*float i = 1;
	cout << i << endl;
	cout << &i << endl;*/
	/*int * pnt = new int;
	*pnt = 20;
	cout << pnt << endl << *pnt << endl;*/
	
	/*double dblFirst = 14.4;
	double dblScond = 12.1;
	double *pntFirst, *pntSecond;
	pntFirst = &dblFirst;
	pntSecond = &dblScond;
	
	cout << pntFirst << endl;
	cout << pntFirst + 5 << endl;*/

	/*const int w = 100;
	const int * pt1;
	int * pt2;
	pt1 = &w;
	++pt1;
	pt2 = &w;*/

	/*double x;
	double *pt;
	double **pt_pt;
	pt = &x;
	pt_pt = &pt;
	x = 11.11;
	cout << **pt_pt << endl;*/

	//int i[20] = { 1, 2, 3, 4 };

	//cout << *(&i[0] + 3) << endl;

	/*double *pt;
	double a[10];
	pt = &a[0];
	++pt;
	pt += 4;
	pt = pt - 2;
	pt += 100;
	cout << *pt << endl;*/

	/*double *pt_1, *pt_2;
	double a[10];
	pt_1 = &a[9];
	pt_2 = &a[3];
	cout << (pt_1 - pt_2) << endl;*/

	/*double sum = 0.0, x[10], *pt, *pt_end;
	pt = x;
	pt_end = pt + 10;
	while (pt < pt_end)
		sum += *pt++;
	cout << sum << endl;*/

	/*const int len = 10;
	int arr[len] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int i = 0; i < len; i++)
	{
		cout << &arr[i] << endl;
	}*/
	first_task();

    return 0;
}