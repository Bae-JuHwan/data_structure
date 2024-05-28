#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

struct Champion {				// è�Ǿ��� �����͸� �����ϴ� ����ü
	string position;
	string name;
	int health;
	int attack;
	int defense;

	Champion(string p, string n, int h, int a, int d) :
		position(p), name(n), health(h), attack(a), defense(d) {}
};

class Node {					// ����� Ʋ�� ¥�� Ŭ����
public:
	Champion champion;
	Node* next;

	Node(string p, string n, int h, int a, int d) :
		champion(p, n, h, a, d), next(nullptr) {};
};

class SL {						// ���Ḯ��Ʈ�� Ʋ�� ¥�� Ŭ����
public:
	Node* head;
	Node* tail;

	SL() : head(nullptr), tail(nullptr) {}

	void AddNodeToSL(string position, string name, int health, int attack, int defense) {
		Node* newNodeSL = new Node(position, name, health, attack, defense);

		if (head == nullptr) {
			head = newNodeSL;
			tail = newNodeSL;
			newNodeSL->next = newNodeSL;
		}
		else {
			newNodeSL->next = head;
			tail->next = newNodeSL;
			tail = newNodeSL;
		}
	}

	void PrintAll_SL() {
		if (head == nullptr) {
			return;
		}
		Node* current = head;
		do {
			cout << current->champion.position << ", " << current->champion.name << ", " << current->champion.health << ", "
				<< current->champion.attack << ", " << current->champion.defense << '\n';
			current = current->next;
		} while (current != head);
		cout << '\n';
	}

	void swap(Node* a, Node* b) {
		Champion temp = a->champion;
		a->champion = b->champion;
		b->champion = temp;
	}

	void SortByName_SL() {
		if (head == nullptr || head->next == head) {
			return;
		}
		bool swapped;
		do {
			swapped = false;
			Node* current = head;
			Node* next = head->next;
			do {
				if (current->champion.name < next->champion.name) {
					swap(current, next);
					swapped = true;
				}
				current = next;
				next = current->next;
			} while (current != tail);
		} while (swapped);
	}
};

struct BT_Node {				// ���� Ʈ�� ����ü
	string position;
	string name;
	int health;
	int attack;
	int defense;

	BT_Node* leftChild = nullptr;
	BT_Node* rightChild = nullptr;

	BT_Node(string p, string n, int h, int a, int d) :
		position(p), name(n), health(h), attack(a), defense(d), leftChild(nullptr), rightChild(nullptr) {};
};

void AddNodeToBT(BT_Node*& tree, BT_Node* node) {
	if (tree == nullptr) {
		tree = node;
		return;
	}
	if (node->name < tree->name) {
		if (tree->leftChild == nullptr) {
			tree->leftChild = node;
		}
		else {
			AddNodeToBT(tree->leftChild, node);
		}
	}
	else if (node->name > tree->name) {
		if (tree->rightChild == nullptr) {
			tree->rightChild = node;
		}
		else {
			AddNodeToBT(tree->rightChild, node);
		}
	}
}

BT_Node* SearchByName_BT(BT_Node* tree, const string& targetName) {
	if (tree == nullptr) {
		return nullptr;
	}

	if (tree->name == targetName) {
		return tree;
	}
	else if (tree->name > targetName) {
		return SearchByName_BT(tree->leftChild, targetName);
	}
	else {
		return SearchByName_BT(tree->rightChild, targetName);
	}
}

void Insert_BT(BT_Node*& btRoot) {
	string position, name;
	int health, attack, defense;

	cout << "è�Ǿ� ������ �Է��ϼ���" << '\n';
	cout << "������: ";
	getline(cin, position);
	cout << "�̸�: ";
	getline(cin, name);
	cout << "ü��: ";
	cin >> health;
	cout << "���ݷ�: ";
	cin >> attack;
	cout << "����: ";
	cin >> defense;
	cin.ignore();

	BT_Node* newNode = new BT_Node(position, name, health, attack, defense);
	AddNodeToBT(btRoot, newNode);

	cout << "è�Ǿ��� ���������� �߰��Ǿ����ϴ�.\n";
}

BT_Node* FindMin(BT_Node* tree) {
	while (tree->leftChild != nullptr) {
		tree = tree->leftChild;
	}
	return tree;
}

BT_Node* Delete_BT(BT_Node* tree, const string& targetName) {
	if (tree == nullptr) {
		return tree;
	}
	if (targetName < tree->name) {
		tree->leftChild = Delete_BT(tree->leftChild, targetName);
	}
	else if (targetName > tree->name) {
		tree->rightChild = Delete_BT(tree->rightChild, targetName);
	}
	else {
		if (tree->leftChild == nullptr) {
			BT_Node* temp = tree->rightChild;
			delete tree;
			return temp;
		}
		else if (tree->rightChild == nullptr) {
			BT_Node* temp = tree->leftChild;
			delete tree;
			return temp;
		}

		BT_Node* temp = FindMin(tree->rightChild);
		tree->name = temp->name;
		tree->position = temp->position;
		tree->health = temp->health;
		tree->attack = temp->attack;
		tree->defense = temp->defense;
		tree->rightChild = Delete_BT(tree->rightChild, targetName);
	}
	return tree;
}

