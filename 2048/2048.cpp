#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>

#include "stack.h"

#define TILE_GAP 6
#define GRID_SIZE 4

enum ColorType {
	BLACK,  	//0
	darkBLUE,	//1
	DarkGreen,	//2
	darkSkyBlue,    //3
	DarkRed,  	//4
	DarkPurple,	//5
	DarkYellow,	//6
	GRAY,		//7
	DarkGray,	//8
	BLUE,		//9
	GREEN,		//10
	SkyBlue,	//11
	RED,		//12
	PURPLE,		//13
	YELLOW,		//14
	WHITE		//15
} COLOR;

typedef enum {UP,DOWN,LEFT ,RIGHT} Direction;

void textcolor(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

// 콘솔 창의 크기와 제목을 지정하는 함수
void SetConsoleView()
{
	system("mode con:cols=100 lines=55");
	system("title Google Dinosaurs. By justsicklife");
}

// 커서의 위치를 x,y로 이동하는 함수
void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int GetKeyDown()
{
	if (_kbhit() != 0)
	{
		return _getch();
	}

	return 0;
}

void CreateTile(int consoleX, int consoleY) {
	

	for (int i = 0; i <= GRID_SIZE; i++) { 
		for (int j = 0; j < GRID_SIZE; j++) {
			for (int k = 0; k < TILE_GAP; k++) {
				GotoXY(consoleX+ TILE_GAP * j + k,consoleY + i * TILE_GAP);
				printf("=");
			}
		}
	}
	
	for (int i = 0; i <= GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			for (int k = 0; k < TILE_GAP; k++) {
				GotoXY(consoleX + i * TILE_GAP, consoleY + TILE_GAP * j + k);
				printf("=");
			}
		}
	}
}

void PrintTileValue(int (*tileValue)[GRID_SIZE], int offsetX, int offsetY) {

	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			GotoXY(offsetX + (TILE_GAP / 2 + TILE_GAP * j), offsetY + (TILE_GAP / 2 + TILE_GAP * i));
			
			switch (tileValue[i][j])
			{
			case 2:
				textcolor(BLUE);
				break;
			case 4:
				textcolor(RED);
				break;
			case 8:
				textcolor(GREEN);
				break;
			case 16:
				textcolor(SkyBlue);
			case 32:
				textcolor(YELLOW);
				break;
			case 64:
				textcolor(DarkPurple);
				break;
			case 128:
				textcolor(PURPLE);
				break;
			case 256:
				textcolor(DarkGray);
				break;
			case 512:
				textcolor(DarkRed);
			case 1024:
				textcolor(darkSkyBlue);
				break;
			case 2048:
				textcolor(darkBLUE);
				break;
			}
			
			printf("%d", tileValue[i][j]);
			textcolor(WHITE);
		}
	}
}

