#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include<MMSystem.h>
#pragma comment(lib,"Winmm.lib")

#define WALL 1 //(임시) 맵파일 나온 후에 이용
#define EMPTY 0
#define CEILLING -1

#define SPACEBAR 64 //사용할 키
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13
#define P 80
#define p 112

int gotoxy(int, int); //함수들
int mainscreen();
int reset();
int GameTitleA();
int GameA();
int Harry();
int pause();


typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE; //열거형 구조체로 커서 조절하기
void setcursortype(CURSOR_TYPE c)
{
	CONSOLE_CURSOR_INFO CurInfo;
	switch (c)
	{
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

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
	system("mode con: cols=150 lines=40"); //콘솔창 크기 조절

	GameTitleA();
	PlaySound(TEXT("music\\start button.wav"), NULL, SND_ASYNC | SND_NODEFAULT); //시작 버튼 음
	Sleep(700);

	return 0;

}

int GameTitleA()
{
	PlaySound(TEXT("music\\Kirby.wav"), NULL, SND_ASYNC | SND_LOOP); // 타이틀 음악 무한반복
	gotoxy(10, 4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); //타이틀 위치와 색깔
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

	while(1)  //다양한 색깔 무한반복
	{
			for (i = 1; i <= 15; i++)
			{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
					gotoxy(58, 25);
					Sleep(300);
					printf("『  Press any key to start game  』\n");

					if (_kbhit())
						break;
			}
			if (_kbhit())
				break;
			
	}
	while (_kbhit()) _getch();
	return 0;
}

int reset()
{
	system("cls"); //화면 완전히 클리어
	while (_kbhit()) _getch(); //입력버퍼 비우기
	return 0;
}

int GameA()
{

	PlaySound(TEXT("music\\challenger.wav"), NULL, SND_ASYNC | SND_LOOP); //인게임 음악 무한루프
	int x =120;
	int y = 2;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //인터페이스
	gotoxy(x, y); printf("  △   : UP");
	gotoxy(x, y+1); printf("◁  ▷ : LEFT / RIGHT");
	gotoxy(x, y+2); printf("  ▽   : DOWN");
	gotoxy(x, y+3); printf(" SPACE : SHOOT");
	gotoxy(x, y+4); printf("   P   : Pause");
	gotoxy(x, y+5); printf("  ESC  : Quit\n");

	Harry();
	
	return 0;
}

int Harry() //해리 움직이기 (이거 뭔가 나중에 수정해야할 것 같은 느낌......)
{
	setcursortype(NOCURSOR);
	int x = 0, y = 20;
	char ch;
	gotoxy(x+5, y);
	printf("ㅁ");



	while (TRUE)
	{
		ch = _getch();

		gotoxy(x+5, y);
		printf(" ");
	
		switch (ch)
		{
		case (UP):
			if (y > 0) y--;
			break;
		case (DOWN):
			if (y < 40) y++;
			break;

		case (LEFT):
			if (x > 0) x--;
			break; 
		case (RIGHT):
			if (x < 150) x++;
			break;
		}
		gotoxy(x+5, y);
		printf("ㅁ");
	
	
	}
	

}
//////////////////////////////////////////////////////////////////
void game_over(void) { //게임종료 함수 
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 5, "+----------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 6, "|      GAME OVER..     |");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 7, "+----------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 8, " YOUR SCORE : ");
    printf("%d", last_score = score);

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, " Press any keys to restart.. ");

    if (score > best_score) {
        best_score = score;
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 4, MAP_Y + 10, "☆ BEST SCORE ☆");
    }
    Sleep(500);
    while (_kbhit()) _getch();
    key = _getch();
    title();
}

//readmap & score 진행중... (맵 완성 후 시도 예정)
