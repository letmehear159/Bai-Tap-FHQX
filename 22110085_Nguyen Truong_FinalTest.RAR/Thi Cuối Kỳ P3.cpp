// Thi Cuối Kỳ P3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//// Thi Cuối Kỳ.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Full Name:Nguyễn Trường
//ID:22110085
//Purpose:Problem 3
//Class:FIE6
#include<conio.h>
#include<ctype.h>
#include <iostream>
using namespace std;
#define MAX 20
//1. Nhập giá trị cho ma trận có kích thước dxc
void nhapmt(int a[][MAX], int n);
//2. Xuất ma trận có kích thước dxc
void inmt(int a[][MAX],int n);
int HollowMatrix(int a[][MAX], int n);
int main()
{
	
	do
	{
		int n;
		int a[8][20];
		do
		{
			cout << "Type the number of row and coloum of maxtrix: ";
			cin >> n;
			if (n <= 0)
				cout << endl << "You have typed wrong value of n!!! Type again" << endl;
			else
			{
				nhapmt(a, n);
				inmt(a, n);
				if (HollowMatrix(a, n) == 1)
					cout << endl << "YES";
				else cout << endl << "NO";
			}
		} while (n <= 0);
		cout << endl << "Press ESC to exit" << endl;
	} while (_getch() != 27);
}
//1. Nhập giá trị cho ma trận có kích thước dxc
void nhapmt(int a[][MAX],int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}
//2. Xuất ma trận có kích thước dxc
void inmt(int a[][MAX],int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout <<"  "<< a[i][j];
		}
		cout << endl;
	}
}
int HollowMatrix(int a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 || i == n - 1)
			{
				if (a[i][j] == 0)
					return 0;
			}
			if (j == 0 || j == n - 1)
			{
				if (a[i][j] == 0)
					return 0;
			}
			if (i > 0 && i < n - 1)
			{
				if (j > 0 && j < n - 1)
				{
					if (a[i][j] != 0)
						return 0;
				}
			}
		}
	}
	return 1;
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
