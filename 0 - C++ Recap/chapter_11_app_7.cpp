// Appendix 7
// The this Pointer

#include <iostream>
#include <cstring>

using namespace std;

class StringClass
{
public:
    StringClass &operator=(const StringClass &right_side);

private:
    char *a; // Pointer to dynamic array that holds the string.
};

int main()
{
    return 0;
}

StringClass &StringClass::operator=(const StringClass &right_side)
{
    if (this == &right_side)
    {
        return *this; // If the object on the left side of the assignment operator is the same as the object on the right side,
                      // then the assignment operator should do nothing and return the object on the left side.
    }
    else
    {
        delete[] a;
        a = new char[strlen(right_side.a) + 1];
        strcpy(a, right_side.a);
        return *this;
    }
}

// How the this pointer works:
// The this pointer is a predefined pointer that points to the calling object.
// The this pointer is passed implicitly to all member functions.

// When to use the this pointer:
// The this pointer is used to access the calling object's data members and member functions.
// The this pointer is used to return the calling object from a member function.
// The this pointer is used to compare the calling object with another object.
