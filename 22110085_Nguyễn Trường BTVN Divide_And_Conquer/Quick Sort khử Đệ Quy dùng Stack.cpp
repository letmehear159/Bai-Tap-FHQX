// Quick Sort khử Đệ Quy dùng Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//ID:22110085 
//FULL NAME: Nguyễn Trường
//PURPOSE: QUICK SORT KHỬ ĐỆ QUY, DÙNG STACK (CỘNG ĐIỂM)
#include <iostream>
#include<stdlib.h>
using namespace std;
#include<stack>
stack <int> lower;			//Ngăn xếp chứa chỉ số bên trái
stack <int> upper;			//Ngăn xếp chứa chỉ số bên phải 
void swap(int& a, int& b);
void QuickSortStack(int a[], int n);
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
	QuickSortStack(a, n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
	
}
void QuickSortStack(int a[], int n)
{
	
	lower.push(0);								//Bắt đầu ngăn xếp với giá trị bên trái là 0
	upper.push(n-1);							//Giá trị bên phải là phần tử cuối cùng của mảng 
	while (lower.size() != 0 && upper.size() != 0)			//Vòng lặp chỉ tiếp tục khi mà trong ngăn xếp còn dữ liệu cần phải sắp xếp 
	{
		int low = lower.top();					//Lấy phần tử bên trái của ngăn xếp 
		int high = upper.top();					//Lấy phần tử bên phải của ngăn xếp 
		lower.pop();							//Xóa đi giá trị trong ngăn xếp vì đoạn này đã tìm ra pivot rồi 
		upper.pop();							//Xóa đi giá trị trong ngăn xếp vì đoạn này đã tìm ra pivot rồi 
		if (low < high)							//Nếu dãy phải có 2 phần tử trở đi mới xét tìm pivot 
		{
			int sm = low - 1;			//Swap Marker	gán từ l-1 nếu nó không gặp giá trị nào bé hơn thì cuối cùng gặp lại chính pivot thì sẽ tăng lên thành l và pivot sẽ nằm ở vị trí đó 	
			int pivot = high;			//Pivot xuất phát từ phần tử cuối cùng 
			for (int i = low; i <= high; i++)
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
			pivot = sm;					//Trả pivot về vị trí đúng hiện tại 
			lower.push(low);			//Đẩy vị trí index bên trái vào ngăn xếp (thấp)
			upper.push(pivot - 1);		//Đẩy vị trí index phải của mảng trái vào ngăn xếp (cao)
			lower.push(pivot + 1);		//Đẩy vị trí index bên phải vào ngăn xếp	(thấp)
			upper.push(high);			//Đẩy vị trí index phải của mảng phải vào ngăn xếp (cao)
		}
		
	}
	
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
