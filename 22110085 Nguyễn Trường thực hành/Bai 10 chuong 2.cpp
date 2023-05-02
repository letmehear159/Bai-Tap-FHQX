// Bai 10 chuong 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int d, m, y;
    cin >> d >> m >> y;
    if (d < 1 || d>31 || m < 1 || m>12 || y < 1  )
    {
        cout << -1;
        
    }
    else if (m == 2 && y % 4 != 0&&d>28)
    {
        cout << -1;
    }
    else if (m == 2 && y % 4 == 0 && d > 29)
    {
        cout << -1;
    }
    else if ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12))         //31 ngày 
    {
        if (d == 31 && m == 12)
        {
            cout << " " << 1 <<" "<< 1 << " " << y + 1;
        }
        if (d == 31 &&m!=12 )
        {
            cout << " " << 1 <<" "<< m + 1 << " " << y;
        }   
        if (d < 31)
        {
            cout << d + 1 << " " << m << " " << y;
        }
    }
    else if (  (m == 4) || (m == 6) || (m == 9) || (m == 11))
    {
        if (d < 30)
        {
            cout << d + 1 << " " << m << " " << y;
        }
        if (d == 30)
        {
            cout << " " << 1 <<" "<< m + 1 << " " << y;
        }
    }
    else if (m == 2)
    {
        if (y % 4 == 0)
        {
            if (d ==29)
            {
                cout << " " << 1 <<" "<< m + 1 << " " << y;
            }
            else
                cout << d + 1 << " " << m << " " << y;
        }
        else
        {
            if (d == 28)
            {
                cout << " " << 1 <<" "<< m + 1 << " " << y;
            }
            else
                cout << d + 1 << " " << m << " " << y;
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
