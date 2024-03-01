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

    void printArray(int Arr[], int n) {   //Function that will print out the array 
        for (int i = 0; i < n; ++i) {
            cout << Arr[i] << " ";
        }
        cout << endl;
    }

    // Max Heap
    void modifyValMax(int Arr[], int i, int val) {      // Function that will replace the max value and mainain heap structure.
        Arr[i] = val;   
        max_heapify(Arr, i);
    }

    void insert_value_maxHeap(int val) {                // Any new element can be added to the array 
        Arr[size] = val;
        ++size;
        max_heapify(Arr, size - 1);
    }

    int extract_maximum() {                             // Extracts the maximum value from the heap and removes it from the list
        if (size <= 0)
            throw out_of_range("Heap underflow");

        int max = Arr[0];
        Arr[0] = Arr[size - 1];
        --size;
        max_heapify(Arr, 0);
        return max;
    }


    void ascendingHeapSort() {                          // Restructures the heap into an ascending order.

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
    void modifyValMin(int Arr[], int i, int val) {      // The minimum value can be changed 
        Arr[i] = val;
        min_heapify(Arr, i);
    }

    void insert_value_minHeap(int val) {                // Insert any element to the array 
        Arr[size] = val;    
        ++size;
        min_heapify(Arr, size - 1);
    }

    int extract_minimum() {                             // Extracts the minimum value from the heap and removes it from the list. 
        if (size <= 0)
            throw out_of_range("Heap underflow");

        int min = Arr[0];
        Arr[0] = Arr[size - 1];
        --size;
        min_heapify(Arr, 0);
        return min;
    }

    void descendingHeapSort() {                         // Restructures the heap into a descedning order. 
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
    void getMaxHeapify(int Arr[], int i){               // Fucntions that call private functions. 
        for (int i = size / 2 - 1; i >= 0; --i)
            max_heapify(Arr, i);
    }
    void getMinHeapify(int Arr[],int i){
          for (int i = size / 2 - 1; i >= 0; --i)
            min_heapify(Arr, i);
    }

private:
    void max_heapify(int Arr[], int i) {                // Max Heap function
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

    void min_heapify(int Arr[], int i) {                // Min Heap function
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
    cout << "Enter the number of elements: ";           //Asks the user for the array size
    cin >> n;
    pq.Arr = new int[n];                                // Creates a new array using the class

    cout << "Enter the elements: ";                     // User enters all elements within the array 
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        pq.insert_value_maxHeap(num);
    }
    cout<<"Input Array:";                               // Displays the given array in a heap structure 
    pq.printArray(pq.Arr, pq.size);

    cout<<"Input Element:"<<element;                    // Inputs a static number of 9
    pq.insert_value_maxHeap(element);
    cout<<endl;

    char order;
    cout << "Enter the order (a for ascending, d for descending): ";    // Prompts the user for which order they would like
    cin >> order;

    if (order == 'A'|| order == 'a'){                  // If statement depending on ascending or descending 
        pq.ascendingHeapSort();
        cout << "Sorted Heap: ";                        // Outputs the ascending form 
        pq.printArray(pq.Arr, pq.size);
        pq.getMaxHeapify(pq.Arr,0);
        cout << "Extract Max value: " << pq.extract_maximum() << endl;  // Extracts the max value
        pq.ascendingHeapSort();
        pq.printArray(pq.Arr, pq.size);               // Prints new heap without the extracted value 
        cout<<"Min:"<<pq.Arr[0]<<endl;                // Min and Max are printed 
        cout<<"Max:"<<pq.Arr[n-1]<<endl;
    }
    else{
        pq.descendingHeapSort();
        cout << "Sorted Heap: ";                     // Displays the descedning order
        pq.printArray(pq.Arr, pq.size);
        pq.getMinHeapify(pq.Arr,0);         
        cout << "Extract Min value: " << pq.extract_minimum() << endl;      // Extracts the min value 
        pq.descendingHeapSort();    
        pq.printArray(pq.Arr, pq.size);              // Displays the new array with the min value removed
        cout<<"Min:"<<pq.Arr[n-1]<<endl;            // prints out min and max values 
        cout<<"Max:"<<pq.Arr[0]<<endl;
    }
    delete[] pq.Arr;
    return 0;
}




