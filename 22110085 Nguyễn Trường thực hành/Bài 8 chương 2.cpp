// Bài 8 chương 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include<stdlib.h>
using namespace std;
void docfile(FILE* fp, int& n, int& m, float a[][20]);
void DiemLoi(float a[][20], int n, int m);
bool Check(float a[][20], int x, int y, int n, int m);
int main()
{
	int n,m;
	float a[20][20];
	FILE* fp=NULL;
	docfile(fp, n,m, a);
	/*cin >> n>>m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}*/
	DiemLoi(a, n, m);
	
}
void DiemLoi(float a[][20], int n, int m)
{
	int x, y;
	float min;
	int time=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (Check(a, i, j, n, m) == true)
			{
				if (time == 0)
				{
					min = a[i][j];
					x = i;
					y = j;
					time = 1;
				}
				else
				{
					if (min > a[i][j])
					{
						min = a[i][j];
						x = i;
						y = j;
					}
				}

			}

		}
	}
	if (time == 1)
		cout << x <<" "<< y;
	else
		cout << -1;
}
bool Check(float a[][20], int x, int y,int n,int m)
{
	int i = x-1, j = y;
	while (i >= 0)
	{
		if (a[x][y] <= a[i][j])
			return false;
		i--;
	}
	i = x + 1;
	while (i < n)
	{
		if (a[x][y] <= a[i][j])
			return false;
		i++;
	}
	i = x;
	j = y - 1;
	while (j >= 0)
	{
		if (a[x][y] <= a[i][j])
			return false;
		j--;
	}
	j = y + 1;
	while (j < m )
	{
		if (a[x][y] <= a[i][j])
			return false;
		j++;
	}
	return true;

}
void docfile(FILE* fp, int& n,int &m , float a[][20])
{
	fp = fopen("D:/INPUT.TXT", "r");
	if (fp == NULL)
	{
		cout << "Error to open file";
		return;
	}
	fscanf(fp, "%d", &n);
	fscanf(fp, "%d", &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			fscanf(fp, "%d", &a[i][j]);
		}
	}
}
void docfile(FILE* fp, int& n, int a[][20]);
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
