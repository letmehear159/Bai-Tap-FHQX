// Hình vuông latin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//ID: 22110085 
//Full Name: Nguyễn Trường 
//Purpose: Hình vuông latin 
using namespace std;
#include<stdlib.h>
#include <iostream>
#define M 4
void docfile(FILE* fp, int& n, int a[][M]);
void Show(int board[][M]);
int LatinSquare(int a[][M], int n,int step);
int main()
{
	int n;
	int t=6;
	int a[M][M];
	FILE* fp = NULL;
	docfile(fp, n, a);
	if (LatinSquare(a, n, t) == 0)
		cout << "Error!!!";
	else
	{
		cout << endl;
		Show(a);
	}
	
}
int CheckLatinSquare(int a[][M], int x, int y,int k)
{
	for (int i = 0; i < M; i++)
	{
		if (a[x][i] == k)		//Hàng ngang 
			return 0;
		if (a[i][y] == k)		//Hàng dọc 
			return 0;	
	}
	return 1;
}
int LatinSquare(int a[][M], int n,int step )
{
	int x;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (a[i][j] == 0)
			{
				for (int k = 1; k <= M; k++)
				{
					if (CheckLatinSquare(a, i, j, k) == 1)
					{
						a[i][j] = k;
						step++;
						if (step == M * M)
							return 1;
						x = LatinSquare(a,n, step);
						if (x == 1)
							return 1;
						step--;
						a[i][j] = 0;
					}
				}
			}
		}
	}
	return 0;
}
void Show(int board[][M])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
			printf("%4d", board[i][j]);
		printf("\n\n");
	}
}
void docfile(FILE* fp, int& n, int a[][M])
{
	fp = fopen("D:/INPUT.TXT", "r");
	if (fp == NULL)
	{
		cout << "Error to open file";
		return;
	}
	fscanf(fp, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fscanf(fp, "%d", &a[i][j]);
		}
	}
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
