/*  Author: Jovani Benavides
 *  Course: CSCI-115
 *  
 *  
 */
#include <iostream>
using namespace std; 

class MyStack {
public:
    MyStack();
    MyStack(int capacity);
    ~MyStack();
    bool IsFull();
    bool IsEmpty();
    double Pop();
    double Top();
    void Push(double x);
    void Display();

private:
    double* s;
    int capacity;
    int size;
};

MyStack::MyStack() {
    capacity = 10; // Fixed Capacity 
    s = new double[capacity];
    size = 0;
}

MyStack::MyStack(int capacity) {
    this->capacity = capacity;
    s = new double[capacity];
    size = 0;
}

MyStack::~MyStack() {
    delete[] s;
}
// checks if stack is full by equaling capacity 
bool MyStack::IsFull() {
    return size == capacity;
}
// Checks if stack is empty 
bool MyStack::IsEmpty() {
    return size == 0;
}
// function that will pop the top element
double MyStack::Pop() {
    if (IsEmpty()) {
        throw "Stack is empty. Cannot pop."; // catch in case the stack is empty therefore nothing is to be popped 
    }
    return s[--size];
}
// returns the top of the stack 
double MyStack::Top() {
    if (IsEmpty()) {
        throw "Stack is empty. Cannot get top element."; // catch in case the stack is empty therefore no top element 
    }
    return s[size - 1];
}
// funciton to push elements into stack 
void MyStack::Push(double x) {
    if (IsFull()) {
        throw "Stack is full. Cannot push."; // catch in case stack is full
    }
    s[size++] = x;
}
// function to output stack 
void MyStack::Display() {
    if (IsEmpty()) {
        cout << "Stack is empty." <<endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << s[i] << " ";
    }
    cout << endl;
}


int main() {
   
    // Create a stack with capacity of 10
    MyStack stack(10);

    // Push elements into the stack
    stack.Push(60);
    stack.Push(40);
    stack.Push(20);

    // Display the elements in the stack
    std::cout << "Stack: ";
    stack.Display();

    // Pop elements from the stack
    cout << "Popped: " << stack.Pop() <<endl;
    // peek: prints the top element 
    cout<<"peek: "<<stack.Top()<<endl;
    // prints final stacl 
    cout << "Stack: ";
    stack.Display();

    return 0;
}