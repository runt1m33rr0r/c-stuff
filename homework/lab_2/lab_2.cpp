// lab_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

int main()
{
	int years = 0;
	cout << "How old are you?" << endl;
	cin >> years;

	cout << "You have lived approximately " << (unsigned long long)(years * 365) << " days, "
		<< (unsigned long long)(years * 8760) << " hours and "
		<< (unsigned long long)(years * 525600) << " minutes" << endl;

	return 0;
}