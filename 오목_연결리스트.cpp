#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define ROW 19
#define COL 19

string map[ROW][COL];

void set() {
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			map[i][j] = "□ ";
		}
	}
}

void printMap() {
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			cout << map[i][j];
		}
		cout << '\n';
	}
}

void placeStone(string map[ROW][COL], int row, int col, string stone) {
	map[row][col] = stone;
}

int main() {
	map[ROW - 1][COL - 1];
	int b_stone = 0, w_stone = 0;
	int row, col;
	string blackStone = "● ";
	string whiteStone = "○ ";

	set();

	while (true) {
		printMap();
		cout << "좌표를 입력하세요 : 숫자 숫자" << '\n';
		cin >> row >> col;
		if (cin.fail()) {
			cout << "숫자를 입력해주세요" << '\n';
			cout << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		cout << "   가로		세로" << '\n';
		for (int i = 0; i < ROW; ++i) {
			cout << setw(2) << i << " : b" << b_stone << ", w" << w_stone << "  | " << i << " : b" << b_stone << ", w" << w_stone << '\n';
		}
		cout << '\n';
		placeStone(map, row, col, blackStone);
	}
}