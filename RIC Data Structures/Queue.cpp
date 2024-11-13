/*
A Queue is a linear data structure that follows the FIFO (First In, First Out) principle.
This means that the first element added to the queue will be the first one to be removed.
Queues are commonly used in scenarios like scheduling tasks, managing requests in servers, or handling asynchronous data.

Key Operations of a Queue
Enqueue: Add an element to the end of the queue.
Dequeue: Remove an element from the front of the queue.
Peek (or Front): Get the front element of the queue without removing it.
isEmpty: Check if the queue is empty.
isFull (for bounded queues): Check if the queue has reached its maximum capacity.
*/



#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, size;
    int* arr;
    int capacity;

public:
    // Constructor to initialize queue
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        size = 0;
        rear = capacity - 1; // Rear starts at end for circular array
    }

    // Destructor to free allocated memory
    ~Queue() {
        delete[] arr;
    }

    // Enqueue function
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % capacity; // Move rear forward in circular fashion
        arr[rear] = value;
        size++;
        cout << "Enqueued: " << value << endl;
    }

    // Dequeue function
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % capacity; // Move front forward in circular fashion
        size--;
        cout << "Dequeued: " << value << endl;
        return value;
    }

    // Get front element
    int getFront() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Check if the queue is full
    bool isFull() const {
        return size == capacity;
    }

    // Get the current size of the queue
    int getSize() const {
        return size;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Front element: " << q.getFront() << endl;

    q.dequeue();
    q.dequeue();

    q.enqueue(50);
    q.enqueue(60);

    cout << "Queue size: " << q.getSize() << endl;

    while (!q.isEmpty()) {
        cout << "Front element: " << q.getFront() << endl;
        q.dequeue();
    }

    return 0;
}

