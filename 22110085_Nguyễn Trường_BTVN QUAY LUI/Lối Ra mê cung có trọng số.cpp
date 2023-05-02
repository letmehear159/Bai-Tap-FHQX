// Lối Ra mê cung có trọng số.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//ID:22110085 
//FULL NAME: NGUYỄN TRƯỜNG
//Purpose: In đường ra mê cung có trọng số nhỏ nhất  
#include <iostream>
#define M 8
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void ShowPath(int a[], int n);
void CopyPath(int a[], int b[], int n);
int KTraDuaVaoK(int a[][M], int x, int y, int k);
void Show(int board[][M]);
void LoiRaMeCung(int a[][M], int P[], int S[], int x, int y, int k, int t, int l);
int L;
int T;
int main()
{
	int A[100];
	int ShortestPath[100];
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
	LoiRaMeCung(a, A, ShortestPath, 4, 5, 0, 0, 0);
	ShowPath(ShortestPath, L);
	cout << endl << "Tong Trong So Be Nhat: " << T;
}
//k : Giá trị để ma trận đi ra trong 4 cạnh 
// x,y vị trí của 1 ô trong ma trận 
//S  mảng chứa đường đi ngắn nhất 
// t: tổng trọng số hiện tại của đường đi đó 
// l: Chiều dài đường đi hiện tại trong mảng P, l đối số đầu tiên là 0.
//P : Mảng hiện tại chứa đường đi 
void LoiRaMeCung(int a[][M], int P[], int S[], int x, int y, int k, int t,int l)
{
	t += a[x][y];
	int c = a[x][y];			//Lưu giữ tạm thời giá trị của ô đó 
	static int N = 1000;		//Tổng trọng số của đường đi ngắn nhất hiện tại 
	a[x][y] = 1000;			//Thay đổi giá trị ô để không lặp lại 
	P[l] = x * 10 + y;		//lưu giá trị của đường đi vào ma trận P 
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (i >= 0 && i < M && j >= 0 && j < M)
			{
				if (a[i][j] < 1000&&(t+a[i][j]<N))							//Đường nào cũng có thể thử miễn sao không bị lặp lại đường trước đó là được và bé hơn 
																			// Tổng trọng số hiện tại 
				{
					if (KTraDuaVaoK(a, i, j, k) == 1&& (t + a[i][j] < N))			//Kiểm tra xem đã đến cạnh yêu cầu hay chưa 
					{
						l++;									//Tăng chiều dài đường lên 1 đơn vị để lưu vào đường đi		
						P[l] = 10 * i + j;						//Lưu vào đường đi 
						CopyPath(P, S, l);						//Lưu chiều dài  vào ma trận chứa tổng trọng số đường đi ngắn nhất 
						N = t+a[i][j];									// Cài lại biến toàn cục cho tổng trọng số đường đi ít nhất 
						L = l;									//Lưu chiều dài của ma trận chứa đường đi ngắn nhất cho biến toàn cục bên ngoài 
						P[l] = 0;								//Trả giá trị lại về như cũ 
						l--;									//Trả chiều dài về lại ô khởi điểm chạy vòng lặp 
						T = N;									
					}
					else
					{
						LoiRaMeCung(a, P, S,  i, j, k, t,l + 1);	//Chạy đệ quy 8 ô xung quanh 
					}
				}
			}
		}
	}
	a[x][y] = c;													//Trả giá trị ô về lại khởi điểm (Không chặn ô nữa )
	P[l] = 0;													//Trả giá trị đường đi về lại 0 
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
		cout << "(" << a[i] / 10;
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
