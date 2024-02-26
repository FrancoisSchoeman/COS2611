// Chaoter 10: Classes
// Chapter 10.1: Structures

#include <iostream>

using namespace std;

// A structure is a user-defined data type that can be used to group related data items of different data types.
// Structures are similar to classes, but they are simpler and do not have member functions.
// Structures are useful for storing related data items of different data types.
// A structure value is a collection of smaller values called member values.

// Creating a structure
struct CDAccount
{
    double balance;
    double interestRate;
    int term;
}; // The semicolon is required after the closing curly brace of a structure definition.

// Defining structures inside other structures
struct Date
{
    int month;
    int day;
    int year;
};

struct PersonInfo
{
    double height; // in inches
    int weight;    // in pounds
    Date birthday;
};

int main()
{
    // Creating structure variables
    CDAccount myAccount, yourAccount;

    // Initializing structure variables
    CDAccount myAccount = {
        1000, // balance
        0.05, // interestRate
        12    // term
    };
    CDAccount yourAccount = {2000, 0.05, 12};

    myAccount.balance = 1000;
    myAccount.interestRate = 0.05;
    myAccount.term = 12;

    // Using structure variables as function parameters
    void displayAccount(CDAccount account);
    displayAccount(myAccount);

    // Returning a structure from a function
    CDAccount shrinkWrap(double theBalance, double theRate, int theTerm);
    CDAccount myAccount = shrinkWrap(200.00, 0.05, 12);

    // Assigning structure values that are structures
    PersonInfo myInfo;
    myInfo.birthday.month = 12;

    return 0;
}

// Returning a structure from a function
CDAccount shrinkWrap(double theBalance, double theRate, int theTerm)
{
    CDAccount temp;
    temp.balance = theBalance;
    temp.interestRate = theRate;
    temp.term = theTerm;
    return temp;
}
