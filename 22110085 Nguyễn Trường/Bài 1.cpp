// Bài 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//FULL NAME: Nguyễn Trường 
//ID :22110085 
//Purpose : Bài 1 
using namespace std;
#include<stdio.h>   
#include <iostream>
void docfile(char filename[], int a[], int& n)
{
	FILE* fp = NULL;
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		cout << "Error to read file";
		return;
	}
	fscanf(fp, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%d", &a[i]);

	}
	fclose(fp);
}
void vietfile(char fname[], int a[], int n)
{
	FILE* fp = NULL;
	fp = fopen(fname, "w");
	if (fp == NULL)				//Trường hợp đường dẫn không tồn tại thì sẽ NULL vì lúc đó nó không tạo ra được file ở đường dẫn đó 
	{
		cout << "Error to write file";
		return;
	}
	fprintf(fp, "%d\n", n);
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%5d", a[i]);
	}
	fclose(fp);
}
void PrimeNum(int a[], int na, int b[], int& nb)
{
	for (int i = 0; i < na; i++)
	{
		bool check = true;
		for (int j = 2; j < a[i]; j++)
		{
			if (a[i] % j == 0)
			{
				check = false;
				break;
			}
		}
		if (check == true)
			b[nb++] = a[i];
	}
}
int main()
{
	int a[100];
	int b[100];
	int nb=0;
	int na = 5;
	char InputFile[] = "D:/INPUT.TXT";
	char OutputFile[] = "D:/OUTPUT.TXT";
	docfile(InputFile, a, na);
	PrimeNum(a, na, b, nb);
	vietfile(OutputFile, b, nb);


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
