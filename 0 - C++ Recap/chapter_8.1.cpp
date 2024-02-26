// Chapter 8: Strings and Vectors
// Chapter 8.1: An Array Type for Strings

#include <iostream>

#include <cstring> // For the C-string functions (strcpy, strlen, etc.)

#include <cstdlib> // For the atoi(), atol() and atof() function

#include <cctype> // For the isdigit() function

using namespace std;

int main()
{

    // C-Strings
    // A C-string is a sequence of characters that ends with a null character '\0'
    // The null character is a special character that is used to mark the end of a string
    // The null character is not a printable character

    // Example 1:
    char myMessage[20] = "Hi there.";
    cout << myMessage << endl; // Hi there.

    // Example 2:
    char myString[] = "Do Be Do"; // The compiler will automatically allocate enough space for the string

    // Example 3:
    char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'}; // The null character is required
    cout << greeting << endl;                           // Hello

    // Example 4:
    const int SIZE = 5;
    char ourString[SIZE] = "Hi";
    int index = 0;
    while ((ourString[index] != '\0' && index < SIZE)) // The second condition is to make sure that if we don't have a null character, we don't go out of bounds
    {
        ourString[index] = 'X';
        index++;
    }

    // Example 5:
    // char aString[10];
    // aString = "Hi"; // This will not work because aString is an array and "Hi" is a string literal

    // Assign a value to a C-string variable
    // Example 1:
    char myString[20];
    strcpy(myString, "Hi there."); // strcpy() is a function that copies a string into a C-string variable
    // strcpy() does not check to see if the string will fit into the C-string variable

    // Example 2:
    char myString[20];
    strncpy(myString, "Hi there.", 19); // strncpy() is a function that copies a string into a C-string variable and specifies the maximum number of characters to copy

    // Checking equality of C-strings
    // Example 1:
    char myString1[20] = "Hi there.";
    char myString2[20] = "Hi there.";
    if (strcmp(myString1, myString2) == 0) // strcmp() is a function that compares two C-strings and returns 0 if they are equal
    {
        cout << "The strings are equal." << endl;
    }
    else
    {
        cout << "The strings are not equal." << endl;
    }
    // The ordering relationship used for comparing characters is called lexicographic ordering
    // If both strings are all in uppercase or all in lowercase, then lexicographic order is just alphabetic order.

    // Predefined C-string Functions (from the cstring header file)
    // strlen() - returns the length of a C-string
    // strcpy() - copies a string into a C-string variable
    // strncpy() - copies a string into a C-string variable and specifies the maximum number of characters to copy
    // strcat() - concatenates two C-strings
    // strncat() - concatenates two C-strings and specifies the maximum number of characters to copy
    // strcmp() - compares two C-strings and returns 0 if they are equal
    // strncmp() - compares two C-strings and returns 0 if they are equal and specifies the maximum number of characters to compare
    // strchr() - returns a pointer to the first occurrence of a character in a C-string
    // strstr() - returns a pointer to the first occurrence of a string in a C-string
    // strupr() - converts a C-string to uppercase
    // strlwr() - converts a C-string to lowercase

    // C-String Variables in Function Parameters and Arguments
    // Example 1:
    void copyString(char source[])
    {
        char target[5];
        signed char length; // Can hold −128 to +127
        length = strlen(source);
        if (length < 5)
        {
            strcpy(target, source);
        }
    }

    // C-String to Number Conversion
    // Example 1:
    char myString[] = "123";
    int myInt;
    myInt = atoi(myString); // atoi() is a function that converts a C-string to an integer

    // Example 2:
    char myString[] = "123.45";
    double myDouble;
    myDouble = atof(myString); // atof() is a function that converts a C-string to a double

    // Example 3:
    char myString[] = "123456789";
    long myLong;             // Can hold −2,147,483,648 to +2,147,483,647
    myLong = atol(myString); // atol() is a function that converts a C-string to a long

    // The isdigit() function
    // Example 1:
    char myString[] = "123";
    int index = 0;
    bool isDigit = true;
    while (myString[index] != '\0')
    {
        if (!isdigit(myString[index])) // isdigit() is a function that returns true if the character is a digit
        {
            isDigit = false;
            break;
        }
        index++;
    }
}