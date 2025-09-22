#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head;
};

void init(LinkedList& list) {
    list.head = nullptr;
}

// O(1) không phụ thuộc vào n
void insertAtHead(LinkedList& list, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = list.head;
    list.head = newNode;
}

// O(n) Cần duyệt tất cả để tìm node cuối
void insertAtTail(LinkedList& list, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if (list.head == nullptr) {
        list.head = newNode;
        return;
    }
    Node* temp = list.head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// O(n) Phải duyệt i vị trí (n-1)
void insertAtPosition(LinkedList& list, int value, int position) {
    if (position < 0) return;
    if (position == 0) {
        insertAtHead(list, value);
        return;
    }
    Node* newNode = new Node;
    newNode->data = value;
    Node* temp = list.head;
    for (int i = 0; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) return;
    newNode->next = temp->next;
    temp->next = newNode;
}

// O(1) Cập nhật head là xong
void deleteAtHead(LinkedList& list) {
    if (list.head == nullptr) return;
    Node* temp = list.head;
    list.head = list.head->next;
    delete temp;
}

// O(n) Phải duyệt n-1 node để tìm node cận cuối
void deleteAtTail(LinkedList& list) {
    if (list.head == nullptr) return;
    if (list.head->next == nullptr) {
        delete list.head;
        list.head = nullptr;
        return;
    }
    Node* temp = list.head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

// O(n) Phải duyệt (n-1) node
void deleteAtPosition(LinkedList& list, int position) {
    if (position < 0 || list.head == nullptr) return;
    if (position == 0) {
        deleteAtHead(list);
        return;
    }
    Node* temp = list.head;
    for (int i = 0; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr) return;
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}

// Truy cập phần tử tại vị trí i
int access(LinkedList list, int position) {
    Node* temp = list.head;
    for (int i = 0; i < position && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) return -1; // Vị trí không hợp lệ
    return temp->data;
}

// O(n) Phải duyệt n node
void traverseForward(LinkedList list) {
    Node* temp = list.head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// O(n) Phải duyệt n node ngược lại
void traverseReverse(Node* node) {
    if (node == nullptr) return;
    traverseReverse(node->next);
    cout << node->data << " ";
}

void traverseReverse(LinkedList list) {
    traverseReverse(list.head);
    cout << endl;
}

void destroy(LinkedList& list) {
    while (list.head != nullptr) {
        Node* temp = list.head;
        list.head = list.head->next;
        delete temp;
    }
}

int main() {
    LinkedList list;
    init(list);

    insertAtHead(list, 3);
    insertAtTail(list, 5);
    insertAtPosition(list, 4, 1);

    traverseForward(list);

    traverseReverse(list);

    cout << access(list, 1) << endl;

    deleteAtPosition(list, 0);

    traverseForward(list);

    destroy(list);

    return 0;
}
