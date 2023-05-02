// MergeSort Run tự nhiên.cpp : This file contains the 'main' function. Program execution begins and ends there.
////ID:22110085 
//FULL NAME: Nguyễn Trường
//PURPOSE: MERGE SORT RUN TỰ NHIÊN (CỘNG ĐIỂM) 
#include <iostream>
#include<stdlib.h>
#include <iostream>
using namespace std;
void NaturalMergeSort(int a[], int n);
void LuuMang(int a[], int T[], int& n, int l, int h);
void TronMang(int a[], int& n, int T1[], int n1, int T2[], int n2, int& k);
int main()
{
	int a[50];
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
	NaturalMergeSort(a, n);

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
}
void NaturalMergeSort(int a[], int n)
{
	int r = 1;
	int h;
	int* T1;
	int* T2;
	int n1, n2;
	do
	{
		r = 1;
		int l = 0;
		int k = 0;
		int mid;
		for (int i = 0; i < n; i++)
		{
			if (a[i] > a[i + 1] ||i==n-1 )
			{
				r++;
				if (r % 2 == 0)
				{
					mid = i + 1;
				}
				if (r % 2 != 0)
				{
					T1 = new int[n];
					T2 = new int[n];
					h = i;
					LuuMang(a, T1, n1, l, mid - 1);
					LuuMang(a, T2, n2, mid, h);
					TronMang(a, n, T1, n1, T2, n2, k);
					if (l == 0 && h == n - 1)
						r = 1;
					l = h + 1;
				}
			}
		}
		int i = 0;
		while (a[i] <= a[i + 1]&&i<n)
		{
			i++;
		}
		
	} while (r > 1);
	
}
void LuuMang(int a[], int T[], int& n, int l, int h)
{
	n = 0;
	//n1 hoặc n2 truyền vào có giá trị chạy từ 0;
	for (int i = l; i <= h; i++)
	{
		T[n++] = a[i];
	}
}
void TronMang(int a[], int& n, int T1[], int n1, int T2[], int n2,int &k)
{
	int i = 0, j = 0;
	while (i < n1 && j < n2)
	{
		if (T1[i] < T2[j])
		{
			a[k++] = T1[i++];
		}
		else
		{
			a[k++] = T2[j++];
		}
	}
	while (i < n1)
	{
		a[k++] = T1[i++];
	}
	while (j < n2)
	{
		a[k++] = T2[j++];
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
