// Chapter 12: Separate Compilation and Namespaces
// Chapter 12.2: Namespaces

#include <iostream>

using namespace std;

// When a program uses different classes and functions written by different programmers,
// there is a possibility that two programmers will use the same name for two different things.
// Namespaces are a way to deal with this problem.

// The global namespace is the namespace that contains all the names that are not declared in a namespace.
// If we did not use the std namespace for iostream, then we would have to write the following:
// std::cout << "Hello, world!" << std::endl;

int main()
{
    // Example of calling the same function from two different namespaces:
    // using namespace ns1;
    // myFunction();

    // using namespace ns2;
    // myFunction();

    // Example 2:
    cout << "Hello, world!" << endl;
    std::cout << "Hello, world!" << std::endl;

    return 0;
}