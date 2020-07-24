#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include<MMSystem.h>
#pragma comment(lib,"Winmm.lib")

#define SPACEBAR 64
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13
#define XALPA 115
#define BACKSPACE 8

int gotoxy(int, int);
int mainscreen();
int reset();
int GameTitleA();
int GameA();
int ShutDown();


int gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

	return 0;
}


int main()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	SetConsoleTitleA("Harry's Adventure");

	mainscreen();
	reset();
	GameA();

	return 0;
}

int mainscreen()
{
	system("mode con: cols=150 lines=40");

	GameTitleA();

}

int GameTitleA()
{
	gotoxy(10, 4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	printf("        ■■        ■■        ■■■■         ■■■■■■          ■■■■■■         ■■     ■■");
	gotoxy(10, 5);
	printf("       ■■        ■■      ■■    ■■      ■■        ■■     ■■        ■■      ■■      ■■");
	gotoxy(10, 6);
	printf("      ■■        ■■     ■■      ■■     ■■         ■■    ■■         ■■    ■■      ■■     ■■");
	gotoxy(10, 7); 
	printf("     ■■■■■■■■    ■■        ■■    ■■        ■■     ■■        ■■     ■■     ■■         ■ ");
	gotoxy(10, 8);
	printf("    ■■■■■■■■    ■■■■■■■■    ■■       ■■      ■■       ■■      ■■    ■■                   ■■■■");
	gotoxy(10, 9);
	printf("   ■■        ■■    ■■        ■■    ■■■■■■■■     ■■■■■■■■        ■■■                    ■■");
	gotoxy(10, 10);
	printf("  ■■        ■■    ■■        ■■    ■■         ■■    ■■         ■■       ■■■                       ■■■■");
	gotoxy(10, 11);
	printf(" ■■        ■■    ■■        ■■    ■■         ■■    ■■         ■■       ■■■                               ■■");
	gotoxy(10, 12);
	printf("■■        ■■    ■■        ■■    ■■         ■■    ■■         ■■       ■■■                       ■■■■■\n");


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	gotoxy(5, 15);
	printf("    ■■■■       ■■■■■      ■■       ■■  ■■■■■■  ■■      ■■  ■■■■■■ ■■       ■■  ■■■■■      ■■■■■■");
	gotoxy(5, 16);
	printf("  ■■    ■■     ■■     ■■   ■■       ■■  ■■          ■■ ■   ■■      ■■     ■■       ■■  ■■     ■■   ■■");
	gotoxy(5, 17);
	printf("■■■■■■■■   ■■      ■■  ■■       ■■  ■■■■■■  ■■  ■  ■■      ■■     ■■       ■■  ■■■■■■    ■■■■■■ ");
	gotoxy(5, 18);
	printf("■■        ■■   ■■     ■■     ■■   ■■    ■■          ■■   ■ ■■      ■■      ■■     ■■   ■■      ■■  ■■ ");
	gotoxy(5, 19);
	printf("■■        ■■   ■■■■■           ■■        ■■■■■■  ■■    ■■■      ■■         ■■■■     ■■      ■■  ■■■■■■\n");



	int i;
	while (1)
	{
		if (_kbhit(NULL))
		{
			break;
		}

		else
			for (i = 1; i <= 15; i++)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
				gotoxy(58, 25);
				Sleep(300);
				printf("『  Press any key to start game  』\n");
			}
		
	}
	while (_kbhit()) _getch();
	return 0;
}

int reset()
{
	system("cls");
	
	return 0;
}

int GameA()
{
	int x =120;
	int y = 2;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(x, y); printf("  △   : UP");
	gotoxy(x, y+1); printf("◁  ▷ : LEFT / RIGHT");
	gotoxy(x, y+2); printf("  ▽   : DOWN");
	gotoxy(x, y+3); printf(" SPACE : SHOOT");
	gotoxy(x, y+4); printf("   P   : Pause");
	gotoxy(x, y+5); printf("  ESC  : Quit\n");
}
