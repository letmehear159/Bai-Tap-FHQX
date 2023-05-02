// Đệ Quy Bài Tập.cpp : This file contains the 'main' function. Program execution begins and ends there.
//ID:22110085
//Full name: Nguyễn Trường
//Purpose :Bài tập đệ quy 


#include <iostream>
#include<stdio.h>
using namespace std;
int FindMaxIndex(int a[], int n);
//3.7 Finding the maximum odd number in the array (if any)
int OddRecursion(int a[], int n, int i);
//If there is no odd number, returns 0
//3.8 Check if the array is is ascending order or not
int AscendingArrRecursion(int a[], int n, int i);
//3.9 Sort the array increasingly, using InsertionSort
void SortAscendingArrRecursion(int a[], int n);
//3.10 Checking if all the elements in the array is non-negative
int CheckNonNegativeRecursion(int a[], int n);
//3.11 Find the MCD (Most Common Divident) of 2 integers (4 ways - 2 recursive)
// Tìm ước chung lớn nhất của 2 số nguyên 
int MostCommonForLoop(int a, int b);
int MostCommonWhileLoop(int a, int b);
int MostCommonRecursionDivide(int a, int b, int i);
int MostCommonRecursionSubtract(int a, int b);
//3.12 Check if a positive integer is a prime number or not
int PrimeRecursion(int a, int i);
//3.13 Kiểm tra mảng tăng giảm xen kẽ
int TangGiamXenKe(int a[], int n,int k);
//3.14 Kiểm tra mảng âm dương xen kẽ
int AmDuongXenke(int a[], int n);
//3.15 Kiểm tra mảng đối xứng
int MangDoiXung(int a[], int i,int n);
int main()
{
	int a[10];
	int n;
	FILE* fp = NULL;
	fp = fopen("D:/INPUT.TXT", "r");
	if (fp == NULL)
		cout << "Error to open file";
	else
	{
		fscanf(fp, "%d", &n);
		for (int i = 0; i < n; i++)
		{
			fscanf(fp, "%d", &a[i]);
		}
	}
	cout << MostCommonRecursionSubtract(45,15);
	 /*for (int i = 0; i < n; i++)
		 cout << a[i] << " ";*/
}
int MostCommonForLoop(int a, int b)
{
	
	for (int i = a; i>1; i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			return i;
		}
	}
	return 1;
}
int MostCommonWhileLoop(int a, int b)
{
	int i = a;
	int x;
	while (i>0)
	{
		if (a % i == 0 && b % i == 0)
		{
			return i;
		}
		i--;
	}
	return i;
}
int MostCommonRecursionDivide(int a, int b, int i)			//Truyền Biến i vào bằng a hoặc b
{
	if (i == 0)				//TH 1 trong 2 số bằng 0
	{
		return a + b;
	}
	if (i == 1)
		return 1;
	if (a % i == 0 && b % i == 0)
		return i;
		MostCommonRecursionDivide(a, b, i-1);
}
int MostCommonRecursionSubtract(int a, int b)
{
	if (a == 0 || b == 0)
		return a + b;
	if (a == b)
		return a;
	else if (a != b)
	{
		if (a > b)
			return MostCommonRecursionSubtract(a - b, b);
		else
			return MostCommonRecursionSubtract(a, b - a);
	}

}
void PrintArray(int a[], int n) {
	if (n > 0) {
		cout << a[n - 1] << "  ";		//print last element
		PrintArray(a, n - 1);
	}
}
int OddRecursion(int a[], int n,int i)
{
	
	if (i >= n || n < 0)
		return 0;
	int x;
	x = OddRecursion(a, n, i + 1);
	if (a[i] % 2 != 0 && a[i] > x)
	{
		return a[i];
	}
	else
		return x;
}
int AscendingArrRecursion(int a[], int n, int i)
{
	if (i >= n-1)
		return 1;
	if (a[i] <= a[i + 1])
	{
		return AscendingArrRecursion(a, n, i + 1);
	}
	else
		return 0;
}
void SortAscendingArrRecursion(int a[], int n)
{
	if ( n==0)
		return;
	int i=FindMaxIndex(a, n);
		int t = a[n];
		a[n] = a[i];
		a[i] = t;
		SortAscendingArrRecursion(a, n-1);

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
int FindMaxIndex(int a[], int n)
{
	if (n == 0)
		return 0;
	int x = FindMaxIndex(a, n - 1);
	if (a[x] > a[n])
		return x;
	else
		return n;
}
int CheckNonNegativeRecursion(int a[], int n)
{
	if (n == 0 && a[n] >= 0)
		return 1;
	else if(n == 0 && a[n] < 0)return 0;
	if (a[n] >= 0)
		return CheckNonNegativeRecursion(a, n - 1);
	return 0;
}
int PrimeRecursion(int a,int i)
{
	if (a < 0)
		return -1;
	else if (a == 1||a==0)
		return 0;
	if (i == a)
		return 1;
	if (a % i == 0)
		return 0;
	PrimeRecursion(a, i + 1);

}
int AmDuongXenke(int a[], int n)
{
	if (n == 0)
		return 1;
	if (a[n] * a[n - 1] < 0)
	{
		return AmDuongXenke(a, n - 1);
	}
	else
		return 0;
}
int MangDoiXung(int a[], int i,int n)
{
	if (i >= n)
		return 1;
	if (a[i] == a[n])
		MangDoiXung(a, i + 1, n - 1);
	else
		return 0;
}
int TangGiamXenKe(int a[], int n,int k)
{
	if (k == 0)		//Tìm xem tăng giảm hay giảm tăng 
	{
		if (a[n] > a[n - 1])		
		{
			k = 1;
		}
		else if (a[n] < a[n - 1])
		{
			k = -1;
		}
		else
			return 0;
	}
	if (n == 0)
		return 1;
	if (k == 1)
	{
		if (a[n] > a[n - 1])
			return TangGiamXenKe(a, n-1,-k);
		else
			return 0;
	}
	else if (k == -1)
	{
		if (a[n] < a[n - 1])
			return TangGiamXenKe(a, n-1,-k);
		else
			return 0;
	}
}
// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
