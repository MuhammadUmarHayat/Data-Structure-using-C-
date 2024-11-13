/*
A Priority Queue is a specialized data structure that, unlike a regular queue,
 associates each element with a priority. 
 Elements with higher priority are dequeued before those with lower priority. 
  In case multiple elements have the same priority, they follow the FIFO order.

Types of Priority Queue
Max Priority Queue: Higher priority items have higher values and are dequeued first.
Min Priority Queue: Higher priority items have lower values and are dequeued first


*/

#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int* arr;
    int capacity;
    int size;

public:
    // Constructor to initialize priority queue
    PriorityQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }

    // Destructor to free allocated memory
    ~PriorityQueue() {
        delete[] arr;
    }

    // Enqueue function to add an element
    void enqueue(int value) {
        if (isFull()) {
            cout << "Priority Queue is full\n";
            return;
        }
        arr[size++] = value; // Add element at the end
        cout << "Enqueued: " << value << endl;
    }

    // Dequeue function to remove the highest priority element (largest value in this case)
    int dequeue() {
        if (isEmpty()) {
            cout << "Priority Queue is empty\n";
            return -1;
        }

        // Find the index of the maximum element
        int maxIndex = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }

        // Store the max value to return
        int maxValue = arr[maxIndex];
        
        // Shift elements to fill the gap left by the removed element
        for (int i = maxIndex; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--; // Reduce the size of the array
        cout << "Dequeued: " << maxValue << endl;
        return maxValue;
    }

    // Peek function to get the highest priority element without removing it
    int peek() const {
        if (isEmpty()) {
            cout << "Priority Queue is empty\n";
            return -1;
        }

        int maxIndex = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }
        return arr[maxIndex];
    }

    // Check if the priority queue is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Check if the priority queue is full
    bool isFull() const {
        return size == capacity;
    }

    // Get the current size of the priority queue
    int getSize() const {
        return size;
    }
};

int main() {
    PriorityQueue pq(5);

    pq.enqueue(10);
    pq.enqueue(30);
    pq.enqueue(20);
    pq.enqueue(5);

    cout << "Highest priority element: " << pq.peek() << endl;

    pq.dequeue();
    cout << "After dequeue, highest priority element: " << pq.peek() << endl;

    while (!pq.isEmpty()) {
        cout << "Dequeued: " << pq.dequeue() << endl;
    }

    return 0;
}

