// Bài 9 chương 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
using namespace std;
void ThapSangNhi(int n);
void ThapSangBat(int n);
void ThapPhanSangThapLuc(int n);
int main()
{
    int  n;
    cin >> n;
    /* ThapSangNhi(n);*/
    /*cout << endl << ThapSangBat(n) << endl;;
    ThapPhanSangThapLuc(n);*/
    ThapSangBat(n);
}
void ThapSangNhi(int n)
{
    int* H = new int[30];
    long k;
    int i = 0;
    long sum = 0;
    while (n > 0)
    {
        
        k = n % 2;
        H[i] = k;
        i++;
        n /= 2;
    }
   /* for (int j = 0; j < i; j++)
    {
        if (H[j] == 1)
            break;
        else
        {
            for (int k = j; k < i - 1; k++)
            {
                H[k] = H[k + 1];
            }
            i--;
        }
    }*/
    for (int j = i-1; j >=0; j--)
    {
        cout << H[j];
    }
}
void ThapSangBat(int n)
{
    int* H = new int[30];
    int k;
    int i = 0;
    int sum = 0;
    int temp;
    while (n > 0)
    {
        k = n / 8;
        temp = n - k * 8;
        H[i] = temp;
        i++;
        n = k;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        cout << H[j];
    }
}
void ThapPhanSangThapLuc(int n)
{
    int k = n / 16;
    int sodu = n - k * 16;
    if (k > 0)
    {
        ThapPhanSangThapLuc(k);
    }
    if (sodu >= 10)
    {

        switch (sodu)
        {
        case 10:
            cout << "A";
            break;
        case 11:
            cout << "B";
            break;
        case 12:
            cout << "C";
            break;
        case 13:
            cout << "D";
            break;
        case 14:
            cout << "E";
            break;
        case 15:
            cout << "F";
            break;
        }
    }
    else
        cout << sodu;

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
