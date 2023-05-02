// Đề thi giữa kỳ 2016.cpp : This file contains the 'main' function. Program execution begins and ends there.
////ID:22110085
//FULL Name :Nguyễn Trường
//Purpose:Midterm Test Homework 

#include<stdlib.h>
#include <iostream>
using namespace std;
void docfile(FILE* fp, int& n, int a[][10]);
int MTHinhThoi(int a[][10], int n, int& total);
int main()
{
	int n;
	int a[10][10];
	FILE *fp = NULL;
	docfile(fp, n, a);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(3);
			cout << a[i][j];
		}
		cout << endl;
	}
	int total=0;
	cout << endl << MTHinhThoi(a, n,total);
	cout << endl << total;
}
void docfile(FILE* fp, int& n, int a[][10])
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
int MTHinhThoi(int a[][10], int n,int &total)
{
	total = 0;
	//Kiểm tra các ô phải khác 0 và bằng 0 hay không 
	int mid = (n - 1) / 2;
	int l = mid, r = mid;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j<l || j>r)				//Các ô bằng 0 
			{
				if (a[i][j] != 0)
					return 0;
			}
			if (j >= l && j <= r)		//Các ô khác 0 
			{
				if (a[i][j] == 0)
					return 0;
			}
			if (j == r || j == l)
			{
				total += a[i][j];
			}
		}
		if (i < mid)
		{
			r++;
			l--;
		}
		else
		{
			r--;
			l++;
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

