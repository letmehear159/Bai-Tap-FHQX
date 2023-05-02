// MergeSort Không ĐQ.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//ID:22110085 
//FULL NAME: Nguyễn Trường
//PURPOSE: MERGE SORT KHÔNG DÙNG ĐỆ QUY 
#include <iostream>
#include<stdlib.h>
void MergeSortNoRecursive(int a[], int n);
void SapXep2Mang(int a[], int& k, int T1[], int T2[], int n1, int n2);
void LuuGiaTriVaoT(int a[], int T1[], int T2[], int& i, int& n1, int& n2, int p, int n);
using namespace std;
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
	MergeSortNoRecursive(a, n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl << 11 / 2;
}
void MergeSortNoRecursive(int a[], int n)
{
	int p = 1;				// p khởi tạo từ 1 
	while (p <= n)			//Nếu p chỉ cần bé hơn hoặc bằng n thì vẫn chạy 
	{
		int k = 0;			//k để làm chỉ số  khi gán giá trị cho mảng a[]
		int n1 = 0, n2 = 0;		//Khởi tạo giá trị của 2 mảng con 
		for (int i = 0; i < n; i++)
		{
			int* T1 = new int[p];
			int* T2 = new int[p];
			LuuGiaTriVaoT(a, T1, T2, i, n1, n2,p,n);		//Lưu giá trị của mỗi mảng với số lượng tối đa là p n1 n2 lưu độ dài mỗi mãng
			SapXep2Mang(a, k, T1, T2, n1, n2);				//Sắp xếp hai mảng T1,T2 vào mảng a[] 
			delete T1;
			delete T2;
		}
		p *= 2;												//Tăng p theo cấp số nhân 1 2 4 8 16;
	}
}
void LuuGiaTriVaoT(int a[],int T1[], int T2[], int &i,int &n1,int &n2,int p,int n)
{
	n1 = 0;
	n2 = 0;
	for (n1=0;n1<p;n1++)
	{
		if (i >= n)				//Nếu i chạy đến n có nghĩa là hết phần tử rồi thì dừng luôn 
		{
			i--;
			return;
		}
		T1[n1] = a[i++];		//Lưu giá trị vào mảng T1
	}
	for (n2 = 0; n2 < p; n2++)	//Nếu i chạy đến n có nghĩa là hết phần tử rồi thì dừng luôn
	{
		if (i >= n)
		{
			i--;
			return;
		}
		T2[n2] = a[i++];     //Lưu giá trị vào mảng T2
	}
	i--;
}
void SapXep2Mang(int a[], int& k, int T1[], int T2[], int n1,int n2)
{
	int i = 0,j=0;
	while (i < n1&&j<n2)
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
