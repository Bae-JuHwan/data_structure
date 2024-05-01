#include <iostream>
#include <string>

#define ARRAY_SIZE 22

using namespace std;

struct Node {		// �迭�� �����͸� �����ϱ� ���� ��� ����ü
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

struct linkedList {		// ���Ḯ��Ʈ ����ü(���, ����, ������ġ, ������ġ. ������ġ�� ��� ����ü�� ����)
	Node* head;
	Node* tail;
	Node* current;
	Node* prev;
};

Node* Array2LinkedList(Node* nodes, int size) {		// �迭�� ���Ḯ��Ʈ�� �ٲ��ִ� �Լ�
	if (size == 0) {
		return nullptr;
	}
	Node* head = new Node(nodes[0].name, nodes[0].health, nodes[0].mana, nodes[0].speed,		// ���Ḯ��Ʈ�� ���κ�
		nodes[0].range, nodes[0].position);
	Node* current = head;		// ���� ��ġ�� ���

	for (int i = 1; i < size; ++i) {		// for���� �̿��� �迭�� ���Ḯ��Ʈ�� ��ȯ
		current->next = new Node(nodes[i].name, nodes[i].health, nodes[i].mana, nodes[i].speed,
			nodes[i].range, nodes[i].position);
		current = current->next;			// �����͸� ��� �����ϱ� ���� current�� �ٲ���.
	}
	current->next = head;		// ȯ�����Ḯ��Ʈ�� ���� ������ ��带 ���� ����.

	return head;
}

void Search_SL(Node* head, const string& championName) {
	Node* current = head;
	bool found = false;
	if (current == nullptr) {
		cout << "���Ḯ��Ʈ�� ��� �ֽ��ϴ�" << '\n';
		return;
	}

	do {
		if (current->name == championName) {		// �Է��� �̸��� ����Ʈ�� �̸��� ���ٸ� ���� ���
			found = true;
			cout << "�̸� : " << current->name << '\n';
			cout << "ü�� : " << current->health << '\n';
			cout << "���� : " << current->mana << '\n';
			cout << "�ӵ� : " << current->speed << '\n';
			cout << "��Ÿ� : " << current->range << '\n';
			cout << "������ : " << current->position << '\n';
			cout << '\n';
			return;
		} 
		current = current->next;		// ���� ���� �̵�
	} while (current != head);

	if (!found) {
		cout << "�߸��� è�Ǿ� �Դϴ�. �ٽ� �Է��ϼ���" << '\n';
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

	cout << "è�Ǿ� �̸��� �Է��ϼ���: ";
	getline(cin, name);
	cout << "ü���� �Է��ϼ���: ";
	cin >> health;
	cout << "������ �Է��ϼ���: ";
	cin >> mana;
	cout << "�ӵ��� �Է��ϼ���: ";
	cin >> speed;
	cout << "��Ÿ��� �Է��ϼ���: ";
	cin >> range;
	cout << "�������� �Է��ϼ���: ";
	cin.ignore(); // ���� ����
	getline(cin, position);

	Node* newNode = new Node(name, health, mana, speed, range, position);
	return newNode;
	cout << "���ο� è�Ǿ��� �߰��Ǿ����ϴ�" << '\n';
	cout << '\n';
}

void Delete_SL(Node* &head, Node* tail, const string& championName) {		// delete�Լ�
	if (head == nullptr) {													// ����尡 ����ִٸ� ���
		cout << "���Ḯ��Ʈ�� ��� �ֽ��ϴ�" << '\n';
		return;
	}

	Node* current = head;													// ������ġ�� ���
	Node* prev = tail;														// ������ġ�� ����
	bool deleted = false;													// ����ó���� ���� ���Լ�

	do {																	// ȯ�� ���Ḯ��Ʈ�̱� ������ do-while���ǹ��� ���(while���� ����Ѵٸ� ���ѷ����� ����)
		if (current->name == championName) {								// ������ġ�� �̸��� �Է��� è�Ǿ� �̸��� ���ٸ�
			if (current == head) {											// ������ġ�� ����϶�
				head = current->next;										// ������ġ�� ������ ���� �ٲ�
				tail->next = head;											// ������ ������ ���(����� ��ġ�� �ٲ�����ϱ� ���� ��忴�� ��带 �ǳʶٰ� ����)
			}
			else {															// ��尡 �ƴ� ��������
				prev->next = current->next;									// ��������� ������ ������ġ�� �������� �����ؼ� ������ġ�� �յ���Ŵ
			}
			delete current;
			cout << "�ش� è�Ǿ��� �����Ǿ����ϴ�" << '\n';
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
		cout << "�߸��� è�Ǿ� �Դϴ�. �ٽ� �Է��ϼ���" << '\n';
		cout << '\n';
	}
}

void DeleteAll_SL(Node* &head, Node* tail, const string& position) {
	if (head == nullptr) {													// ����尡 ����ִٸ� ���
		cout << "���Ḯ��Ʈ�� ��� �ֽ��ϴ�" << '\n';
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
	cout << "�ش� �������� è�Ǿ���� �����Ǿ����ϴ�" << '\n';
	cout << '\n';
	if (!deleted) {
		cout << "�߸��� è�Ǿ� �Դϴ�. �ٽ� �Է��ϼ���" << '\n';
		cout << '\n';
	}
}

void PrintAll_SL(Node* head) {
	Node* current = head;
	if (current == nullptr) {
		cout << "���Ḯ��Ʈ�� ��� �ֽ��ϴ�" << '\n';
		return;
	}
	cout << "���Ḯ��Ʈ�� ����� è�Ǿ� ������ ������� ����մϴ�" << '\n';
	do {
		cout << current->name << ", " << current->health << ", " << current->mana << ", " <<
			current->speed << ", " << current->range << ", " << current->position << '\n';
		current = current->next;
	} while (current != head);
	cout << '\n';
}

void FindMaxHp_SL(Node* head) {
	if (head == nullptr) {
		cout << "���Ḯ��Ʈ�� ��� �ֽ��ϴ�" << '\n';
		return;
	}

	Node* current = head->next;
	int maxHp = head->health;

	cout << "ü���� ���� ū è�Ǿ� ����:" << '\n';

	do {
		if (current->health > maxHp) { 
			maxHp = current->health;
			cout << "�̸�: " << current->name << '\n';
			cout << "ü��: " << current->health << '\n';
			cout << "����: " << current->mana << '\n';
			cout << "�ӵ�: " << current->speed << '\n';
			cout << "��Ÿ�: " << current->range << '\n';
			cout << "������: " << current->position << '\n';
			cout << '\n';
		}
		else if (maxHp == current->health) {
			cout << "�̸�: " << current->name << '\n';
			cout << "ü��: " << current->health << '\n';
			cout << "����: " << current->mana << '\n';
			cout << "�ӵ�: " << current->speed << '\n';
			cout << "��Ÿ�: " << current->range << '\n';
			cout << "������: " << current->position << '\n';
			cout << '\n';
		}
		current = current->next;
	} while (current != head);
}

void SortByHp_SL(Node*& head) {
	if (head == nullptr) {
		cout << "���Ḯ��Ʈ�� ��� �ֽ��ϴ�" << '\n';
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
	cout << "ü���� ���� ������ ���ĵǾ����ϴ�" << '\n';
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

	cout << "��ɾ �Է��ϼ���" << '\n';
	cout << "Search_SL[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���" << '\n';
	cout << "Insert_SL : ���ο� è�Ǿ� ���� ����" << '\n';
	cout << "Delete_SL[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ����" << '\n';
	cout << "DeleteAll_SL[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����" << '\n';
	cout << "PrintAll_SL : �迭�� ����� è�Ǿ� ������ ������� ���" << "\n";
	cout << "FindMaxHp_SL : ü���� ���� ū è�Ǿ� ���� ���" << '\n';
	cout << "SortByHp_SL : ü���� ���� ������� �迭�� ����" << '\n';
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

			cout << "��ɾ �Է��ϼ���" << '\n';
			cout << "Search_SL[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���" << '\n';
			cout << "Insert_SL : ���ο� è�Ǿ� ���� ����" << '\n';
			cout << "Delete_SL[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ����" << '\n';
			cout << "DeleteAll_SL[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����" << '\n';
			cout << "PrintAll_SL : �迭�� ����� è�Ǿ� ������ ������� ���" << "\n";
			cout << "FindMaxHp_SL : ü���� ���� ū è�Ǿ� ���� ���" << '\n';
			cout << "SortByHp_SL : ü���� ���� ������� �迭�� ����" << '\n';
			cout << '\n';
		}

		else if (command == "Insert_SL") {
			Node* newChampion = GetChampionInfo();
			Insert_SL(circleList, newChampion);

			cout << "��ɾ �Է��ϼ���" << '\n';
			cout << "Search_SL[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���" << '\n';
			cout << "Insert_SL : ���ο� è�Ǿ� ���� ����" << '\n';
			cout << "Delete_SL[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ����" << '\n';
			cout << "DeleteAll_SL[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����" << '\n';
			cout << "PrintAll_SL : �迭�� ����� è�Ǿ� ������ ������� ���" << "\n";
			cout << "FindMaxHp_SL : ü���� ���� ū è�Ǿ� ���� ���" << '\n';
			cout << "SortByHp_SL : ü���� ���� ������� �迭�� ����" << '\n';
			cout << '\n';
		}

		else if (command.substr(0, 10) == "Delete_SL[") {
			size_t startPos = command.find('[');
			size_t endPos = command.find(']');

			if (startPos != string::npos && endPos != string::npos && endPos > startPos + 1) {
				string championName = command.substr(startPos + 1, endPos - startPos - 1);

				Delete_SL(circleList, circleList, championName);
			}

			cout << "��ɾ �Է��ϼ���" << '\n';
			cout << "Search_SL[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���" << '\n';
			cout << "Insert_SL : ���ο� è�Ǿ� ���� ����" << '\n';
			cout << "Delete_SL[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ����" << '\n';
			cout << "DeleteAll_SL[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����" << '\n';
			cout << "PrintAll_SL : �迭�� ����� è�Ǿ� ������ ������� ���" << "\n";
			cout << "FindMaxHp_SL : ü���� ���� ū è�Ǿ� ���� ���" << '\n';
			cout << "SortByHp_SL : ü���� ���� ������� �迭�� ����" << '\n';
			cout << '\n';
		}

		else if (command.substr(0, 13) == "DeleteAll_SL[") {
			size_t startPos = command.find('[');
			size_t endPos = command.find(']');

			if (startPos != string::npos && endPos != string::npos && endPos > startPos + 1) {
				string position = command.substr(startPos + 1, endPos - startPos - 1);

				DeleteAll_SL(circleList, circleList, position);
			}

			cout << "��ɾ �Է��ϼ���" << '\n';
			cout << "Search_SL[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���" << '\n';
			cout << "Insert_SL : ���ο� è�Ǿ� ���� ����" << '\n';
			cout << "Delete_SL[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ����" << '\n';
			cout << "DeleteAll_SL[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����" << '\n';
			cout << "PrintAll_SL : �迭�� ����� è�Ǿ� ������ ������� ���" << "\n";
			cout << "FindMaxHp_SL : ü���� ���� ū è�Ǿ� ���� ���" << '\n';
			cout << "SortByHp_SL : ü���� ���� ������� �迭�� ����" << '\n';
			cout << '\n';
		}

		else if (command == "PrintAll_SL") {
			PrintAll_SL(circleList);
			cout << "��ɾ �Է��ϼ���" << '\n';
			cout << "Search_SL[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���" << '\n';
			cout << "Insert_SL : ���ο� è�Ǿ� ���� ����" << '\n';
			cout << "Delete_SL[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ����" << '\n';
			cout << "DeleteAll_SL[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����" << '\n';
			cout << "PrintAll_SL : �迭�� ����� è�Ǿ� ������ ������� ���" << "\n";
			cout << "FindMaxHp_SL : ü���� ���� ū è�Ǿ� ���� ���" << '\n';
			cout << "SortByHp_SL : ü���� ���� ������� �迭�� ����" << '\n';
			cout << '\n';
		}

		else if (command == "FindMaxHp_SL") {
			FindMaxHp_SL(circleList);
			cout << "��ɾ �Է��ϼ���" << '\n';
			cout << "Search_SL[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���" << '\n';
			cout << "Insert_SL : ���ο� è�Ǿ� ���� ����" << '\n';
			cout << "Delete_SL[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ����" << '\n';
			cout << "DeleteAll_SL[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����" << '\n';
			cout << "PrintAll_SL : ����Ʈ�� ����� è�Ǿ� ������ ������� ���" << "\n";
			cout << "FindMaxHp_SL : ü���� ���� ū è�Ǿ� ���� ���" << '\n';
			cout << "SortByHp_SL : ü���� ���� ������� ����Ʈ�� ����" << '\n';
			cout << '\n';
		}

		else if (command == "SortByHp_SL") {
			SortByHp_SL(circleList);
			cout << "��ɾ �Է��ϼ���" << '\n';
			cout << "Search_SL[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ���" << '\n';
			cout << "Insert_SL : ���ο� è�Ǿ� ���� ����" << '\n';
			cout << "Delete_SL[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ����" << '\n';
			cout << "DeleteAll_SL[position] : �־��� ��ġ�� ��� è�Ǿ� ���� ����" << '\n';
			cout << "PrintAll_SL : ����Ʈ�� ����� è�Ǿ� ������ ������� ���" << "\n";
			cout << "FindMaxHp_SL : ü���� ���� ū è�Ǿ� ���� ���" << '\n';
			cout << "SortByHp_SL : ü���� ���� ������� ����Ʈ�� ����" << '\n';
			cout << '\n';
		}

		else {
			cout << "��ɾ �߸� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���" << '\n';
			cout << '\n';
		}
	}
}