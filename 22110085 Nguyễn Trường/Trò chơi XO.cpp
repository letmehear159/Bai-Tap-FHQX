// Trò chơi XO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//Kiểm tra xem điều kiện thắng 
int CheckConditionWin(int a[][20], int n,int row,int coloumn,int num )
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
  int  ri = row,rj=row;
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
//Kiểm tra xem số lượng 2 ô X và O có bằng nhau hay không 
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
            if (a[i][j] == 0)
                y++;
        }
    }
    if (abs(x - y) > 1)
        return false;
    else return true;
}
int main()
{
    int mt[20][20];
    int n;
    FILE* fp =NULL ;
    fp = fopen("D:/INPUT.TXT", "r");
    if (fp == NULL)
        cout << "Error to open file" << endl;
    else
    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(fp, "%d", &mt[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout.width(4);
            cout << mt[i][j];
        }
        cout << endl;
    }
    int a = 0;
    int b = 0;
    cout<< CheckConditionWin(mt, n, 1, 1, mt[1][1]);
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
