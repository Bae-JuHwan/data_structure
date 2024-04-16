#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define SIZE 19

void printBoard(char board[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}

void placeStone(char board[SIZE][SIZE], int row, int col, char stone) {
	board[row][col] = stone;
}

bool isValidMove(char board[SIZE][SIZE], int row, int col) {
	return (board[row][col] == '+');
}

void countStones(char board[SIZE][SIZE], int* blackStone, int* whiteStone) {
	*blackStone = 0;
	*whiteStone = 0;
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (board[i][j] == 'o') {
				(*blackStone)++;
			}
			else if (board[i][j] == 'x') {
				(*whiteStone)++;
			}
		}
	}
}

int main() {
	char board[SIZE][SIZE];
	int row, col;
	char currentPlayer = 'o';
	int blackStone, whiteStone;

	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			board[i][j] = '+';
		}
	}

	while (true) {
		printBoard(board);
		printf("\n��ǥ�� �Է��ϼ���(����,����) : ");
		scanf("%d,%d", &row, &col);

		if (!isValidMove(board, row, col)) {
			printf("�̹� ���� ���� �ֽ��ϴ�\n");
			continue;
		}

		placeStone(board, row, col, currentPlayer);

		countStones(board, &blackStone, &whiteStone);
		printf("���� �� ���� : %d, �� �� ���� : %d\n", blackStone, whiteStone);

		currentPlayer = (currentPlayer == 'o') ? 'x' : 'o';
	}
	return 0;
}