// Trò chơi sudoku.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Full name :Nguyễn Trường
//ID:22110085
//Purpose Sudoku game
//Phần kiểm tra ô có hợp lệ không em để ở hàm KiemTra 
#include <iostream>
using namespace std;
int	 KiemTra(int mt[][10], int row, int coloumn, int R[][10], int C[][10], int num,int H[]);
void TraverseArray(int R[][10], int C[][10], int mt[][10], int row, int coloumn);
void SquareCheck(int mt[][10], int row, int coloumn, int H[]);
void PossibleCheck(int mt[][10], int H[], int R[][10], int C[][10], int T[]);
void Refresh(int R[][10], int C[][10], int H[], int row, int coloumn);
void FindOneSolution(int mt[][10], int mtx[][10], int T[], int R[][10], int C[][10], int H[]);
void WriteAns(int mtx[][10], int R[][10], int C[][10], int H[], int T[], int mt[][10]);
int Still(int mt[][10]);
int main()
{
    int T[81] = { 0 };
    int mt[10][10];
	int R[10][10] = { 0 };
	int C[10][10] = { 0 };
    int H[10] = { 0 };
    int n; 
    int mtx[10][10] = { 0 };
    int condition;
        FILE* fp = NULL;
        fp = fopen("D:/INPUT.TXT", "r");
        if (fp == NULL)
            cout << "Error to open file" << endl;
            fscanf(fp, "%d", &n);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    fscanf(fp, "%d", &mt[i][j]);
                }
            }
            PossibleCheck(mt, H, R, C, T);
            /*FindOneSolution(mt, mtx, T, R, C, H);*/
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout.width(3);
                cout << mt[i][j];
            }
            cout << endl;
        }
        int k = 0;
        cout << endl << "=================================" << endl;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout.width(3);
                cout << T[k++];
            }
            cout << endl;
        }
       /* for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout.width(3);
                cout << mtx[i][j];
            }
            cout << endl;
        }*/
       /* while (condition > 0)
        {
            WriteAns(mt, R, C, H, T, mt);
            condition = Still(mt);
        }*/
     /*   for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout.width(3);
                cout << mt[i][j];
            }
            cout << endl;
        }*/
}
//int Still(int mt[][10])
//{
//    for (int i = 0; i < 9; i++)
//    {
//        for (int j = 0; j < 9; j++)
//        {
//            if (mt[i][j] == 0)
//                return 1;
//        }
//    }
//    return 0;
//}
void WriteAns(int mtx[][10], int R[][10], int C[][10], int H[], int T[], int mt[][10])
{
    PossibleCheck(mt, H, R, C, T);
    FindOneSolution(mt, mtx, T, R, C, H);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (mtx[i][j] != 0)             //Nếu phát hiện ra 1 số có thể điền vào 
            {
                mt[i][j] = mtx[i][j];
            }
        }
    }
}
void Refresh(int R[][10], int C[][10], int H[],int row,int coloumn)
{
    for (int i = 0; i < 10; i++)
    {
        H[i] = 0;
        R[row][i] = 0;
        C[i][coloumn] = 0;
    }
}
void PossibleCheck(int mt[][10], int H[], int R[][10], int C[][10],int T[])         //Kiểm tra từng ô thằng nào bằng 0 thì tiến tới kiểm tra 
{
    int n = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (mt[i][j] == 0)
            {
                for (int k = 1; k <= 9; k++)
                {
                    if (KiemTra(mt, i, j, R, C, k, H) == 1)
                    {
                        T[n]++;
                        Refresh(R, C, H, i, j);
                    }
                }
            }
            n++;
        }
    }
}
 int KiemTra(int mt[][10], int row, int coloumn, int R[][10], int C[][10], int num, int H[])
    {
     for (int i = 0; i < 10; i++)
     {
         H[i] = 0;
     }
        TraverseArray(R, C, mt, row, coloumn);
        SquareCheck(mt, row, coloumn,H);
        //Hàng 
        if (R[row][num] >= 1)
            return 0;
        //Dòng 
        if (C[num][coloumn] >= 1)
            return 0;
        //Ô vuông 
        if (H[num] >= 1)
            return 0;
        return 1;
    }
void TraverseArray(int R[][10], int C[][10], int mt[][10], int row, int coloumn)
{
    //Duyệt hàng ngang 
    for (int j = 0; j < 9; j++)
    {
        R[row][mt[row][j]]++;
    }
    //Duyệt hàng dọc 
    for (int j = 0; j < 9; j++)
    { 
        C[mt[j][coloumn]][coloumn]++;
    }
}
void SquareCheck(int mt[][10], int row, int coloumn,int H[])
{
    if (row >= 0 && row <= 2)
        row = 0;
    else if (row >= 3 && row <= 5)
    {
        row = 3;
    }
    else
    {
        row = 6;
    }
    if (coloumn >= 0 && coloumn <= 2)
        row = 0;
    else if (coloumn >= 3 && coloumn <= 5)
    {
        coloumn = 3;
    }
    else
    {
        coloumn = 6;
    }
    for (int i = row; i < row + 3; i++)
    {
        for (int j = coloumn; j < coloumn + 3; j++)
        {
            H[mt[i][j]]++;
        }
    }
}
void FindOneSolution(int mt[][10],int mtx[][10], int T[], int R[][10], int C[][10], int H[])            //Trường hợp thằng nào bằng 1 thì lấp số vào 
{
    int i=0, j = -1;
    for (int n = 0; n < 81; n++)
    {  
        j++;
        if (j > 8)
        {
            i++;
            j = 0;
        }
        if (T[n] == 1) //Chỉ có 1 trường hợp duy nhất 
        {
            for (int k = 1; k <= 9; k++)
            {
                if (KiemTra(mt, i, j, R, C, k, H) == 1)
                {
                    mtx[i][j] = k;
                    Refresh(R, C, H, i, j);
                    break;
                }
            }
        }
    }
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
