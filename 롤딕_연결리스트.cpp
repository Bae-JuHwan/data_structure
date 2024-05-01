#include <iostream>
#include <string>

#define ARRAY_SIZE 22

using namespace std;

struct Node {		// 배열의 데이터를 저장하기 위한 노드 구조체
	string name;
	int health;
	int mana;
	int speed;
	int range;
	string position;

	struct Node* next;

	Node(string n, int h, int m, int s, int r, string p) :
		name(n), health(h), mana(m), speed(s), range(r), position(p), next(nullptr) {}
};

struct linkedList {		// 연결리스트 구조체(헤드, 테일, 현재위치, 이전위치. 다음위치는 노드 구조체에 있음)
	Node* head;
	Node* tail;
	Node* current;
	Node* prev;
};

Node* Array2LinkedList(Node* nodes, int size) {		// 배열을 연결리스트로 바꿔주는 함수
	if (size == 0) {
		return nullptr;
	}
	Node* head = new Node(nodes[0].name, nodes[0].health, nodes[0].mana, nodes[0].speed,		// 연결리스트의 헤드부분
		nodes[0].range, nodes[0].position);
	Node* current = head;		// 현재 위치는 헤드

	for (int i = 1; i < size; ++i) {		// for문을 이용해 배열을 연결리스트로 변환
		current->next = new Node(nodes[i].name, nodes[i].health, nodes[i].mana, nodes[i].speed,
			nodes[i].range, nodes[i].position);
		current = current->next;			// 데이터를 계속 저장하기 위해 current를 바꿔줌.
	}
	current->next = head;		// 환형연결리스트를 위해 마지막 노드를 헤드로 연결.

	return head;
}

void Search_SL(Node* head, const string& championName) {
	Node* current = head;
	bool found = false;
	if (current == nullptr) {
		cout << "연결리스트가 비어 있습니다" << '\n';
		return;
	}

	do {
		if (current->name == championName) {		// 입력한 이름이 리스트의 이름과 같다면 정보 출력
			found = true;
			cout << "이름 : " << current->name << '\n';
			cout << "체력 : " << current->health << '\n';
			cout << "마나 : " << current->mana << '\n';
			cout << "속도 : " << current->speed << '\n';
			cout << "사거리 : " << current->range << '\n';
			cout << "포지션 : " << current->position << '\n';
			cout << '\n';
			return;
		} 
		current = current->next;		// 다음 노드로 이동
	} while (current != head);

	if (!found) {
		cout << "잘못된 챔피언 입니다. 다시 입력하세요" << '\n';
		cout << '\n';
	}
}

void Insert_SL(Node*& head, Node* newNode) {
	if (head == nullptr) {
		head = newNode;
		head->next = head;
		return;
	}

	Node* current = head;
	Node* prev = nullptr;

	do {
		if (newNode->health >= current->health) {
			newNode->next = current;
			if (prev) {
				prev->next = newNode;
			}
			else {
				head = newNode;
			}
			return;
		}
		prev = current;
		current = current->next;
	} while (current != head);

	prev->next = newNode;
	newNode->next = head;
}

Node* GetChampionInfo() {
	string name, position;
	int health, mana, speed, range;

	cout << "챔피언 이름을 입력하세요: ";
	getline(cin, name);
	cout << "체력을 입력하세요: ";
	cin >> health;
	cout << "마나를 입력하세요: ";
	cin >> mana;
	cout << "속도를 입력하세요: ";
	cin >> speed;
	cout << "사거리를 입력하세요: ";
	cin >> range;
	cout << "포지션을 입력하세요: ";
	cin.ignore(); // 버퍼 비우기
	getline(cin, position);

	Node* newNode = new Node(name, health, mana, speed, range, position);
	return newNode;
	cout << "새로운 챔피언이 추가되었습니다" << '\n';
	cout << '\n';
}

