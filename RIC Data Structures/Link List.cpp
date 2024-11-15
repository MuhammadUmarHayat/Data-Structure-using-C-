/*

A Linked List is a data structure in which elements, called nodes, are stored sequentially
 but not in contiguous memory locations.
 
 Each node contains two parts:

Data: Stores the value.
Pointer (or link): Stores the address of the next node in the sequence.

The main advantage of a linked list is that it allows efficient insertion and deletion of elements without reorganizing other elements, 
as opposed to arrays where elements need to be shifted when inserting or deleting an element.
 However, accessing elements by index is slower in a linked list compared to an array since you have to traverse from the head node to reach a specific node.


*/


#include <iostream>
using namespace std;

class Node 
{
public:
    int data;      // Data part of the node
    Node* next;    // Pointer to the next node

    // Constructor to initialize node with data
    Node(int value) 
	{
        data = value;
        next = NULL; 
    }
};

class LinkedList {
private:
    Node* head;  // Pointer to the first node in the list

public:
    // Constructor to initialize an empty list
    LinkedList() {
        head = NULL; 
    }

    // Insert a new node at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);
        
        if (head == NULL) {  // If list is empty
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {  // Traverse to the end
                temp = temp->next;
            }
            temp->next = newNode;  // Link last node to new node
        }
    }

    // Delete a node with a specific value
    void deleteNode(int value) {
        if (head == NULL) {  // If list is empty
            cout << "List is empty." << endl;
            return;
        }

        // If head node itself holds the value
        if (head->data == value) {
            Node* temp = head;
            head = head->next;  // Move head to next node
            delete temp;
            return;
        }

        // Search for the node with the value
        Node* current = head;
        Node* previous = NULL;
        while (current != NULL && current->data != value) {
            previous = current;
            current = current->next;
        }

        // If value not found in list
        if (current == NULL) {
            cout << "Value not found in the list." << endl;
            return;
        }

        // Unlink the node from the list
        previous->next = current->next;
        delete current;
    }

    // Display the contents of the list
    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    // Destructor to clean up memory
    ~LinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    LinkedList list;

    // Insert elements into the list
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    // Display the list
    cout << "Linked List: ";
    list.display();  // Output: 10 -> 20 -> 30 -> 40 -> nullptr

    // Delete an element
    list.deleteNode(20);
    cout << "After deleting 20: ";
    list.display();  // Output: 10 -> 30 -> 40 -> nullptr

    return 0;
}

