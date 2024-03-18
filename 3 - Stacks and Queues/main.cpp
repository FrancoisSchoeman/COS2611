#include <iostream>
#include "stackType.h"

using namespace std;

void testCopyConstructor(stackType<int> otherStack);

int main()
{

    stackType<int> stack(50);
    stackType<int> copyStack(50);
    stackType<int> dummyStack(100);

    stack.initializeStack();
    stack.push(85);
    stack.push(28);
    stack.push(56);

    copyStack = stack;

    cout << "The elements of copyStack: ";

    while (!copyStack.isEmptyStack())
    {
        cout << copyStack.top() << " ";
        copyStack.pop();
    }
    cout << endl;

    copyStack = stack;
    testCopyConstructor(copyStack); // Test the copy constructor

    if (!stack.isEmptyStack())
    {
        cout << "The original stack is not empty." << endl
             << "The top element of the original stack: " << endl
             << copyStack.top() << endl;
    }

    dummyStack = stack;

    cout << "The elements of dummyStack: ";
    while (!dummyStack.isEmptyStack())
    {
        cout << dummyStack.top() << endl;

        dummyStack.pop();
    }

    cout << endl;

    return 0;
}

void testCopyConstructor(stackType<int> otherStack)
{
    if (!otherStack.isEmptyStack())
    {
        cout << "otherStack is not empty." << endl
             << "The top element of otherStack: " << endl
             << otherStack.top() << endl;
    }
}