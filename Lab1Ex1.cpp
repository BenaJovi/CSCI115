/*  Author: Jovani Benavides
 *  Course: CSCI-41
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

bool MyStack::IsFull() {
    return size == capacity;
}

bool MyStack::IsEmpty() {
    return size == 0;
}

double MyStack::Pop() {
    if (IsEmpty()) {
        throw "Stack is empty. Cannot pop.";
    }
    return s[--size];
}

double MyStack::Top() {
    if (IsEmpty()) {
        throw "Stack is empty. Cannot get top element.";
    }
    return s[size - 1];
}

void MyStack::Push(double x) {
    if (IsFull()) {
        throw "Stack is full. Cannot push.";
    }
    s[size++] = x;
}

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

    // Push elements into the second stack
    stack.Push(60);
    stack.Push(40);
    stack.Push(20);

    // Display the elements in the second stack
    std::cout << "Stack: ";
    stack.Display();

    // Pop elements from the stack
    cout << "Popped: " << stack.Pop() <<endl;

    cout<<"Peeked: "<<stack.Top()<<endl;

    cout << "Stack: ";
    stack.Display();

    return 0;
}