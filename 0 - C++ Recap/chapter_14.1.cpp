// Chapter 14: Recursion
// Chapter 14.1: Recursive Functions for Tasks

#include <iostream>
using namespace std;

// In C++, a function definition may contain a call to the function being defined. In such cases, the function is said to be recursive.

// A recursive function is a function that calls itself. A recursive function must have a base case and a recursive case (a terminating condition).

// The general outline of a successful recursive function definition is as follows:
// ■ One or more cases that include one or more recursive calls to the function being defined. These recursive calls should solve “smaller” versions of the task performed by the function being defined.
// ■ One or more cases that include no recursive calls.These cases without any recursive calls are called base cases or stopping cases.

// Infinite recursion occurs when a recursive function never reaches a base case. This can happen if the recursive case does not make the problem smaller.

// Exmaple 1:
void writeVertical(int n);
void writeVerticalIterative(int n);

int main()
{

    writeVertical(1234);

    return 0;
}

void writeVertical(int n)
{
    if (n < 10)
        cout << n << endl;
    else
    {
        writeVertical(n / 10); // Computation will stop here when the recursive call returns
        cout << (n % 10) << endl;
    }
}

void writeVerticalIterative(int n)
{
    int tensInN = 1;
    int leftEndPiece = n;
    while (leftEndPiece > 9)
    {
        leftEndPiece = leftEndPiece / 10;
        tensInN = tensInN * 10;
    }
    // tensInN is a power of ten that has the same number
    // of digits as n. For example, if n is 2345, then
    // tensInN is 1000.
    for (int powerOf10 = tensInN; powerOf10 > 0; powerOf10 = powerOf10 / 10)
    {
        cout << (n / powerOf10) << endl;
        n = n % powerOf10;
    }
}

// Stacks for Recursion:
// In order to keep track of recursion, and a number of other things, most computer systems make use of a structure called a stack.
// Since the last sheet that is put on the stack is the first sheet taken off the stack, a stack is often called a last-in/first-out (LIFO) memory structure.
// The contents of one of these portions of memory (“sheets of paper”) is called an activation frame.

// Stack Overflow:
// A stack overflow occurs when there is no more room in the stack to store activation frames. This can happen if a recursive function never reaches a base case.

// Recursion versus Iteration:
// Recursion is a powerful technique that can be used to solve a wide variety of problems. However, recursion is not always the best solution to a problem.