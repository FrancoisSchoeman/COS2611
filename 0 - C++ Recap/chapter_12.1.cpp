// Chapter 12: Separate Compilation and Namespaces
// Chapter 12.1: Separate Compilation

#include <iostream>

using namespace std;

// ADT Revision:
// An abstract data type (ADT) is a class that uses private member variables and public functions to represent a data type.

// How to construct an ADT:

// 1. Make all member variables private.

// 2. Make each of the basic operations for the ADT (the class) either a public member function of the class,
//    a friend function, an ordinary function, or an overloaded operator. Group the class definition and the function
//    and operator declarations together. This group, along with its accompanying comments, is called the interface for
//    the ADT. Fully specify how to use each such function or operator in a comment given with the class or with the function
//    or operator declaration.

// 3. Make the implementation of the basic operations unavailable to the programmer who uses the abstract data type.
//    The implementation consists of the function definitions and overloaded operator definitions (along with any helping
//    functions or other additional items these definitions require). Put the implementation in a separate file.

// The file that contains the interface is called the interface file.
// The file that contains the implementation is called the implementation file.
// The public part of the class definition is called the interface of the class.
// The private part of the class definition is called the implementation of the class.
// Since we cannot split a class definition into two files, we must put the interface and the implementation in
// the same interface file.

// The interface file for an ADT is called a header file.
// The header file has a .h extension and is imported into the program with a #include "name.h" directive.

// Example of an ADT:

// Header file dtime.h: This is the INTERFACE for the class DigitalTime.
// Values of this type are times of day. The values are input and output in
// 24-hour notation, as in 9:30 for 9:30 AM and 14:45 for 2:45 PM.

#ifndef DTIME_H
#define DTIME_H

class DigitalTime
{
public:
    friend bool operator==(const DigitalTime &time1, const DigitalTime &time2);
    // Returns true if time1 and time2 represent the same time;
    // otherwise, returns false.

    DigitalTime(int theHour, int theMinute);
    // Precondition: 0 <= theHour <= 23 and 0 <= theMinute <= 59.

    DigitalTime();
    // Initializes the time value to 0:00 (which is midnight).

    void advance(int minutesAdded);
    // Precondition: The object has a time value.
    // Postcondition: The time has been changed to minutesAdded minutes later.

    void advance(int hoursAdded, int minutesAdded);
    // Precondition: The object has a time value.
    // Postcondition: The time value has been advanced
    // hoursAdded hours plus minutesAdded minutes.

    friend istream &operator>>(istream &ins, DigitalTime &theObject);
    // Overloads the >> operator for input values of type DigitalTime.
    // Precondition: If ins is a file input stream, then ins has already been
    // connected to a file. An hour is next in the file, followed by a colon,

    friend ostream &operator<<(ostream &outs, const DigitalTime &theObject);
    // Overloads the << operator for output values of type DigitalTime.
    // Precondition: If outs is a file output stream, then outs has already been
    // connected to a file.

private: // This is not part of the interface for DigitalTime.
    int hour;
    int minute;
};

#endif // DTIME_H

// Implementation file dtime.cpp: This is the IMPLEMENTATION for the class DigitalTime
// where the implementation of the basic operations is unavailable to the programmer who uses the abstract data type.
// The implementation consists of the function definitions and overloaded operator definitions (along with any helping
// functions or other additional items these definitions require).
// The implementation file must include the header file. (#include "dtime.h")

// .h vs .hpp:
// Some programmers use the .hpp extension for header files that contain C++ code.
// The .h extension is used for header files that contain C code.
// The .h extension is also used for header files that contain C++ code but are included in C programs.

// Avoiding multiple definitions of the same class using #ifndef:
// The #ifndef DTIME_H directive is used to avoid multiple definitions of the same class.
// The #ifndef DTIME_H directive is called a header guard.
// The header guard is placed at the beginning of the header file, along with the #define DTIME_H directive.
// At the end of the header file, the #endif directive is placed.

// #pragma once:
// Although the #ifndef directive is the most common way to avoid multiple definitions of the same class,
// some compilers support the #pragma once directive.
// The #pragma once directive is placed at the beginning of the header file.
// The #pragma once directive is not part of the C++ standard, but it is supported by many compilers.

// Programming Tip: Defining Other Libraries
// You don't need to define a class inside a header file.
// If you have a collection of related functions that you want to use in several programs,
// you can define them in a header file.

int main()
{
    return 0;
}