// �������� ��� ����, �����ٿ� ���Ͽ� �� �ٿ��� ���� ���� �������� ������ ���� ������ ������ ����϶�
// �������� ��� �밢�� �ٿ� ���Ͽ� �� �ٿ��� ���� ���� �������� ������ ���� ������ ������ ����϶�
// ��� �����ٿ� ���ؼ��� ���� ���� �������� ������ ������ ��ġ�� ��ǥ�� ǥ���϶�

#include <iostream>
#include <string>
#include <limits>

using namespace std;

#define ROW 19
#define COL 19
#define L_To_R 37
#define R_To_L 37

string map[ROW][COL];

struct Line {
	int blackStone = 0;
	int whiteStone = 0;
	int longConsecutiveBlack = 0;
	int longConsecutiveWhite = 0;
};

void set() {
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			map[i][j] = "�� ";
		}
	}
}

void printMap(Line lines[ROW + COL + L_To_R + R_To_L]) {
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			cout << map[i][j];
		}
		cout << "   " << i << " : ���� b" << lines[i].blackStone << ", w" << lines[i].whiteStone <<
			",   ���� b" << lines[ROW + i].blackStone << ", w" << lines[ROW + i].whiteStone << '\n';
	}
}

void placeStone(string map[ROW][COL], int row, int col, string stone) {
	map[row][col] = stone;
}

bool isValidMove(string map[ROW][COL], int row, int col) {
	return (map[row][col] == "�� ");
}

void countStone(Line lines[ROW + COL + L_To_R + R_To_L], string map[ROW][COL], int row, int col ) {
	lines[row].blackStone = 0;
	lines[row].whiteStone = 0;

	lines[ROW + col].blackStone = 0;
	lines[ROW + col].whiteStone = 0;

	for (int i = 0; i < ROW; ++i) {
		if (map[row][i] == "�� ") {
			lines[row].blackStone++;
		}
		else if (map[row][i] == "�� ") {
			lines[row].whiteStone++;
		}

		if (map[i][col] == "�� ") {
			lines[ROW + col].blackStone++;
		}
		else if (map[i][col] == "�� ") {
			lines[ROW + col].whiteStone++;
		}
	}
}

