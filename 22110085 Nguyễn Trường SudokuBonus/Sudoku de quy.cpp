// Sudoku de quy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int Check(int mt[][10], int row, int coloumn, int num);
int sudoku(int mt[][10], int row, int coloumn)
{
    int c;
    int a=0;
    int x = 0;
    if (row == 8 && coloumn == 8 && mt[row][coloumn] != 0)
    {
        return 1;
    }
    else if (row == 8 && coloumn == 8 && mt[row][coloumn] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            c = i;
            x = Check(mt, row, coloumn, i);
            if (x == 1)            //Trường hợp số này hợp lệ 
            {
                mt[row][coloumn] = i;   
                return 1;
            }
        }
    }
    if (mt[row][coloumn] != 0)         //Trường hợp ô này không trống 
    {
        if (coloumn == 8&&row<8)            //Trường hợp ở dòng cột cuối cùng 
        {
            a=sudoku(mt, row + 1, 0);
        }
        else if(row<=8)
        {
            a=sudoku(mt, row, coloumn + 1);
        }
        if (a == 1)
            return 1;
    }
    else if (mt[row][coloumn] == 0)                               //Trường hợp ô trống chưa điền 
    {
        for (int i = 1; i <= 9; i++)
        {
            c = i;
            x = Check(mt, row, coloumn, i);
            if (x == 1)            //Trường hợp số này hợp lệ 
            {
                mt[row][coloumn] = c;
                if (coloumn == 8 && row < 8)            //Trường hợp ở dòng cột cuối cùng 
                {
                   a= sudoku(mt, row + 1, 0);
                }
                else if(row<=8)
                {
                   a= sudoku(mt, row, coloumn + 1);
                }
            }
            if (a == 1)
            {
                mt[row][coloumn] = i;
                return 1;
            }
            mt[row][coloumn] = 0;
        }

    }
    return 0;
}
int main()
{
    int n;
    int mt[10][10];
    FILE* fp = NULL;
    fp = fopen("D:/INPUT.TXT", "r");
    if (fp == NULL)
        cout << "Error to open file" << endl;
    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(fp, "%d", &mt[i][j]);
        }
    } 
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout.width(3);
            cout << mt[i][j];
        }
        cout << endl;
    }
    cout<<endl << "===============================" << endl;
    sudoku(mt, 0, 0);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout.width(3);
            cout << mt[i][j];
        }
        cout << endl;
    }
}
int Check(int mt[][10], int row, int coloumn,int num)
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
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
