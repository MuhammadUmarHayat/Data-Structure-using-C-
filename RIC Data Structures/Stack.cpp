/*

Stack is a linear data structure which follows LIFO (Last In First Out) priciple.
Key Operations:
Push: Adding an element to the top of the stack.
Pop: Removing the top element from the stack.
Peek: Viewing the top element without removing it.
IsEmpty: Checking if the stack is empty.

*/

#include <iostream>
using namespace std;

class Stack {
private:
    int data[10]; // Array to hold stack elements (fixed size for simplicity)
    int topIndex;  // Index of the top element in the stack
    int maxSize;   // Maximum size of the stack

public:
    // Constructor to initialize the stack
    Stack(int size = 10)
	 {
        topIndex = -1;  // Stack is initially empty
        maxSize = size; // Set maximum size
    }

    // Push a new element onto the stack
    void push(int value) {
        if (topIndex >= maxSize - 1) { // Check if stack is full
            cout << "Stack overflow, cannot push " << value << endl;
        } else {
            data[++topIndex] = value;
            cout << "Pushed " << value << " onto the stack." << endl;
        }
    }

    // Pop an element from the stack
    void pop() {
        if (topIndex < 0) { // Check if stack is empty
            cout << "Stack underflow, cannot pop." << endl;
        } else {
            cout << "Popped " << data[topIndex--] << " from the stack." << endl;
        }
    }

    // Get the top element of the stack
    void top() const {
        if (topIndex < 0) { // Check if stack is empty
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element is " << data[topIndex] << endl;
        }
    }

    // Display all elements in the stack
    void display() const {
        if (topIndex < 0) { // Check if stack is empty
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= topIndex; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack myStack(5); // Create a stack with maximum size of 5

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.display(); // Should show all elements in the stack

    myStack.top();     // Should show the top element
    myStack.pop();     // Remove the top element
    myStack.display(); // Show elements after popping

    myStack.pop();
    myStack.pop();
    myStack.pop();     // Attempt to pop from an empty stack

    return 0;
}

