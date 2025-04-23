#include<iostream>
#include<conio.h>
#include<time.h>
#include<Windows.h>
#include<dos.h>
#include<stdio.h>
#include<string.h>
using namespace std;
void gotoxy(int, int);
void final();
int main()
{
	int ale,ale1,error=0,bueno=0,rap=300,i,error1=0,salir;
	char abc[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' },let;
	srand(time(NULL));
	do
	{
		ale = 0 + rand() % (26);
		ale1 = 0 + rand() % (80);
		for (i = 0; i < 21 && !_kbhit(); i++)
		{
			final();
			gotoxy(ale1, i);
			cout << abc[ale];
			Sleep(rap);
			system("cls");
		}
		if (i == 21)
		{
			salir = 0;

			gotoxy(40, 15);
			cout << "Lose=perdido";
			system("pause");
		}
		else
		{
			let = _getch();
		}
		if (let==abc[ale])
		{
			bueno++;
			if (bueno == 10 || bueno == 20 || bueno == 30 || bueno == 40)
			{
				rap = rap - 100;
			}
			if (bueno==50)
			{
				error = 3;
				system("cls");
				gotoxy(40, 15);
				cout << "ganaste";
			}
		}
		else
		{
			error++;
		}
		if (error == 3)
		{
			salir = 0;
			system("cls");
			gotoxy(40, 15);
			cout << "Lose";
		}
	} while (salir!=0);
	
	system("pause");
	return 0;
	
}
void final()
{
	for (int i = 0; i <= 80; i++)
	{
		gotoxy(i, 20);
		cout << "_";
	}
}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x, coord.Y = y;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdOut, coord);
}
