// Thi Cuối Kỳ P2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Thi Cuối Kỳ.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Full Name:Nguyễn Trường
//ID:22110085
//Purpose:Problem 2
//Class:FIE6
#include <iostream>
#include<conio.h>
#include<ctype.h>
using namespace std;
//1. Hàm nhập giá trị cho mảng có n phần tử
void nhapm(int a[], int n);
//2. Hàm in giá trị của mảng ra màn hình
void inm(int a[], int n);
//3: Tìm và in ra số dương chia ít nhất 
void LeastDiv(int a[], int n);
//24. Hàm xóa tất cả các phần tử trùng nhau trong mảng
void xoatrung3(int a[], int& n);
void xoak(int a[], int& n, int k);
int main()
{
    do
    {
        int n;
        int a[100];
        do
        {
            cout << "Type the number of element: ";
            cin >> n;
            if (n <= 0)
                cout << endl<<"You have typed wrong value of n!!! Type again" << endl;
            else
            {
                 nhapm(a, n);
                 inm(a, n);
                 xoatrung3(a, n);
                 inm(a, n);
            }
        } while (n <= 0);
        cout << endl << "Press ESC to exit" << endl;
    } while (_getch() != 27);
}
//1. Hàm nhập giá trị cho mảng có n phần tử
void nhapm(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]: ";
        cin >> a[i];
    }
}
//2. Hàm in giá trị của mảng ra màn hình
void inm(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout <<"  "<< a[i];
    }
    cout << endl;
}
//3: Tìm và in ra số dương chia ít nhất 
void LeastDiv(int a[], int n)
{
    int count;
    int min = 2;
    int result;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = 1; j <= a[i]; j++)
        {
            if (a[i] % j == 0)
                count++;
        }
        if (count <= min)
        {
            min = count;
            result = a[i];
        }
    }
    cout << result << " With " << min << " Divisor";
}
//24. Hàm xóa tất cả các phần tử trùng nhau trong mảng
void xoatrung3(int a[], int& n)
{
    bool check;
    int times = 0;
    for (int i = 0; i < n ; i++)
    {
        check = false;
        times = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                times++;
            }
        }
        for (int k = i + 1; k < n; k++)
        {
            if (times>2)
            {
                if (a[i] == a[k])
                {
                    xoak(a, n, k--);
                    check = true;
                }
              
            }
        }
        if (check == true)
            xoak(a, n, i--);
    }
}

void xoak(int a[], int& n, int k)
{
    for (int i = k; i < n - 1; i++)
        a[i] = a[i + 1];
    n--;
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
