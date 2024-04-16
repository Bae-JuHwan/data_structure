// LOLè�Ǿ��� 6���� ����(name, hp, mp, speed, range, position)�� ����
// Search[è�Ǿ��̸�] : �־��� è�Ǿ��� ���� ���
// Insert : ���ο� è�Ǿ��� ������ �Է¹޾� ����
// Delete[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���� ����
// DeleteAll[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����
// PrintAll : ��� è�Ǿ��� ������ �迭�� ����� ������� ���
// FindMaxHp : ���� ü���� ū è�Ǿ��� ���� ���
// SortbyHp : ü���� ū è�Ǿ���� ������� ����

#include <iostream>
#include <string>

using namespace std;

struct Player {
	string name;
	int health;
	int mana;
	int speed;
	int range;
	string position;
};

int main() {
	int DATA_COUNT = 22;

	Player players[300];

	players[0] = { "Jayce", 3466, 8307, 452, 73, "mid" };
	players[1] = { "Vayne",	3318, 2790, 390, 60, "support" };
	players[2] = { "Lee Sin", 9864, 6257, 747, 19, "support" };
	players[3] = { "Teemo", 1915, 1313, 700, 68, "mid" };
	players[4] = { "Nami", 2968, 2153, 803, 74, "support" };
	players[5] = { "Jinx", 2583, 3042, 123, 53, "jungle" };
	players[6] = { "Cassiopeia", 6067, 7330, 683, 24, "top" };
	players[7] = { "Ahri", 4573, 7079, 177, 79, "top" };
	players[8] = { "Fiora", 2591, 9329, 337, 81, "jungle" };
	players[9] = { "Zac", 9864, 7272, 405, 49, "bottom" };
	players[10] = { "Janna", 4922, 2275, 690, 66, "jungle" };
	players[11] = { "Ashe", 7421, 5549, 428, 31, "top" };
	players[12] = { "Twitch", 2980, 7703, 204, 91, "mid" };
	players[13] = { "Ezreal", 3660, 9835, 274, 44, "mid" };
	players[14] = { "Sona", 5655, 8442, 252, 26, "bottom" };
	players[15] = { "Lulu", 3231, 2014, 503, 32, "support" };
	players[16] = { "Amumu",	6763, 3994, 427, 19, "jungle" };
	players[17] = { "Master Yi", 5737, 7168, 434, 61, "top" };
	players[18] = { "Jarvan", 1895, 3070, 323, 80, "mid" };
	players[19] = { "Shen", 4794, 9220, 783, 42, "mid" };
	players[20] = { "Fizz", 9864, 1913, 433,	38, "bottom" };
	players[21] = { "Taric", 6158, 7451, 160, 36, "bottom" };

	for (int i = DATA_COUNT; i < 300; ++i) {
		players[i] = { "", 0, 0, 0, 0, "" };
	}

	cout << "��ɾ �Է��ϼ���" << '\n';
	cout << "Search[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���" << '\n';
	cout << "Insert : ���ο� è�Ǿ� ���� ����" << '\n';
	cout << "Delete[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ����" << '\n';
	cout << "DeleteAll[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����" << '\n';
	cout << "PrintAll : �迭�� ����� è�Ǿ� ������ ������� ���" << "\n";
	cout << "FindMaxHp : ü���� ���� ū è�Ǿ� ���� ���" << '\n';
	cout << "SortByHp : ü���� ���� ������� �迭�� ����" << '\n';
	cout << '\n';

	while (true) {
		string command;
		getline(cin, command);

		if (command.substr(0, 7) == "Search[") {
			size_t startPos = command.find('[');
			size_t endPos = command.find(']');

			if (startPos != string::npos && endPos != string::npos && endPos > startPos + 1) {
				string championName = command.substr(startPos + 1, endPos - startPos - 1);
				bool found = false;

				for (int i = 0; i < DATA_COUNT; ++i) {
					if (players[i].name == championName) {
						found = true;
						cout << "è�Ǿ� �̸� : " << players[i].name << '\n';
						cout << "ü�� : " << players[i].health << '\n';
						cout << "���� : " << players[i].mana << '\n';
						cout << "�ӵ� : " << players[i].speed << '\n';
						cout << "��Ÿ� : " << players[i].range << '\n';
						cout << "������ : " << players[i].position << '\n';
						cout << "\n";
					}
				}
				if (!found) {
					cout << "�߸��� è�Ǿ��Դϴ�. �ٽ� �Է����ּ���" << '\n';
					cout << '\n';
				}
			}
			cout << "��ɾ �Է��ϼ���" << '\n';
			cout << "Search[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���" << '\n';
			cout << "Insert : ���ο� è�Ǿ� ���� ����" << '\n';
			cout << "Delete[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ����" << '\n';
			cout << "DeleteAll[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����" << '\n';
			cout << "PrintAll : �迭�� ����� è�Ǿ� ������ ������� ���" << "\n";
			cout << "FindMaxHp : ü���� ���� ū è�Ǿ� ���� ���" << '\n';
			cout << "SortByHp : ü���� ���� ������� �迭�� ����" << '\n';
			cout << '\n';
		}
		else if (command == "Insert") {
			if (DATA_COUNT < 300) {
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

				players[DATA_COUNT++] = newPlayer;
			}
			cout << "��ɾ �Է��ϼ���" << '\n';
			cout << "Search[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���" << '\n';
			cout << "Insert : ���ο� è�Ǿ� ���� ����" << '\n';
			cout << "Delete[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ����" << '\n';
			cout << "DeleteAll[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����" << '\n';
			cout << "PrintAll : �迭�� ����� è�Ǿ� ������ ������� ���" << "\n";
			cout << "FindMaxHp : ü���� ���� ū è�Ǿ� ���� ���" << '\n';
			cout << "SortByHp : ü���� ���� ������� �迭�� ����" << '\n';
			cout << '\n';

			cin.ignore();
		}
		else if (command.substr(0, 7) == "Delete[") {
			size_t startPos = command.find('[');
			size_t endPos = command.find(']');

			if (startPos != string::npos && endPos != string::npos && endPos > startPos + 1) {
				string championName = command.substr(startPos + 1, endPos - startPos - 1);
				bool deleted = false;

				for (int i = 0; i < DATA_COUNT; ++i) {
					if (players[i].name == championName) {
						deleted = true;
						players[i] = Player();
						cout << "�ش� è�Ǿ��� ������ �����߽��ϴ�" << '\n';
						cout << '\n';
					}
				}
				if (!deleted) {
					cout << "�߸��� �����Դϴ�. �ٽ� �Է����ּ���" << '\n';
					cout << '\n';
				}
			}
			cout << "��ɾ �Է��ϼ���" << '\n';
			cout << "Search[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���" << '\n';
			cout << "Insert : ���ο� è�Ǿ� ���� ����" << '\n';
			cout << "Delete[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ����" << '\n';
			cout << "DeleteAll[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����" << '\n';
			cout << "PrintAll : �迭�� ����� è�Ǿ� ������ ������� ���" << "\n";
			cout << "FindMaxHp : ü���� ���� ū è�Ǿ� ���� ���" << '\n';
			cout << "SortByHp : ü���� ���� ������� �迭�� ����" << '\n';
			cout << '\n';
		}
		else if (command.substr(0, 10) == "DeleteAll[") {
			size_t startPos = command.find('[');
			size_t endPos = command.find(']');

			if (startPos != string::npos && endPos != string::npos && endPos > startPos + 1) {
				string position = command.substr(startPos + 1, endPos - startPos - 1);
				bool deleted = false;

				for (int i = 0; i < DATA_COUNT; ++i) {
					if (players[i].position == position) {
						deleted = true;
						players[i] = Player();
					}
				}
				if (deleted) {
					cout << position << "�� ��� è�Ǿ� ������ �����Ǿ����ϴ�" << '\n';
					cout << '\n';
				}
			}
			cout << "��ɾ �Է��ϼ���" << '\n';
			cout << "Search[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���" << '\n';
			cout << "Insert : ���ο� è�Ǿ� ���� ����" << '\n';
			cout << "Delete[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ����" << '\n';
			cout << "DeleteAll[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����" << '\n';
			cout << "PrintAll : �迭�� ����� è�Ǿ� ������ ������� ���" << "\n";
			cout << "FindMaxHp : ü���� ���� ū è�Ǿ� ���� ���" << '\n';
			cout << "SortByHp : ü���� ���� ������� �迭�� ����" << '\n';
			cout << '\n';
		}
		else if (command == "PrintAll") {
			cout << "�迭�� ����� è�Ǿ� ������ ������� ����մϴ�" << '\n';
			for (int i = 0; i < DATA_COUNT; ++i) {
				if (players[i].name != "") {
					cout << players[i].name << ", " << players[i].health << ", " << players[i].mana << ", " <<
						players[i].speed << ", " << players[i].range << ", " << players[i].position << '\n';
					cout << '\n';
				}
			}
			cout << "��ɾ �Է��ϼ���" << '\n';
			cout << "Search[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���" << '\n';
			cout << "Insert : ���ο� è�Ǿ� ���� ����" << '\n';
			cout << "Delete[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ����" << '\n';
			cout << "DeleteAll[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����" << '\n';
			cout << "PrintAll : �迭�� ����� è�Ǿ� ������ ������� ���" << "\n";
			cout << "FindMaxHp : ü���� ���� ū è�Ǿ� ���� ���" << '\n';
			cout << "SortByHp : ü���� ���� ������� �迭�� ����" << '\n';
			cout << '\n';
		}
		else if (command == "FindMaxHp") {
			int maxHealth = -1;
			cout << "ü���� ���� ū è�Ǿ� ���� ���" << '\n';
			cout << '\n';
			for (int i = 0; i < DATA_COUNT; ++i) {
				if (players[i].health > maxHealth) {
					maxHealth = players[i].health;
				}
			}
			for (int i = 0; i < DATA_COUNT; ++i) {
				if (players[i].health == maxHealth) {
					cout << "è�Ǿ� �̸� : " << players[i].name << '\n';
					cout << "ü�� : " << players[i].health << '\n';
					cout << "���� : " << players[i].mana << '\n';
					cout << "�ӵ� : " << players[i].speed << '\n';
					cout << "��Ÿ� : " << players[i].range << '\n';
					cout << "������ : " << players[i].position << '\n';
					cout << "\n";
				}
			}
			cout << "��ɾ �Է��ϼ���" << '\n';
			cout << "Search[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���" << '\n';
			cout << "Insert : ���ο� è�Ǿ� ���� ����" << '\n';
			cout << "Delete[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ����" << '\n';
			cout << "DeleteAll[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����" << '\n';
			cout << "PrintAll : �迭�� ����� è�Ǿ� ������ ������� ���" << "\n";
			cout << "FindMaxHp : ü���� ���� ū è�Ǿ� ���� ���" << '\n';
			cout << "SortByHp : ü���� ���� ������� �迭�� ����" << '\n';
			cout << '\n';
		}
		else if (command == "SortByHp") {
			cout << "ü���� ���� ������� �迭�� �����մϴ�" << '\n';
			cout << '\n';
			for (int i = 0; i < DATA_COUNT; ++i) {
				for (int j = 0; j < DATA_COUNT - i - 1; ++j) {
					if (players[j].health < players[j + 1].health) {
						Player temp = players[j];
						players[j] = players[j + 1];
						players[j + 1] = temp;
					}
				}
			}
			cout << "��ɾ �Է��ϼ���" << '\n';
			cout << "Search[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���" << '\n';
			cout << "Insert : ���ο� è�Ǿ� ���� ����" << '\n';
			cout << "Delete[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ����" << '\n';
			cout << "DeleteAll[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����" << '\n';
			cout << "PrintAll : �迭�� ����� è�Ǿ� ������ ������� ���" << "\n";
			cout << "FindMaxHp : ü���� ���� ū è�Ǿ� ���� ���" << '\n';
			cout << "SortByHp : ü���� ���� ������� �迭�� ����" << '\n';
			cout << '\n';
		}
		else {
			cout << "�߸��Է��Ͽ����ϴ�. �ٽ� �Է����ּ���" << '\n';
			cout << '\n';
		}
	}
}