// Thi Thử Giữa Kỳ CL2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//ID:22110085
//FULL Name :Nguyễn Trường
//Purpose:Midterm Test Homework 
#include<stdlib.h>
#include <iostream>
using namespace std;
int SoLuongMinTrong1O(int a[][10], int x, int y, int r, int c);
int KiemTraBaiMinHopLe(int a[][10], int r, int c);
int SoLuongMinMaTran(int a[][10], int r, int c);
void VungNhieuMinNhat(int a[][10], int r, int c, int n, int d);
int DemMinTrong1PhamVi(int a[][10], int r, int c, int n, int d, int x, int y);
int main()
{
	int a[10][10];
	int r, c;
	FILE* fp = NULL;
	fp = fopen("D:/INPUT.TXT", "r");
	if (fp == NULL)
	{
		cout << "Error to open file";
		return 0;
	}
	fscanf(fp, "%d", &r);
	fscanf(fp, "%d", &c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			fscanf(fp, "%d", &a[i][j]);
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout.width(3);
			cout << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
	VungNhieuMinNhat(a, r, c, 2, 3);
}
int DemMinTrong1PhamVi(int a[][10], int r, int c, int n, int d, int x, int y)
{
	int t = 0;
	for (int i = x; i <= x + n - 1; i++)
	{
		for (int j = y; j <= y + d - 1; j++)
		{
			if (i >= 0 && i < r && j >= 0 && j < c && a[i][j] == -1)
				t++;
		}
	}
	return t;
}
void VungNhieuMinNhat(int a[][10], int r, int c, int n, int d)
{
	int x, y, t = 0,k;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j< c; j++)
		{
			 k = DemMinTrong1PhamVi(a, r, c, n, d, i, j);
			if (k > t)
			{
				x = i;
				y = j;
				t = k;
			}
		}
	}
	for (int i = x; i <= x + n - 1; i++)
	{
		for (int j = y; j <= y + d - 1; j++)
		{
			cout.width(3);
			cout << a[i][j];
		}
		cout << endl;
	}
	cout << endl << t;
}
int SoLuongMinMaTran(int a[][10], int r, int c)
{
	int t = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] == -1)
				t++;
		}
	}
	return t;
}
int KiemTraBaiMinHopLe(int a[][10], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] == -1)
				continue;
			if (SoLuongMinTrong1O(a, i, j, r, c) != a[i][j])				//Nếu Kiểm tra thấy có khác 
				return -1;
		}
	}
	return 1;
}
int SoLuongMinTrong1O(int a[][10], int x, int y,int r,int c)
{
	int t = 0;
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (i >= 0 && i < r && j >= 0 && j < c && a[i][j] == -1)
				t++;
		}
	}
	return t;
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
