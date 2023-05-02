// Kỹ Thuật quay lui 8 quân Hậu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//ID:22110085 
//FULL NAME: NGUYỄN TRƯỜNG
//Purpose: In tất cả cách đặt quân hậu 
#define M 8
#define W 92
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void CopyOrder(int a[][M], int T[][M], int order);
int CheckDuongDiQuanHau(int a[][M], int x, int y);
int CheckDuplicateWay(int a[][M], int T[][M], int step, int order);
int TamQuanHau(int a[][M], int t, int T[][M]);
void Init(int board[][M])
{
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			board[i][j] = 0;
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
int main()
{
	int a[M][M];
	int T[W][M] = { 0 };
	//int n;
	//FILE* fp = NULL;
	//fp = fopen("D:/INPUT.TXT", "r");
	//if (fp == NULL)
	//{
	//	cout << "Error to open file";
	//	return 0;
	//}
	//fscanf(fp, "%d", &n);
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		fscanf(fp, "%d", &a[i][j]);
	//	}
	//}
	Init(a);
	cout << TamQuanHau(a, 1,T);
	cout << endl;
}
int CheckDuongDiQuanHau(int a[][M], int x, int y)
{
	for (int i = 0; i < M; i++)
	{

		if (a[x][i] != 0)		//Hàng ngang 
			return 0;
		if (a[i][y] != 0)		//Hàng dọc 
			return 0;
	}
	//9 ô xung quanh 
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (i >= 0 && i < M && j >= 0 && j < M)
			{
				if (a[i][j] != 0)
					return 0;
			}
		}
	}
	for (int i = x, j = y; i >= 0 && i < M && j >= 0 && j < M; i++, j++)
	{
		if (a[i][j] != 0)
			return 0;
	}
	for (int i = x, j = y; i >= 0 && i < M && j >= 0 && j < M; i--, j--)
	{
		if (a[i][j] != 0)
			return 0;
	}
	for (int i = x, j = y; i >= 0 && i < M && j >= 0 && j < M; i--, j++)
	{
		if (a[i][j] != 0)
			return 0;
	}
	for (int i = x, j = y; i >= 0 && i < M && j >= 0 && j < M; i++, j--)
	{
		if (a[i][j] != 0)
			return 0;
	}
	return 1;
}
int TamQuanHau(int a[][M], int t,int T[][M])		//Sau Khi thử với con laptop  của em thì với 7 quân hậu trở lên thì chỉ cho ra 8-9 cách 
													//còn lại nó đứng lại và cũng  không trả về 0 hay 1, chờ 1 khoảng lâu thì ra thêm 1 2 cách 
{
	static int order = 0;				//Số lượng cách khác nhau để đặt quân hậu 
	static int ways = 0;
	int c = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (CheckDuongDiQuanHau(a, i, j) == 1)
			{
				a[i][j] = t;			//Đặt quân hậu và ma trận 
				if (t == M)				//Nếu đã đặt đủ tất quả M quân Hậu 
				{
					if (CheckDuplicateWay(a, T, 0, order) == 1)					//Nếu kiểm tra thấy đây là cách mới 
					{
						CopyOrder(a, T, order);	 //Sao chép vị trí và Ma trận T để kiểm tra cho lần sau tránh bị lặp cách 
						order++;				//tăng order lên 1 để chuẩn bị cho cách mới nếu có 
						ways++;
						for (int i = 0; i < M; i++)			//In ra cách mới 
						{
							cout << T[order-1][i] << "  ";
						}				
						cout << endl;
						if (ways == W)			//Nếu đã đủ cách (Mỗi M tương ứng với số lượng lời giải đặt quân hậu khác nhau thì dừng )
							return 1;
					}
					a[i][j] = 0;				//Nếu không đủ tất cả cách thì quay lui làm tiếp 
					return 0;			
				}
				c = TamQuanHau(a, t + 1,T);
				if (c == 1)
					return 1;
				a[i][j] = 0;
			}
		}
	}
	return 0;
}
int CheckDuplicateWay(int a[][M], int T[][M], int step, int order)
{
	//Check 1 lúc hết tất cả các hàng luôn khi mà có 1 trường hợp step tăng lên đến lúc lớn hơn order thì là cách mới 
	//Order là chỉ số lượng hàng liệt kê các cách đi quân hậu đã có từ trước đó 
	int k = 0;					//chỉ số index trong một hàng 
	int c = 0;
	if (step > order)			//Khi step vượt qua order nghĩa là đây là cách mới 
		return 1;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (a[i][j] != 0)
			{
				if (10 * i + j != T[step][k])					//lưu mỗi element là giá trị của vị trí của mỗi quân hậu trong 1 cách đặt quân hậu 
				{
					c = CheckDuplicateWay(a, T, step + 1, order);
				}
				if (c == 1)										//Trường hợp cách mới trả về 1 để copy cách này vào ma trận T 
					return 1;
				k++;
			}
		}
	}
	return 0;								//Khi vị trí các quân hậu trùng với giá trị của 1 hàng thì sẽ không cần kiểm tra tiếp nữa vì cách này đã có rồi 
}
void CopyOrder(int a[][M], int T[][M], int order)
{
	int k = 0;							//chỉ số index trong một hàng 
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (a[i][j] != 0)		//Khi gặp vị trí của quân hậu 
			{
				T[order][k++] = i * 10 + j;			//Copy vị trí quân hậu vào ma trận để có cách mới sau khi kiểm tra trong hàm CheckDuplicate 
			}
		}
	}
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu+		b	0x000000ea5e90f800 {1, 1, 1, 1, 1, 1, 1, 1}	int[8] *

// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
