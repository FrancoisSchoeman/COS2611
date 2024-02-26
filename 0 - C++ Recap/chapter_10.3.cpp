// Chapter 10: Classes
// Chapter 10.3: Abstract Data Types

#include <iostream>

using namespace std;

// An abstract data type (ADT) is a type (or class) for which all the operations are specified, but not the implementation.
// An ADT is a logical description of how the data should be organized and what operations can be performed on the data.

// How to create an ADT?
// 1. Make all the member variables private.
// 2. Create member functions to do all the necessary operations. (Accessor and Mutator functions)
// 3. Make any helper functions private.

// Interface for an ADT
// The interface tells the user what operations are available and how to use them.
// The interface is the public part of the class definition.

// Implementation of an ADT
// The implementation tells how the operations are performed.
// The implementation is the private part of the class definition.

// Benefits of using ADTs
// 1. The user of the ADT does not need to know how the ADT is implemented.
// 2. The implementation of the ADT can be changed without affecting the user of the ADT.
// 3. You can divide work among several programmers. Each programmer can work on a different part of the ADT.

int main()
{

    return 0;
}