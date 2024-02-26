// Chapter 8: Strings and Vectors
// Chapter 8.2: Converting between C-Strings and String Objects

#include <iostream>

#include <cstring> // For the C-string functions (strcpy, strlen, etc.)

#include <string> // For the string class

using namespace std;

int main()
{

    // Converting a C-string to a string object
    // Example 1:
    char myString[] = "Hi there.";
    string myStringObject = myString; // This will work because a string object is a class and a C-string is an array

    // Convert a string object to a C-string
    // Example 1:
    char aCString[20];
    string stringVariable = "Hi there.";
    strcpy(aCString, stringVariable.c_str());
}