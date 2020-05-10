// ќбработка массива.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <locale>
#include <time.h>

using namespace std;

void sort(int*, int, int);
void print(int*, int);
int process(int*, int*, int); // возвращает количество неповтор€ющихс€ значений

int main()
{
	setlocale(LC_ALL, "");
	int* a;
	int n;
	cout << "«адайте длину массива ";
	cin >> n;
	a = new int[n];
	srand((int)time(0));
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10;
	cout << "»сходный массив:" << endl;
	print(a, n);
	sort(a, 0, n - 1);
	cout << "ќтсортированный массив:" << endl;
	print(a, n);
	int *b = new int[n];
	int count = process(a, b, n);
	cout << "ћассив неповтор€ющихс€ значений:" << endl;
	print(b, count);
	_getch();
	return 0;
}

void sort(int* a, int L, int R)
{
	int x = a[(L + R) >> 1];
	int i = L, j = R;
	do
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			++i; --j;
		}
	} while (i <= j);
	if (i < R)
		sort(a, i, R);
	if (j > L)
		sort(a, L, j);
}

void print(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int process(int* a, int* b, int n)
{
	int count = 0;	// число неповтор€ющихс€ значений
	int j;			// длина серии
	for (int i = 0; i < n; i += j)
	{
		int x = a[i];
		if (a[i + 1] == x)
		{			// пропустить серию
			j = 1;
			while (a[i + j] == x) j++;
		}
		else
		{			// записать неповтор€ющеес€ значение
			b[count] = x;
			++count;
			j = 1;
		}
	}
	return count;
}
