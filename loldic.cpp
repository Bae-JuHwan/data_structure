// Search_R[è�Ǿ��̸�] : �־��� è�Ǿ��� ������ ���
// Insert_R : ���ο� è�Ǿ��� ������ �Է¹޾� ����
// Delete_R[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���� ����
// DeleteAll_R[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����
// PrintAll_R : ��� è�Ǿ��� ������ �迭�� ����� ������� ���
// FindMaxHp_R : ���� ü���� ū è�Ǿ��� ������ ���
// SortByHp_R : ü���� ū è�Ǿ���� ������� ���

#include <iostream>
#include <string>

#define MAX 300
using namespace std;

struct Player {
	string name;
	int health;
	int mana;
	int speed;
	int range;
	string position;
};

int SearchRecursive(struct Player* players, int max, int i, string* championName ) {
	if (i == MAX) {
		return 0;
	}
	else if(*championName == players[i].name) {
		cout << "�̸� : " << players[i].name << ", ü�� : " << players[i].health << ", ���� : " << players[i].mana
			<< ", �ӵ� : " << players[i].speed << ", ��Ÿ� : " << players[i].range << ", ������ : " << players[i].position << '\n';
		cout << "\n";
	}
	SearchRecursive(players, max, ++i,championName);
}

int InsertRecursive(struct Player* players, int max, int i) {
	if (i == MAX) {
		cout << "�� �̻� �߰��� �� �����ϴ�" << '\n';
		return 0;
	}
	else if (players[i].name == "") {
		Player newPlayer;
		cout << "���ο� è�Ǿ� ������ �Է��ϼ���" << '\n';
		cout << "è�Ǿ��̸� : ";
		cin >> newPlayer.name;
		cout << "ü�� : ";
		cin >> newPlayer.health;
		cout << "���� : ";
		cin >> newPlayer.mana;
		cout << "�ӵ� : ";
		cin >> newPlayer.speed;
		cout << "��Ÿ� : ";
		cin >> newPlayer.range;
		cout << "������ : ";
		cin >> newPlayer.position;
		cout << '\n';
		players[i] = newPlayer;
		return 0;
	}
	InsertRecursive(players, MAX, ++i);
}

int DeleteRecursive(struct Player* players, int max, int i, string* championName) {
	if (i == MAX) {
		return 0;
	}
	else if (*championName == players[i].name) {
		players[i] = Player();
		cout << "�ش� è�Ǿ��� ������ �����߽��ϴ�" << '\n';
		cout << '\n';
	}
	DeleteRecursive(players, max, ++i, championName);
}

int DeleteAllRecursive(struct Player* players, int max, int i, string* position) {
	if (i == MAX) {
		return 0;
	}
	else if (*position == players[i].position){
		players[i] = Player();
	}
	DeleteAllRecursive(players, max, ++i, position);
}

int PrintAllRecursive(struct Player* players, int max, int i) {
	if (i == MAX) {
		return 0;
	}
	else if (players[i].name != "") {
		cout << "�̸� : " << players[i].name << ", ü�� : " << players[i].health << ", ���� : " << players[i].mana
			<< ", �ӵ� : " << players[i].speed << ", ��Ÿ� : " << players[i].range << ", ������ : " << players[i].position << '\n';
		cout << "\n";
	}
	PrintAllRecursive(players, MAX, ++i);
}

int FindMaxHpRecursive(struct Player* players, int max, int i, int MaxHealth) {
	if (i == MAX) {
		return 0;
	}
	if (players[i].health > MaxHealth) {
		MaxHealth = players[i].health;
	}

	if (players[i].health == MaxHealth) {
		cout << "�̸� : " << players[i].name << '\n';
		cout << "ü�� : " << players[i].health << '\n';
		cout << "���� : " << players[i].mana << '\n';
		cout << "�ӵ�: " << players[i].speed << '\n';
		cout << "��Ÿ� : " << players[i].range << '\n';
		cout << "������ : " << players[i].position << '\n';
		cout << '\n';
	}
	FindMaxHpRecursive(players, MAX, ++i, MaxHealth);
}

int SortByHpRecursive(struct Player* players, int max, int i) {
	if (i == MAX) {
		return 0;
	}
	else {
		for (int j = 0; j < MAX - i - 1; ++j) {
			if (players[j].health < players[j + 1].health) {
				Player temp = players[j];
				players[j] = players[j + 1];
				players[j + 1] = temp;
			}
		}
	}
	SortByHpRecursive(players, MAX, ++i);
}

