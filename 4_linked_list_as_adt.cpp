// Linked Lists as Abstract Data Types (ADT)

// At Page 1191 - Unordered Linked Lists

#include <iostream>
using namespace std;

//* The basic operations on linked lists are:
// 1. Initialize the list.
// 2. Determine whether the list is empty.
// 3. Print the list.
// 4. Find the length of the list.
// 5. Destroy the list.
// 6. Retrieve the info contained in the first node.
// 7. Retrieve the info contained in the last node.
// 8. Search the list for a given item.
// 9. Insert an item in the list.
// 10. Delete an item from the list.
// 11. Make a copy of the linked list.

//* In general, there are two types of linked lists:
// Sorted lists, whose elements are arranged according to some criteria, and
// Unsorted lists, whose elements are in no particular order.

// *The algorithms to implement the operations search, insert, and remove slightly differ for sorted and unsorted lists.
// Therefore, we will define the class linkedListType to implement the basic operations on a linked list as an abstract class.
// Using the principle of inheritance, we, will derive two classes — unorderedLinkedList and orderedLinkedList — from the class linkedListType.

// Definition of the node
template <class Type>
struct node
{
    Type value;
    node<Type> *next;
};

// Defining our base Linked List Type Class
template <class Type>
class LinkedListType
{
protected:
    int count;         // Variable to store the number of items in the list
    node<Type> *first; // Pointer to the first node
    node<Type> *last;  // Pointer to the last node
};

//* A common technique to traverse a linked list is to provide an iterator.
//* An iterator is an object that produces each element of a container, such as a linked list, one element at a time.

//* The two most common operations on iterators are ++ (the increment operator) and * (the dereferencing operator).
//* The increment operator advances the iterator to the next node in the list, and the dereferencing operator returns the info of the current node.

template <class Type>
class LinkedListIterator
{
private:
    // pointer to point to the current node in the linked list
    node<Type> *current;

public:
    // Constructors
    LinkedListIterator();
    LinkedListIterator(node<Type> *ptr);

    // Function to overload the dereferencing operator *.
    // Postcondition: Returns the info contained in the node.
    Type operator*();

    // Overload the pre-increment operator.
    // Postcondition: The iterator is advanced to the next node.
    LinkedListIterator<Type> operator++();

    // Overload the equality operator.
    // Postcondition: Returns true if this iterator is equal to the iterator specified by right, otherwise it returns false.
    bool operator==(const LinkedListIterator<Type> &right) const;

    // Overload the not equal to operator.
    // Postcondition: Returns true if this iterator is not equal to the iterator specified by right, otherwise it returns false.
    bool operator!=(const LinkedListIterator<Type> &right) const;
};

// Abstract class for the basic properties of a linked list as an ADT
template <class Type>
class LinkedListType
{
public:
    // Overload the assignment operator
    const LinkedListType<Type> &operator=(const LinkedListType<Type> &);

    // Initialize the list
    void initializeList();

    // Check if the list is empty
    bool isEmptyList() const;

    // Print the list
    void print() const;

    // Get the length of the list
    int length() const;

    // Destroy the list
    void destroyList();

    // Get the first element of the list
    Type front() const;

    // Get the last element of the list
    Type back() const;

    // Search for an item in the list (pure virtual function)
    virtual bool search(const Type &searchItem) const = 0;

    // Insert an item at the beginning of the list (pure virtual function)
    virtual void insertFirst(const Type &newValue) = 0;

    // Insert an item at the end of the list (pure virtual function)
    virtual void insertLast(const Type &newValue) = 0;

    // Delete a specific item from the list (pure virtual function)
    virtual void deleteNode(const Type &deleteItem) = 0;

    // Get an iterator pointing to the beginning of the list
    LinkedListIterator<Type> begin();

    // Get an iterator pointing to the end of the list
    LinkedListIterator<Type> end();

    // Default constructor
    LinkedListType();

    // Copy constructor
    LinkedListType(const LinkedListType<Type> &otherList);

    // Destructor
    ~LinkedListType();

protected:
    int count;         // Number of elements in the list
    node<Type> *first; // Pointer to the first node
    node<Type> *last;  // Pointer to the last node

private:
    // Copy the nodes from another list
    void copyList(LinkedListType<Type> &otherList);
};

int main()
{
    return 0;
}

// Implementation of the LinkedListIterator class methods
template <class Type>
LinkedListIterator<Type>::LinkedListIterator<Type>()
{
    current = nullptr; // Same as NULL
}

