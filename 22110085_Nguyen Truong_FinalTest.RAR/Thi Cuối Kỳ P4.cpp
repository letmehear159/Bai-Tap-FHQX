//
// Thi Cuối Kỳ P4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Full Name:Nguyễn Trường
//ID:22110085
//Purpose:Problem 4
//Class:FIE6
#include<conio.h>
#include<ctype.h>
#include <iostream>
#include<string>;
#include<cstring>;
using namespace std;

int main()
{
	char s[200];
	cout << "Input The String: ";
	cin.getline(s, 200);
	char* p = NULL;
	char vowel[] = "AEOIUYaeoiuy";
	int result=0;
	p = strtok(s, " ");
	while (p != NULL)
	{
		bool check = false;
		int slen = strlen(p);
		for (int i = 0; i<slen; i++)
		{
			if (strchr(vowel, p[i]))
			{
				int j = i + 1;
				if (strchr(vowel, p[j])&&p[j]!='\0')
				{
					check = true;
					break;
				}
			}
		}
		if (check == true)
		{
			result++;
		}
		p=strtok(NULL, " ");
	}
	cout << "The Number of word has at least 2 consecutive Vowels: " << result;
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
