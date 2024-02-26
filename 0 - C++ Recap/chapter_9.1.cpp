// Chapter 9: Pointers and Dynamic Arrays
// Chapter 9.1: Pointers

#include <iostream>

using namespace std;

int main()
{

    // A pointer is a variable that stores the memory address of another variable

    // Creating a pointer
    int num = 1;
    int *myPointer;   // The asterisk (*) is used to declare a pointer
    myPointer = &num; // The ampersand (&) is used to get the memory address of a variable

    // Initializing a pointer
    int myInt = 5;
    int *myPointer2 = &myInt; // The ampersand (&) is used to get the memory address of a variable

    // Accessing the value of a pointer
    cout << *myPointer2 << endl; // The asterisk (*) is used to get the value of a pointer, also known as DEREFERENCING

    // Accessing the memory address of a pointer
    cout << myPointer2 << endl;

    // Changing the value of a pointer
    *myPointer2 = 10; // The asterisk (*) is used to get the value of a pointer

    // A pointer of type int is not an int, it is a memory address
    // You can't do math with a pointer

    // Example 1:
    int *p1;
    int v1 = 0;
    p1 = &v1;
    *p1 = 42;
    cout << v1 << endl;  // This will print 42
    cout << *p1 << endl; // This will print 42

    int *p2;
    p2 = p1;             // This will copy the memory address of p1 to p2
    cout << *p2 << endl; // This will print 42

    // Using the new operator to create a pointer to a nameless variable
    // Example 1:
    int *p3 = new int; // This will create a pointer to a nameless variable
    *p3 = 42;
    cout << *p3 << endl; // This will print 42

    // Example 2:
    p3 = new int; // This will create a pointer to a nameless variable
    *p3 = 53;
    cout << *p3 << endl; // This will print 53

    // Using the delete operator to delete a pointer
    // Example 1:
    delete p3; // This will delete the pointer

    // Example 2:
    int *p4 = new int;
    *p4 = 42;
    cout << *p4 << endl; // This will print 42
    delete p4;           // This will delete the pointer

    // Dangling pointers
    // If you delete a pointer that is connected to another pointer, the other pointer will become a dangling pointer (undefined)

    // Static, automatic, and dynamic variables
    // Static variables are created when the program starts and destroyed when the program ends
    // Automatic variables are created when they are needed and destroyed when they go out of scope
    // Dynamic variables are created when they are needed and destroyed when they are deleted (like the new and delete operators)

    // Defining pointer types
    // Example 1:
    typedef int *IntPtr; // This will create a new type called IntPtr
    IntPtr p5;           // This is the same as int *p5;

    // You can also use the typedef keyword to define other types
    // Example 2:
    typedef double Kilometers;
    Kilometers distance = 5.0;

    // Using typed pointers in functions
    // Example 1:
    void sample_function(IntPtr & pointer_variable); // This will pass a pointer by reference

    return 0;
}