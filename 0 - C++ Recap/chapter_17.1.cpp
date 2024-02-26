// Chapter 17: Templates
// Chapter 17.1: Templates for Algorithm Abstraction

#include <iostream>
#include <string>

using namespace std;

// Templates allow you to define func-tions and classes that have parameters for type names.
// This will allow you to design functions that can be used with arguments of different types
// and to define classes that are much more general than those you have seen before this chapter.

// Normal function definition (the arguments must be of type int):
void swapValues(int &variable1, int &variable2)
{
    int temp;
    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}

// If we also want to swap the values of two variables of type char, we have to write another function:
void swapValues(char &variable1, char &variable2)
{
    char temp;
    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}

// Templates for functions:
template <class T> // template prefix, T is a type parameter (you can call it anything you want)
void swapValues(T &variable1, T &variable2)
{
    T temp;
    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}

// You can have a separate declaration and definition for a template function, just as you can for a normal function.
// It is a best practice to not do this and to also not separate the definition and declaration into separate files.
// Another common technique is to put your definition and implementation, all in the header file.

// More than one type parameter:
template <class T1, class T2> // All type parameters must be used in the function definition.

int main()
{

    // Example 1:
    int integer1 = 1, integer2 = 2;
    swapValues(integer1, integer2); // T is replaced by int

    char symbol1 = 'A', symbol2 = 'B';
    swapValues(symbol1, symbol2); // T is replaced by char

    return 0;
}