// Bài toán .cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//ID:22110085
//FULL NAME: NGUYỄN TRƯỜNG
//PURPOSE: Bài Toán tô màu đồ thị 
#include <iostream>
#include <iostream>
#include<stdlib.h>
using namespace std;
void docfile(FILE* fp, int& n, int a[][20]);
void ToMauDoThi(int a[][20], int n);
int main()
{
	int n;
	int a[20][20];
	FILE* fp = NULL;
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
	ToMauDoThi(a, n);
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(3);
			cout << a[i][j];
		}
		cout << endl;
	}
}
//void ToMauDoThi(int a[][10], int n, int k, int x, int y)
//{
//	if (a[x][y] == 1)
//	{
//		bool c = true;
//		for (int i = x - 1; i <= x + 1; i++)
//		{
//			for (int j = y - 1; j <= y + 1; j++)
//			{
//				if (i == x && j == y)
//					continue;
//				if (i >= 0 && i < n && j >= 0 && j < n)
//				{
//					if (a[i][j] == k)
//					{
//						c = false;
//						break;
//					}
//
//				}
//			}
//			if (c == false)
//				break;
//		}
//		if (c == true)
//			a[x][y] = k;
//	}
//	for(int i=)
//}
//Chạy vòng for hết cả ma trận để kiểm tra xem còn ô nào chưa tô mau nữa hay không, Đồng thời gọi hàm đệ quy trong đó 
void ToMauDoThi(int a[][20], int n)
{
	int* H = new int[n * n + 2];					//Cấp phát động cho 1 mảng để lưu màu của 8 ô quanh 1 ô cố định 
	for (int i = 2; i <= n * n; i++)
	{
		H[i] = 0;
	}
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			if (a[x][y] == 1)					//Nếu đây là 1 ô có chưa được tô màu 
			{
				for (int i = x - 1; i <= x + 1; i++)		//Chạy 8 ô xung quanh nó 
				{
					for (int j = y - 1; j <= y + 1; j++)
					{
						if (i == x && j == y)				//
							continue;
						if (i >= 0 && i < n && j >= 0 && j < n )		//Lưu màu của 8 ô xung quanh ô đó vào mảng H
						{
							H[a[i][j]]++;								//Tăng giá trị của mảng lên 1 lần để biết ô đó có xuất hiện ở 1 trong 8 ô xung quanh 
						}
					}
				}
				for (int i = 2; i <= n * n; i++)						//Từ mảng H bắt đầu chạy từ màu bé nhất là 2 trở đi nếu tại chỉ số màu đó không có 
				{														//Thì màu đó không trùng với 8 ô xung quanh ô cố định hiện tại 
					if (H[i] == 0)
					{
						a[x][y] = i;									//Gán ô đó cho màu không bị trùng 
						H[i] = 0;										//Trả giá trị của mảng về 0 
						break;
					}
					else
					{
						H[i] = 0;										//Trả giá trị của mảng về 0 
					}
				}
			}
		}
	}
	delete[] H;															//Xóa mảng được cấp phát động 
}

void docfile(FILE* fp, int& n, int a[][20])
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
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