void PrintAll_BT(BT_Node* tree) {
	if (tree == nullptr) {
		return;
	}
	PrintAll_BT(tree->leftChild);
	cout << tree->position << ", " << tree->name << ", " << tree->health << ", " << tree->attack << ", " << tree->defense << '\n';
	PrintAll_BT(tree->rightChild);
}

void SwapChildren(BT_Node* tree) {
	if (tree == nullptr) {
		return;
	}
	swap(tree->leftChild, tree->rightChild);
	SwapChildren(tree->leftChild);
	SwapChildren(tree->rightChild);
}

void SortByName_BT(BT_Node* tree) {
	SwapChildren(tree);
	PrintAll_BT(tree);
	SwapChildren(tree);
}

int main() {
	ifstream in("�ӽ�.txt");
	SL sl;
	BT_Node* btRoot = nullptr;
	LARGE_INTEGER start, end, frequency;

	string position, name;
	int health, attack, defense;

	while (in >> position >> name >> health >> attack >> defense) {
		sl.AddNodeToSL(position, name, health, attack, defense);
		BT_Node* newNode = new BT_Node(position, name, health, attack, defense);
		AddNodeToBT(btRoot, newNode);
	}

	cout << "��ɾ �Է��ϼ���" << '\n';
	cout << "SortByName_SL : SL�� �̿��ؼ� �̸� ������� ����" << '\n';
	cout << "SearchByName_BT : BT�� �̿��ؼ� è�Ǿ� �̸� ã��" << '\n';
	cout << "Delete_BT : BT�� �̿��ؼ� è�Ǿ� ����" << '\n';
	cout << "PrintAll_BT : BT�� �̿��ؼ� ��� è�Ǿ� ���� ���" << '\n';
	cout << '\n';

	QueryPerformanceCounter(&frequency);

	while (true) {
		string command;
		getline(cin, command);

		if (command == "SortByName_SL") {
			QueryPerformanceCounter(&start);
			sl.SortByName_SL();
			QueryPerformanceCounter(&end);
			double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) * 1000000.0 / frequency.QuadPart;
			cout << "����ð� : " << elapsedTime << "����ũ����" << '\n';
		}
		else if (command == "SearchByName_BT") {
			cout << "�̸��� �Է��ϼ��� : ";		// P54151216
			string targetName;
			getline(cin, targetName);
			QueryPerformanceCounter(&start);
			BT_Node* result = SearchByName_BT(btRoot, targetName);
			QueryPerformanceCounter(&end);
			double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) * 1000000.0 / frequency.QuadPart;

			if (result != nullptr) {
				cout << "������: " << result->position << '\n';
				cout << "�̸�: " << result->name << '\n';
				cout << "ü��: " << result->health << '\n';
				cout << "���ݷ�: " << result->attack << '\n';
				cout << "����: " << result->defense << '\n';
			}
			else {
				cout << "è�Ǿ��� ã�� �� ����" << '\n';
			}
			cout << "����ð� : " << elapsedTime << "����ũ����" << '\n';
		}
		else if (command == "Insert_BT") {
			QueryPerformanceCounter(&start);
			Insert_BT(btRoot);
			QueryPerformanceCounter(&end);
			double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) * 1000000.0 / frequency.QuadPart;
			cout << "����ð� : " << elapsedTime << "����ũ����" << '\n';
		}
		else if (command == "Delete_BT") {
			cout << "������ è�Ǿ��� �̸��� �Է��ϼ���: ";
			string targetName;
			getline(cin, targetName);

			QueryPerformanceCounter(&start);
			btRoot = Delete_BT(btRoot, targetName);
			QueryPerformanceCounter(&end);
			double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) * 1000000.0 / frequency.QuadPart;

			cout << "����ð� : " << elapsedTime << "����ũ����" << '\n';
		}
		else if (command == "PrintAll_BT") {
			QueryPerformanceCounter(&start);
			PrintAll_BT(btRoot);
			QueryPerformanceCounter(&end);
			double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) * 1000000.0 / frequency.QuadPart;
			cout << "����ð� : " << elapsedTime << "����ũ����" << '\n';
		}
		else if (command == "SortByName_BT") {
			QueryPerformanceCounter(&start);
			SortByName_BT(btRoot);
			QueryPerformanceCounter(&end);
			double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) * 1000000.0 / frequency.QuadPart;
			cout << "����ð� : " << elapsedTime << "����ũ����" << '\n';
		}
		else {
			cout << "�߸��Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���" << '\n';
			cout << '\n';
		}
	}
	return 0;
}