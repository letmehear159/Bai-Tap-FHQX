// Thi Giữa Kỳ CL1.cpp : This file contains the 'main' function. Program execution begins and ends there.
////ID:22110085
//FULL Name :Nguyễn Trường
//Purpose:Midterm Test Homework 
#include<stdlib.h>
#include <iostream>
using namespace std;
void docfile(FILE* fp, int& n, int a[][10]);
int Check(int mt[][10], int row, int coloumn, int num);
int SoLanXuatHienCuaX(int a[][10], int n, int x, int H[]);
void DongItOTrongNhat(int a[][10], int n);
int main()
{
    int H[10] = { 0 };
	int Soluong0=0;
	int n;
	int a[10][10];
	FILE* fp = NULL;
	docfile(fp, n, a);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(3);
			cout << a[i][j];
			if (a[i][j] == 0)
			{
				Soluong0++;
			}
		}
		cout << endl;
	}
	cout << (Soluong0 * 100 / 81)<<"%";
    cout <<endl<< SoLanXuatHienCuaX(a, n, 3, H) << endl;
    cout << H[3];
    cout << endl;
    DongItOTrongNhat(a, n);
}
void DongItOTrongNhat(int a[][10], int n)
{
    int H[19] = { 0 };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
            {
                H[i]++;
                H[j + 9]++;
            }
        }
    }
    int min = 9;
    int po = -1;
    for (int i = 0; i < 18; i++)
    {
        if (H[i] <min )
        {
            min= H[i];
            po = i;
        }
    }
    int result;
    if (H[po] == 1)        //Chỉ có 1 ô trống 
    {
        if (po <= 8)        //Nếu là hàng ngang 
        {
         
            for (int i = 1,j=0; i <= 9&&j<n; i++,j++)
            {
                if (Check(a, po, j, i) == 1)
                    result= i;
            }
        }
        else        //Hàng dọc 
        {
            for (int i = 1, j = 0; i <= 9 && j < n; i++, j++)
            {
                if (Check(a, j, po - 9, i) == 1)
                    result = i;
            }
        }
        cout << "Gia tri co the thay the: " << result<<endl;
    }
    if (po <= 8)
        cout << "Hang Thu " << po << endl;
    else
        cout << "Cot thu " << po - 9 << endl;


}
int SoLanXuatHienCuaX(int a[][10], int n, int f,int H[])
{
    int row, coloumn;
    int tx = 0;
    int result=1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            H[a[i][j]]++;
            if (a[i][j] == f)
            {
                a[i][j] = 0;
                if (Check(a, i, j, f) == -1)
                    result = -1;        //Trường hợp số f vi phạm 
                a[i][j] = f;
            }
        }
    }
    return result;
}
void docfile(FILE* fp, int& n, int a[][10])
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
int Check(int mt[][10], int row, int coloumn, int num)
{

    {
        //Kiểm tra hàng 
        for (int i = 0; i < 9; i++)
        {
            if (mt[row][i] == num)
                return -1;
        }
        //Kiểm tra cột 
        for (int i = 0; i < 9; i++)
        {
            if (mt[i][coloumn] == num)
                return -1;
        }
        //Kiểm tra ô vuông 
        if (row >= 0 && row <= 2)
            row = 0;
        else if (row >= 3 && row <= 5)
        {
            row = 3;
        }
        else
        {
            row = 6;
        }
        if (coloumn >= 0 && coloumn <= 2)
            coloumn = 0;
        else if (coloumn >= 3 && coloumn <= 5)
        {
            coloumn = 3;
        }
        else
        {
            coloumn = 6;
        }
        for (int i = row; i < row + 3; i++)
        {
            for (int j = coloumn; j < coloumn + 3; j++)
            {
                if (mt[i][j] == num)
                    return -1;
            }
        }
        return 1;
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
