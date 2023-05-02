// MidTerm Test Ở Lớp part 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <time.h>
#include <iostream>
#define MAX 52	

using namespace std;
typedef struct CARD {
	int kind;		//1: hearts, 2: diamonds, 3: clubs, 4: spades
	int number;	//1 -> 13: 11 = J, 12 = Q, 13 = K, 1 = Ace
};
CARD deck[52];
//1. Tạo bộ bài tây gồm 52 lá
void CreateDeck(CARD deck[52]);
int AbsoluteWin(CARD hand[][MAX], int n);
void DealCards(CARD deck[52], CARD hands[MAX][MAX], int n, int k);
//8. In tay bài ra màn hình để quan sát

void PrintHand(CARD hand[], int k);
//7. In thông tin 1 lá bài ra màn hình
void PrintCard(CARD b);
//2. Xáo trộn thứ tự trong bộ bài (ngẫu nhiên)
void ShuffleDeck(CARD deck[52]);
void PrintPlayerHand(CARD hand[][MAX], int n, int k);
int main()
{
	CARD hands[MAX][MAX];
	srand((unsigned)time(NULL));		//generate a different set of random numbers each time
	CreateDeck(deck);
	ShuffleDeck(deck);
	DealCards(deck, hands, 4, 6);

	//for (int i = 0; i < 6; i++)
	//{
	//	cout << "Hand[" << i << "].number :";
	//	cin >> hand[n][i].number;
	//	cout << endl << "Hand[" << i << "].Kind: ";
	//	cin >> hand[n][i].kind;
	//	cout << endl;
	//}
	int f;
	cout <<endl<< "Choose player to go first:";
	cin >> f;
	PrintPlayerHand(hands, f, 6);
	if (AbsoluteWin(hands, f) == 1)
		cout << "Player " << f << " Can win if he/she goes first";
	else
		cout << "Player " << f << " Cant win if he/she goes first";
}
void PrintPlayerHand(CARD hand[][MAX], int n,int k)
{
	for (int i = 0; i < k; i++)
	{
		PrintCard(hand[n][i]);
		cout << endl;
	}
}
int AbsoluteWin(CARD hand[][MAX],int n)
{
	int J[5] = { 0 }, Q[5] = { 0 }, K[5] = { 0 }, A[5] = { 0 };
	for (int i = 0; i < 6; i++)
	{
		if (hand[n][i].number == 11)
		{
			J[0]++;
			J[hand[n][i].kind]++;
		}
		if (hand[n][i].number == 12)
		{
			Q[0]++;
			Q[hand[n][i].kind]++;

		}
		if (hand[n][i].number == 13)
		{
			K[0]++;
			K[hand[n][i].kind]++;
		}
		if (hand[n][i].number == 1)
		{
			A[0]++;
			A[hand[n][i].kind]++;
		}

	}
	if (A[0] == 4)			//4 Át 
		return 1;
	if (A[0] == 3&&K[0]>=1)		//3 Át và 1 K trở lên 
	{
		for (int i = 1; i <= 4; i++)
		{
			for(int j=1;j<=4;j++)
			if (A[i]==1 &&K[j]==1&&i==j)			//Nếu K và Át 2 con cùng có và số kind nó bằng nhau 
				return 1;
		}
	}
	if (A[0] == 2 && K[0] == 2)
	{
		int c = 0;
		for (int i = 1; i <= 4; i++)
		{
			for (int j = 1; j <= 4; j++)
				if (A[i] == 1 && K[j] == 1 && i == j)			//Nếu K và Át 2 con cùng tồn tại và số kind nó bằng nhau 2 lần 
				{
					c++;
				}
		}
		if (c == 2)
			return 1;
	}
	if (A[0] >= 2 && K[0] >= 1 && Q[0] >= 1)			//Có QKA cùng màu và 1 con A khác 
	{
		for (int i = 1; i <= 4; i++)
		{
			if (A[i] == 1 && K[i] == 1 && Q[i] == 1)
				return 1;
		}
	}
	if (A[0] >= 1 && K[0] >= 1 && Q[0] >= 1 && J[0] >= 1)			//Có JQK và Át  cùng màu 
	{
		for (int i = 1; i <= 4; i++)
		{
			if (A[i] == 1 && K[i] == 1 && Q[i] == 1&&J[i]==1)
				return 1;
		}
	}
	return 0;
}
//Function definitions
//1. Tạo bộ bài tây gồm 52 lá
void CreateDeck(CARD deck[52])
{
	int n = 0;			//current card
	for (int shape = 1; shape <= 4; shape++)
		for (int num = 1; num <= 13; num++)
		{
			deck[n].kind = shape;
			deck[n].number = num;
			n++;
		}
}
//Function that gives a random number from 0 to n-1
int Random(int n) {
	return rand() % n;
}
//Function that swaps the content of 2 cards
void Swap(CARD& a, CARD& b) {
	CARD t = a;
	a = b;
	b = t;
}

//2. Xáo trộn thứ tự trong bộ bài (ngẫu nhiên)
void ShuffleDeck(CARD deck[52])
{
	//Swap at least 30 times, at most 52 times between two cards
	int no = 30 + Random(23);
	for (int i = 0; i < no; i++) {
		int v1 = Random(52);
		int v2 = Random(52);
		if (v1 != v2) Swap(deck[v1], deck[v2]);
	}

}
//3. Chia bài cho n người chơi, mỗi người cầm k lá bài
void DealCards(CARD deck[52], CARD hands[MAX][MAX], int n, int k)
{
	int v = 0;					//position in the deck
	for (int j = 0; j < k; j++)
		for (int i = 0; i < n; i++)
			hands[i][j] = deck[v++];
}
void PrintCard(CARD b)
{
	char t1[] = { 'J', 'Q', 'K' };
	if (b.number == 1) cout << "A";
	else if (b.number > 10) cout << t1[b.number - 11];
	else cout << b.number;
	char t2[][20] = { ""," heart", " diamond", " club", " spade" };
	cout << t2[b.kind];
}
void PrintHand(CARD hand[], int k)
{
	for (int i = 0; i < k; i++) {
		PrintCard(hand[i]);
		cout << endl;
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
