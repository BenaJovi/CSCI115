/*  Author: Jovani Benavides
*  Course: CSCI-115
* 
* Counting sort 
*/
#include <iostream>
#include <ctime>
using namespace std;

#define MAX 1000000

//Function that will print out the array 
void printArray(int Arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << Arr[i] << " ";
    }
    cout << endl;
}

// Function that creates a random array
void randomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Uses numbers up to 10000
    }
}

// Function to get the maximum value from array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Counting Sort
void countingSort(int arr[], int n) {
    int output[MAX];
    int count[MAX] = {0};
    int max = getMax(arr, n);

    for (int i = 0; i < n; i++) // Stores the count for each element 
        count[arr[i]]++;

    for (int i = 1; i <= max; i++) // Stores the cummulative values   
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {  // Finds the index of each value and places the corresponding value in that index
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) // Transfers values into the actual array 
        arr[i] = output[i];
}

// Counting Sort for radix sort
void countingSortForRadix(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) // Finds the count of elements
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++) // Calculates the cummulative value
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {  // Places the elements in sorted order 
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) // Transfers the values into the actual array 
        arr[i] = output[i];
}

// Radix Sort function
void radixSort(int arr[], int n) {
    int m = getMax(arr, n); // Calls getmax function to get the max value

    for (int exp = 1; m / exp > 0; exp *= 10) // applies the countsort for each place value 
        countingSortForRadix(arr, n, exp);
}

int main() {
    clock_t start_time, end_time; // Using <Ctime> to initialize time functions

    int size = 25; // set size of 25

    int* array = new int[size];
    cout << "Randomly generated array:" << endl;
    randomArray(array, size);
    printArray(array, size);
    cout<<"\n";

    cout<<"Array after counting sort:"<<endl;
    start_time =clock();// Starts Timer
    countingSort(array, size);
    end_time=clock();// End Timer 
    printArray(array, size);
    cout << "Time taken using counting sort: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl; // Calculates Time Taken From Start To End 
    cout<<"\n";


    cout << "Array after radix sort:" << endl;
    start_time = clock(); // Starts Timer
    radixSort(array, size);
    end_time = clock(); // End Timer
    printArray(array, size);
    cout << "Time taken using radix sort: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl; // Calculates Time Taken From Start To End
    cout << "\n";

    return 0;
}

