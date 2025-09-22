#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

struct List {
    Node* head;
    List() { head = nullptr; }

    // (O(1))
    void push_front(int x) {
        Node* node = new Node(x);
        node->next = head;
        head = node;
    }

    // (O(n)) phải đi qua (n-1)
    void push_back(int x) {
        Node* node = new Node(x);
        if (head == nullptr) {
            head = node;
            return;
        }
        Node* cur = head;
        while (cur->next != nullptr) cur = cur->next;
        cur->next = node;
    }

    //  (O(n)) Phải duyệt n bước
    int get(int i) {
        Node* cur = head;
        int idx = 0;
        while (cur != nullptr && idx < i) {
            cur = cur->next;
            idx++;
        }
        if (cur == nullptr) throw out_of_range("Index out of range");
        return cur->data;
    }

    // (O(n)) Phải duyệt n-1 bước
    void insert(int i, int x) {
        if (i == 0) { push_front(x); return; }
        Node* cur = head;
        int idx = 0;
        while (cur != nullptr && idx < i-1) {
            cur = cur->next;
            idx++;
        }
        if (cur == nullptr) throw out_of_range("Index out of range");
        Node* node = new Node(x);
        node->next = cur->next;
        cur->next = node;
    }

    // (O(1))
    void pop_front() {
        if (head == nullptr) return;
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }

   // (O(n)) phải duyệt n bước
    void pop_back() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* cur = head;
        while (cur->next->next != nullptr) cur = cur->next;
        delete cur->next;
        cur->next = nullptr;
    }

    // (O(n)) phải duyệt n bước
    void erase(int i) {
        if (i == 0) { pop_front(); return; }
        Node* cur = head;
        int idx = 0;
        while (cur != nullptr && idx < i-1) {
            cur = cur->next;
            idx++;
        }
        if (cur == nullptr || cur->next == nullptr) return;
        Node* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
    }

    // (O(n)) phải duyệt n bước
    void print_forward() {
        Node* cur = head;
        while (cur != nullptr) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    // (O(n)) phải duyệt n bước
    void print_backward(Node* node) {
        if (node == nullptr) return;
        print_backward(node->next);
        cout << node->data << " ";
    }

    void print_backward() {
        print_backward(head);
        cout << endl;
    }
};

int main() {
    List lst;

    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_front(0);

    lst.print_forward();

    lst.print_backward();

    cout << lst.get(2) << endl;

    lst.insert(2, 99);
    lst.print_forward();

    lst.erase(3);
    lst.print_forward();

    lst.pop_front();
    lst.print_forward();

    lst.pop_back();
    lst.print_forward();

    return 0;
}
