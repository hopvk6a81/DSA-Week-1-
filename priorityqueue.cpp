#include <iostream>
using namespace std;

#define MAX 100

struct PriorityQueue {
    int arr[MAX];
    int n;

    PriorityQueue() {
        n = 0;
    }

    // Chèn phần tử mới vào cuối mảng O(1)
    void insert(int value) {
        if (n >= MAX) {
            return;
        }
        arr[n++] = value;
    }

    // Kiểm tra rỗng O(1)
    bool isEmpty() {
        return n == 0;
    }

    // Trả về kích thước O(1)
    int size() {
        return n;
    }

    // Trả về giá trị lớn nhất O(n)
    int max() {
        if (isEmpty()) {
            return -1;
        }
        int maxVal = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > maxVal)
                maxVal = arr[i];
        }
        return maxVal;
    }

    // Xóa và trả về giá trị lớn nhất O(n)
    int delMax() {
        if (isEmpty()) {
            cout << "Hang doi rong!" << endl;
            return -1;
        }

        int maxIndex = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        int maxVal = arr[maxIndex];

        for (int i = maxIndex; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;

        return maxVal;
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(10);
    pq.insert(5);
    pq.insert(20);
    pq.insert(15);

    cout  << pq.size() << endl;
    cout  << pq.max() << endl;

    cout  << pq.delMax() << endl;
    cout  << pq.max() << endl;

    return 0;
}
