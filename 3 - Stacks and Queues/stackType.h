// Stacks

// A stack is a linear data structure that follows the Last In First Out (LIFO) principle.
// This means that the last element added to the stack will be the first one to be removed.
// Stacks can also be used to convert recursive algorithms to non-recursive (iterative) ones.

// Stack operations:
// - Push: Adds an element to the stack
// - Pop: Removes an element from the stack
// - Top / Peek: Returns the top element of the stack
// - initializeStack: Initializes the stack to an empty state
// - isEmptyStack: Checks if the stack is empty
// - isFullStack: Checks if the stack is full

#ifndef H_STACK_TYPE
#define H_STACK_TYPE

#include <iostream>
#include <cassert>
using namespace std;

#include "stackADT.h"

// Implementation of a stack
template <class Type>
class stackType : public stackADT<Type>
{
public:
    // Functions from ADT
    void initializeStack();
    bool isEmptyStack() const;
    bool isFullStack() const;

    void push(const Type &newItem);
    void pop();
    Type top() const;

    //* Overloading assignment operatot
    const stackType<Type> &operator=(const stackType<Type> &);

    // Constructors and Destructors
    stackType(int stackSize = 100);               // Default size is 100
    stackType(const stackType<Type> &otherStack); // Copy constructor
    ~stackType();                                 // Remove all elements from the stack

private:
    int maxStackSize; // Maximum amount of elements in the stack
    int stackTop;     // Variable to point to the top of the stack
    Type *list;       // Stack elements

    void copyStack(const stackType<Type> &otherStack);
};

//* Stack Type Function Definitions
template <class Type>
void stackType<Type>::initializeStack()
{
    // Simply set stackTop to 0 to initialize
    stackTop = 0;
}

template <class Type>
bool stackType<Type>::isEmptyStack() const
{
    // If stackTop == 0, then stack is empty
    return (stackTop == 0);
}

template <class Type>
bool stackType<Type>::isFullStack() const
{
    // If stackTop == maxStackSize, then stack is full
    return (stackTop == maxStackSize);
}

template <class Type>
void stackType<Type>::push(const Type &newItem)
{
    // Check if stack is full or not to avoid overloading errors
    if (!isFullStack())
    {
        // Add new item to the top of the stack
        list[stackTop] = newItem;

        // Increment stack top
        stackTop++;
    }
    else
    {
        cout << "Stack is full, can't add to full stack!" << endl;
    }
}

template <class Type>
void stackType<Type>::pop()
{
    // Check if stack is empty to avoid underflowing errors
    if (!isEmptyStack())
    {
        // Simply decrement stack tope by 1 to remove the stack item
        stackTop--;
    }
    else
    {
        cout << "Cannot delete item from empty stack!" << endl;
    }
}

template <class Type>
Type stackType<Type>::top() const
{
    // If stack is empty, terminate the process
    assert(stackTop != 0);

    // Return the top element of the stack by using the index (stackTop - 1)
    return list[stackTop - 1];
}

template <class Type>
void stackType<Type>::copyStack(const stackType<Type> &otherStack)
{
    // Delete the current array pointed to list
    delete[] list;

    // Copy the size of the other stack into the current stack
    maxStackSize = otherStack.maxStackSize;

    // Copy the stack top from the other stack to the current stack
    stackTop = otherStack.stackTop;

    // Allocate a new list of size maxStackSize
    list = new Type[maxStackSize];

    // Copy each other element of the list into the current stack
    for (int j = 0; j < stackTop; j++)
    {
        list[j] = otherStack.list[j];
    }
}

template <class Type>
stackType<Type>::stackType(int stackSize)
{
    if (stackSize <= 0)
    {
        cout << "Size of the array must be positive" << endl;
        cout << "Creating an array of size 100" << endl;

        maxStackSize = 100;
    }
    else
    {
        maxStackSize = stackSize;
    }

    // Initialise a new stack
    stackTop = 0;

    // Create an array to hold the stack elements
    list = new Type[maxStackSize];
}

template <class Type>
stackType<Type>::~stackType()
{
    // Deallocate the memory occupied by the array
    delete[] list;
}

// The copy constructor is called when a stack is passed as a value parameter to a function
// It copies the values of the member variables.
template <class Type>
stackType<Type>::stackType(const stackType<Type> &otherStack)
{
    // Make the current stack array empty
    list = nullptr;

    // Copy the otherStack to the current stack
    copyStack(otherStack);
}

//* Classes with pointer member variables need an overloaded assignment operator.
template <class Type>
const stackType<Type> &stackType<Type>::operator=(const stackType<Type> &otherStack)
{
    // Avoid making a copy of itself
    if (this != &otherStack)
    {
        copyStack(otherStack);
    }

    return *this;
}

#endif