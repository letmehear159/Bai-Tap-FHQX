// Structure HomeWork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//ID: 22110085
//FullName: Nguyễn Trường
//Purpose: Structure Homework week 1 

#include <iostream>
using namespace std;
typedef struct PS {
	int tu;
	int mau;
};
//Function declaration
//1.Input values for a fraction
void InputFraction(PS& r);


//2. Output a fraction
void OutputFraction(PS r);






//4. Add 2 fractions
PS AddFrac(PS r, PS f);


//3. Minus 2 fractions
PS MinusFrac(PS r, PS f);


//5 Tối giản kết quả phân số 
void TG(PS& r);


//6. Add 2 fractions
PS MulFraction(PS r, PS f);



//7. Divide 2 fractions
PS DivFrac(PS r, PS f);

//8 Reverse Fractions
void RevFrac(PS& r);



//9 Tính Giá Trị
float GetValue(PS r);


//10 So Sánh 2 Phân số 
int CmpFrac(PS r, PS f);
int main()
{
	PS a, b, t;
	InputFraction(a);
	InputFraction(b);
	t = AddFrac(a, b);
	OutputFraction(t);
	t = MinusFrac(a, b);
	OutputFraction(t);
	t = MulFraction(a, b);
	OutputFraction(t);
	t = DivFrac(a, b);
	OutputFraction(t);
	RevFrac(a);
	OutputFraction(a);
	cout << CmpFrac(a, b);



}

void InputFraction(PS& r)
{
	cout << "Nhap gia tri tu: ";
	cin >> r.tu;
	do {
		cout << endl << "Nhap gia tri mau: ";
		cin >> r.mau;
		if (r.mau == 0)
		{
			cout << endl << "Mau bang 0 Khong Hop le " << endl;
		}
	} while (r.mau == 0);

}
void OutputFraction(PS r)
{
	cout << r.tu << "/" << r.mau << endl;
}


//5 Tối giản kết quả phân số 
void TG(PS& r)
{
	int x = 1;
	int tu = r.tu;
	int mau = r.mau;
	if (r.tu < 0)
	{
		tu *= -1;
	}
	if (r.mau < 0)
	{
		mau *= -1;
	}
	for (int i = 2; i <= tu || i <= mau; i++)
	{
		if (tu % i == 0 && mau % i == 0)
		{
			x = i;
		}
	}
	r.tu /= x;
	r.mau /= x;
}


//4. Add 2 fractions
PS AddFrac(PS r, PS f)
{
	PS result = { (r.tu * f.mau + f.tu * r.mau),(r.mau * f.mau) };
	TG(result);
	return result;
}


//3. Minus 2 fractions
PS MinusFrac(PS r, PS f)
{
	PS result = { (r.tu * f.mau - f.tu * r.mau),(r.mau * f.mau) };
	TG(result);
	return result;
}


//6. Multiply 2 fractions
PS MulFraction(PS r, PS f)
{
	PS kq;
	kq.tu = r.tu * f.tu;
	kq.mau = f.mau * r.mau;
	TG(kq);
	return kq;
}




//7. Divide 2 fractions
PS DivFrac(PS r, PS f)
{
	PS kq;
	kq.tu = r.tu * f.mau;
	kq.mau = r.mau * f.tu;
	TG(kq);
	return kq;
}
//8 Reverse Fractions
void RevFrac(PS& r)
{
	int x = r.tu;
	r.tu = r.mau;
	r.mau = x;
} 


//9 Tính Giá Trị 
float GetValue(PS r)
{
	return (float)r.tu / r.mau;
}

//10 So Sánh 2 Phân số 
int CmpFrac(PS r, PS f)
{
	if (GetValue(r) > GetValue(f))
		return 1;
	else if (GetValue(r) < GetValue(f))
		return -1;
	else
		return 0;
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
