// Bài 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//FULL NAME: Nguyễn Trường 
//ID :22110085 
//Purpose : Bài 2 
#include<stdio.h>   
#include <iostream>
#define MAX 20
using namespace std;
void WMatrixFile(char filename[], int a[][MAX], int r, int c) {
	FILE* fp = NULL;
	fp = fopen(filename, "w");
	if (fp == NULL)
	{

		cout << "Error to open matrix file";
		return;
	}
	fprintf(fp, " Row: %3d", r);
	fprintf(fp, " Coloumn: %3d\n", c);
	fprintf(fp, "\n");
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			fprintf(fp, "%5d", a[i][j]);
		}
		fprintf(fp, "\n");
	}
}
void RMatrixFile(char filename[], int a[][MAX], int& r, int& c) {
	FILE* fp = NULL;
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		cout << "Error to open matrix file";
		return;
	}
	fscanf(fp, "%d", &r);
	fscanf(fp, "%d", &c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			fscanf(fp, "%d", &a[i][j]);
		}
	}
}
void TMaxtrix(int a[][MAX], int ra, int ca, int b[][MAX], int &rb, int &cb)
{
	rb = ca;
	cb = ra;
	for (int i = 0; i < ra; i++)
	{
		for (int j = 0; j < ca; j++)
		{
			b[j][i] = a[i][j];
		}
	}
}
int main()
{
	int a[5][MAX];
	int b[5][MAX];
	int ra = 3;
	int ca = 4;
	int rb, cb;
	char InputFile[] = "D:/INPUT.TXT";
	char OutputFile[] = "D:/OUTPUT.TXT";
	RMatrixFile(InputFile, a, ra, ca);
	TMaxtrix(a, ra, ca, b, rb, cb);
	WMatrixFile(OutputFile, b, rb, cb);

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
