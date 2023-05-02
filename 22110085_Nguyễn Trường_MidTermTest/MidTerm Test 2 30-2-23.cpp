// MidTerm Test 2 30-2-23.cpp : This file contains the 'main' function. Program execution begins and ends there.
////// Thi Thử Giữa Kỳ CL2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//ID:22110085
//FULL Name :Nguyễn Trường
//Purpose:Midterm Test 

#include <iostream>
#include <stdlib.h>
using namespace std;
bool CheckRITMatrix(int a[][20], int n);
void CreateNPrintIsoMatrix(int a[][20], int b[][20], int n);
bool CheckDecendingMatrix(int b[][20], int n);
int main()
{
	int a[10][20];
	int b[10][20];
	int n;
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
		for (int j = 0; j < 2*n-1; j++)
		{
			fscanf(fp, "%d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n - 1; j++)
		{
			cout.width(3);
			cout << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
	if (CheckRITMatrix(a, n) == true)
		cout << "This Matrix conforms to the structure of reverse isosceles triangle matrix" << endl;
	else 
		cout<< "This Matrix doesnt conform to the structure of reverse isosceles triangle matrix" << endl;
	cout << endl;
	CreateNPrintIsoMatrix(a, b, n);
	cout << endl;
	if (CheckDecendingMatrix(b, n) == true)
		cout << "the last row of the resulting matrix is in descending order " << endl;
	else
		cout << "the last row of the resulting matrix is not in descending order " << endl;
}
bool CheckRITMatrix(int a[][20], int n)
{
	int mid = n - 1;
	int r = 2*n - 2;
	int l = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n - 1; j++)
		{
			if (j >= l && j <= r)
			{
				if (a[i][j] == 0)
					return false;
			}
			else
			{
				if (a[i][j] != 0)
					return false;
			}
		}
		r--;
		l++;
		if (l > r)
			break;	
	}
	return true;
}
void CreateNPrintIsoMatrix(int a[][20], int b[][20], int n)
{
	int mid = n - 1;
	int r = 2 * n - 2;
	int l = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n - 1; j++)
		{
			b[n - i - 1][j] = a[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n - 1; j++)
		{
			cout.width(3);
			cout << b[i][j];
		}
		cout << endl;
	}
}
bool CheckDecendingMatrix(int b[][20], int n)
{
	for (int i = 0; i < 2 * n - 2; i++)
	{
		if (b[n - 1][i] < b[n - 1][i + 1])
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
