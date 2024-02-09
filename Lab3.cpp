/*  Author: Jovani Benavides
*  Course: CSCI-115
* 
* Merge sort and Selection sort.
*/

#include <iostream>
#include <ctime>
using namespace std;

void sortedArray(int arr[], int n){   // Funciton that creates a sorted in array size of n
    for (int i=0;i<n;i++){
    arr[i]=i;
    }
    return;

}

void halfSortedArray(int arr[],int n){ // Function that creates a half sorted array size of n 
    for (int i=0;i<n;i++){
        if(i<n/2)
        {
            arr[i]=i;
        }
        else
        {
             arr[i]=rand()%100; 
        }
    }
    return;
}

void reverseSortedArray(int arr[],int n){ // Function that creates a reverse sorted array size of n 
    for(int i=0; i<n;i++){
        arr[i]=n-i;
    }
    return;

}

// Selection sort 
void selectionSort(int arr[], int n)     
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {      
        min_idx = i;
        for (j = i + 1; j < n; j++) {  
            if (arr[j] < arr[min_idx]) 
                min_idx = j;           
        }
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

// Merge Sort
void merge(int array[], int const left,int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    int *leftArray = new int[subArrayOne];
    int *rightArray = new int[subArrayTwo];
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
    int indexOfSubArrayOne = 0;
    int indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while (indexOfSubArrayOne < subArrayOne &&
           indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <=rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray]=leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] =rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] =leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] =rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
void mergeSort(int array[],int const begin,int const end)
{
    if (begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

// Print array function
void printArray(int arr[], int n)
{
    for (int i=0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

int main()
{
    clock_t start_time, end_time; // Using <Ctime> to initialize time functions
    int size=100000;
    int* array= new int[size];

    cout<<"Case 1: Sorted Array"<<endl;
    sortedArray(array,size);
    printArray(array,size);

    start_time =clock();// Starts Timer
    selectionSort(array,size);
    end_time=clock();
    cout<<"After selection sort:"<<endl;
    printArray(array,size);
    cout << "Time taken using selection sort: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl; // Calculates Time Taken From Start To End 

    sortedArray(array,size);
    start_time =clock();// Starts Timer
    mergeSort(array,0,size-1);
    end_time=clock();
    cout<<"After merge sort:"<<endl;
    printArray(array,size);
    cout << "Time taken using merge sort: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl; // Calculates Time Taken From Start To End 
    cout<<"\n";
    

    cout<<"Case 2: Half sorted array"<<endl;
    halfSortedArray(array,size);
    printArray(array,size);

    start_time =clock();// Starts Timer
    selectionSort(array,size);
    end_time=clock();
    cout<<"After selection sort:"<<endl;
    printArray(array,size);
    cout << "Time taken using selection sort: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl; // Calculates Time Taken From Start To End

    halfSortedArray(array,size);
    start_time =clock();// Starts Timer
    mergeSort(array,0,size-1);
    end_time=clock();
    cout<<"After merge sort:"<<endl;
    printArray(array,size);
    cout << "Time taken using merge sort: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl; // Calculates Time Taken From Start To End 
    cout<<"\n";

    cout<<"Case 3: Reverse sorted array"<<endl;
    reverseSortedArray(array,size);
    printArray(array,size);

    start_time =clock();// Starts Timer
    selectionSort(array,size);
    end_time=clock();
    cout<<"After selection sort:"<<endl;
    printArray(array,size);
    cout << "Time taken using seletion sort: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl; // Calculates Time Taken From Start To End

    reverseSortedArray(array,size);
    start_time =clock();// Starts Timer
    mergeSort(array,0,size-1);
    end_time=clock();
    cout<<"After merge sort:"<<endl;
    printArray(array,size);
    cout << "Time taken using merge sort: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl; // Calculates Time Taken From Start To End 
}