#include "pch.h"
#include <iostream>

using namespace std;

int result = 0;
int depth = 0;
void GCD(int a, int b)
{
	cout << "depth: " << depth << endl
		<< "    a: " << a << endl
		<< "    b: " << b << endl;

	if (a % b > 0)
	{
		depth++;
		/*cout << "depth: " << depth << endl 
			<< "    a: " << a << endl
			<< "    b: " << b << endl;*/

		GCD(b, a % b);

		/*cout << "depth: " << depth << endl
			<< "    a: " << a << endl
			<< "    b: " << b << endl;*/
		depth--;
	}
	else
	{
		result = b;
	}
}

int main()
{
	GCD(7134, 98);
	cout << "result: " << result << endl;
}