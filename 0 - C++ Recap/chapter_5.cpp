// Chapter 5: Assert Macro

#include <iostream>

#define NDEBUG // This will disable the assert macro
#include <cassert>

using namespace std;

int main()
{
    int x = 0;
    int y = 0;

    cout << "Enter a number: ";
    cin >> x;

    cout << "Enter another number: ";
    cin >> y;

    assert(x != 0); // This will cause the program to terminate if x is 0

    cout << "The quotient of " << x << " and " << y << " is " << y / x << endl;

    return 0;
}