void MoveTiles(Direction dir,int (*arr)[GRID_SIZE]) {
	switch (dir) {
	case UP:
		for (int i = 0; i < GRID_SIZE; i++) {
			Stack stack = {};
			initStack(&stack);
			int prev = -1;
			for (int j = GRID_SIZE-1; j >= 0; j--) 
			{
				int curValue = arr[j][i];

				if (curValue == 0)
					continue;

				push(&stack, curValue);
				
				if (prev == curValue) {
					peek(&stack, &prev);
					int a = 0;
					pop(&stack, &a);
					pop(&stack, &a);
					push(&stack, a * 2);
					prev = -1;
				}
				else {
					prev = curValue;
				}
				arr[j][i] = 0;
			}

			int index = 0;
			while (!isEmpty(&stack)) {
				int a = 0;
				pop(&stack, &a);
				arr[index][i] = a;
				index++;
			}
		}
		break;
	case DOWN:
		for (int i = 0; i < GRID_SIZE; i++) {
			Stack stack = {};
			initStack(&stack);
			int prev = -1;
			for (int j = 0; j <  GRID_SIZE; j++) {
				if (arr[j][i] == 0) continue;

				int curValue = arr[j][i];

				push(&stack, curValue);

				if (prev == curValue) {
					peek(&stack, &prev);
					int a = 0;
					pop(&stack, &a);
					pop(&stack, &a);
					push(&stack, a * 2);
					prev = -1;
				}
				else {
					prev = curValue;
				}
				arr[j][i] = 0;
			}

			int index = GRID_SIZE -1;
			while (!isEmpty(&stack)) {
				int a = 0;
				pop(&stack, &a);
				arr[index][i] = a;
				index--;
			}
		}
		break;
	case LEFT:
		for (int i = 0; i < GRID_SIZE; i++) {
			Stack stack = {};
			initStack(&stack);
			int prev = -1;
			for (int j = GRID_SIZE - 1; j >= 0; j--) {
				int curValue = arr[i][j];

				if (curValue == 0) continue;

				push(&stack, curValue);

				if (prev == curValue) {
					peek(&stack, &prev);
					int a = 0;
					pop(&stack, &a);
					pop(&stack, &a);
					push(&stack, a * 2);
					prev = -1;
				}
				else {
					prev = curValue;
				}
				arr[i][j] = 0;
			}

			int index = 0;
			while (!isEmpty(&stack)) {
				int a = 0;
				pop(&stack, &a);
				arr[i][index] = a;
				index++;
			}
		}
		break;
	case RIGHT:
		for (int i = 0; i < GRID_SIZE; i++) {
			Stack stack = {};
			initStack(&stack);
			int prev = -1;
			for (int j = 0; j < GRID_SIZE; j++) {
				int curValue = arr[i][j];

				if (curValue == 0) continue;

				push(&stack, curValue);

				if (prev == curValue) {
					peek(&stack, &prev);
					int a = 0;
					pop(&stack, &a);
					pop(&stack, &a);
					push(&stack, a * 2);
					prev = -1;
				}
				else {
					prev = curValue;
				}
				arr[i][j] = 0;
			}

			int index = GRID_SIZE-1;
			while (!isEmpty(&stack)) {
				int a = 0;
				pop(&stack, &a);
				arr[i][index] = a;
				index--;
			}
		}
		break;
	}
}

void spawnRandomTile(int arr[GRID_SIZE][GRID_SIZE]) {

	COORD pointList[GRID_SIZE * GRID_SIZE] = {NULL};

	int index = 0;
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			if (arr[i][j] == 0) {
				COORD pos = { i,j };
				pointList[index] = pos;
				index += 1;
			}
		}
	}

	if (index == 0) {
		printf("Game Over");
		Sleep(1000);
		exit(0);
	}

	int randomIndex = rand() % (index + 1);

	COORD Pos = pointList[randomIndex];

	arr[Pos.X][Pos.Y] = 2;

	GotoXY(0, 30);
}

int main()
{

	SetConsoleView();

	srand(time(NULL));

	int arr[GRID_SIZE][GRID_SIZE] = { NULL };

	spawnRandomTile(arr);

	while (true) {

		CreateTile(0,0);

		PrintTileValue(arr, 0, 0);

		GotoXY(0, 25);
		char input[10];
		printf("방향키를 입력하세요 (w, a, s, d): ");
		scanf_s("%s", input, sizeof(input));

		if (strcmp(input, "w") == 0) {
			MoveTiles(UP, arr);
		}
		else if (strcmp(input, "a") == 0) {
			MoveTiles(LEFT, arr);
		}
		else if (strcmp(input, "d") == 0) {
			MoveTiles(RIGHT, arr);
		}
		else if (strcmp(input, "s") == 0) {
			MoveTiles(DOWN, arr);
		}
		else {
			printf("잘못된 입력입니다.\n");
			Sleep(500);
			system("cls");
			continue;
		}

		spawnRandomTile(arr);

		system("cls");
	}

	return 0;
}
