// ATM Có giới hạn.cpp : This file contains the 'main' function. Program execution begins and ends there.
////ID:22110085
//FULL NAME: NGUYỄN TRƯỜNG
//PURPOSE: Bài Toán ATM có giới hạn số tiền 
#include <iostream>
#include<stdlib.h>
using namespace std;
typedef struct GiaTien
{
	int Value;
	int Quantity;
};
void docfile(FILE* fp, int& n, GiaTien a[]);
int  ATMLimit(GiaTien a[], int n, int k, int soluong[]);

int main()
{
	int n;
	GiaTien a[6];
	int P[6]={0};
	FILE* fp = NULL;
	docfile(fp, n, a);
	int c=ATMLimit(a, n, 1900, P);
	if (c == 1)
	{
		for (int i = 0; i < n; i++)
		{
			cout << a[i].Value << "  ";
			cout << P[i];
			cout << endl;
		}
	}
	else
		cout << "So Tien Trong ATM Khong Du?!!!!";
}
int  ATMLimit(GiaTien a[], int n, int k,int soluong[])
{
	for (int i = 0; i < n; i++)
	{
		if (a[i].Quantity * a[i].Value <= k)			//Nếu số tiền rút lớn hơn số tổng số tiền của mệnh giá hiện tại 
		{												//Trả ra hết tất cả số tiền mệnh giá đó 
			soluong[i] = a[i].Quantity;
			k = k - a[i].Quantity * a[i].Value;
		}
		else											//Nếu số tiền rút bé hơn tổng số tiền mệnh giá hiện tại 
		{
			soluong[i] = k / a[i].Value;				//Lấy số lượng tiền mệnh giá đó nhiều nhất có thể 
			k = k - a[i].Value * soluong[i];
		}
		if (k == 0)										//Nếu số tiền trong ATM đủ để chi trả 
			return 1;
	}
	if (k > 0)											//Nếu số tiền trong ATM không đủ để chi trả 
		return 0;

}
void docfile(FILE* fp, int& n, GiaTien a[])
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
		fscanf(fp, "%d", &a[i].Value);
		fscanf(fp, "%d", &a[i].Quantity);
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
