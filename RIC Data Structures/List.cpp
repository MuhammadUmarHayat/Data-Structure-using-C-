/*
List Data Structure
In C++, a list is a linear data structure that consists of a sequence of elements,
 where each element points to the next one.
We can create a list data structure using an array.
We can use an array as data structure. 
An array is a fixed size container which can contain different elements.
We can add ,show, update, find and remove different element to and from an array. 
In the given example i am working on integer type array List for sake of simplisity. 
You can enhance as per your requirements.................

*/


#include<iostream>
using namespace std;

class List {
private:
    int* arr;   // Dynamic array to store the list elements
    int index;  // Tracks the current size of the list (next index for insertion)
    int size;   // The maximum size of the list

public:
    // Constructor with initial size
    List(int s) 
	{
        size = s;
        arr = new int[size]; // Dynamically allocate memory for the array
        index = 0;           // Initially, the list is empty

        // Initialize all elements to zero
        for (int i = 0; i < size; i++) 
		{
            arr[i] = 0;
        }
    }

    // Destructor to free allocated memory
    ~List() {
        delete[] arr;
    }

    // Add an element at the next available index
    void insert(int value) {
        if (index < size) {
            arr[index] = value;
            index++;
        } else {
            cout << "List is full. Cannot insert element." << endl;
        }
    }

    // Update an element at a specified index
    void update(int index, int value) {
        if (index >= 0 && index < size) 
		{
            arr[index] = value;
        } else {
            cout << "Invalid index." << endl;
        }
    }

    // Remove an element at a specified index (set it to 0)
    void remove(int index)
	 {
        if (index >= 0 && index < size) {
            arr[index] = 0;
        } else {
            cout << "Invalid index." << endl;
        }
    }

    // Show the contents of the list
    void show() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << endl;
        }
    }

    // Find and print the index of a value
    void find(int value) {
        bool found = false;
        for (int i = 0; i < size; i++) 
		{
            if (arr[i] == value) {
                cout << "Found value " << value << " at index " << i << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Value not found." << endl;
        }
    }
};

int main() {
    int size = 5;
    List mymlist(size); // Create an object of List class with a size of 5

    // Insert elements into the list
    mymlist.insert(10);
    mymlist.insert(20);
    mymlist.insert(30);
    mymlist.insert(40);
    mymlist.insert(50);

    // Find an element in the list
    mymlist.find(30);  // Output: Found value 30 at index 2

    // Show all elements in the list
    mymlist.show();
   

    return 0;
}

