#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <utility>

using namespace std;
using namespace std::chrono;

struct Node {
    string position;
    string name;
    int health;
    int attack;
    int defense;
    Node* next;
    Node* prev;

    Node(string p, string n, int h, int a, int d) :
        position(p), name(n), health(h), attack(a), defense(d), next(nullptr), prev(nullptr) {}
};

struct SL {
    Node* head;
    Node* tail;
};

struct DL {
    Node* head;
    Node* tail;
};

SL sl = { nullptr, nullptr };
DL dl = { nullptr, nullptr };

Node* AddNodeToSL(string position, string name, int health, int attack, int defense) {
    Node* newNodeSL = new Node(position, name, health, attack, defense);
    if (sl.head == nullptr) {
        sl.head = newNodeSL;
        sl.tail = newNodeSL;
        newNodeSL->next = newNodeSL;
    }
    else {
        newNodeSL->next = sl.head;
        sl.tail->next = newNodeSL;
        sl.tail = newNodeSL;
    }
    return newNodeSL;
}

Node* AddNodeToDL(string position, string name, int health, int attack, int defense) {
    Node* newNodeDL = new Node(position, name, health, attack, defense);
    if (dl.head == nullptr) {
        dl.head = newNodeDL;
        dl.tail = newNodeDL;
    }
    else {
        dl.tail->next = newNodeDL;
        newNodeDL->prev = dl.tail;
        newNodeDL->next = nullptr;
        dl.tail = newNodeDL;
    }
    return newNodeDL;
}

void PrintAll_SL(SL& sl) {
    if (sl.head == nullptr) {
        return;
    }
    Node* current = sl.head;
    cout << "SL�� ����� ������� ����մϴ�" << '\n';
    do {
        cout << current->position << ", " << current->name << ", " << current->health << ", " << current->attack << ", " << current->defense << '\n';
        current = current->next;
    } while (current != sl.head);
    cout << '\n';
}

void PrintAll_DL(DL& dl) {
    if (dl.head == nullptr) {
        return;
    }
    Node* current = dl.head;
    cout << "DL�� ����� ������� ����մϴ�" << '\n';
    while (current != nullptr) {
        cout << current->position << ", " << current->name << ", " << current->health << ", " << current->attack << ", " << current->defense << '\n';
        current = current->next;
    }
    cout << '\n';
}

