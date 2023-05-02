// Midterm Test 30-3-23.cpp : This file contains the 'main' function. Program execution begins and ends there.
//// Thi Thử Giữa Kỳ CL2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//ID:22110085
//FULL Name :Nguyễn Trường
//Purpose:Midterm Test 
#include <iostream>
#include<stdio.h>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int CheckConditionWin(int a[][20], int n, int row, int coloumn, int num);
bool CheckSoLuong(int a[][20], int n);
bool CheckValidCaro(int a[][20], int n);
bool CheckGameOver(int a[][20], int n);
int KiemTraCo4DonVi(int a[][20], int n, int row, int coloumn, int k);
void MaximizeRateWin(int a[][20], int n, int k);
int KiemTraCo3DonVi(int a[][20], int n, int row, int coloumn, int k);
int main()
{
	int a[10][20];
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
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(3);
			cout << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
    if (CheckValidCaro(a, n) == true)
        cout << "Caro Game is valid " << endl;
    else 
        cout << "Caro Game is not valid " << endl;
    if (CheckGameOver(a, n) == true)
        cout << "Caro game is over " << endl;
    else
        cout << "Caro game is not over " << endl;
    cout << endl;
    MaximizeRateWin(a, n, 1);
}
int CheckConditionWin(int a[][20], int n, int row, int coloumn, int num)
{
    //TH1 Hàng dọc 
    int i = row;
    int j = row;
    while (a[i][coloumn] == num)i++;
    i--;
    while (a[j][coloumn] == num)j--;
    j++;
    if (i - j + 1 == 5)
        return 1;
    //TH2 Hàng ngang 
    i = coloumn;
    j = coloumn;
    while (a[row][i] == num)i++;
    i--;
    while (a[row][j] == num)j--;
    j++;
    if (i - j + 1 == 5)
        return 1;
    //TH Hàng xiên bên phải
    i = coloumn;
    j = coloumn;
    int  ri = row, rj = row;
    while (a[ri][i] == num)
    {
        i++;
        ri--;
    }
    i--;
    ri++;
    while (a[rj][j] == num)
    {
        j--;
        rj++;
    }
    j++;
    rj--;
    if (i - j + 1 == 5)
        return 1;
    //TH Hàng xiên bên trái 
    i = coloumn;
    j = coloumn;
    ri = row, rj = row;
    while (a[ri][i] == num)
    {
        i++;
        ri++;
    }
    i--;
    ri--;
    while (a[rj][j] == num)
    {
        j--;
        rj--;
    }
    j++;
    rj++;
    if (i - j + 1 == 5)
        return 1;
    return 0;
}
bool CheckSoLuong(int a[][20], int n)
{
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1)
                x++;
            if (a[i][j] == 2)
                y++;
        }
    }
    if (abs(x - y) > 1)
        return false;
    else return true;
}
bool CheckValidCaro(int a[][20], int n)
{
    if (CheckSoLuong(a, n) == false)            //Kiểm tra xem số lượng x và o của 2 người có lệch quá 1 con hay không 
        return false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 1 && a[i][j] != 2 && a[i][j] != 0)
                return false;
        }
    }
    return true;
}
bool CheckGameOver(int a[][20], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                if (CheckConditionWin(a, n, i, j, a[i][j]) == 1)              //Trường hợp đã đủ điều kiện thắng 
                    return true;
            }
        }
    }
    return false;
}
void MaximizeRateWin(int a[][20], int n,int k)
{
    int c = 0;
    for (int i = 0; i < n; i++)                 //Trường hợp có 4 thằng     
    {
        for (int j = 0; j < n; j++)
        {
            c = KiemTraCo4DonVi(a, n, i, j, k);
            if (c == 1)
                return;
        }
    }
    if (c == 0)    //Nếu không có 4 thằng thì thực hiện 3 thằng 
    {
        for (int i = 0; i < n; i++)                 //Trường hợp có 4 thằng     
        {
            for (int j = 0; j < n; j++)
            {
                c = KiemTraCo3DonVi(a, n, i, j, k);
                if (c == 1)
                    return;
            }
        }
    }

}
int KiemTraCo4DonVi(int a[][20], int n, int row, int coloumn,int k)
{
    int num = k;
    //TH1 Hàng dọc 
    int i = row;
    int j = row;
    while (a[i][coloumn] == num)i++;
    i--;
    while (a[j][coloumn] == num)j--;
    j++;
    if (i - j + 1 == 4)
    {
        //4 cho thấy có 4 ô 1 cho thấy là hàng dọc có 4 ô 
        if (a[i + 1][coloumn] == 0 && a[j - 1][coloumn] == 0)               //Trường hợp 2 đầu không bị chặn 
        {
            cout << "Hang: " << i + 1;
            cout << endl << "Dong: " << coloumn;
            return 1;
        }
        if (a[i + 1][coloumn] == 0 && j - 1 < 0)                                      //Trường hợp 1 đầu không bị chặn 1 đầu không có ô trống để đánh 
        {
            cout << "Hang: " << i + 1;
            cout << endl << "Dong: " << coloumn;
            return 1;
        }
        if (a[j - 1][coloumn] == 0 && i + 1 >= n)                             //Trường hợp 1 đầu không bị chặn 1 đầu không có ô trống để đánh 
        {
            cout << "Hang: " << j - 1;
            cout << endl << "Dong: " << coloumn;
            return 1;
        }
        if (a[i + 1][coloumn] == 0 && a[j - 1][coloumn] != 0)               //Bị chặn 1 đầu 
        {
            cout << "Hang: " << i + 1;
            cout << endl << "Dong: " << coloumn;
            return 1;
        }
        if (a[i + 1][coloumn] != 0 && a[j - 1][coloumn] == 0)               //Bị chặn 1 đầu 
        {
            cout << "Hang: " << j - 1;
            cout << endl << "Dong: " << coloumn;
            return 1;
        }
    }
    //TH2 Hàng ngang 
    i = coloumn;
    j = coloumn;
    while (a[row][i] == num)i++;
    i--;
    while (a[row][j] == num)j--;
    j++;
    if (i - j + 1 == 4)
    {
        //4 cho thấy có 4 ô 2 cho thấy là hàng ngang có 4 ô 
        if (a[row][i+1] == 0 && a[row][j-1] == 0)               //Trường hợp 2 đầu không bị chặn 
        {
            cout << "Hang: " << row;
            cout << endl << "Dong: " << i + 1;
            return 1;
        }
        if (a[row][i + 1] == 0 && j - 1 < 0)                                      //Trường hợp 1 đầu không bị chặn 1 đầu không có ô trống để đánh 
        {
            cout << "Hang: " << row;
            cout << endl << "Dong: " << i + 1;
            return 1;
        }
        if (a[row][j - 1] == 0 && i + 1 >= n)                             //Trường hợp 1 đầu không bị chặn 1 đầu không có ô trống để đánh 
        {
            cout << "Hang: " << row;
            cout << endl << "Dong: " << j - 1;
            return 1;
        }
        if (a[row][i + 1] == 0 && a[row][j - 1] != 0)               //Trường hợp 1 đầu không bị chặn 
        {
            cout << "Hang: " << row;
            cout << endl << "Dong: " << i + 1;
            return 1;
        }
        if (a[row][i + 1] != 0 && a[row][j - 1] == 0)               //Trường hợp 1 đầu không bị chặn 
        {
            cout << "Hang: " << row;
            cout << endl << "Dong: " << j - 1;
            return 1;
        }
    }
    //TH Hàng xiên bên phải
    i = coloumn;
    j = coloumn;
    int  ri = row, rj = row;
    while (a[ri][i] == num)
    {
        i++;
        ri--;
    }
    i--;
    while (a[rj][j] == num)
    {
        j--;
        rj++;
    }
    j++;
    if (i - j + 1 == 4)
    {
        if (a[ri][i + 1] == 0 && a[rj][j - 1] == 0)               //Trường hợp 2 đầu không bị chặn 
        {
            cout << "Hang: " << ri;
            cout << endl << "Dong: " << i + 1;
            return 1;
        }
        if (a[ri][i + 1] == 0 && j - 1 < 0)                                      //Trường hợp 1 đầu không bị chặn 1 đầu không có ô trống để đánh 
        {
            cout << "Hang: " << ri;
            cout << endl << "Dong: " << i + 1;
            return 1;
        }
        if (a[rj][j - 1] == 0 && i + 1 >= n)                             //Trường hợp 1 đầu không bị chặn 1 đầu không có ô trống để đánh 
        {
            cout << "Hang: " << rj;
            cout << endl << "Dong: " << j - 1;
            return 1;
        }
        if (a[ri][i + 1] == 0 && a[rj][j - 1] != 0)               //Trường hợp 1 đầu không bị chặn 
        {
            cout << "Hang: " << ri;
            cout << endl << "Dong: " << i + 1;
            return 1;
        }
        if (a[ri][i + 1] != 0 && a[rj][j - 1] == 0)               //Trường hợp 1 đầu không bị chặn 
        {
            cout << "Hang: " << rj;
            cout << endl << "Dong: " << j-1;
            return 1;
        }
    }
    //TH Hàng xiên bên trái 
    i = coloumn;
    j = coloumn;
    ri = row, rj = row;
    while (a[ri][i] == num)
    {
        i++;
        ri++;
    }
    i--;
    while (a[rj][j] == num)
    {
        j--;
        rj--;
    }
    j++;
    if (i - j + 1 == 4)
    {
        if (a[ri][i + 1] == 0 && a[rj][j - 1] == 0)               //Trường hợp 2 đầu không bị chặn 
        {
            cout << "Hang: " << ri;
            cout << endl << "Dong: " << i + 1;
            return 1;
        }
        if (a[ri][i + 1] == 0 && j - 1 < 0)                                      //Trường hợp 1 đầu không bị chặn 1 đầu không có ô trống để đánh 
        {
            cout << "Hang: " << ri;
            cout << endl << "Dong: " << i + 1;
            return 1;
        }
        if (a[rj][j - 1] == 0 && i + 1 >= n)                             //Trường hợp 1 đầu không bị chặn 1 đầu không có ô trống để đánh 
        {
            cout << "Hang: " << rj;
            cout << endl << "Dong: " << j - 1;
            return 1;
        }
        if (a[ri][i + 1] == 0 && a[rj][j - 1] != 0)               //Trường hợp 1 đầu không bị chặn 
        {
            cout << "Hang: " << ri;
            cout << endl << "Dong: " << i + 1;
            return 1;
        }
        if (a[ri][i + 1] != 0 && a[rj][j - 1] == 0)               //Trường hợp 1 đầu không bị chặn 
        {
            cout << "Hang: " << rj;
            cout << endl << "Dong: " << j - 1;
            return 1;
        }
    }
    return 0;
}
int KiemTraCo3DonVi(int a[][20], int n, int row, int coloumn, int k)
{
    int num = k;
    //TH1 Hàng dọc 
    int i = row;
    int j = row;
    while (a[i][coloumn] == num)i++;
    i--;
    while (a[j][coloumn] == num)j--;
    j++;
    if (i - j + 1 == 3)
    {
        //3 cho thấy có 3 ô 1 cho thấy là hàng dọc có 4 ô 
        if (a[i + 1][coloumn] == 0 && a[j - 1][coloumn] == 0)               //Trường hợp 2 đầu không bị chặn 
        {   
            //Nếu thằng đứng cách nó 1 đơn vị nữa mà không có số chặn thì đánh ô đó không thì dánh ngược lại  
            if (a[i + 2][coloumn] == 0 && i + 2 < n)
            {
                cout << "Hang: " << i + 1;
                cout << endl << "Dong: " << coloumn;
                return 1;
            }
            else
            {
                cout << "Hang: " << j-1;
                cout << endl << "Dong: " << coloumn;
                return 1;
            }
          
        }
        if (a[i + 1][coloumn] == 0 && j - 1 < 0)                                      //Trường hợp 1 đầu không bị chặn 1 đầu không có ô trống để đánh 
        {
            cout << "Hang: " << i + 1;
            cout << endl << "Dong: " << coloumn;
            return 1;
        }
        if (a[j - 1][coloumn] == 0 && i + 1 >= n)                             //Trường hợp 1 đầu không bị chặn 1 đầu không có ô trống để đánh 
        {
            cout << "Hang: " << j - 1;
            cout << endl << "Dong: " << coloumn;
            return 1;
        }
        if (a[i + 1][coloumn] == 0 && a[j - 1][coloumn] != 0)               //Bị chặn 1 đầu 
        {
            cout << "Hang: " << i + 1;
            cout << endl << "Dong: " << coloumn;
            return 1;
        }
        if (a[i + 1][coloumn] != 0 && a[j - 1][coloumn] == 0)               //Bị chặn 1 đầu 
        {
            cout << "Hang: " << j - 1;
            cout << endl << "Dong: " << coloumn;
            return 1;
        }
    }
    //TH2 Hàng ngang 
    i = coloumn;
    j = coloumn;
    while (a[row][i] == num)i++;
    i--;
    while (a[row][j] == num)j--;
    j++;
    if (i - j + 1 == 3)
    {
        //4 cho thấy có 4 ô 2 cho thấy là hàng ngang có 4 ô 
        if (a[row][i + 1] == 0 && a[row][j - 1] == 0)               //Trường hợp 2 đầu không bị chặn 
        {
            if (a[row][i + 2] == 0 && i + 2 < n)
            {
                cout << "Hang: " << row;
                cout << endl << "Dong: " << i + 1;
                return 1;
            }
            else
            {
                cout << "Hang: " << row;
                cout << endl << "Dong: " << j-1;
                return 1;
            }
        }
        if (a[row][i + 1] == 0 && j - 1 < 0)                                      //Trường hợp 1 đầu không bị chặn 1 đầu không có ô trống để đánh 
        {
            cout << "Hang: " << row;
            cout << endl << "Dong: " << i + 1;
            return 1;
        }
        if (a[row][j - 1] == 0 && i + 1 >= n)                             //Trường hợp 1 đầu không bị chặn 1 đầu không có ô trống để đánh 
        {
            cout << "Hang: " << row;
            cout << endl << "Dong: " << j - 1;
            return 1;
        }
        if (a[row][i + 1] == 0 && a[row][j - 1] != 0)               //Trường hợp 1 đầu không bị chặn 
        {
            cout << "Hang: " << row;
            cout << endl << "Dong: " << i + 1;
            return 1;
        }
        if (a[row][i + 1] != 0 && a[row][j - 1] == 0)               //Trường hợp 1 đầu không bị chặn 
        {
            cout << "Hang: " << row;
            cout << endl << "Dong: " << j - 1;
            return 1;
        }
    }
    //TH Hàng xiên bên phải
    i = coloumn;
    j = coloumn;
    int  ri = row, rj = row;
    while (a[ri][i] == num)
    {
        i++;
        ri--;
    }
    i--;
    while (a[rj][j] == num)
    {
        j--;
        rj++;
    }
    j++;
    if (i - j + 1 == 3)
    {
        if (a[ri][i + 1] == 0 && a[rj][j - 1] == 0)               //Trường hợp 2 đầu không bị chặn 
        {
            if (a[ri + 1][i + 2] == 0 && i + 2 < n)
            {
            cout << "Hang: " << ri;
            cout << endl << "Dong: " << i + 1;
            return 1;
            }
            else
            {
                cout << "Hang: " << rj;
                cout << endl << "Dong: " << j- 1;
                return 1;
            }

        }
        if (a[ri][i + 1] == 0 && j - 1 < 0)                                      //Trường hợp 1 đầu không bị chặn 1 đầu không có ô trống để đánh 
        {
            cout << "Hang: " << ri;
            cout << endl << "Dong: " << i + 1;
            return 1;
        }
        if (a[rj][j - 1] == 0 && i + 1 >= n)                             //Trường hợp 1 đầu không bị chặn 1 đầu không có ô trống để đánh 
        {
            cout << "Hang: " << rj;
            cout << endl << "Dong: " << j - 1;
            return 1;
        }
        if (a[ri][i + 1] == 0 && a[rj][j - 1] != 0)               //Trường hợp 1 đầu không bị chặn 
        {
            cout << "Hang: " << ri;
            cout << endl << "Dong: " << i + 1;
            return 1;
        }
        if (a[ri][i + 1] != 0 && a[rj][j - 1] == 0)               //Trường hợp 1 đầu không bị chặn 
        {
            cout << "Hang: " << rj;
            cout << endl << "Dong: " << j - 1;
            return 1;
        }
    }
    //TH Hàng xiên bên trái 
    i = coloumn;
    j = coloumn;
    ri = row, rj = row;
    while (a[ri][i] == num)
    {
        i++;
        ri++;
    }
    i--;
    while (a[rj][j] == num)
    {
        j--;
        rj--;
    }
    j++;
    if (i - j + 1 == 3)
    {
        if (a[ri][i + 1] == 0 && a[rj][j - 1] == 0)               //Trường hợp 2 đầu không bị chặn 
        {
            if (a[ri + 1][i + 2] == 0 && i + 2 < n)
            {
                cout << "Hang: " << ri;
                cout << endl << "Dong: " << i + 1;
                return 1;
            }
            else
            {
                cout << "Hang: " << rj;
                cout << endl << "Dong: " << j - 1;
                return 1;
            }
        }
        if (a[ri][i + 1] == 0 && j - 1 < 0)                                      //Trường hợp 1 đầu không bị chặn 1 đầu không có ô trống để đánh 
        {
            cout << "Hang: " << ri;
            cout << endl << "Dong: " << i + 1;
            return 1;
        }
        if (a[rj][j - 1] == 0 && i + 1 >= n)                             //Trường hợp 1 đầu không bị chặn 1 đầu không có ô trống để đánh 
        {
            cout << "Hang: " << rj;
            cout << endl << "Dong: " << j - 1;
            return 1;
        }
        if (a[ri][i + 1] == 0 && a[rj][j - 1] != 0)               //Trường hợp 1 đầu không bị chặn 
        {
            cout << "Hang: " << ri;
            cout << endl << "Dong: " << i + 1;
            return 1;
        }
        if (a[ri][i + 1] != 0 && a[rj][j - 1] == 0)               //Trường hợp 1 đầu không bị chặn 
        {
            cout << "Hang: " << rj;
            cout << endl << "Dong: " << j - 1;
            return 1;
        }
    }
    return 0;
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
