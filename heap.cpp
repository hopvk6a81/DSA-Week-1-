#include <iostream>
using namespace std;

#define MAX 100

struct MaxHeap {
    int arr[MAX];
    int n;

    MaxHeap() { n = 0; }

    // Hàm hoán đổi
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Thêm 1 phần tử vào heap
    void insert(int value) {
        if (n >= MAX) {
            cout << "Heap day!" << endl;
            return;
        }
        arr[n] = value;
        int i = n;
        n++;

        while (i > 0) {
            int parent = (i - 1) / 2;
            if (arr[i] > arr[parent]) {
                swap(arr[i], arr[parent]);
                i = parent;
            } else break;
        }
    }

    // Xóa phần tử lớn nhất (root)
    int delMax() {
        if (n == 0) {
            cout << "Heap rong!" << endl;
            return -1;
        }

        int maxVal = arr[0];
        arr[0] = arr[n - 1];
        n--;

        int i = 0;
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < n && arr[left] > arr[largest]) largest = left;
            if (right < n && arr[right] > arr[largest]) largest = right;

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else break;
        }

        return maxVal;
    }

    // Lấy phần tử lớn nhất
    int getMax() {
        if (n == 0) {
            cout << "Heap rong!" << endl;
            return -1;
        }
        return arr[0];
    }

    bool isEmpty() { return n == 0; }

    int size() { return n; }

    void printHeap() {
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap heap;

    heap.insert(10);
    heap.insert(30);
    heap.insert(20);
    heap.insert(5);

    heap.printHeap();

    cout  << heap.getMax() << endl;
    cout  << heap.delMax() << endl;

    heap.printHeap();
}