void Delete_SL(Node* &head, Node* tail, const string& championName) {		// delete함수
	if (head == nullptr) {													// 헤드노드가 비어있다면 출력
		cout << "연결리스트가 비어 있습니다" << '\n';
		return;
	}

	Node* current = head;													// 현재위치는 헤드
	Node* prev = tail;														// 이전위치는 테일
	bool deleted = false;													// 예외처리를 위한 불함수

	do {																	// 환형 연결리스트이기 때문에 do-while조건문을 사용(while문을 사용한다면 무한루프에 빠짐)
		if (current->name == championName) {								// 현재위치의 이름이 입력한 챔피언 이름과 같다면
			if (current == head) {											// 현재위치가 헤드일때
				head = current->next;										// 현재위치의 다음을 헤드로 바꿈
				tail->next = head;											// 테일의 다음은 헤드(헤드의 위치가 바뀌었으니까 원래 헤드였던 노드를 건너뛰고 연결)
			}
			else {															// 헤드가 아닌 나머지는
				prev->next = current->next;									// 이전노드의 다음을 현재위치의 다음으로 연결해서 현재위치를 왕따시킴
			}
			delete current;
			cout << "해당 챔피언이 삭제되었습니다" << '\n';
			cout << '\n';
			deleted = true;
			return;
		}
		if (current == head) {
			prev = tail;
			current = current->next;
		}
		else {
			prev = current;
			current = current->next;
		}
	} while (current != head);

	if (!deleted) {
		cout << "잘못된 챔피언 입니다. 다시 입력하세요" << '\n';
		cout << '\n';
	}
}

void DeleteAll_SL(Node* &head, Node* tail, const string& position) {
	if (head == nullptr) {													// 헤드노드가 비어있다면 출력
		cout << "연결리스트가 비어 있습니다" << '\n';
		return;
	}

	Node* current = head;				
	Node* prev = tail;					
	bool deleted = false;

	do {														
		if (current->position == position) {							
			if (current == head) {								
				head = current->next;								
				tail->next = head;
				delete current;
				current = head;
			}
			else {													
				prev->next = current->next;
				Node* temp = current;
				current = current->next;
				delete temp;
			}
			deleted = true;
			continue;
		}
		else {
			prev = current;
			current = current->next;
		}
	} while (current != head);
	cout << "해당 포지션의 챔피언들이 삭제되었습니다" << '\n';
	cout << '\n';
	if (!deleted) {
		cout << "잘못된 챔피언 입니다. 다시 입력하세요" << '\n';
		cout << '\n';
	}
}

void PrintAll_SL(Node* head) {
	Node* current = head;
	if (current == nullptr) {
		cout << "연결리스트가 비어 있습니다" << '\n';
		return;
	}
	cout << "연결리스트에 저장된 챔피언 정보를 순서대로 출력합니다" << '\n';
	do {
		cout << current->name << ", " << current->health << ", " << current->mana << ", " <<
			current->speed << ", " << current->range << ", " << current->position << '\n';
		current = current->next;
	} while (current != head);
	cout << '\n';
}

void FindMaxHp_SL(Node* head) {
	if (head == nullptr) {
		cout << "연결리스트가 비어 있습니다" << '\n';
		return;
	}

	Node* current = head->next;
	int maxHp = head->health;

	cout << "체력이 가장 큰 챔피언 정보:" << '\n';

	do {
		if (current->health > maxHp) { 
			maxHp = current->health;
			cout << "이름: " << current->name << '\n';
			cout << "체력: " << current->health << '\n';
			cout << "마나: " << current->mana << '\n';
			cout << "속도: " << current->speed << '\n';
			cout << "사거리: " << current->range << '\n';
			cout << "포지션: " << current->position << '\n';
			cout << '\n';
		}
		else if (maxHp == current->health) {
			cout << "이름: " << current->name << '\n';
			cout << "체력: " << current->health << '\n';
			cout << "마나: " << current->mana << '\n';
			cout << "속도: " << current->speed << '\n';
			cout << "사거리: " << current->range << '\n';
			cout << "포지션: " << current->position << '\n';
			cout << '\n';
		}
		current = current->next;
	} while (current != head);
}

void SortByHp_SL(Node*& head) {
	if (head == nullptr) {
		cout << "연결리스트가 비어 있습니다" << '\n';
		return;
	}

	Node* current = head->next;

	Node* sortedHead = new Node("", 0, 0, 0, 0, "");
	sortedHead->next = sortedHead;

	while (current != head) {
		Node* next = current->next;

		Node* prev = sortedHead;
		while (prev->next != sortedHead && prev->next->health > current->health) {
			prev = prev->next;
		}

		current->next = prev->next;
		prev->next = current;

		current = next;
	}

	head = sortedHead->next;

	delete sortedHead;
	cout << "체력이 높은 순으로 정렬되었습니다" << '\n';
	cout << '\n';
}

