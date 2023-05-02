// MidTerm test ở lớp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdlib.h>
using namespace std;
bool InRange(int a[][10], int n);
bool DuplicateValue(int a[][10], int n);
bool MagicalMatrix(int a[][10], int n);
int main()
{
	int n;
	int a[10][10];
	FILE* fp = NULL;
	fp = fopen("D:/INPUT.TXT", "r");
	if (fp == NULL)
	{
		cout << "Error to open file";
		return 0;
	}
	fscanf(fp, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fscanf(fp, "%2d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(5);
			cout << a[i][j];
		}
		cout << endl;
	}
	if (MagicalMatrix(a, n) == true)
		cout << 1;
	else cout<< 0;
}
bool InRange(int a[][10], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > n * n || a[i][j] < 1)
				return false;
		}
	}
	return true;
}
bool DuplicateValue(int a[][10], int n)
{
	int H[101] = { 0 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			H[a[i][j]]++;
			if (H[a[i][j]] >= 2)
				return true;
		}
	}
	return false;
}
bool MagicalMatrix(int a[][10], int n)
{
	int H[20] = { 0 };
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			H[k] += a[i][j];
			H[2 * n - k - 1] += a[j][i];
		}
		k++;
	}
	for (int i = 0; i < 2 * n - 2; i++)
	{
		if (H[i] != H[i + 1])
			return false;
	}
	return true;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
