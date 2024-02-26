// Chapter 14: Recursion
// Chapter 14.2: Recursive Functions for Values

#include <iostream>
#include <cstdlib>
using namespace std;

// The general outline of a successful recursive function that returns a value is as follows:
// ■ One or more cases in which the value returned is computed in terms of calls to the same function
//   (that is, using recursive calls). As was the case with void functions, the arguments for the recursive calls should intuitively be “smaller.”
// ■ One or more cases in which the value returned is computed without the use of any recursive calls.
//   These cases without any recursive calls are called base cases or stopping cases(just as they were with void functions).

int power(int base, int exponent);

int main()
{
    cout << power(2, 3) << endl;
    return 0;
}

int power(int base, int exponent)
{
    if (exponent < 0)
    {
        cout << "Illegal argument to power.\n";
        exit(1); // Exits the program using the cstdlib library
    }
    if (exponent > 0)
        return (power(base, exponent - 1) * base);
    else // n == 0
        return (1);
}