int main() {
	Node nodes[ARRAY_SIZE] = {
		{ "Jayce", 3466, 8307, 452, 73, "mid" },
		{ "Vayne",	3318, 2790, 390, 60, "support" },
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
		{ "Amumu",	6763, 3994, 427, 19, "jungle" },
		{ "Master Yi", 5737, 7168, 434, 61, "top" },
		{ "Jarvan", 1895, 3070, 323, 80, "mid" },
		{ "Shen", 4794, 9220, 783, 42, "mid" },
		{ "Fizz", 9864, 1913, 433,	38, "bottom" },
		{ "Taric", 6158, 7451, 160, 36, "bottom" },
	};
	Node* circleList = Array2LinkedList(nodes, ARRAY_SIZE);

	cout << "명령어를 입력하세요" << '\n';
	cout << "Search_SL[챔피언이름] : 주어진 챔피언 정보 출력" << '\n';
	cout << "Insert_SL : 새로운 챔피언 정보 삽입" << '\n';
	cout << "Delete_SL[챔피언이름] : 주어진 챔피언 정보 삭제" << '\n';
	cout << "DeleteAll_SL[position] : 주어진 위치의 모든 챔피언 정보 삭제" << '\n';
	cout << "PrintAll_SL : 배열에 저장된 챔피언 정보를 순서대로 출력" << "\n";
	cout << "FindMaxHp_SL : 체력이 가장 큰 챔피언 정보 출력" << '\n';
	cout << "SortByHp_SL : 체력이 높은 순서대로 배열에 저장" << '\n';
	cout << '\n';

	while (true) {
		string command;
		getline(cin, command);

		if (command.substr(0, 10) == "Search_SL[") {
			size_t startPos = command.find('[');
			size_t endPos = command.find(']');

			if (startPos != string::npos && endPos != string::npos && endPos > startPos + 1) {
				string championName = command.substr(startPos + 1, endPos - startPos - 1);

				Search_SL(circleList, championName);
			}

			cout << "명령어를 입력하세요" << '\n';
			cout << "Search_SL[챔피언이름] : 주어진 챔피언 정보 출력" << '\n';
			cout << "Insert_SL : 새로운 챔피언 정보 삽입" << '\n';
			cout << "Delete_SL[챔피언이름] : 주어진 챔피언 정보 삭제" << '\n';
			cout << "DeleteAll_SL[position] : 주어진 위치의 모든 챔피언 정보 삭제" << '\n';
			cout << "PrintAll_SL : 배열에 저장된 챔피언 정보를 순서대로 출력" << "\n";
			cout << "FindMaxHp_SL : 체력이 가장 큰 챔피언 정보 출력" << '\n';
			cout << "SortByHp_SL : 체력이 높은 순서대로 배열에 저장" << '\n';
			cout << '\n';
		}

		else if (command == "Insert_SL") {
			Node* newChampion = GetChampionInfo();
			Insert_SL(circleList, newChampion);

			cout << "명령어를 입력하세요" << '\n';
			cout << "Search_SL[챔피언이름] : 주어진 챔피언 정보 출력" << '\n';
			cout << "Insert_SL : 새로운 챔피언 정보 삽입" << '\n';
			cout << "Delete_SL[챔피언이름] : 주어진 챔피언 정보 삭제" << '\n';
			cout << "DeleteAll_SL[position] : 주어진 위치의 모든 챔피언 정보 삭제" << '\n';
			cout << "PrintAll_SL : 배열에 저장된 챔피언 정보를 순서대로 출력" << "\n";
			cout << "FindMaxHp_SL : 체력이 가장 큰 챔피언 정보 출력" << '\n';
			cout << "SortByHp_SL : 체력이 높은 순서대로 배열에 저장" << '\n';
			cout << '\n';
		}

		else if (command.substr(0, 10) == "Delete_SL[") {
			size_t startPos = command.find('[');
			size_t endPos = command.find(']');

			if (startPos != string::npos && endPos != string::npos && endPos > startPos + 1) {
				string championName = command.substr(startPos + 1, endPos - startPos - 1);

				Delete_SL(circleList, circleList, championName);
			}

			cout << "명령어를 입력하세요" << '\n';
			cout << "Search_SL[챔피언이름] : 주어진 챔피언 정보 출력" << '\n';
			cout << "Insert_SL : 새로운 챔피언 정보 삽입" << '\n';
			cout << "Delete_SL[챔피언이름] : 주어진 챔피언 정보 삭제" << '\n';
			cout << "DeleteAll_SL[position] : 주어진 위치의 모든 챔피언 정보 삭제" << '\n';
			cout << "PrintAll_SL : 배열에 저장된 챔피언 정보를 순서대로 출력" << "\n";
			cout << "FindMaxHp_SL : 체력이 가장 큰 챔피언 정보 출력" << '\n';
			cout << "SortByHp_SL : 체력이 높은 순서대로 배열에 저장" << '\n';
			cout << '\n';
		}

		else if (command.substr(0, 13) == "DeleteAll_SL[") {
			size_t startPos = command.find('[');
			size_t endPos = command.find(']');

			if (startPos != string::npos && endPos != string::npos && endPos > startPos + 1) {
				string position = command.substr(startPos + 1, endPos - startPos - 1);

				DeleteAll_SL(circleList, circleList, position);
			}

			cout << "명령어를 입력하세요" << '\n';
			cout << "Search_SL[챔피언이름] : 주어진 챔피언 정보 출력" << '\n';
			cout << "Insert_SL : 새로운 챔피언 정보 삽입" << '\n';
			cout << "Delete_SL[챔피언이름] : 주어진 챔피언 정보 삭제" << '\n';
			cout << "DeleteAll_SL[position] : 주어진 위치의 모든 챔피언 정보 삭제" << '\n';
			cout << "PrintAll_SL : 배열에 저장된 챔피언 정보를 순서대로 출력" << "\n";
			cout << "FindMaxHp_SL : 체력이 가장 큰 챔피언 정보 출력" << '\n';
			cout << "SortByHp_SL : 체력이 높은 순서대로 배열에 저장" << '\n';
			cout << '\n';
		}

		else if (command == "PrintAll_SL") {
			PrintAll_SL(circleList);
			cout << "명령어를 입력하세요" << '\n';
			cout << "Search_SL[챔피언이름] : 주어진 챔피언 정보 출력" << '\n';
			cout << "Insert_SL : 새로운 챔피언 정보 삽입" << '\n';
			cout << "Delete_SL[챔피언이름] : 주어진 챔피언 정보 삭제" << '\n';
			cout << "DeleteAll_SL[position] : 주어진 위치의 모든 챔피언 정보 삭제" << '\n';
			cout << "PrintAll_SL : 배열에 저장된 챔피언 정보를 순서대로 출력" << "\n";
			cout << "FindMaxHp_SL : 체력이 가장 큰 챔피언 정보 출력" << '\n';
			cout << "SortByHp_SL : 체력이 높은 순서대로 배열에 저장" << '\n';
			cout << '\n';
		}

		else if (command == "FindMaxHp_SL") {
			FindMaxHp_SL(circleList);
			cout << "명령어를 입력하세요" << '\n';
			cout << "Search_SL[챔피언이름] : 주어진 챔피언 정보 출력" << '\n';
			cout << "Insert_SL : 새로운 챔피언 정보 삽입" << '\n';
			cout << "Delete_SL[챔피언이름] : 주어진 챔피언 정보 삭제" << '\n';
			cout << "DeleteAll_SL[position] : 주어진 위치의 모든 챔피언 정보 삭제" << '\n';
			cout << "PrintAll_SL : 리스트에 저장된 챔피언 정보를 순서대로 출력" << "\n";
			cout << "FindMaxHp_SL : 체력이 가장 큰 챔피언 정보 출력" << '\n';
			cout << "SortByHp_SL : 체력이 높은 순서대로 리스트에 저장" << '\n';
			cout << '\n';
		}

		else if (command == "SortByHp_SL") {
			SortByHp_SL(circleList);
			cout << "명령어를 입력하세요" << '\n';
			cout << "Search_SL[챔피언이름] : 주어진 챔피언 정보 출력" << '\n';
			cout << "Insert_SL : 새로운 챔피언 정보 삽입" << '\n';
			cout << "Delete_SL[챔피언이름] : 주어진 챔피언 정보 삭제" << '\n';
			cout << "DeleteAll_SL[position] : 주어진 위치의 모든 챔피언 정보 삭제" << '\n';
			cout << "PrintAll_SL : 리스트에 저장된 챔피언 정보를 순서대로 출력" << "\n";
			cout << "FindMaxHp_SL : 체력이 가장 큰 챔피언 정보 출력" << '\n';
			cout << "SortByHp_SL : 체력이 높은 순서대로 리스트에 저장" << '\n';
			cout << '\n';
		}

		else {
			cout << "명령어를 잘못 입력하였습니다. 다시 입력하세요" << '\n';
			cout << '\n';
		}
	}
}