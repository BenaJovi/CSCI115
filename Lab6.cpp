/*  Author: Jovani Benavides
*  Course: CSCI-115
* 
* Quick Sort 
*/
#include <iostream>
#include <ctime>

using namespace std;

// Function to swap two elements in the array
void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// Function to choose pivot using a switch statement 
int choosePivot(int arr[], int left, int right, int choice) {
    switch(choice){
        case 1:
            return left;
            break;
        case 2:
            return left + rand() % (right - left + 1);
            break;
        case 3:
            return (right + left) / 2;
            break;
    }
    return 0;
}

int partition(int arr[], int low, int high, int choice) {
    int pivotIndex = choosePivot(arr, low, high, choice);
    int pivot = arr[pivotIndex];
    
    swap(arr, pivotIndex, high); // Move pivot element to the end
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high); // Move pivot to its correct position
    return i + 1;
}



// Function to implement Quick Sort
void quickSort(int arr[], int left, int right, int choice) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right, choice);
        quickSort(arr, left, pivotIndex - 1, choice);
        quickSort(arr, pivotIndex + 1, right, choice);
    }
}
// Function that creates a random array
void randomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Uses numbers up to 10000
    }
}
// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Random number generator
    clock_t start_time, end_time; // Using <Ctime> to initialize time functions


    int size = 500000; // set size of 25

    int* arr = new int[size];
    randomArray(arr, size);
    cout<<"\n";

    int choice;
    cout << "Choice 1: First element "<<endl;
    cout << "Choice 2: Random element "<<endl;
    cout << "Choice 3: Middle element "<<endl;

    cout << "Enter pivot choice (1, 2, or 3): ";

    cin >> choice;

    //cout << "Original array: ";
    //printArray(arr, size);

    start_time =clock();// Starts Timer
    quickSort(arr, 0, size - 1, choice);
    end_time=clock();// End Timer 

    //cout << "Sorted array: ";
    //printArray(arr, size);
    cout << "Time taken using Quick sort: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl; // Calculates Time Taken From Start To End 
    cout<<"\n";

    return 0;
}
