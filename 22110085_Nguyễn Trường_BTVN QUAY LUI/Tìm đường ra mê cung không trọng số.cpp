// Tìm đường ra mê cung không trọng số.cpp : This file contains the 'main' function. Program execution begins and ends there.
//ID:22110085 
//FULL NAME: NGUYỄN TRƯỜNG
//Purpose: In tất cả đường ra mê cung và in đường đi ngắn nhất không trọng số 
#define M 8
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
void LoiRaMeCung(int a[][M], int P[], int S[], int s, int x, int y, int k, int l);
int KTraDuaVaoK(int a[][M], int x, int y, int k);
void ShowPath(int a[], int n);
void CopyPath(int a[], int b[], int n);
int L;
int main()
{
	int A[20];
	int ShortestPath[20];
	int a[M][M];
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
		for (int j = 0; j < n; j++)
		{
			fscanf(fp, "%d", &a[i][j]);
		}
	}
	LoiRaMeCung(a, A, ShortestPath, 0, 4, 6, 2, 0);
	cout << endl;
	ShowPath(ShortestPath, L);
}
//k : Giá trị để ma trận đi ra trong 4 cạnh 
// x,y vị trí của 1 ô trong ma trận 
//S: mảng chứa đường đi ngắn nhất 
// P: mảng chứa đường đi hiện tại 
//s giá trị để các đường chỉ đi theo giá trị đó 
// l chiều dài của đường đi hiện tại từ đầu =0

void LoiRaMeCung(int a[][M], int P[],int S[],int s,int x,int y,int k,int l )
{
	static int N = 100;		//Chiều dài của đường đi ngắn nhất 
	a[x][y] =s - 1;			//Thay đổi giá trị ô để không lặp lại 
	P[l] = x * 10 + y;		//lưu giá trị của đường đi vào ma trận P 
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (i >= 0 && i < M && j >= 0 && j < M)
			{
				if (a[i][j] == s)	//Nếu đường này đi được 
				{
					if (KTraDuaVaoK(a, i, j, k) == 1)			//Kiểm tra xem đã đến cạnh yêu cầu hay chưa 
					{
						l++;									//Tăng chiều dài đường lên 1 đơn vị để lưu vào đường đi		
						P[l] = 10 * i + j;						//Lưu vào đường đi 
						ShowPath(P, l);							//Khi đã đi ra được in ra con đường đi sau đó trả giá trị về lại như cũ 
						cout << endl;
						if (l <= N)								// Cài lại biến toàn cục cho chiều dài đường đi ít nhất 
						{
							CopyPath(P, S, l);					//Lưu chiều dài ít nhất vào ma trận chứa đường đi ngắn nhất 
							N = l;		
							L = N;
						}
						P[l] = 0;								//Trả giá trị lại về như cũ 
						l--;									//Trả chiều dài về lại ô khởi điểm chạy vòng lặp 
					}
					else
					{
						LoiRaMeCung(a, P, S, s, i, j, k, l+1);	//Chạy đệ quy 8 ô xung quanh 
					}
				}
			}
		}
	}
	a[x][y] = s;												//Trả giá trị ô về lại khởi điểm (Không chặn ô nữa )
	P[l] = 0;													//Trả giá trị đường đi về lại 0 
}
int KTraDuaVaoK(int a[][M], int x, int y, int k)
{
	if (k == 0)			//Cạnh trái 
	{
		if (y == 0)
			return 1;
	}
	else if (k == 1)		//Cạnh trên 
	{
		if (x == 0)
			return 1;
	}
	else if (k == 2)		//Cạnh phải 
	{
		if (y == M - 1)
			return 1;
	}
	else if (k == 3)	//Cạnh dưới 
	{
		if (x == M - 1)
			return 1;
	}
	return 0;
}
void ShowPath(int a[], int n)
{
	for (int i = 0; i <= n; i++)			//In ra đường đi 
	{
		cout <<"("<< a[i] / 10;
		cout << "," << a[i] % 10 << ")";
		cout << "->";
	}
	cout << "Da Ra ngoai";
}
void CopyPath(int a[], int b[], int n)
{
	for (int i = 0; i <= n; i++)
	{
		b[i] = 0;
	}
	for (int i = 0; i <= n; i++)
	{
		b[i] = a[i];
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
