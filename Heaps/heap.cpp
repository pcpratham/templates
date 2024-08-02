#include<bits/stdc++.h>

using namespace std;

class heap {
    public:
        int arr[100];
        int size;

        heap() {
            arr[0] = -1;
            size = 0;
        }

        void insert(int val) {
            size = size + 1;
            int index = size;
            arr[index] = val;

            while(index > 1) {
                int parent = index / 2;
                if(arr[parent] < arr[index]) {
                    // Max-heap property violated
                    swap(arr[parent], arr[index]);
                    index = parent;
                } else {
                    return;
                }
            }
        }

        void print() {
            for(int i = 1; i <= size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        void deleteFromHeap() {
            if(size == 0) {
                cout << "Nothing to delete" << endl;
                return;
            }

            arr[1] = arr[size];
            size--;

            int i = 1;
            while(i <= size) {
                int leftIndex = 2 * i;
                int rightIndex = 2 * i + 1;
                int largest = i;

                if(leftIndex <= size && arr[leftIndex] > arr[largest]) {
                    largest = leftIndex;
                }
                if(rightIndex <= size && arr[rightIndex] > arr[largest]) {
                    largest = rightIndex;
                }
                if(largest != i) {
                    swap(arr[largest], arr[i]);
                    i = largest;
                } else {
                    return;
                }
            }
        }
};

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if(left <= n && arr[left] > arr[largest]) {
        largest = left;
    }
    if(right <= n && arr[right] > arr[largest]) {
        largest = right;
    }
    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int size = n;
    while(size > 1) {
        cout << "Element at 1st index " << arr[1] << endl;
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}

int main() {
    // Uncomment to test the heap class functionality
    heap hs;
    cout << "Heap started" << endl;
    hs.insert(60);
    hs.insert(50);
    hs.insert(40);
    hs.insert(30);
    hs.insert(20);
    hs.insert(10);
    hs.print();
    hs.insert(55);
    hs.print();
    hs.deleteFromHeap();
    hs.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for(int i = n / 2; i > 0; i--) {
        heapify(arr, n, i);
    }

    cout << "Printing the array now" << endl;
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);

    cout << "Printing the sorted array now" << endl;
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
