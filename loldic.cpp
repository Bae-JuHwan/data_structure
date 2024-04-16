// Search_R[챔피언이름] : 주어진 챔피언의 정보를 출력
// Insert_R : 새로운 챔피언의 정보를 입력받아 삽입
// Delete_R[챔피언이름] : 주어진 챔피언에 대한 정보 삭제
// DeleteAll_R[position] : 주어진 위치의 모든 챔피언 정보 삭제
// PrintAll_R : 모든 챔피언의 정보를 배열에 저장된 순서대로 출력
// FindMaxHp_R : 가장 체력이 큰 챔피언의 정보를 출력
// SortByHp_R : 체력이 큰 챔피언부터 순서대로 출력

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
		cout << "이름 : " << players[i].name << ", 체력 : " << players[i].health << ", 마나 : " << players[i].mana
			<< ", 속도 : " << players[i].speed << ", 사거리 : " << players[i].range << ", 포지션 : " << players[i].position << '\n';
		cout << "\n";
	}
	SearchRecursive(players, max, ++i,championName);
}

int InsertRecursive(struct Player* players, int max, int i) {
	if (i == MAX) {
		cout << "더 이상 추가할 수 없습니다" << '\n';
		return 0;
	}
	else if (players[i].name == "") {
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
		cout << "해당 챔피언의 정보를 삭제했습니다" << '\n';
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
		cout << "이름 : " << players[i].name << ", 체력 : " << players[i].health << ", 마나 : " << players[i].mana
			<< ", 속도 : " << players[i].speed << ", 사거리 : " << players[i].range << ", 포지션 : " << players[i].position << '\n';
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
		cout << "이름 : " << players[i].name << '\n';
		cout << "체력 : " << players[i].health << '\n';
		cout << "마나 : " << players[i].mana << '\n';
		cout << "속도: " << players[i].speed << '\n';
		cout << "사거리 : " << players[i].range << '\n';
		cout << "포지션 : " << players[i].position << '\n';
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

	cout << "명령어를 입력하세요" << '\n';
	cout << "Search_R[챔피언이름] : 주어진 챔피언 정보 출력" << '\n';
	cout << "Insert_R : 새로운 챔피언 정보 삽입" << '\n';
	cout << "Delete_R[챔피언이름] : 주어진 챔피언 정보 삭제" << '\n';
	cout << "DeleteAll_R[position] : 주어진 위치의 모든 챔피언 정보 삭제" << '\n';
	cout << "PrintAll_R : 배열에 저장된 챔피언 정보를 순서대로 출력" << "\n";
	cout << "FindMaxHp_R : 체력이 가장 큰 챔피언 정보 출력" << '\n';
	cout << "SortByHp_R : 체력이 높은 순서대로 배열에 저장" << '\n';
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
				cout << "잘못된 명령어 입니다." << '\n';
				cout << '\n';
			}
			cout << "명령어를 입력하세요" << '\n';
			cout << "Search_R[챔피언이름] : 주어진 챔피언 정보 출력" << '\n';
			cout << "Insert_R : 새로운 챔피언 정보 삽입" << '\n';
			cout << "Delete_R[챔피언이름] : 주어진 챔피언 정보 삭제" << '\n';
			cout << "DeleteAll_R[position] : 주어진 위치의 모든 챔피언 정보 삭제" << '\n';
			cout << "PrintAll_R : 배열에 저장된 챔피언 정보를 순서대로 출력" << "\n";
			cout << "FindMaxHp_R : 체력이 가장 큰 챔피언 정보 출력" << '\n';
			cout << "SortByHp_R : 체력이 높은 순서대로 배열에 저장" << '\n';
			cout << '\n';
		}

		else if (command == "Insert_R") {
			InsertRecursive(players, MAX, 0);
			cout << "새로운 챔피언 정보가 추가되었습니다" << '\n';
			cout << '\n';
			cout << "명령어를 입력하세요" << '\n';
			cout << "Search_R[챔피언이름] : 주어진 챔피언 정보 출력" << '\n';
			cout << "Insert_R : 새로운 챔피언 정보 삽입" << '\n';
			cout << "Delete_R[챔피언이름] : 주어진 챔피언 정보 삭제" << '\n';
			cout << "DeleteAll_R[position] : 주어진 위치의 모든 챔피언 정보 삭제" << '\n';
			cout << "PrintAll_R : 배열에 저장된 챔피언 정보를 순서대로 출력" << "\n";
			cout << "FindMaxHp_R : 체력이 가장 큰 챔피언 정보 출력" << '\n';
			cout << "SortByHp_R : 체력이 높은 순서대로 배열에 저장" << '\n';
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
				cout << "잘못된 명령어 입니다." << '\n';
				cout << '\n';
			}
			cout << "명령어를 입력하세요" << '\n';
			cout << "Search_R[챔피언이름] : 주어진 챔피언 정보 출력" << '\n';
			cout << "Insert_R : 새로운 챔피언 정보 삽입" << '\n';
			cout << "Delete_R[챔피언이름] : 주어진 챔피언 정보 삭제" << '\n';
			cout << "DeleteAll_R[position] : 주어진 위치의 모든 챔피언 정보 삭제" << '\n';
			cout << "PrintAll_R : 배열에 저장된 챔피언 정보를 순서대로 출력" << "\n";
			cout << "FindMaxHp_R : 체력이 가장 큰 챔피언 정보 출력" << '\n';
			cout << "SortByHp_R : 체력이 높은 순서대로 배열에 저장" << '\n';
			cout << '\n';
		}

		else if (command.find("DeleteAll_R") != string::npos) {
			size_t start = command.find('[');
			size_t end = command.find(']');
			if (start != string::npos && end != string::npos && end > start + 1) {
				string position = command.substr(start + 1, end - start - 1);

				DeleteAllRecursive(players, MAX, 0, &position);

				cout << position << "의 모든 챔피언 정보를 삭제했습니다" << '\n';
				cout << '\n';
			}
			else {
				cout << "잘못된 명령어 입니다" << '\n';
				cout << '\n';
			}
			cout << "명령어를 입력하세요" << '\n';
			cout << "Search_R[챔피언이름] : 주어진 챔피언 정보 출력" << '\n';
			cout << "Insert_R : 새로운 챔피언 정보 삽입" << '\n';
			cout << "Delete_R[챔피언이름] : 주어진 챔피언 정보 삭제" << '\n';
			cout << "DeleteAll_R[position] : 주어진 위치의 모든 챔피언 정보 삭제" << '\n';
			cout << "PrintAll_R : 배열에 저장된 챔피언 정보를 순서대로 출력" << "\n";
			cout << "FindMaxHp_R : 체력이 가장 큰 챔피언 정보 출력" << '\n';
			cout << "SortByHp_R : 체력이 높은 순서대로 배열에 저장" << '\n';
			cout << '\n';
		}

		else if (command == "PrintAll_R") {
			cout << "배열에 저장된 챔피언 정보를 순서대로 출력합니다" << '\n';
			cout << '\n';
			PrintAllRecursive(players, MAX, 0);
			
			cout << "명령어를 입력하세요" << '\n';
			cout << "Search_R[챔피언이름] : 주어진 챔피언 정보 출력" << '\n';
			cout << "Insert_R : 새로운 챔피언 정보 삽입" << '\n';
			cout << "Delete_R[챔피언이름] : 주어진 챔피언 정보 삭제" << '\n';
			cout << "DeleteAll_R[position] : 주어진 위치의 모든 챔피언 정보 삭제" << '\n';
			cout << "PrintAll_R : 배열에 저장된 챔피언 정보를 순서대로 출력" << "\n";
			cout << "FindMaxHp_R : 체력이 가장 큰 챔피언 정보 출력" << '\n';
			cout << "SortByHp_R : 체력이 높은 순서대로 배열에 저장" << '\n';
			cout << '\n';
		}

		else if (command == "FindMaxHp_R") {
			cout << "체력이 가장 큰 챔피언 정보를 출력합니다" << '\n';
			cout << '\n';
			FindMaxHpRecursive(players, MAX, 0, numeric_limits<int>::min());
			cout << "명령어를 입력하세요" << '\n';
			cout << "Search_R[챔피언이름] : 주어진 챔피언 정보 출력" << '\n';
			cout << "Insert_R : 새로운 챔피언 정보 삽입" << '\n';
			cout << "Delete_R[챔피언이름] : 주어진 챔피언 정보 삭제" << '\n';
			cout << "DeleteAll_R[position] : 주어진 위치의 모든 챔피언 정보 삭제" << '\n';
			cout << "PrintAll_R : 배열에 저장된 챔피언 정보를 순서대로 출력" << "\n";
			cout << "FindMaxHp_R : 체력이 가장 큰 챔피언 정보 출력" << '\n';
			cout << "SortByHp_R : 체력이 높은 순서대로 배열에 저장" << '\n';
			cout << '\n';
		}

		else if (command == "SortByHp_R") {
			SortByHpRecursive(players, MAX, 0);
			cout << "체력이 높은 순서대로 챔피언 정보가 정렬되었습니다" << '\n';
			cout << '\n';
			cout << "명령어를 입력하세요" << '\n';
			cout << "Search_R[챔피언이름] : 주어진 챔피언 정보 출력" << '\n';
			cout << "Insert_R : 새로운 챔피언 정보 삽입" << '\n';
			cout << "Delete_R[챔피언이름] : 주어진 챔피언 정보 삭제" << '\n';
			cout << "DeleteAll_R[position] : 주어진 위치의 모든 챔피언 정보 삭제" << '\n';
			cout << "PrintAll_R : 배열에 저장된 챔피언 정보를 순서대로 출력" << "\n";
			cout << "FindMaxHp_R : 체력이 가장 큰 챔피언 정보 출력" << '\n';
			cout << "SortByHp_R : 체력이 높은 순서대로 배열에 저장" << '\n';
			cout << '\n';
		}
		else {
			cout << "잘못 입력하였습니다. 다시 입력해주세요" << '\n';
			cout << '\n';
		}
	}
}