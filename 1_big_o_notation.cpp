#include <iostream>
using namespace std;

// Big-O-Notation

// The Big O Notation is used to describe the performance of an algorithm.
// It is a theoretical measure of the execution of an algorithm and does not depend on the hardware or the programming language.
// The Big O Notation is used to describe the worst-case scenario of an algorithm.

// Time Complexity: It is a measure of how fast an algorithm runs.
// Space Complexity: It is a measure of how much memory an algorithm uses.

// These are the most common time complexities:
// O(1) - Constant Time
// O(n) - Linear Time
// O(log n) - Logarithmic Time
// O(n log n) - Linearithmic Time
// O(n^2) - Quadratic Time
// O(n^3) - Cubic Time
// O(2^n) - Exponential Time
// O(n!) - Factorial Time

// These are the most common space complexities:
// Halving a list of items: O(log n)
// One for loop: O(n)
// Two for loops in sequence: O(n + n) = O(2n) = O(n)
// For loop with halving: O(n log n)
// Two nested for loops: O(n * n) = O(n^2)
// Three nested for loops: O(n^3)
// Check all combinations of a list of items: O(2^n)

int main()
{

    // O(1) - Constant Time
    int a = 1;
    cout << a << endl;

    // O(n) - Linear Time
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        cout << i << endl;
    }

    // O(n) - Linear Time - Example 2
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        cout << i << endl;
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << endl;
    }

    // O(log n) - Logarithmic Time
    int m = 10;
    while (m > 1)
    {
        cout << m << endl;
        m = m / 2;
    }

    // O(n log n) - Linearithmic Time
    for (int i = 0; i < n; i++)
    {
        m = 10;
        while (m > 1)
        {
            cout << m << endl;
            m = m / 2;
        }
    }

    // O(n^2) - Quadratic Time
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << i << " " << j << endl;
        }
    }

    // O(n^3) - Cubic Time
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cout << i << " " << j << " " << k << endl;
            }
        }
    }

    // O(2^n) - Exponential Time
    int fib(int n)
    {
        if (n <= 1)
        {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }

    // O(n!) - Factorial Time
    int fact(int n)
    {
        if (n <= 1)
        {
            return 1;
        }
        return n * fact(n - 1);
    }

    return 0;
}