// Trò chơi gỡ mìn.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Full name :Nguyễn Trường
//ID:22110085
//Purpose Trò gỡ mìn 
#include <cstdlib> // for rand() and srand()
#include <ctime>  // for time()
#include <iostream>
#include <stdlib.h>
using namespace std;
//Function declaration
//1 Print the minefield---> Print the matrix
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
//Find MaxMines

int random(int minN, int maxN) {
	return minN + rand() % (maxN + 1 - minN);
}
//Gán mìn cho bãi mìn, số mìn<=1/4 số ô vuông 50 cái 
void PlaceMine(int mt[][20],int n)
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			mt[i][j] = 0;
		}
	}
	int somin = 0;
	int row;
	int coloumn;
	while (somin < n)
	{
		row = random(0, 15);
		coloumn = random(0, 15);
		if (mt[row][coloumn] == -1)
		{
			continue;
		}
		mt[row][coloumn] = -1;
		somin++;
	}
}
//Gán số cho mỗi ô xem 8 ô xung quanh nó có mìn hay không nếu có thì tăng bản thân nó lên 1 đơn vị 
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
			if (mt[i ][j - 1] == -1)
			{
				mt[i][j]++;
			}
			if (mt[i + 1][j - 1] == -1)
			{
				mt[i][j]++;
			}
			if (mt[i - 1][j +1] == -1)
			{
				mt[i][j]++;
			}
			if (mt[i ][j + 1] == -1)
			{
				mt[i][j]++;
			}
			if (mt[i + 1][j ] == -1)
			{
				mt[i][j]++;
			}
			if (mt[i + 1][j + 1] == -1)
			{
				mt[i][j]++;
			}
			if (mt[i - 1][j ] == -1)
			{
				mt[i][j]++;
			}
		}
	}
}
void DetectZero(char mtx[][20], int mt[][20], int row, int coloumn)
{
	if (mt[row - 1][coloumn - 1] == 0)
	{
		mt[row][coloumn] = 9;
		mtx[row - 1][coloumn - 1] = 'O';
		DetectZero(mtx, mt, row - 1, coloumn - 1);
	}
	if (mt[row][coloumn - 1] == 0)
	{
		mt[row][coloumn] = 9;
		mtx[row ][coloumn - 1] = 'O';
		DetectZero(mtx, mt, row , coloumn - 1);
	}
	if (mt[row + 1][coloumn - 1] == 0)
	{
		mt[row][coloumn] = 9;
		mtx[row + 1][coloumn - 1] = 'O';
		DetectZero(mtx, mt, row + 1, coloumn - 1);
	}
	if (mt[row - 1][coloumn + 1] == 0)
	{
		mt[row][coloumn] = 9;
		mtx[row - 1][coloumn + 1] = 'O';
		DetectZero(mtx, mt, row - 1, coloumn + 1);
	}
	if (mt[row][coloumn + 1] == 0)
	{
		mt[row][coloumn] = 9;
		mtx[row ][coloumn + 1] = 'O';
		DetectZero(mtx, mt, row , coloumn + 1);
	}
	if (mt[row + 1][coloumn] == 0)
	{
		mt[row][coloumn] = 9;
		mtx[row + 1][coloumn ] = 'O';
		DetectZero(mtx, mt, row +1, coloumn );
	}
	if (mt[row + 1][coloumn + 1] == 0)
	{
		mt[row][coloumn] = 9;
		mtx[row + 1][coloumn + 1] = 'O';
		DetectZero(mtx, mt, row + 1, coloumn + 1);
	}
	if (mt[row - 1][coloumn] == 0)
	{
		mt[row][coloumn] = 9;
		mtx[row - 1][coloumn ] = 'O';
		DetectZero(mtx, mt, row - 1, coloumn );
	}
}
void PrintMt(char mt[][20])
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
int Menu()
{
	int key=-1;
	do {
		cout << "1: Do Min" << endl;
		cout << "2: Dat Co" << endl;
		cout << "3: Chua biet Ro" << endl;
		cout << "Chon HD ban muon lam: ";
		cin >> key;
		if (key != 1 && key != 2 && key != 3)
			cout <<endl<< "So ban chon khong hop le vui long chon lai!!!" << endl;
	} while (key != 1 && key != 2 && key != 3);
	return key;
}
int CheckMin(char mtx[][20], int mt[][20], int row, int coloumn)
{
	if (mt[row][coloumn] == -1)			//Nếu dẫm phải mìn 
	{
		return -1;
	}
	else								//Trường hợp không gặp mìn 
	{
		//Trường hợp là 0 thì cho nó thành O và tìm 8 thằng quanh nó có thằng nào là 0 không cứ thế đến khi nào hết thì thôi (Như Covid)
		if (mt[row][coloumn] >=1 && mt[row][coloumn]<=8)
		{
			mtx[row][coloumn] = mt[row][coloumn]+48;
			return 1;
		}
		else if (mt[row][coloumn] == 0)
		{
			mt[row][coloumn] = 9;
			mtx[row][coloumn] = 'O';
			DetectZero(mtx, mt, row, coloumn);								//Kiểm tra 8 ô xung quanh 
			return 1;
		}
	}
}
int Operation(char mtx[][20], int mt[][20],int key)
{
	int row, coloumn;
	int ans;
	switch (key)
	{
	case 1:					//Dò mìn 
		cout << "Chon Hang: ";
		cin >> row;
		cout << endl << "Chon Cot: ";
		cin >> coloumn;
		cout << endl;
		//Thực hiện hoạt động 
		ans = CheckMin(mtx, mt, row, coloumn);
		break;
	case 2:				//Đặt cờ 
		cout << "Chon Hang: ";
		cin >> row;
		cout << endl << "Chon Cot: ";
		cin >> coloumn;
		cout << endl;
		//Thực hiện hoạt động 
		mtx[row][coloumn] = '!';
		ans = 1;
		break;
	case 3:				//Nghi hoặc 
		cout << "Chon Hang: ";
		cin >> row;
		cout << endl << "Chon Cot: ";
		cin >> coloumn;
		cout << endl;
		//Thực hiện hoạt động 
		mtx[row][coloumn] = '?';
		ans = 1;
		break;
	}
	return ans;
}
void Maxmines(int mt[][20], int n, int& x,int &y)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mt[i][j] > max)
			{
				x = i;
				y = j;
				max = mt[i][j];
			}
		}
	}
}
void MaxMineArea(int mt[][20], int n, int& x, int& y, int k)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int times = 0;
			for (int a = i - 1; a <= i + 1; a++)
			{
				for (int b = j - 1; b <= j + 1; b++)
				{
					if (a >= 0 && b >= 0 && a < 16 && b < 16 && mt[a][b] == -1)
					{
						times++;
					}
				}
			}
			if (times > max)
			{
				x = i;
				y = j;
				max = times;
			}
		}
	}
}
int main()
{
	srand(time(NULL));
	char mtx[20][20];
	int mt[20][20];
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			mtx[i][j] = 'X';
		}
	}
	PlaceMine(mt,50);
	CountMine(mt);
	cout << endl;
	int condition = 1;
	do
	{
		PrintMt(mtx);
		int key=Menu();
		condition=Operation(mtx, mt, key);
		system("CLS");
		if (condition == -1)
		{
			PrintMatrix(mt);
			cout << "Ban Da Do` Trung' Min`";
		}
	} while (condition==1);
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
