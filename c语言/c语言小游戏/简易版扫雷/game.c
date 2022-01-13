#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set) {
	int i = 0, j = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			board[i][j] = set;
		}
	}
}
void  DisplayBoard(char board[ROWS][COLS], int row, int col) {
	int i = 1, j = 1;
	//打印列号
	for (i = 0; i <= row; i++) {
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++) {
		printf("%d ", i);
		for (j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void SetMine(char board[ROWS][COLS], int row, int col) {
	int count = EASY_COUNT;
	while (count) {
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0') {
			board[x][y] = '1';
			count--;
		}
	}
}
int MineCount(char mine[ROWS][COLS], int x, int y) {
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1]
		+ mine[x][y - 1] + mine[x][y + 1]
		+ mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1]
		- 8 * '0';
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	int win = 0;
	while (win < row * col - EASY_COUNT) {
		printf("请输入排查雷的坐标：");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (mine[x][y] == '1') {
				printf("您踩到了雷！\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else {
				int count = MineCount(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else {
			printf("输入的坐标非法，请从重新输入！");
		}
	}
	if (win == row * col - EASY_COUNT) {
		printf("恭喜您 过关！\n");
		DisplayBoard(mine, row, col);
	}
}

