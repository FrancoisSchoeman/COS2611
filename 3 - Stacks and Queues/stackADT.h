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

#ifndef H_STACK_ADT
#define H_STACK_ADT

#include <iostream>
using namespace std;

template <class Type>
class stackADT
{
public:
    virtual void initializeStack() = 0;
    virtual bool isEmptyStack() const = 0; // Using const, since the state of the stack will be unchanged
    virtual bool isFullStack() const = 0;  // Using const, since the state of the stack will be unchanged

    virtual void push(const Type &newItem) = 0; // The const and & are used for performance, since a copy will not be made
    virtual void pop() = 0;
    virtual Type top() const = 0; // Using const, since the state of the stack will be unchanged
};

#endif