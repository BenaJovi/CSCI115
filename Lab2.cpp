
/*  Author: Jovani Benavides
*  Course: CSCI-115
* 
* 
*/
#include <iostream>
#include <ctime>
using namespace std;


// Fibonacci Sequence Using Recursion 
int RecursiveFib(int n)
{
   if(n<=1)
   {
       return n;
   }
       return RecursiveFib(n-1)+RecursiveFib(n-2);  
  
}
  
// Fibonacci Sequence Using Memoization 
int memoizationFib(int n){
   int fib[n+1];
   fib[0]=0;
   fib[1]=1;
   for(int i=2; i<=n;i++){
       fib[i]=fib[i-1]+fib[i-2];
   }
   return fib[n];
}

// Fibonacci Sequence Using Bottom-Up 
int iterativeFib(int n){
   int previous=0;
   int current=1;
   int next=n;
   for(int i=2; i<=n;i++){
       next=current+previous;
       previous=current;
       current=next;
   }
   return next;
}


int main()
{
    int num= 120;
    clock_t start_time, end_time; // Using <Ctime> to initialize time functions
    cout<<"This is a test using 120 to show it only works for memoization and iterative methods."<<endl;
    cout<<"Input:"<<num<<endl;
    cout<<"Memoization Output:";
    start_time =clock();// Starts Timer
    cout<<memoizationFib(num)<<endl;
    end_time=clock();// Ends Timer
    cout << "Time taken: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl; // Calculates Time Taken From Start To End

    cout<<"Input:"<<num<<endl;
    cout<<"Bottom-Up Output:";
    start_time =clock();// Starts Timer
    cout<<iterativeFib(num)<<endl;
    end_time=clock();// Ends Timer
    cout << "Time taken: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl; // Calculates Time Taken From Start To End

    cout<<"Input:"<<num<<endl;
    cout<<"Recursive Output:";
    start_time =clock();// Starts Timer
    cout<<RecursiveFib(num)<<endl; // Executes Function Using Recursion
    end_time=clock();// Ends Timer
    cout << "Time taken: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl; // Calculates Time Taken From Start To End
}
