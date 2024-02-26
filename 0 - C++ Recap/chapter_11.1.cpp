// Chapter 11: Friends, Overloaded Operators and Arrays in Classes
// Chapter 11.1: Friend Functions

#include <iostream>

using namespace std;

// Friend functions are not members of a class, but they have access to the private and protected members of a class.
// Friend functions are not in the scope of a class. They are defined outside the class.

// Example:
class Box
{
public:
    friend void printWidth(Box box); // Friend function
    void setWidth(double wid);

private:
    double width;
};

// Member function definition
void Box::setWidth(double wid)
{
    width = wid;
}

// Friend function definition
void printWidth(Box box)
{
    cout << "Width of box: " << box.width << endl;
}

// How to decide whether to make a function a friend or a member function?
// 1. Use a member function if the task requires only one object.
// 2. Use a friend function if the task requires multiple objects. (you can use normal non-member functions as well)

// A call by reference is more efficient than a call by value.
// Use const with reference class parameters to avoid accidental changes to the object in a friend function.

// Using const on a member function prevents the member function from changing the object.
// Example:
// void output(ostream outs) const; // This function cannot change the object

// The const keyword should be used in the function definition as well as in the function declaration.
// If you do not use const every time that it is appropriate for a class, then you should never use it for that class.

int main()
{
    // REMEMBER: Converting a char to an int
    char c = 'a';
    int i;

    i = static_cast<int>(c) - static_cast<int>('0'); // This is the way to convert a char to an int

    return 0;
}