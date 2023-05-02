// QuickSort Không mảng phụ.cpp : This file contains the 'main' function. Program execution begins and ends there.
////ID:22110085 
//FULL NAME: Nguyễn Trường
//PURPOSE: QUICK SORT KHÔNG DÙNG MẢNG PHỤ 
#include <iostream>
#include<stdlib.h>
#include <iostream>
using namespace std;
void swap(int& a, int& b);
void QuickSort(int a[], int l, int h);
int main()
{
	int a[50];
	int n;
	FILE* fp = NULL;
	fp = fopen("D:/INPUT.TXT", "r");
	if (fp == NULL)
	{
		cout << "Error to open file";
		return 0;
	}
	fscanf(fp, "%d", &n);
	for (int i = 0; i < n; i++)
	{

		fscanf(fp, "%d", &a[i]);
	}
	QuickSort(a,  0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
}
//l Khởi điểm là 0 
// h khởi điểm là n-1
//Chọn pivot là phần tử cuối cùng sau khi thực hiện sắp xếp thì sẽ đổi vị trí của pivot bằng sm và lúc đó pivot là vị trí được sắp xếp đúng không đụng vào nữa 
void QuickSort(int a[],  int l, int h)
{
	int sm = l - 1;			//Swap Marker	gán từ l-1 nếu nó không gặp giá trị nào bé hơn thì cuối cùng gặp lại chính pivot thì sẽ tăng lên thành l và pivot sẽ nằm ở vị trí đó 	
	int pivot = h;			//Pivot xuất phát từ phần tử cuối cùng 
	for (int i = l; i <= h; i++)
	{	
		if (a[i] > a[pivot])		//Nếu a[i] lớn hơn a[pivot] thì tiếp tục 
			continue;
		if (a[i] <= a[pivot])		
		{	
			sm++;					//Tăng swap marker lên +1 vì đã có số bé hơn pivot nên không cần thay thế pivot đứng trước số đó 
			if (i > sm)				//Nếu index hiện tại lớn hơn marker nghĩa là số a[i] bé hơn a[sm] nên sẽ swap 
			{
				swap(a[i], a[sm]);
			}
		}
	}
	pivot = sm;					//Chỉnh pivot về lại vị trí đúng của mình còn giá trị a[pivot] đã được swap ở trên rồi 
	if (l < h)					//Tránh trường hợp lặp đệ quy vô tận nếu khi chia chỉ có 1 số duy nhất 
	{
		//Chaỵ bên trái pivot 
		QuickSort(a, l, pivot - 1);		//Chạy bên trái với i xuất phát từ l và kết thúc là phần từ đứng trước pivot 
		//Chạy bên phải pivot 
		QuickSort(a, pivot + 1, h);		//Chạy bên phải với i xuất phải từ phần tử đứng sau pivot và kết thúc ở h 
	}
	//SIUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU
}
void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
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
