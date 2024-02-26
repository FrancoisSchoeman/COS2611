// Chapter 11: Friends, Overloaded Operators and Arrays in Classes
// Chapter 11.3: Classes and Dynamic Arrays

#include <iostream>
#include <cstdlib> // Provides size_t
#include <cstring> // Provides strlen and strcpy
#include <cstddef> // Provides NULL

using namespace std;

class StringVar
{
public:
    StringVar(int size);
    StringVar();
    StringVar(const char a[]); // constructor for yourName
    StringVar(const StringVar &stringObject);
    ~StringVar(); // Returns the dynamic memory used by the object to the freestore
    // A destructor has no parameters and no return type.
    // The name of the destructor is the name of the class preceded by a tilde (~).
    // A destructor is called automatically when an object of the class goes out of scope.
    // A class can have only one destructor.
    int length() const;
    void inputLine(istream &ins);
    friend ostream &operator<<(ostream &outs, const StringVar &theString);
    void operator=(const StringVar &rightSide); // Overloaded assignment operator
    // Overloads the assignment operator so that it copies the value of one StringVar object into another.
    // The assignment operator is a member function that has one parameter of type StringVar.
    // The overloaded assignment operator must be a member function.

private:
    char *value; // Pointer to dynamic array that holds the string.
    int maxLength;
};

// Uses cstddef and cstdlib:
StringVar::StringVar(int size) : maxLength(size)
{
    value = new char[maxLength + 1]; //+1 is for '\0'. value[0] = '\0';
} // Uses cstddef and cstdlib:

StringVar::StringVar() : maxLength(100)
{
    value = new char[maxLength + 1]; //+1 is for '\0'. value[0] = '\0';
}

// Uses cstring, cstddef, and cstdlib:
StringVar::StringVar(const char a[]) : maxLength(strlen(a))
{
    value = new char[maxLength + 1]; //+1 is for '\0'.
    strcpy(value, a);                // strcpy copies a into value (a is a cstring)
}

// Uses cstring, cstddef, and cstdlib:
StringVar::StringVar(const StringVar &stringObject) : maxLength(stringObject.length()) // Copy constructor (discussed later)
{
    value = new char[maxLength + 1]; //+1 is for '\0'.
    strcpy(value, stringObject.value);
}

StringVar::~StringVar() // Destructor
{
    delete[] value;
}

// Uses cstring:
int StringVar::length() const
{
    return strlen(value);
}

// Uses iostream:
void StringVar::inputLine(istream &ins)
{
    ins.getline(value, maxLength + 1);
}

// Uses iostream:
ostream &operator<<(ostream &outs, const StringVar &theString)
{
    outs << theString.value;
    return outs;
}

void StringVar::operator=(const StringVar &rightSide)
{
    if (maxLength != rightSide.maxLength)
    {
        delete[] value;
        maxLength = rightSide.maxLength;
        value = new char[maxLength + 1];
    }
    strcpy(value, rightSide.value);
}

// C++ has a special kind of member function called a destructor (~).
// A destructor is a member function that is automatically called when an object of the class goes out of scope.
// If the destructor is defined correctly, the destructor calls delete to eliminate all the dynamic variables created by the object.
// This may be done with a single call to delete or it may require several calls to delete.
// You might also want your destructor to perform some other cleanup details as well, but returning memory to the freestore is the main job of the destructor.

void conversation(int maxNameSize);

int main()
{
    conversation(30); // Memory is returned to the freestore when conversation function ends.
    // Notice that the size of this array is not determined until the object is declared
    cout << "End of demonstration.\n";
    return 0;
}

void conversation(int maxNameSize)
{
    StringVar yourName(maxNameSize), ourName("Borg"); // Determines the size of the dynamic array

    cout << "What is your name?\n";
    yourName.inputLine(cin);
    cout << "We are " << ourName << endl;
    cout << "We will meet again " << yourName << endl;
}

// Pitfalls of Pointers as Call-by-Value Parameters
// 1. The function can change the value of the pointer parameter so that it no longer points to the original variable.
// 2. The function can change the value of the variable to which the pointer points.
// 3. The function can change the value of the variable to which the pointer points to a value that is not valid.

// Copy Constructors
// A copy constructor is a constructor that initializes an object using another object of the same class.
// The one parameter of a copy constructor is a reference to an object of the same class.
// Normally the parameter is declared to be const.
// A copy constructor is defined in the same way as any other constructor and is used just like any other constructors.

// When to use a copy constructor
// If a class definition involves pointers and dynamic memory (using the new operator), then a copy constructor is needed.

// The Big Three
// The copy constructor, the = operator, and the destructor are called the big three because experts say that if you need to define
// any of them, then you need to define all three. If any of these is missing, the compiler will create it, but it may not behave as
// you want. So it pays to define them yourself.The copy constructor and overloaded = operator that the compiler generates for you
// will work fine if all member variables are of predefined types such as int and double, but they may misbehave on classes that have
// class or pointer member variables.For any class that uses pointers and the new operator, it is safest to define your own copy
// constructor, overloaded =, and destructor.
