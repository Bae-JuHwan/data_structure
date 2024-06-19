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
	cout << "�̸��� �Է��ϼ��� : ";
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
		cout << "��尡 �����ϴ�.";
	}
}

int main() {
	ifstream in("�ڱ�_����.txt");

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
		else {
			cout << "�߸��� ��ɾ��Դϴ�.";
		}
	}
	return 0;
}