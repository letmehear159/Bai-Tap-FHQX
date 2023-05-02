// Bai 12 chuong 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void docfile(FILE* fp, int& n, int a[][20]);
int SoLuongMinTrong1O(int a[][20], int x, int y, int r, int c);
int main()
{
	int a[20][20];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 1)
			{
				a[i][j] = -1;
			}
		}
		cout << endl;
	}
	cout<<endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] != -1)
			{
				a[i][j] = SoLuongMinTrong1O(a, i, j, n, n);
			}
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
void PrintMatrix(int mt[][20])
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			cout.width(3);
			cout << mt[i][j];
			cout.width(3);
		}
		cout << endl;
	}
}
void CountMine(int mt[][20])
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			//Kiểm tra xem nó có phải là mìn hay là không ?
			if (mt[i][j] == -1)
				continue;
			//Dò từng ô 
			if (mt[i - 1][j - 1] == -1)
			{
				mt[i][j]++;
			}
			if (mt[i][j - 1] == -1)
			{
				mt[i][j]++;
			}
			if (mt[i + 1][j - 1] == -1)
			{
				mt[i][j]++;
			}
			if (mt[i - 1][j + 1] == -1)
			{
				mt[i][j]++;
			}
			if (mt[i][j + 1] == -1)
			{
				mt[i][j]++;
			}
			if (mt[i + 1][j] == -1)
			{
				mt[i][j]++;
			}
			if (mt[i + 1][j + 1] == -1)
			{
				mt[i][j]++;
			}
			if (mt[i - 1][j] == -1)
			{
				mt[i][j]++;
			}
		}
	}
}
int SoLuongMinTrong1O(int a[][20], int x, int y, int r, int c)
{
	int t = 0;
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (i >= 0 && i < r && j >= 0 && j < c && a[i][j] == -1)
				t++;
		}
	}
	return t;
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
