#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
	string position;
	string name;
	int health;
	int attack;
	int defense;

	Node* next;

	Node(string p, string n, int h, int a, int d) :
		position(p), name(n), health(h), attack(a), defense(d), next(nullptr) {}
};

struct LinkedList {
	Node* head;
	Node* tail;
};

LinkedList linkedList = { nullptr, nullptr };

Node* AddNodeToLinkedList(string position, string name, int health, int attack, int defense) {
	Node* newNode = new Node(position, name, health, attack, defense);

	if (linkedList.head == nullptr) {
		linkedList.head = newNode;
		linkedList.tail = newNode;
		newNode->next = newNode;
	}
	else {
		newNode->next = linkedList.head;
		linkedList.tail->next = newNode;
		linkedList.tail = newNode;
	}
	return newNode;
}

void PrintAll() {
	Node* current = linkedList.head;
	if (current == nullptr) {
		return;
	}
	do {
		cout << current->position << ", " << current->name << ", " << current->health << ", " << current->attack << ", " << current->defense << '\n';
		current = current->next;
	} while (current != linkedList.head);
	cout << '\n';
}

void Search() {
	cout << "이름을 입력하세요 : ";
	string name;
	getline(cin, name);

	Node* current = linkedList.head;
	bool found = false;
	if (current == nullptr) {
		return;
	}
	do {
		if (current->name == name) {
			cout << current->position << ", " << current->name << ", " << current->health << ", " << current->attack << ", " << current->defense << '\n';
			return;
		}
		current = current->next;
	} while (current != linkedList.head);

	if (!found) {
		cout << "노드가 없습니다.";
	}
}

void Insert() {
	cout << "새로운 챔피언의 정보를 입력하세요 (포지션 이름 체력 공격력 방어력) : ";
	string position, name;
	int health, attack, defense;
	cin >> position >> name >> health >> attack >> defense;
	cin.ignore();
	AddNodeToLinkedList(position, name, health, attack, defense);
}

void Delete() {
	cout << "삭제할 챔피언의 이름을 입력하세요: ";
	string deleteName;
	getline(cin, deleteName);

	if (linkedList.head == nullptr) {
		cout << "리스트가 비어 있습니다.\n";
		return;
	}

	Node* current = linkedList.head;
	Node* previous = linkedList.tail;
	do {
		if (current->name == deleteName) {
			if (current == linkedList.head && current == linkedList.tail) {
				// Only one node in the list
				linkedList.head = nullptr;
				linkedList.tail = nullptr;
			}
			else {
				previous->next = current->next;
				if (current == linkedList.head) {
					linkedList.head = current->next;
				}
				if (current == linkedList.tail) {
					linkedList.tail = previous;
				}
			}
			delete current;
			cout << deleteName << " 노드가 삭제되었습니다.\n";
			return;
		}
		previous = current;
		current = current->next;
	} while (current != linkedList.head);

	cout << "노드를 찾을 수 없습니다.\n";
}

int main() {
	ifstream in("자구_연습.txt");

	string position, name;
	int health, attack, defense;

	while (in >> position >> name >> health >> attack >> defense) {
		AddNodeToLinkedList(position, name, health, attack, defense);
	}
	in.close();

	while (true) {
		string command;
		getline(cin, command);

		if (command == "PrintAll") {
			PrintAll();
		}
		else if (command == "Search") {
			Search();
		}
		else if (command == "Insert") {
			Insert();
		}
		else if (command == "Delete") {
			Delete();
		}
		else {
			cout << "잘못된 명령어입니다.";
		}
	}
	return 0;
}