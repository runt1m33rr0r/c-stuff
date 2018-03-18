#include "stdafx.h"
#include <iostream>
using namespace std;

class Money
{
private:
	unsigned lv;
	unsigned st;
public:
	Money(unsigned lv = 0, unsigned st = 0) : lv(lv), st(st) {};

	void print();

	Money operator+(const Money &other) const;
	Money operator-(const Money &other) const;
	Money operator*(const Money &other) const;
	Money operator/(const Money &other) const;

	friend double operator%(const double n, const Money &other);

	bool operator>(const Money &other) const;
	bool operator<(const Money &other) const;
	bool operator==(const Money &other) const;
	bool operator!=(const Money &other) const;

	friend istream& operator>>(istream &in, Money &val);
	friend ostream& operator<<(ostream &out, const Money &val);
};

Money Money::operator+(const Money &other) const
{
	unsigned st = this->st + other.st;
	unsigned lv = this->lv + other.lv;
	while (st >= 100)
	{
		lv++;
		st -= 100;
	}
	return Money(lv, st);
}

Money Money::operator-(const Money &other) const
{
	return Money(this->st - other.st, this->lv - other.lv);
}

Money Money::operator*(const Money &other) const
{
	unsigned lv = this->lv * other.lv;
	unsigned st = this->st * other.st;
	while (st >= 100)
	{
		lv++;
		st -= 100;
	}
	return Money(lv, st);
}

Money Money::operator/(const Money &other) const
{
	return Money((unsigned)(this->lv / other.lv), unsigned(this->st / other.st));
}

bool Money::operator>(const Money &other) const
{
	if (this->lv > other.lv)
		return true;

	if (this->st > other.st)
		return true;

	return false;
}

bool Money::operator<(const Money &other) const
{
	if (this->lv < other.lv)
		return true;

	if (this->st < other.st)
		return true;

	return false;
}

bool Money::operator==(const Money &other) const
{
	return this->lv == other.lv && this->st == other.st;
}

bool Money::operator!=(const Money &other) const
{
	return this->lv != other.lv || this->st != other.st;
}

istream& operator>>(istream &in, Money &val)
{
	cout << "lv: ";
	in >> val.lv;
	cout << "st: ";
	in >> val.st;
	return in;
}

ostream& operator<<(ostream &out, const Money &val)
{
	out << "lv: " << val.lv << " st: " << val.st << endl;
	return out;
}

double operator%(const double n, const Money &other)
{
	unsigned lv = other.lv;
	unsigned st = other.st;
	while (lv > 0)
	{
		st += 100;
		lv--;
	}
	return n / st * 100;
}

void Money::print()
{
	cout << "lv: " << this->lv << " st: " << this->st << endl;
}

int main()
{
	Money first;
	Money second(0, 10);
	cin >> first;
	cout << first << endl;
    return 0;
}