#include <iostream>
using namespace std;

// Define a node structure
struct node
{
    int value;  // Value stored in the node
    node *next; // Pointer to the next node
};

class LinkedList
{
private:
    node *head, *tail; // Pointers to the head and tail of the list

public:
    // Constructor initializes an empty list
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    // Function to create node
    void createNode(int newValue)
    {
        node *temp = new node;  // Create a new node
        temp->value = newValue; // Assign the value
        temp->next = NULL;      // Initialize the next pointer to NULL

        // If the list is empty, make the new node the head and tail
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else
        {
            // Otherwise, add the new node to the end of the list
            tail->next = temp;
            tail = temp;
        }
    }

    // Function to insert node at start, can also work for the end of the list
    void insertHead(int newValue)
    {
        node *temp = new node;  // Create a new node
        temp->value = newValue; // Assign the value
        temp->next = head;      // Point the next pointer to the current head
        head = temp;            // Make the new node the head of the list
    }

    // Function to insert a node at a given position
    void insertPosition(int position, int newValue)
    {
        node *previous = new node;
        node *current = new node;
        node *temp = new node;

        current = head;

        // Traverse the list to the desired position
        for (int i = 0; i < position; i++)
        {
            previous = current;
            current = current->next;
        }

        temp->value = newValue;
        previous->next = temp; // Insert the new node
        temp->next = current;  // Link the new node to the rest of the list
    }

    // Function to delete node at head
    void deleteHead()
    {
        node *temp = new node;
        temp = head;       // Save the head node
        head = head->next; // Make the next node the new head

        delete temp; // Delete the old head
    }

    // Funciton to delete tail of list
    void deleteTail()
    {
        node *current = new node;
        node *previous = new node;

        current = head;

        // Traverse the list until the end
        while (current->next != NULL)
        {
            previous = current;
            current = current->next;
        }

        tail = previous;       // Make the previous node the new tail
        previous->next = NULL; // Unlink the last node

        delete current; // Delete old tail
    }

    // Function to remove a node at a specific position
    void removePosition(int position)
    {
        node *current = new node;
        node *previous = new node;

        current = head;

        // Traverse the list to the desired position
        for (int i = 0; i < position; i++)
        {
            previous = current;
            current = current->next;
        }

        previous->next = current->next; // Unlink the node at the position
    }

    // Function to display linked list
    void displayList()
    {
        node *current = new node;

        current = head;

        while (current != NULL)
        {
            cout << current->value << endl;
            current = current->next;
        }
    }
};

int main()
{

    LinkedList list;

    list.createNode(10);
    list.createNode(20);
    list.createNode(30);
    list.createNode(40);
    list.createNode(50);

    list.displayList();

    list.insertHead(5);

    list.insertPosition(3, 25);

    list.displayList();

    list.deleteHead();

    list.deleteTail();

    list.removePosition(2);

    list.displayList();

    return 0;
}