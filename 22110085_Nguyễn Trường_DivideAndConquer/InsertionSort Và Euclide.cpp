// InsertionSort Và Euclide.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//ID:22110085
//Full name: Nguyễn Trường
//Purpose: Divide and conquer at class 
#include <iostream>
#include<stdlib.h>
using namespace std;
int ucln1(int a, int b);
int ucln2(int a, int b);
void Insert(int a[], int &n, int x);
void InsertionSort(int a[], int n);
void InsertionSortRecursive(int a[], int n);
int ucln3(int a, int b);
int ucln4(int a, int b);
int main()
{
	int a[20];
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

		fscanf(fp, "%d", &a[i]);
	}
	/*InsertionSort(a, n);*/
	/*QuickSort(a, n);*/
	/*for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}*/
	cout << ucln4(255,15);
}
void Insert(int a[], int& n, int x)
{
	int i;
	for (i = n - 1; i >= 0; i--)
	{
		if (x < a[i])
		{
			a[i + 1] = a[i];
		}
		else
			break;
	}
	i++;
	a[i] = x;
	n++;
}
//Đối số thứ 2 là n-1 
void InsertionSortRecursive(int a[], int n)
{
	if (n >= 1)
	{
		InsertionSortRecursive(a, n - 1);
		Insert(a, n, a[n]);
	}
	return;

}
int ucln1(int a, int b)				//Phương pháp trừ 
{
	if (a == b)
		return a;
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if (a > b)
		return ucln1(a - b, b);
	if (a < b)
		return ucln1(a, b - a);
}
int ucln2(int a, int b)
{
	if (a == 0 && b == 0)  //Lỗi 
		return 0;
	else if (a == 0)	// Chia hết 
		return b;
	else if (b == 0)	//Trường hợp đối số =0 thì ucln là a luôn 
		return a;
	if (a >= b)			// Nếu a>=b thì cứ chia như bình thường 
	{
		return ucln2(a % b, b);
	}
	if (b > a)			//Nếu a<b thì đổi vị trí 2 số 
	{
		return ucln2(b % a, a);
	}
}
// Vòng lặp trừ 
int ucln3(int a, int b)
{
	while (0==0)
	{
		if (a == b)
			return a;
		if (a == 0)
			return b;
		if (b == 0)
			return a;
		if (a > b)
			a = a - b;
		if (a < b)
			b = b - a;
	}
}
//Vòng lặp chia lấy phần dư 
int ucln4(int a, int b)
{
	while (0 == 0)
	{
		if (a == 0 && b == 0)  //Lỗi 
			return 0;
		else if (a == 0)	// Chia hết 
			return b;
		else if (b == 0)	//Trường hợp đối số =0 thì ucln là a luôn 
			return a;
		if (a > b)
		{
			a = a % b;
		}
		else if (a < b)
		{
			swap(a, b);
			a = a % b;
		}
	}
}
//Sắp xếp không có đệ quy 
void InsertionSort(int a[], int n)
{
	for (int i = 1; i  <n; i++)
	{
		int t = i;
		Insert(a, t, a[i]);
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
