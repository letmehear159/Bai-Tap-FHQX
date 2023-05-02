// ATM Không giới hạn số tiền.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//ID:22110085
//FULL NAME: NGUYỄN TRƯỜNG
//PURPOSE: Bài Toán ATM Không giới hạn số tiền 
#include <iostream>
#include<stdlib.h>
using namespace std;
void docfile(FILE* fp, int& n, int a[]);
void ATMNoLimit(int a[], int n, int k, int soluong[]);
int main()
{
	int P[6];
	int c;
	int n;
	int a[20];
	FILE* fp = NULL;
	docfile(fp, n, a);
	ATMNoLimit(a, n, 10700, P);
	for (int i = 0; i < n; i++)
	{
		cout << a[i]<<"  ";
		cout << P[i] ;
		cout << endl;
	}
	cout << endl;
	
}
//k: Số tiền rút
// soluong: Mảng chứa số lượng tiền mệnh giá mỗi loại
void ATMNoLimit(int a[], int n, int k, int soluong[])
{
	int sodu = k;			
	for (int i = 0; i < n; i++)
	{
		soluong[i] = k / a[i];
		k = k - a[i] * soluong[i];
		if (sodu == 0)
			return;
	}
}
void docfile(FILE* fp, int& n, int a[])
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
			fscanf(fp, "%d", &a[i]);
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
