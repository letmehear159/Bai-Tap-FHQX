// Xử Lý số lớn.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<string>
#include <iostream>
using namespace std;
//Khai báo hằng 
#define MAXDIGITS 100  //maximum length
#define PLUS 1   //Positive sign bit    
#define MINUS -1  //Negative sign bit
//Khai bao cau truc
typedef struct
{
    char digits[MAXDIGITS];// The number
    int signbit;  //Plus or minus 
    int lastdigit;  //Index of high-order digit

}bignum;
//Khai báo hàm
void addnumberFunc(bignum a, bignum b, bignum &c);
void scan_bignum(bignum& n);
void print_bignum(bignum n);
int kiemtra(char s[]);
void DelZero(bignum& a);
void Subtract(bignum a, bignum b, bignum& c);
void FindSignOfC(bignum a, bignum b, bignum& c);
int DecideAddOrSub(bignum a, bignum b);
void Subtract(bignum a, bignum b, bignum& c);
void SubtractFunc(bignum a, bignum b, bignum& c);
void addnumber(bignum a, bignum b, bignum& c);
int chuyenkt(char a)
{
    return (int)a - 48;
}
void MultiNum(bignum a, bignum b, bignum& c);
void ShiftRight(bignum &a,int n);
void BignumShift(int b, bignum& a);
int main()
{
    bignum a, b, c;
    scan_bignum(a);
    scan_bignum(b);
    Subtract(a, b, c);
    print_bignum(c);
}
void scan_bignum(bignum& n)
{
    cout << "Nhap so: ";
    char temp[256];
    cin.getline(temp, 256);
    if (kiemtra(temp) == -1)        //Nếu số không hợp lệ 
    {
        n.digits[0] = 0;
        n.lastdigit = 0;
        n.signbit = PLUS;
    }
    else
    {
        if (temp[0] != '-')         //Trường hợp số dương 
        {
            n.signbit = PLUS;
            n.lastdigit = strlen(temp) - 1;
            for (int i = 0; i <= n.lastdigit; i++)
            {
                n.digits[i] = temp[n.lastdigit - i];
            }
        }
        else                //Trường hợp số âm 
        {
            n.signbit = MINUS;
            n.lastdigit = strlen(temp) - 2;
            for (int i = 0; i <= n.lastdigit; i++)
            {
                n.digits[i] = temp[n.lastdigit - i + 1];
            }
        }
    }
}
void print_bignum(bignum n)
{
    if (n.signbit == MINUS)
        cout << "-";
    for (int i = n.lastdigit; i >= 0; i--)
    {
        cout << n.digits[i] - 48;
    }
}
void DelZero(bignum& a)
{
    for (int i = a.lastdigit; i >= 1; i--)
    {
        if (a.digits[i] == 48)
            a.lastdigit -= 1;
        else
            return;
    }
}
void addnumberFunc(bignum a, bignum b, bignum &c)
{
 
    int carry = 0;
    int n;
    if (a.lastdigit > b.lastdigit)
        n = a.lastdigit;
    else
        n = b.lastdigit;
    c.lastdigit = n + 1;
    int temp = 0;
    int i;
    if (a.signbit==PLUS&&b.signbit==PLUS)             ////Trường hợp 2 thg này  cùng dương 
    {
        c.signbit = PLUS;
    }
    else if (a.signbit == MINUS && b.signbit == MINUS)               //   Trường hợp 2 thg này cùng âm 
    {
        c.signbit = MINUS;
    }
        for (i=0; i <= n + 1; i++)                          //Thực hiện phép toán cộng như thường 
        {
            temp = 0;
            if (a.digits[i] > 57 || a.digits[i] < 48)       //Nếu chưa có số không thì thêm vào 
            {
                a.digits[i] = 48;
            }
            if (b.digits[i] > 57 || b.digits[i] < 48)
            {
                b.digits[i] = 48;
            }
            if (carry == 0)
            {
                temp = a.digits[i] + b.digits[i] - 96;
            }
            else if (carry == 1)
            {
                temp = a.digits[i] + b.digits[i] - 96 + 1;

            }
            if (temp >= 10)
            {
                carry = 1;
                c.digits[i] = temp - 10 + 48;
            }
            else
            {
                carry = 0;
                c.digits[i] = temp + 48;
            }
        }
        DelZero(c);
}
int kiemtra(char s[])
{
    if(s[0]!='-'&&!isdigit(s[0]))
        return 0;
    int len = strlen(s);
    for (int i = 1; i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            return 0;
        }
    }
    return 1;
}
void Subtract(bignum a, bignum b, bignum& c)
{
    if (DecideAddOrSub(a, b) == 1)              //Cộng 
    {
        addnumberFunc(a, b, c);
        if (a.signbit == MINUS)
        {
            c.signbit = MINUS;
        }
        else if (b.signbit == MINUS)
        {
            c.signbit == PLUS;
        }
    }
    else                    //Trừ 
    {
        FindSignOfC(a, b, c);
        SubtractFunc(a, b, c);
        if (a.signbit == MINUS && b.signbit == MINUS)
        {
            c.signbit *= -1;
        }
    }
}
void FindSignOfC(bignum a, bignum b, bignum& c)
{
    //Quy ước là sẽ lấy số lớn trừ số nhỏ và a trừ b nếu a lớn thì PLUS còn a bé hơn thì MINUS 
    int n;
    bool cmp = false;
    if (a.lastdigit > b.lastdigit)          //Số a lớn hơn số b 
    {
        n = a.lastdigit;
        c.signbit = PLUS;
        cmp = true;
    }
    else if (a.lastdigit < b.lastdigit)     //Số a bé hơn số b 
    {
        n = b.lastdigit;
        c.signbit = MINUS;
        cmp = true;
    }
    else                                //2 số chưa biết số nào lớn hơn    
    {
        n = b.lastdigit;
    }
    c.lastdigit = n;
    if (cmp == false)
    {
        for (int i = n; i >= 0; i--)
        {
            if (a.digits[i] > b.digits[i])
            {
                c.signbit = PLUS;
                cmp = true;
                break;
            }
            else if (a.digits[i] < b.digits[i])
            {
                c.signbit = MINUS;
                cmp = true;
                break;
            }
        }
    }
   
    if (cmp == false)          //Trường hợp 2 a b bằng số nhau 
    {
        c.signbit = PLUS;
        return;
    }
}
int DecideAddOrSub(bignum a, bignum b)
{
    if (a.signbit * b.signbit == -1)              //Cộng   
        return 1;
    else if (a.signbit * b.signbit == 1)            //Trừ 
        return -1;
}
void SubtractFunc(bignum a, bignum b, bignum& c)
{
    int n = c.lastdigit;
      for (int i = 0; i <= n; i++)
      {
          if (a.digits[i] > 57 || a.digits[i] < 48)
          {
              a.digits[i] = 48;
          }
          if (b.digits[i] > 57 || b.digits[i] < 48)
          {
              b.digits[i] = 48;
          }
      }
      int carry = 0;
      int temp;
    if(c.signbit==PLUS)         //a lớn hơn b 
        for (int i = 0; i <= n; i++)
        {
            temp = 0;
            if (a.digits[i] + carry < b.digits[i])
            {
                temp = a.digits[i]+10+carry - 48 - (b.digits[i] - 48) ;
                carry = -1;
            }
            else
            {
                temp = a.digits[i]+carry - 48 - (b.digits[i] - 48);
                carry = 0;

            }
            c.digits[i] = temp + 48;
        }
    else if (c.signbit == MINUS)   //b lớn hơn a 
    {
        for (int i = 0; i <= n; i++)
        {
            temp = 0;
            if (b.digits[i] + carry < a.digits[i])
            {
                temp = b.digits[i] + 10 + carry - 48 - (a.digits[i] - 48);
                carry = -1;
            }
            else
            {
                temp = b.digits[i] + carry - 48 - (a.digits[i] - 48);
                carry = 0;
            }
            c.digits[i] = temp + 48;
        }
    }
}
void addnumber(bignum a, bignum b, bignum& c) {
    if (a.signbit * b.signbit == 1)              //Trường hợp hai số cùng dấu thì sẽ cộng 
    {
        addnumberFunc(a, b, c);
    }
    else if (a.signbit * b.signbit == -1)              //Trường hợp hai số ngược dấu thì sẽ trừ 
    {
        FindSignOfC(a, b, c);
        SubtractFunc(a, b, c);
        if (c.signbit == PLUS)          //Nếu A lớn hơn b 
        {
            if (a.signbit == MINUS)
            {
                c.signbit = MINUS;
            }
            else if (a.signbit == PLUS)
                c.signbit = PLUS;
        }
        else if (c.signbit == MINUS)        ////Nếu A Bé hơn B
        {
            if (a.signbit == MINUS)
            {
                c.signbit = PLUS;
            }
            else if (a.signbit == PLUS)
                c.signbit = MINUS;
        }
    }
}
void ShiftRight(bignum &a,int n )
{
    for (int j = 0; j < n; j++)
    {
        for (int i = a.lastdigit; i >= 0; i--)          //Chuyển lên 1 đơn vị 
        {
            a.digits[i + 1] = a.digits[i];
        }
        a.digits[0] = '0';
        a.lastdigit++;
    }
}
void MultiNum(bignum a, bignum b, bignum& c)
{
    c.signbit = a.signbit;                  //
    bignum temp;
    temp.signbit = a.signbit;
    temp.lastdigit = 0;
    for (int i = 0; i <= b.lastdigit; i++)          //Tách từng đứa trong bignum b
    {   
        for (int j = 0; j < chuyenkt(b.digits[i]); j++)                 //Vòng lặp với số lần là chữ số của b.digits[i] 
        {
            addnumberFunc(a, temp, temp);
        }
        ShiftRight(temp, i);               //Với từng số chục trăm hay nghìn thì dịch sang phải và thêm vào i số 0 tương ứng 
        addnumberFunc(temp, c, c);
    }
    c.signbit = a.signbit * b.signbit;
         
}
void BignumShift(int b, bignum& a)
{
    int phandu;
    int leftover=b;
    a.lastdigit = 0;
    if (b >= 0)
        a.signbit = PLUS;
    else
    {
        a.signbit = MINUS;
        leftover = -b;
    }
    while (leftover > 0)
    {
        phandu = leftover % 10;
        a.digits[a.lastdigit++] = phandu + 48;
        leftover /= 10;
    }
    a.lastdigit--;
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