int main() {
	Player players[MAX] = {
		{ "Jayce", 3466, 8307, 452, 73, "mid" },
		{ "Vayne", 3318, 2790, 390, 60, "support" },
		{ "Lee Sin", 9864, 6257, 747, 19, "support" },
		{ "Teemo", 1915, 1313, 700, 68, "mid" },
		{ "Nami", 2968, 2153, 803, 74, "support" },
		{ "Jinx", 2583, 3042, 123, 53, "jungle" },
		{ "Cassiopeia", 6067, 7330, 683, 24, "top" },
		{ "Ahri", 4573, 7079, 177, 79, "top" },
		{ "Fiora", 2591, 9329, 337, 81, "jungle" },
		{ "Zac", 9864, 7272, 405, 49, "bottom" },
		{ "Janna", 4922, 2275, 690, 66, "jungle" },
		{ "Ashe", 7421, 5549, 428, 31, "top" },
		{ "Twitch", 2980, 7703, 204, 91, "mid" },
		{ "Ezreal", 3660, 9835, 274, 44, "mid" },
		{ "Sona", 5655, 8442, 252, 26, "bottom" },
		{ "Lulu", 3231, 2014, 503, 32, "support" },
		{ "Amumu", 6763, 3994, 427, 19, "jungle" },
		{ "Master Yi", 5737, 7168, 434, 61, "top" },
		{ "Jarvan", 1895, 3070, 323, 80, "mid" },
		{ "Shen", 4794, 9220, 783, 42, "mid" },
		{ "Fizz", 9864, 1913, 433, 38, "bottom" },
		{ "Taric", 6158, 7451, 160, 36, "bottom" }
	};

	for (int i = 22; i < 300; ++i) {
		players[i] = { "", 0, 0, 0, 0, "" };
	}

	cout << "��ɾ �Է��ϼ���" << '\n';
	cout << "Search_R[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���" << '\n';
	cout << "Insert_R : ���ο� è�Ǿ� ���� ����" << '\n';
	cout << "Delete_R[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ����" << '\n';
	cout << "DeleteAll_R[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����" << '\n';
	cout << "PrintAll_R : �迭�� ����� è�Ǿ� ������ ������� ���" << "\n";
	cout << "FindMaxHp_R : ü���� ���� ū è�Ǿ� ���� ���" << '\n';
	cout << "SortByHp_R : ü���� ���� ������� �迭�� ����" << '\n';
	cout << '\n';

	while (true) {
		string command;
		getline(cin, command);

		if (command.find("Search_R") != string::npos) {
			size_t start = command.find('[');
			size_t end = command.find(']');
			if (start != string::npos && end != string::npos && end > start + 1) {
				string championName = command.substr(start + 1, end - start - 1); 
				
				SearchRecursive(players, MAX, 0, &championName);
			}
			else {
				cout << "�߸��� ��ɾ� �Դϴ�." << '\n';
				cout << '\n';
			}
			cout << "��ɾ �Է��ϼ���" << '\n';
			cout << "Search_R[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���" << '\n';
			cout << "Insert_R : ���ο� è�Ǿ� ���� ����" << '\n';
			cout << "Delete_R[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ����" << '\n';
			cout << "DeleteAll_R[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����" << '\n';
			cout << "PrintAll_R : �迭�� ����� è�Ǿ� ������ ������� ���" << "\n";
			cout << "FindMaxHp_R : ü���� ���� ū è�Ǿ� ���� ���" << '\n';
			cout << "SortByHp_R : ü���� ���� ������� �迭�� ����" << '\n';
			cout << '\n';
		}

		else if (command == "Insert_R") {
			InsertRecursive(players, MAX, 0);
			cout << "���ο� è�Ǿ� ������ �߰��Ǿ����ϴ�" << '\n';
			cout << '\n';
			cout << "��ɾ �Է��ϼ���" << '\n';
			cout << "Search_R[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���" << '\n';
			cout << "Insert_R : ���ο� è�Ǿ� ���� ����" << '\n';
			cout << "Delete_R[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ����" << '\n';
			cout << "DeleteAll_R[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����" << '\n';
			cout << "PrintAll_R : �迭�� ����� è�Ǿ� ������ ������� ���" << "\n";
			cout << "FindMaxHp_R : ü���� ���� ū è�Ǿ� ���� ���" << '\n';
			cout << "SortByHp_R : ü���� ���� ������� �迭�� ����" << '\n';
			cout << '\n';
			cin.ignore();
		}

		else if (command.find("Delete_R") != string::npos) {
			size_t start = command.find('[');
			size_t end = command.find(']');
			if (start != string::npos && end != string::npos && end > start + 1) {
				string championName = command.substr(start + 1, end - start - 1);

				DeleteRecursive(players, MAX, 0, &championName);
			}
			else {
				cout << "�߸��� ��ɾ� �Դϴ�." << '\n';
				cout << '\n';
			}
			cout << "��ɾ �Է��ϼ���" << '\n';
			cout << "Search_R[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���" << '\n';
			cout << "Insert_R : ���ο� è�Ǿ� ���� ����" << '\n';
			cout << "Delete_R[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ����" << '\n';
			cout << "DeleteAll_R[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����" << '\n';
			cout << "PrintAll_R : �迭�� ����� è�Ǿ� ������ ������� ���" << "\n";
			cout << "FindMaxHp_R : ü���� ���� ū è�Ǿ� ���� ���" << '\n';
			cout << "SortByHp_R : ü���� ���� ������� �迭�� ����" << '\n';
			cout << '\n';
		}

		else if (command.find("DeleteAll_R") != string::npos) {
			size_t start = command.find('[');
			size_t end = command.find(']');
			if (start != string::npos && end != string::npos && end > start + 1) {
				string position = command.substr(start + 1, end - start - 1);

				DeleteAllRecursive(players, MAX, 0, &position);

				cout << position << "�� ��� è�Ǿ� ������ �����߽��ϴ�" << '\n';
				cout << '\n';
			}
			else {
				cout << "�߸��� ��ɾ� �Դϴ�" << '\n';
				cout << '\n';
			}
			cout << "��ɾ �Է��ϼ���" << '\n';
			cout << "Search_R[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���" << '\n';
			cout << "Insert_R : ���ο� è�Ǿ� ���� ����" << '\n';
			cout << "Delete_R[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ����" << '\n';
			cout << "DeleteAll_R[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����" << '\n';
			cout << "PrintAll_R : �迭�� ����� è�Ǿ� ������ ������� ���" << "\n";
			cout << "FindMaxHp_R : ü���� ���� ū è�Ǿ� ���� ���" << '\n';
			cout << "SortByHp_R : ü���� ���� ������� �迭�� ����" << '\n';
			cout << '\n';
		}

		else if (command == "PrintAll_R") {
			cout << "�迭�� ����� è�Ǿ� ������ ������� ����մϴ�" << '\n';
			cout << '\n';
			PrintAllRecursive(players, MAX, 0);
			
			cout << "��ɾ �Է��ϼ���" << '\n';
			cout << "Search_R[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���" << '\n';
			cout << "Insert_R : ���ο� è�Ǿ� ���� ����" << '\n';
			cout << "Delete_R[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ����" << '\n';
			cout << "DeleteAll_R[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����" << '\n';
			cout << "PrintAll_R : �迭�� ����� è�Ǿ� ������ ������� ���" << "\n";
			cout << "FindMaxHp_R : ü���� ���� ū è�Ǿ� ���� ���" << '\n';
			cout << "SortByHp_R : ü���� ���� ������� �迭�� ����" << '\n';
			cout << '\n';
		}

		else if (command == "FindMaxHp_R") {
			cout << "ü���� ���� ū è�Ǿ� ������ ����մϴ�" << '\n';
			cout << '\n';
			FindMaxHpRecursive(players, MAX, 0, numeric_limits<int>::min());
			cout << "��ɾ �Է��ϼ���" << '\n';
			cout << "Search_R[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���" << '\n';
			cout << "Insert_R : ���ο� è�Ǿ� ���� ����" << '\n';
			cout << "Delete_R[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ����" << '\n';
			cout << "DeleteAll_R[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����" << '\n';
			cout << "PrintAll_R : �迭�� ����� è�Ǿ� ������ ������� ���" << "\n";
			cout << "FindMaxHp_R : ü���� ���� ū è�Ǿ� ���� ���" << '\n';
			cout << "SortByHp_R : ü���� ���� ������� �迭�� ����" << '\n';
			cout << '\n';
		}

		else if (command == "SortByHp_R") {
			SortByHpRecursive(players, MAX, 0);
			cout << "ü���� ���� ������� è�Ǿ� ������ ���ĵǾ����ϴ�" << '\n';
			cout << '\n';
			cout << "��ɾ �Է��ϼ���" << '\n';
			cout << "Search_R[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���" << '\n';
			cout << "Insert_R : ���ο� è�Ǿ� ���� ����" << '\n';
			cout << "Delete_R[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ����" << '\n';
			cout << "DeleteAll_R[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����" << '\n';
			cout << "PrintAll_R : �迭�� ����� è�Ǿ� ������ ������� ���" << "\n";
			cout << "FindMaxHp_R : ü���� ���� ū è�Ǿ� ���� ���" << '\n';
			cout << "SortByHp_R : ü���� ���� ������� �迭�� ����" << '\n';
			cout << '\n';
		}
		else {
			cout << "�߸� �Է��Ͽ����ϴ�. �ٽ� �Է����ּ���" << '\n';
			cout << '\n';
		}
	}
}