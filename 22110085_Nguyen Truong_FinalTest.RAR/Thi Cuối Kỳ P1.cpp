// Thi Cuối Kỳ.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Full Name:Nguyễn Trường
//ID:22110085
//Purpose:Problem 1
//Class:FIE6

#include <iostream>
#include<conio.h>
#include<ctype.h>
using namespace std;

int main()
{
    int n, k;
    do
    {
        do
        {
            cout << "Input value n: ";
            cin >> n;
            cout << endl << "Input value k: ";
            cin >> k;
            if (n <= 0 || n >= 10 || k < 0 || k >= n)
                cout << endl << "Your value is wrong type again!!" << endl;
            else
            {
                int result;
               
                bool check = false;
                int integer = 1;
                while (check == false)
                {
                    int times = 0;
                    int mod = 0;
                    int sub = integer;
                    int count = 0;
                    while (sub > 0)
                    {
                        mod = sub % 10;
                        sub /= 10;
                        times++;
                        if (mod == 0)
                            count++;
                    }
                    if (times == n && count == k)
                    {
                        result = integer;
                        check = true;
                    }
                    integer++;
                }
                cout << endl << result;
            }

        } while (n <= 0 || n >= 10 || k < 0 || k >= n);

        cout << endl << "Press ESC to exit" << endl;
    } while (_getch() != 27);
        
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
