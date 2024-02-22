/*  Author: Jovani Benavides
*  Course: CSCI-115
* 
* HEAP sort 
*/
#include <iostream>
using namespace std;
class Heap {
public:
    int *Arr;
    int size;

    Heap() : Arr(nullptr), size(0) {}

    void printArray(int Arr[], int n) {
        for (int i = 0; i < n; ++i) {
            cout << Arr[i] << " ";
        }
        cout << endl;
    }

    // Max Heap
    void modifyValMax(int Arr[], int i, int val) {
        Arr[i] = val;
        max_heapify(Arr, i);
    }

    void insert_value_maxHeap(int val) {
        Arr[size] = val;
        ++size;
        max_heapify(Arr, size - 1);
    }

    int extract_maximum() {
        if (size <= 0)
            throw out_of_range("Heap underflow");

        int max = Arr[0];
        Arr[0] = Arr[size - 1];
        --size;
        max_heapify(Arr, 0);
        return max;
    }


    void ascendingHeapSort() {

        for (int i = size / 2 - 1; i >= 0; --i)
            max_heapify(Arr, i);
        int cSize=size;
        for (int i = size - 1; i > 0; --i) {
            swap(Arr[0], Arr[i]);
        size--;
            max_heapify(Arr, 0);
        }
        size=cSize;
    }

    // Min Heap
    void modifyValMin(int Arr[], int i, int val) {
        Arr[i] = val;
        min_heapify(Arr, i);
    }

    void insert_value_minHeap(int val) {
        Arr[size] = val;
        ++size;
        min_heapify(Arr, size - 1);
    }

    int extract_minimum() {
        if (size <= 0)
            throw out_of_range("Heap underflow");

        int min = Arr[0];
        Arr[0] = Arr[size - 1];
        --size;
        min_heapify(Arr, 0);
        return min;
    }

    void descendingHeapSort() {
        for (int i = size / 2 - 1; i >= 0; --i)
            min_heapify(Arr, i);
        int cSize=size;
        for (int i = size - 1; i > 0; --i) {
            swap(Arr[0], Arr[i]);
            size--;
            min_heapify(Arr, 0);
        }
        size=cSize;
    }
    // Get heap
    void getMaxHeapify(int Arr[], int i){
        for (int i = size / 2 - 1; i >= 0; --i)
            max_heapify(Arr, i);
    }
    void getMinHeapify(int Arr[],int i){
          for (int i = size / 2 - 1; i >= 0; --i)
            min_heapify(Arr, i);
    }

private:
    void max_heapify(int Arr[], int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && Arr[left] > Arr[largest])
            largest = left;

        if (right < size && Arr[right] > Arr[largest])
            largest = right;

        if (largest != i) {
            swap(Arr[i], Arr[largest]);
            max_heapify(Arr, largest);
        }
    }

    void min_heapify(int Arr[], int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && Arr[left] < Arr[smallest])
            smallest = left;

        if (right < size && Arr[right] < Arr[smallest])
            smallest = right;

        if (smallest != i) {
            swap(Arr[i], Arr[smallest]);
            min_heapify(Arr, smallest);
        }
    }
};

int main() {
    Heap pq;
    int n;
    int element=9;
    cout << "Enter the number of elements: ";
    cin >> n;
    pq.Arr = new int[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        pq.insert_value_maxHeap(num);
    }
    cout<<"Input Array:";
    pq.printArray(pq.Arr, pq.size);

    cout<<"Input Element:"<<element;
    pq.insert_value_maxHeap(element);
    cout<<endl;

    char order;
    cout << "Enter the order (a for ascending, d for descending): ";
    cin >> order;

    if (order == 'A'|| order == 'a'){
        pq.ascendingHeapSort();
        cout << "Sorted Heap: ";
        pq.printArray(pq.Arr, pq.size);
        pq.getMaxHeapify(pq.Arr,0);
        cout << "Extract Max value: " << pq.extract_maximum() << endl;
        pq.ascendingHeapSort();
        pq.printArray(pq.Arr, pq.size);
    }
    else{
        pq.descendingHeapSort();
        cout << "Sorted Heap: ";
        pq.printArray(pq.Arr, pq.size);
        pq.getMinHeapify(pq.Arr,0);
        cout << "Extract Min value: " << pq.extract_minimum() << endl;
        pq.descendingHeapSort();
        pq.printArray(pq.Arr, pq.size);
    }
    delete[] pq.Arr;
    return 0;
}
