// LOL챔피언의 6가지 정보(name, hp, mp, speed, range, position)를 관리
// Search[챔피언이름] : 주어진 챔피언의 정보 출력
// Insert : 새로운 챔피언의 정보를 입력받아 삽입
// Delete[챔피언이름] : 주어진 챔피언에 대한 정보 삭제
// DeleteAll[position] : 주어진 위치의 모든 챔피언 정보 삭제
// PrintAll : 모든 챔피언의 정보를 배열에 저장된 순서대로 출력
// FindMaxHp : 가장 체력이 큰 챔피언의 정보 출력
// SortbyHp : 체력이 큰 챔피언부터 순서대로 저장

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

	cout << "명령어를 입력하세요" << '\n';
	cout << "Search[챔피언이름] : 주어진 챔피언 정보 출력" << '\n';
	cout << "Insert : 새로운 챔피언 정보 삽입" << '\n';
	cout << "Delete[챔피언이름] : 주어진 챔피언 정보 삭제" << '\n';
	cout << "DeleteAll[position] : 주어진 위치의 모든 챔피언 정보 삭제" << '\n';
	cout << "PrintAll : 배열에 저장된 챔피언 정보를 순서대로 출력" << "\n";
	cout << "FindMaxHp : 체력이 가장 큰 챔피언 정보 출력" << '\n';
	cout << "SortByHp : 체력이 높은 순서대로 배열에 저장" << '\n';
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
						cout << "챔피언 이름 : " << players[i].name << '\n';
						cout << "체력 : " << players[i].health << '\n';
						cout << "마나 : " << players[i].mana << '\n';
						cout << "속도 : " << players[i].speed << '\n';
						cout << "사거리 : " << players[i].range << '\n';
						cout << "포지션 : " << players[i].position << '\n';
						cout << "\n";
					}
				}
				if (!found) {
					cout << "잘못된 챔피언입니다. 다시 입력해주세요" << '\n';
					cout << '\n';
				}
			}
			cout << "명령어를 입력하세요" << '\n';
			cout << "Search[챔피언이름] : 주어진 챔피언 정보 출력" << '\n';
			cout << "Insert : 새로운 챔피언 정보 삽입" << '\n';
			cout << "Delete[챔피언이름] : 주어진 챔피언 정보 삭제" << '\n';
			cout << "DeleteAll[position] : 주어진 위치의 모든 챔피언 정보 삭제" << '\n';
			cout << "PrintAll : 배열에 저장된 챔피언 정보를 순서대로 출력" << "\n";
			cout << "FindMaxHp : 체력이 가장 큰 챔피언 정보 출력" << '\n';
			cout << "SortByHp : 체력이 높은 순서대로 배열에 저장" << '\n';
			cout << '\n';
		}
		else if (command == "Insert") {
			if (DATA_COUNT < 300) {
				Player newPlayer;
				cout << "새로운 챔피언 정보를 입력하세요" << '\n';
				cout << "챔피언이름 : ";
				cin >> newPlayer.name;
				cout << "체력 : ";
				cin >> newPlayer.health;
				cout << "마나 : ";
				cin >> newPlayer.mana;
				cout << "속도 : ";
				cin >> newPlayer.speed;
				cout << "사거리 : ";
				cin >> newPlayer.range;
				cout << "포지션 : ";
				cin >> newPlayer.position;
				cout << '\n';

				players[DATA_COUNT++] = newPlayer;
			}
			cout << "명령어를 입력하세요" << '\n';
			cout << "Search[챔피언이름] : 주어진 챔피언 정보 출력" << '\n';
			cout << "Insert : 새로운 챔피언 정보 삽입" << '\n';
			cout << "Delete[챔피언이름] : 주어진 챔피언 정보 삭제" << '\n';
			cout << "DeleteAll[position] : 주어진 위치의 모든 챔피언 정보 삭제" << '\n';
			cout << "PrintAll : 배열에 저장된 챔피언 정보를 순서대로 출력" << "\n";
			cout << "FindMaxHp : 체력이 가장 큰 챔피언 정보 출력" << '\n';
			cout << "SortByHp : 체력이 높은 순서대로 배열에 저장" << '\n';
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
						cout << "해당 챔피언의 정보를 삭제했습니다" << '\n';
						cout << '\n';
					}
				}
				if (!deleted) {
					cout << "잘못된 정보입니다. 다시 입력해주세요" << '\n';
					cout << '\n';
				}
			}
			cout << "명령어를 입력하세요" << '\n';
			cout << "Search[챔피언이름] : 주어진 챔피언 정보 출력" << '\n';
			cout << "Insert : 새로운 챔피언 정보 삽입" << '\n';
			cout << "Delete[챔피언이름] : 주어진 챔피언 정보 삭제" << '\n';
			cout << "DeleteAll[position] : 주어진 위치의 모든 챔피언 정보 삭제" << '\n';
			cout << "PrintAll : 배열에 저장된 챔피언 정보를 순서대로 출력" << "\n";
			cout << "FindMaxHp : 체력이 가장 큰 챔피언 정보 출력" << '\n';
			cout << "SortByHp : 체력이 높은 순서대로 배열에 저장" << '\n';
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
					cout << position << "의 모든 챔피언 정보가 삭제되었습니다" << '\n';
					cout << '\n';
				}
			}
			cout << "명령어를 입력하세요" << '\n';
			cout << "Search[챔피언이름] : 주어진 챔피언 정보 출력" << '\n';
			cout << "Insert : 새로운 챔피언 정보 삽입" << '\n';
			cout << "Delete[챔피언이름] : 주어진 챔피언 정보 삭제" << '\n';
			cout << "DeleteAll[position] : 주어진 위치의 모든 챔피언 정보 삭제" << '\n';
			cout << "PrintAll : 배열에 저장된 챔피언 정보를 순서대로 출력" << "\n";
			cout << "FindMaxHp : 체력이 가장 큰 챔피언 정보 출력" << '\n';
			cout << "SortByHp : 체력이 높은 순서대로 배열에 저장" << '\n';
			cout << '\n';
		}
		else if (command == "PrintAll") {
			cout << "배열에 저장된 챔피언 정보를 순서대로 출력합니다" << '\n';
			for (int i = 0; i < DATA_COUNT; ++i) {
				if (players[i].name != "") {
					cout << players[i].name << ", " << players[i].health << ", " << players[i].mana << ", " <<
						players[i].speed << ", " << players[i].range << ", " << players[i].position << '\n';
					cout << '\n';
				}
			}
			cout << "명령어를 입력하세요" << '\n';
			cout << "Search[챔피언이름] : 주어진 챔피언 정보 출력" << '\n';
			cout << "Insert : 새로운 챔피언 정보 삽입" << '\n';
			cout << "Delete[챔피언이름] : 주어진 챔피언 정보 삭제" << '\n';
			cout << "DeleteAll[position] : 주어진 위치의 모든 챔피언 정보 삭제" << '\n';
			cout << "PrintAll : 배열에 저장된 챔피언 정보를 순서대로 출력" << "\n";
			cout << "FindMaxHp : 체력이 가장 큰 챔피언 정보 출력" << '\n';
			cout << "SortByHp : 체력이 높은 순서대로 배열에 저장" << '\n';
			cout << '\n';
		}
		else if (command == "FindMaxHp") {
			int maxHealth = -1;
			cout << "체력이 가장 큰 챔피언 정보 출력" << '\n';
			cout << '\n';
			for (int i = 0; i < DATA_COUNT; ++i) {
				if (players[i].health > maxHealth) {
					maxHealth = players[i].health;
				}
			}
			for (int i = 0; i < DATA_COUNT; ++i) {
				if (players[i].health == maxHealth) {
					cout << "챔피언 이름 : " << players[i].name << '\n';
					cout << "체력 : " << players[i].health << '\n';
					cout << "마나 : " << players[i].mana << '\n';
					cout << "속도 : " << players[i].speed << '\n';
					cout << "사거리 : " << players[i].range << '\n';
					cout << "포지션 : " << players[i].position << '\n';
					cout << "\n";
				}
			}
			cout << "명령어를 입력하세요" << '\n';
			cout << "Search[챔피언이름] : 주어진 챔피언 정보 출력" << '\n';
			cout << "Insert : 새로운 챔피언 정보 삽입" << '\n';
			cout << "Delete[챔피언이름] : 주어진 챔피언 정보 삭제" << '\n';
			cout << "DeleteAll[position] : 주어진 위치의 모든 챔피언 정보 삭제" << '\n';
			cout << "PrintAll : 배열에 저장된 챔피언 정보를 순서대로 출력" << "\n";
			cout << "FindMaxHp : 체력이 가장 큰 챔피언 정보 출력" << '\n';
			cout << "SortByHp : 체력이 높은 순서대로 배열에 저장" << '\n';
			cout << '\n';
		}
		else if (command == "SortByHp") {
			cout << "체력이 높은 순서대로 배열에 저장합니다" << '\n';
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
			cout << "명령어를 입력하세요" << '\n';
			cout << "Search[챔피언이름] : 주어진 챔피언 정보 출력" << '\n';
			cout << "Insert : 새로운 챔피언 정보 삽입" << '\n';
			cout << "Delete[챔피언이름] : 주어진 챔피언 정보 삭제" << '\n';
			cout << "DeleteAll[position] : 주어진 위치의 모든 챔피언 정보 삭제" << '\n';
			cout << "PrintAll : 배열에 저장된 챔피언 정보를 순서대로 출력" << "\n";
			cout << "FindMaxHp : 체력이 가장 큰 챔피언 정보 출력" << '\n';
			cout << "SortByHp : 체력이 높은 순서대로 배열에 저장" << '\n';
			cout << '\n';
		}
		else {
			cout << "잘못입력하였습니다. 다시 입력해주세요" << '\n';
			cout << '\n';
		}
	}
}