#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Định nghĩa cấu trúc Stack sử dụng Array
struct StackArray {
    static const int MAX = 1000;
    int arr[MAX];
    int topIndex;

    StackArray() : topIndex(-1) {}

    // Kiểm tra stack rỗng - O(1)
    bool isEmpty() {
        return topIndex == -1;
    }

    // Thêm phần tử vào stack - O(1)
    void push(int item) {
        if (topIndex >= MAX - 1) {
            cout << "Overflow";
            return;
        }
        arr[++topIndex] = item;
    }

    // Xóa và trả về phần tử cuối - O(1)
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty";
            return -1;
        }
        return arr[topIndex--];
    }

    // Trả về phần tử cuối  - O(1)
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty";
            return -1;
        }
        return arr[topIndex];
    }

    // Trả về kích thước stack - O(1)
    int size() {
        return topIndex + 1;
    }
};

// Định nghĩa cấu trúc Stack sử dụng Linked List
struct StackLinkedList {
    Node* topNode;
    int count;

    StackLinkedList() : topNode(nullptr), count(0) {}

    // Kiểm tra stack rỗng - O(1)
    bool isEmpty() {
        return topNode == nullptr;
    }

    // Thêm phần tử vào đầu stack - O(1)
    void push(int item) {
        Node* newNode = new Node(item);
        newNode->next = topNode;
        topNode = newNode;
        count++;
    }

    // Xóa và trả về phần tử đầu - O(1)
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty";
            return -1;
        }
        Node* temp = topNode;
        int value = temp->data;
        topNode = topNode->next;
        delete temp;
        count--;
        return value;
    }

    // Trả về phần tử đầu  - O(1)
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty";
            return -1;
        }
        return topNode->data;
    }

    // Trả về kích thước stack - O(1)
    int size() {
        return count;
    }

    ~StackLinkedList() {
        while (!isEmpty()) {
            pop();
        }
    }
};

struct QueueArray {
    static const int MAX = 1000; // Kích thước tối đa của mảng
    int arr[MAX];
    int frontIndex;
    int rearIndex;
    int count;

    QueueArray() : frontIndex(0), rearIndex(-1), count(0) {}

    // Kiểm tra queue rỗng - O(1)
    bool isEmpty() {
        return count == 0;
    }

    // Thêm phần tử vào cuối queue - O(1)
    void enqueue(int item) {
        if (count >= MAX) {
            cout << "Queue Overflow";
            return;
        }
        arr[++rearIndex] = item;
        count++;
    }

    // Xóa và trả về phần tử đầu - O(n) do cần dịch chuyển mảng
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty";
            return -1;
        }
        int value = arr[frontIndex];
        for (int i = 0; i < rearIndex; i++) {
            arr[i] = arr[i + 1];
        }
        rearIndex--;
        count--;
        return value;
    }

    // Trả về phần tử đầu  - O(1)
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[frontIndex];
    }

    // Trả về kích thước queue - O(1)
    int size() {
        return count;
    }
};

// Định nghĩa cấu trúc Queue sử dụng Linked List
struct QueueLinkedList {
    Node* frontNode;
    Node* rearNode;
    int count;

    QueueLinkedList() : frontNode(nullptr), rearNode(nullptr), count(0) {}

    // Kiểm tra queue rỗng - O(1)
    bool isEmpty() {
        return frontNode == nullptr;
    }

    // Thêm phần tử vào cuối queue - O(1)
    void enqueue(int item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        count++;
    }

    // Xóa và trả về phần tử đầu - O(1)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty";
            return -1;
        }
        Node* temp = frontNode;
        int value = temp->data;
        frontNode = frontNode->next;
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }
        delete temp;
        count--;
        return value;
    }

    // Trả về phần tử đầu mà không xóa - O(1)
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty";
            return -1;
        }
        return frontNode->data;
    }

    // Trả về kích thước queue - O(1)
    int size() {
        return count;
    }

    ~QueueLinkedList() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    StackArray sa;
    sa.push(1);
    sa.push(2);
    sa.push(3);
    cout  << sa.top() << endl;
    cout  << sa.size() << endl;
    cout  << sa.pop() << endl;
    cout  << sa.top() << endl;
    cout  << sa.isEmpty() << endl;

    StackLinkedList sl;
    sl.push(1);
    sl.push(2);
    sl.push(3);
    cout  << sl.top() << endl;
    cout  << sl.size() << endl;
    cout  << sl.pop() << endl;
    cout  << sl.top() << endl;
    cout  << sl.isEmpty() << endl;

    QueueArray qa;
    qa.enqueue(1);
    qa.enqueue(2);
    qa.enqueue(3);
    cout  << qa.front() << endl;
    cout  << qa.size() << endl;
    cout  << qa.dequeue() << endl;
    cout  << qa.front() << endl;
    cout  << qa.isEmpty() << endl;

    QueueLinkedList ql;
    ql.enqueue(1);
    ql.enqueue(2);
    ql.enqueue(3);
    cout  << ql.front() << endl;
    cout  << ql.size() << endl;
    cout  << ql.dequeue() << endl;
    cout  << ql.front() << endl;
    cout  << ql.isEmpty() << endl;

    return 0;
}
