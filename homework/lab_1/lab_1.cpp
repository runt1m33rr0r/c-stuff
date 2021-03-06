// lab_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

string lower_string(string input)
{
	string result;
	for (char elem : input)
	{
		result += (char)tolower(elem);
	}
	return result;
}

int main()
{
	string name;
	string first_answer;
	string second_answer;
	bool likes_to_study = false;
	unsigned short year;
	unsigned short term;

	cout << "Hello! What is your name?" << endl;
	cin >> name;
	cout << "Hi, \"" << name << "\". Nice to meet you. How are you?" << endl;
	cin >> first_answer;
	cout << "Do you like to study informatics in NBU?" << endl;
	cin >> second_answer;

	string lower_second = lower_string(second_answer);
	if (lower_second != "yes" && lower_second != "no")
	{
		cout << "Invalid answer!" << endl;
		return 1;
	}
	else 
	{
		if (lower_second == "yes")
		{
			likes_to_study = true;
		}
		else
		{
			likes_to_study = false;
		}
	}

	cout << "Which year are you?" << endl;
	cin >> year;
	cout << "Which term you are in?" << endl;
	cin >> term;
	cout << endl;

	cout << "My name is " << name << endl;
	cout << "I am feeling " << first_answer << endl;
	
	if (likes_to_study)
	{
		cout << "I do like to study informatics in NBU" << endl;
	}
	else
	{
		cout << "I do not like to study informatics in NBU" << endl;
	}

	cout << "I am " << year << " year" << endl;
	cout << "I am " << term << " term" << endl;
	cout << "Bye :)" << endl;

    return 0;
}