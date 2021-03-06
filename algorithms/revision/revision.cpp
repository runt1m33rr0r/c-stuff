#include "pch.h"
#include <iostream>
#include <chrono>
#include <functional>

using namespace std;

void BubbleSort(int* data, size_t len)
{
	bool swapped = true;
	int iteration = 0;

	while (swapped)
	{
		swapped = false;
		for (size_t i = 0; i < len - iteration - 1; i++)
		{
			if (data[i] > data[i + 1])
			{
				swap(data[i], data[i + 1]);
				swapped = true;
			}
		}
		iteration++;
	}
}

void SelectionSort(int* data, size_t len)
{
	int i, j, minIdx;

	for (i = 0; i < len - 1; i++)
	{
		minIdx = i;
		for (j = i + 1; j < len; j++)
		{
			if (data[j] < data[minIdx])
			{
				minIdx = j;
			}
		}

		swap(data[minIdx], data[i]);
	}
}

void FillArray(int* data, size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		data[i] = i + 1;
	}
}

void FillArrayBackwards(int* data, size_t len)
{
	size_t cachedLen = len;
	for (size_t i = 0; i < len; i++)
	{
		data[i] = cachedLen - i;
	}
}

void PrintArray(int* data, size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		cout << data[i] << ", ";
	}
	cout << endl;
}

void MeasureTime(
	function<void(int*, size_t)> fillFunction, 
	function<void(int*, size_t)> sortFunction,
	int* data,
	size_t len)
{
	fillFunction(data, len);

	auto start = chrono::high_resolution_clock::now();
	sortFunction(data, len);
	auto finish = std::chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = finish - start;

	cout << "sort finished in: " << elapsed.count() << " s" << endl;
}

int main()
{
	size_t len = 100;
	cout << "len: ";
	cin >> len;
	int* data = new int[len];

	cout << "bubble sort with arranged data: " << endl;
	MeasureTime(FillArray, BubbleSort, data, len);
	cout << "-----------------------------------------" << endl;

	cout << "bubble sort with reversed data: " << endl;
	MeasureTime(FillArrayBackwards, BubbleSort, data, len);
	cout << "-----------------------------------------" << endl;

	cout << "selection sort with arranged data: " << endl;
	MeasureTime(FillArray, SelectionSort, data, len);
	cout << "-----------------------------------------" << endl;

	cout << "selection sort with reversed data: " << endl;
	MeasureTime(FillArrayBackwards, SelectionSort, data, len);
	cout << "-----------------------------------------" << endl;

	delete[] data;
}