void SortByName_SL(SL& sl) {
    if (sl.head == nullptr || sl.head->next == sl.head) {
        return;
    }

    Node* sorted = nullptr;

    Node* current = sl.head;
    do {
        Node* next = current->next;

        if (sorted == nullptr || sorted->name > current->name) {
            current->next = sorted;
            sorted = current;
        }
        else {
            Node* temp = sorted;
            while (temp->next != nullptr && temp->next->name <= current->name) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    } while (current != sl.head);

    Node* tail = sorted;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = sorted;

    sl.head = sorted;
    sl.tail = tail;
}

void SortByName_DL(DL& dl) {
    if (dl.head == nullptr || dl.head->next == nullptr) {
        return;
    }

    Node* sorted = nullptr;

    Node* current = dl.head;
    while (current != nullptr) {
        Node* next = current->next;

        if (sorted == nullptr || sorted->name > current->name) {
            current->next = sorted;
            current->prev = nullptr;
            if (sorted != nullptr) {
                sorted->prev = current;
            }
            sorted = current;
        }
        else {
            Node* temp = sorted;
            while (temp->next != nullptr && temp->next->name <= current->name) {
                temp = temp->next;
            }
            current->next = temp->next;
            if (temp->next != nullptr) {
                temp->next->prev = current;
            }
            temp->next = current;
            current->prev = temp;
        }

        current = next;
    }

    dl.head = sorted;
    Node* tail = sorted;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    dl.tail = tail;
}

void FindMaxHp_SL(SL& sl) {
    if (sl.head == nullptr) {
        cout << "����Ʈ�� ��� �ֽ��ϴ�." << '\n';
        return;
    }

    Node* maxNode = sl.head;
    Node* current = sl.head->next;

    int maxHealth = maxNode->health;
    while (current != sl.head) {
        if (current->health > maxHealth) {
            maxHealth = current->health;
            maxNode = current;
        }
        current = current->next;
    }

    cout << "ü���� ���� ���� è�Ǿ�: " << '\n';
    current = sl.head;
    do {
        if (current->health == maxHealth) {
            cout << current->position << ", " << current->name << ", " << current->health << ", " << current->attack << ", " << current->defense << '\n';
        }
        current = current->next;
    } while (current != sl.head);
}

void FindMaxHp_DL(DL& dl) {
    if (dl.head == nullptr) {
        cout << "����Ʈ�� ��� �ֽ��ϴ�." << '\n';
        return;
    }

    Node* maxNode = dl.head;
    Node* current = dl.head->next;

    int maxHealth = maxNode->health;
    while (current != nullptr) {
        if (current->health > maxHealth) {
            maxHealth = current->health;
            maxNode = current;
        }
        current = current->next;
    }

    cout << "ü���� ���� ���� è�Ǿ�: " << '\n';
    current = maxNode;
    while (current != nullptr) {
        if (current->health == maxHealth) {
            cout << current->position << ", " << current->name << ", " << current->health << ", " << current->attack << ", " << current->defense << '\n';
        }
        current = current->next;
    }
}

int main() {
    ifstream in("�ӽ�.txt");

    if (!in.is_open()) {
        cout << "������ ã�� �� �����ϴ�" << '\n';
        return 1;
    }

    string position, name;
    int health, attack, defense;

    while (in >> position >> name >> health >> attack >> defense) {
        AddNodeToSL(position, name, health, attack, defense);
        AddNodeToDL(position, name, health, attack, defense);
    }
    in.close();

    cout << "��ɾ �Է��ϼ���" << '\n';
    cout << "PrintAll_SL : SL�� ��� ���� ���" << '\n';
    cout << "PrintAll_DL : DL�� ��� ���� ���" << '\n';
    cout << "SortByName_SL : SL�� �̸� ������� ����" << '\n';
    cout << "SortByName_DL : DL�� �̸� ������� ����" << '\n';
    cout << "FindMaxHp_SL : SL�� ���� ü���� ���� è�Ǿ� ���" << '\n';
    cout << "FindMaxHp_DL : DL�� ���� ü���� ���� è�Ǿ� ���" << '\n';
    cout << '\n';

    while (true) {
        string command;
        getline(cin, command);

        if (command == "PrintAll_SL") {
            auto start = high_resolution_clock::now();
            PrintAll_SL(sl);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<seconds>(end - start).count();
            cout << "PrintAll_SL ����ð�: " << duration << "��" << '\n';
            cout << '\n';
        }
        else if (command == "PrintAll_DL") {
            auto start = high_resolution_clock::now();
            PrintAll_DL(dl);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<seconds>(end - start).count();
            cout << "PrintAll_DL ����ð�: " << duration << "��" << '\n';
            cout << "\n";
        }
        else if (command == "SortByName_SL") {
            auto start = high_resolution_clock::now();
            SortByName_SL(sl);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<seconds>(end - start).count();
            cout << "SortByName_SL ����ð�: " << duration << "��" << '\n';
            cout << '\n';
        }
        else if (command == "SortByName_DL") {
            auto start = high_resolution_clock::now();
            SortByName_DL(dl);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<seconds>(end - start).count();
            cout << "SortByName_DL ����ð�: " << duration << "��" << '\n';
            cout << '\n';
        }
        else if (command == "FindMaxHp_SL") {
            auto start = high_resolution_clock::now();
            FindMaxHp_SL(sl);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<seconds>(end - start).count();
            cout << "FindMaxHp_SL ����ð�: " << duration << "��" << '\n';
            cout << '\n';
        }
        else if (command == "FindMaxHp_DL") {
            auto start = high_resolution_clock::now();
            FindMaxHp_DL(dl);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<seconds>(end - start).count();
            cout << "FindMaxHp_DL ����ð�: " << duration << "��" << '\n';
            cout << '\n';
        }
        else {
            cout << "�߸��� ��ɾ��Դϴ�. �ٽ� �Է��ϼ���" << '\n';
			cout << '\n';
		}
	}
}