void consecutiveStone(Line lines[ROW + COL + L_To_R + R_To_L], string map[ROW][COL], int row, int col, int l_to_r, int r_to_l) {
	lines[row].longConsecutiveBlack = 0;
	lines[row].longConsecutiveWhite = 0;

	lines[ROW + col].longConsecutiveBlack = 0;
	lines[ROW + col].longConsecutiveWhite = 0;

	lines[ROW + COL + l_to_r].longConsecutiveBlack = 0;
	lines[ROW + COL + l_to_r].longConsecutiveWhite = 0;

	lines[ROW + COL + L_To_R + r_to_l].longConsecutiveBlack = 0;
	lines[ROW + COL + L_To_R + r_to_l].longConsecutiveWhite = 0;

	int startCol = -1;
	for (int i = 0; i < ROW; ++i) {
		if (map[row][i] == "�� ") {
			lines[row].longConsecutiveBlack = 1;
			if (startCol == -1) {
				startCol = i;
			}
			if (map[row][i] == map[row][i + 1] && i + 1 < ROW) {
				lines[row].longConsecutiveBlack++;
			}
		}
		else if (map[row][i] == "�� ") {
			lines[row].longConsecutiveWhite = 1;
			if (startCol == -1) {
				startCol = i;
			}
			if (map[row][i] == map[row][i + 1] && i + 1 < ROW) {
				lines[row].longConsecutiveWhite++;
			}
		}
		if (lines[i].longConsecutiveBlack > lines[i].longConsecutiveWhite) {
			cout << i << " : ����, ������, ���Ӱ��� : " << lines[i].longConsecutiveBlack << '\n';
		}
		else if (lines[i].longConsecutiveBlack < lines[i].longConsecutiveWhite) {
			cout << i << " : ����, ��, ���Ӱ��� : " << lines[i].longConsecutiveWhite << '\n';
		}
		else if (lines[i].longConsecutiveBlack == lines[i].longConsecutiveWhite) {
			cout << i << " : ����, ������, ���Ӱ��� : " << lines[i].longConsecutiveBlack <<
				", : ����, ��, ���Ӱ��� : " << lines[i].longConsecutiveWhite << '\n';
		}
		if (startCol != -1 && (i == ROW - 1 || map[row][i] != map[row][i + 1])) {
			cout << row << " : ��ġ(" << row << ", " << startCol << ")~(" << row << ", " << i << ")" << '\n';
			startCol = -1;
		}
	}

	for (int i = 0; i < COL; ++i) {
		if (map[i][col] == "�� ") {
			lines[ROW + col].longConsecutiveBlack = 1;
			if (map[i][col] == map[i + 1][col] && i + 1 < COL) {
				lines[ROW + col].longConsecutiveBlack++;
			}
		}
		else if (map[i][col] == "�� ") {
			lines[ROW + col].longConsecutiveWhite = 1;
			if (map[i][col] == map[i + 1][col] && i + 1 < COL) {
				lines[ROW + col].longConsecutiveWhite++;
			}
		}
		if (lines[ROW + i].longConsecutiveBlack > lines[ROW + i].longConsecutiveWhite) {
			cout << i << " : ����, ������, ���Ӱ��� : " << lines[ROW + i].longConsecutiveBlack << '\n';
		}
		else if (lines[ROW + i].longConsecutiveBlack < lines[ROW + i].longConsecutiveWhite) {
			cout << i << " : ����, ��, ���Ӱ��� : " << lines[ROW + i].longConsecutiveWhite << '\n';
		}
		else if (lines[ROW + i].longConsecutiveBlack == lines[ROW + i].longConsecutiveWhite) {
			cout << i << " : ����, ������, ���Ӱ��� : " << lines[ROW + i].longConsecutiveBlack << 
				" : ����, ��, ���Ӱ��� : " << lines[ROW + i].longConsecutiveWhite << '\n';
		}
	}
	for (int i = 0; i < L_To_R; ++i) {
		int startRow = max(0, i - COL + 1);
		int startCol = min(i, COL - 1);

		for (int r = startRow, c = startCol; r + 1 < ROW && c + 1 < COL; ++r, ++c) {
			if (map[r][c] == "�� ") {
				lines[ROW + COL + i].longConsecutiveBlack++;
			}
			else if (map[r][c] == "�� ") {
				lines[ROW + COL + i].longConsecutiveWhite++;
			}
		}
		if (lines[ROW + COL + i].longConsecutiveBlack > lines[ROW + COL + i].longConsecutiveWhite) {
			cout << i << " : �밢��(�»��->���ϴ�), ������, ���Ӱ��� : " << lines[ROW + COL + i].longConsecutiveBlack << '\n';
		}
		else if (lines[ROW + COL + i].longConsecutiveBlack < lines[ROW + COL + i].longConsecutiveWhite) {
			cout << i << " : �밢��(�»��->���ϴ�), ��, ���Ӱ��� : " << lines[ROW + COL + i].longConsecutiveWhite << '\n';
		}
		else if (lines[ROW + COL + i].longConsecutiveBlack == lines[ROW + COL + i].longConsecutiveWhite) {
			cout << i << " : �밢��(�»��->���ϴ�), ������, ���Ӱ��� : " << lines[ROW + COL + i].longConsecutiveBlack <<
				" : �밢��(�»��->���ϴ�), ��, ���Ӱ��� : " << lines[ROW + COL + i].longConsecutiveWhite << '\n';
		}
	}

	for (int i = 0; i < R_To_L; ++i) {

		int startRow = min(i, ROW - 1);
		int startCol = max(0, COL - 1 - (i - ROW + 1));

		for (int r = startRow, c = startCol; r - 1 >= 0 && c + 1 < COL; --r, ++c) {
			if (map[r][c] == "�� ") {
				lines[ROW + COL + L_To_R + i].longConsecutiveBlack++;
			}
			else if (map[r][c] == "�� ") {
				lines[ROW + COL + L_To_R + i].longConsecutiveWhite++;
			}
		}
		if (lines[ROW + COL + L_To_R + i].longConsecutiveBlack > lines[ROW + COL + L_To_R + i].longConsecutiveWhite) {
			cout << i << " : �밢��(����->���ϴ�), ������, ���Ӱ��� : " << lines[ROW + COL + L_To_R + i].longConsecutiveBlack << '\n';
		}
		else if (lines[ROW + COL + L_To_R + i].longConsecutiveBlack < lines[ROW + COL + L_To_R + i].longConsecutiveWhite) {
			cout << i << " : �밢��(����->���ϴ�), ��, ���Ӱ��� : " << lines[ROW + COL + L_To_R + i].longConsecutiveWhite << '\n';
		}
		else if (lines[ROW + COL + L_To_R + i].longConsecutiveBlack == lines[ROW + COL + L_To_R + i].longConsecutiveWhite) {
			cout << i << " : �밢��(����->���ϴ�), ������, ���Ӱ��� : " << lines[ROW + COL + L_To_R + i].longConsecutiveBlack <<
				" : �밢��(����->���ϴ�), ��, ���Ӱ��� : " << lines[ROW + COL + L_To_R + i].longConsecutiveWhite << '\n';
		}
	}
}

int main() {
	Line lines[ROW + COL + L_To_R + R_To_L];
	int b_stone = 0, w_stone = 0;
	int row, col;
	int l_to_r = 0, r_to_l = 0;
	string currentPlayer = "�� ";
	string blackStone = "�� ";
	string whiteStone = "�� ";

	set();
	printMap(lines);

	while (true) {
		cout << "��ǥ�� �Է��ϼ��� : ���� ����" << '\n';
		cin >> row >> col;

		if (cin.fail() || row < 0 || row > 18 || col < 0 || col > 18) {
			cout << "������ �´� ���ڸ� �Է����ּ���(0~18)" << '\n';
			cout << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		if (!isValidMove(map, row, col)) {
			cout << "�̹� ���� �ֽ��ϴ�" << '\n';
			continue;
		}
		
		cout << '\n';

		placeStone(map, row, col, currentPlayer);

		countStone(lines, map, row, col);
		
		printMap(lines);
		consecutiveStone(lines, map, row, col, l_to_r, r_to_l);

		currentPlayer = (currentPlayer == "�� ") ? "�� " : "�� ";
	}
}