template <class Type>
LinkedListIterator<Type>::LinkedListIterator<Type>(node<Type> *ptr)
{
    current = ptr;
}

template <class Type>
Type LinkedListIterator<Type>::operator*()
{
    return current->value;
}

template <class Type>
LinkedListIterator<Type> LinkedListIterator<Type>::operator++()
{
    current = current->next;
    return *this;
}

template <class Type>
bool LinkedListIterator<Type>::operator==(const LinkedListIterator<Type> &right) const
{
    return (current == right.current);
}

template <class Type>
bool LinkedListIterator<Type>::operator!=(const LinkedListIterator<Type> &right) const
{
    return (current != right.current);
}

// LinkedListType function definitions
template <class Type>
bool LinkedListType<Type>::isEmptyList() const
{
    return (first == nullptr);
}

template <class Type>
LinkedListType<Type>::LinkedListType() // default constructor
{
    first = nullptr;
    last = nullptr;
    count = 0;
}

template <class Type>
void LinkedListType<Type>::destroyList()
{
    node<Type> *temp; // pointer to deallocate the memory
    // occupied by the node
    while (first != nullptr) // while there are nodes in
    {                        // the list
        temp = first;        // set temp to the current node
        first = first->next; // advance first to the next node
        delete temp;         // deallocate the memory occupied by temp
    }
    last = nullptr; // initialize last to nullptr; first has
    // already been set to nullptr by the while loop
    count = 0;
}

template <class Type>
void LinkedListType<Type>::initializeList()
{
    destroyList(); // if the list has any nodes, delete them
}

template <class Type>
void LinkedListType<Type>::print() const
{
    node<Type> *current; // pointer to traverse the list
    current = first;     // set current so that it points to
    // the first node
    while (current != nullptr) // while more data to print
    {
        cout << current->value << " ";
        current = current->next;
    }
}

template <class Type>
int LinkedListType<Type>::length() const
{
    return count;
}

template <class Type>
Type LinkedListType<Type>::front() const
{
    assert(first != nullptr);
    return first->value; // return the info of the first node
}

template <class Type>
Type LinkedListType<Type>::back() const
{
    assert(last != nullptr);
    return last->value; // return the info of the last node
}

template <class Type>
LinkedListType<Type> LinkedListType<Type>::begin()
{
    LinkedListIterator<Type> temp(first);
    return temp;
}

template <class Type>
LinkedListType<Type> LinkedListType<Type>::end()
{
    LinkedListIterator<Type> temp(nullptr);
    return temp;
}

template <class Type>
void LinkedListType<Type>::copyList(const LinkedListType<Type> &otherList)
{
    node<Type> *newNode;  // pointer to create a node
    node<Type> *current;  // pointer to traverse the list
    if (first != nullptr) // if the list is nonempty, make it empty
        destroyList();
    if (otherList.first == nullptr) // otherList is empty
    {
        first = nullptr;
        last = nullptr;
        count = 0;
    }
    else
    {
        current = otherList.first; // current points to the
        // list to be copied
        count = otherList.count;
        // copy the first node
        first = new node<Type>;        // create the node
        first->value = current->value; // copy the info
        first->next = nullptr;         // set the link field of
        // the node to nullptr
        last = first;            // make last point to the
                                 // first node
        current = current->next; // make current point to
        // the next node
        // copy the remaining list
        while (current != nullptr)
        {
            newNode = new node<Type>;        // create a node
            newNode->value = current->value; // copy the info
            newNode->next = nullptr;         // set the link of
            // newNode to nullptr
            last->next = newNode; // attach newNode after last
            last = newNode;       // make last point to
            // the actual last node
            current = current->next; // make current point
            // to the next node
        } // end while
    }     // end else
} // end copyList

template <class Type>
LinkedListType<Type>::~LinkedListType() // destructor
{
    destroyList();
} // end destructor

template <class Type>
LinkedListType<Type>::LinkedListType(const LinkedListType<Type> &otherList)
{
    first = nullptr;
    copyList(otherList);
} // end copy constructor

// overload the assignment operator
template <class Type>
const LinkedListType<Type> &LinkedListType<Type>::operator=(const LinkedListType<Type> &otherList)
{
    if (this != &otherList) // avoid self-copy
    {
        copyList(otherList);
    } // end else
    return *this;
}