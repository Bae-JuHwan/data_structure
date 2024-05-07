#include <iostream>
#include <fstream>
#include <memory>

using namespace std;

enum Stone {
	NONE,
	BLACK,
	WHITE,
};

struct Node {
	int x;
	int y;
	struct Node* next;
	struct Node* prev;

	Node(int x, int y) : x(x), y(y), next(nullptr), prev(nullptr) {}
};

Node* make_turn(int a, int b, Node* p);
void save(int count);
void load(int count, Node* p);
void undo(int&, Node*, int board[19][19]);
void redo(int&, Node*&, int board[19][19]);

int main() {
	char key;
	int count = 0, i = 0, j = 0;
	const int BOARD_SIZE = 19;
	int board[BOARD_SIZE][BOARD_SIZE] = { 0 };
	Node* plist = nullptr;
	Node* temp = nullptr;

	while (true) {
		for (i = 0; i < BOARD_SIZE; ++i) {
			for (j = 0; j < BOARD_SIZE; ++j) {
				switch (board[i][j]) {
				case BLACK:
					cout << "�� ";
					break;
				case WHITE:
					cout << "�� ";
					break;
				default:
					cout << "�� ";
					break;
				}
			}
			cout << '\n';
		}

		if (count % 2 == 0) {
			int row, col;
			do {
				cout << "�������� ���� ���� 0~18�� ���ڸ� �Է����ּ��� : ";
				cin >> row >> col;

				if (!(row >= 0 && row < 19 && col >= 0 && col < 19)) {
					cout << "�߸��� ��ġ�Դϴ�. �ٽ� �Է��ϼ���" << '\n';
					continue;
				}
				if (board[row][col] != NONE) {
					cout << "�̹� ���� �����ֽ��ϴ�. �ٸ� ��ġ�� �����ϼ���" << '\n';
					continue;
				}
				break;
			} while (true);
			board[row][col] = BLACK;
			plist = make_turn(row, col, plist);
		}
		else {
			int row, col;
			do {
				cout << "���� ���� ���� 0~18�� ���ڸ� �Է����ּ��� : ";
				cin >> row >> col;

				if (!(row >= 0 && row < 19 && col >= 0 && col < 19)) {
					cout << "�߸��� ��ġ�Դϴ�. �ٽ� �Է��ϼ���" << '\n';
					continue;
				}
				if (board[row][col] != NONE) {
					cout << "�̹� ���� �����ֽ��ϴ�. �ٸ� ��ġ�� �����ϼ���" << '\n';
					continue;
				}
				break;
			} while (true);
			board[row][col] = WHITE;
			plist = make_turn(row, col, plist);
		}
		count++;

		cout << "��ɾ �Է��ϼ���(S : save, L : load, U : undo, R : redo) : ";
		cin >> key;
		switch (key) {
		case 'S':
			save(count);
			break;
		case 'L':
			load(count, plist);
			break;
		case 'U':
			undo(count, plist, board);
			break;
		case 'R':
			redo(count, *&plist, board);
			break;
		default:
			cout << "��ɾ �߸��Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���" << '\n';
			break;
		}
	}
	return 0;
}

Node* make_turn(int a, int b, Node* p) {
	Node* pnew = new Node(a, b);

	if (!pnew) {
		cout << "�޸� ����!" << '\n';
	}
	else {
		pnew->x = a;
		pnew->y = b;

		if (p == NULL) {
			pnew->prev = NULL;
			pnew->next = NULL;
			p = pnew;
		}
		else {
			p->next = pnew;
			pnew->prev = p;
			pnew->next = NULL;
			p = pnew;
		}
	}
	return p;
}

void save(int count) {
	ifstream file("save.txt");
	Node* p = nullptr;

	if (file.is_open()) {
		file >> count;
		for (int i = 0; i < count; ++i) {
			int x, y;
			file >> x >> y;
			p = (x, y, p);
		}
		file.close();
	}
	else {
		cerr << "�ε� �� ������ �� �� �����ϴ�" << '\n';
	}
	return;
}

void load(int count, Node* p) {
	ofstream file("save.txt");
	if (file.is_open()) {
		file << count << '\n';
		while (p) {
			file << p->x << " " << p->y << '\n';
			p = p->next;
		}
		file.close();
	}
	else {
		cerr << "���̺� �� ������ �� �� �����ϴ�" << '\n';
	}
}

void undo(int& count, Node* p, int board[19][19]) {
	if (p) {
		board[p->x][p->y] = NONE;
		p = p->prev;
		count--;
	}
	else {
		cout << "������ �� ���� �����ϴ�" << '\n';
	}
}

void redo(int& count, Node*& p, int board[19][19]) {
	if (p && p->next) {
		p = p->next;
		board[p->x][p->y] = (count % 2 == 0) ? BLACK : WHITE;
		count++;
	}
	else {
		cout << "�����⸦ ����� ���� �����ϴ�" << '\n';
	}
}