// Linked lists
// Insertion and deletion on linked lists
// Build and manipulate linked lists
// Create linked list iterators
// Implement basic operations on a linked list
// Implement linked lists as ADTs

#include <iostream>
using namespace std;

//** What is a linked list?
// A linked list is a data structure that consists of a sequence of elements, where each element links to the location of the next element (node) in the sequence.
// A linked list consists of a head and a tail.
// The head is the first element in the list, and the tail is the last element in the list.
// The value of the element is store in the head.
// The tail points to the next element in the list, or it points to NULL if it is the last element in the list.

//** Difference between arrays and linked lists
//* Arrays:
// - Defined size
// - Insertion and deletion of elements are difficult
// - Accessing the elements is permitted at random
// - Elements are contiguous (they are stored in a sequence)
// - No additional space is required for the pointer to the next element

//* Linked lists:
// - Size is variable
// - Insertion and deletion of elements are simpler
// - No random access to the elements is possible
// - Elements are not contiguous (they are scattered in memory)
// - A pointer is required and requires additional memory

//** Singly Linked List:
// A singly linked list is a type of linked list that is unidirectional (it can be traversed in only one direction from the head to the last node).

//* Linked List example 1:
class Node
{
public:
    int Value;
    Node *Next;
};

//* Linked List example 2:
struct nodeType
{
    int info;
    nodeType *nextNode;
};

//* Function to print all values of a linked list (example 1)
void printList(Node *node)
{
    while (node != NULL) // Checks if the entire node is not NULL
    {
        cout << node->Value << endl;
        node = node->Next; // Change the location of the current node to the next node
    }
}

//** Function to add a node to the start of the linked list
void insertAtBeginning(Node **head, int value) // The ** is a pointer to a pointer
{
    // 1. Prepare a new node
    Node *newNode = new Node();
    newNode->Value = value;

    // 2. Put the new node in front of the current head
    newNode->Next = *head;

    // 3. Move the head of the list to point to the new node
    *head = newNode;
}

// ** Function to add a node to the end of the linked list
void insertAtEnd(Node **head, int value)
{
    // 1. Prepare a new node
    Node *newNode = new Node();
    newNode->Value = value;
    newNode->Next = NULL; // Since it's at the end of the list

    // 2. If current head pointer is equal to NULL, then our head pointer is equal to the new node
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    // 3. Find the last node
    Node *last = *head;
    while (last->Next != NULL) // Checks if the location of the node is not NULL
    {
        last = last->Next;
    }

    // 4. Insert the new node after the last node
    last->Next = newNode;
}

//** Function to add a node after a selected node
void insertAfter(Node *previous, int value)
{
    // 1. Check if previous node is NULL
    if (previous == NULL)
    {
        cout << "Previous can not be NULL" << endl;
        return;
    }

    // 2. Prepare a new node
    Node *newNode = new Node();
    newNode->Value = value;
    newNode->Next = previous->Next;

    // 3. Insert new node after previous element (node)
    previous->Next = newNode;
}

//** Function to remove a node from a linked list
void removeAfter(Node *beforeNode)
{
    // 1. Add a temporary node with the values of the node before the one that needs to be removed
    Node *temp = new Node();

    // 2. Store the node to be deleted in the temp node
    temp = beforeNode->Next;

    // 3. Set the location of the node before to the node after the one that is deleted
    beforeNode->Next = temp->Next;

    // 4. Delete the temp node
    delete temp;
}

int main()
{

    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();

    head->Value = 1;     // The -> symbol is used to access members of a pointer class
    head->Next = second; // Linking the list to the next element

    second->Value = 2;
    second->Next = third;

    third->Value = 3;
    third->Next = NULL;

    // Option 1: Printing value of linked list nodes
    // cout << head->Value << endl;
    // cout << second->Value << endl;
    // cout << third->Value << endl;

    insertAtBeginning(&head, -1);
    insertAtBeginning(&head, -2);

    insertAtEnd(&third, 4);
    insertAtEnd(&third, 5);

    insertAfter(second, 22);

    removeAfter(second);

    // Option 2: use a function to print all values in the Linked List
    printList(head);

    return 0;
}