// Chapter 9: Pointers and Dynamic Arrays
// Chapter 9.2: Dynamic Arrays

#include <iostream>

using namespace std;

int main()
{
    // Dynamic arrays are created using the new operator and deleted using the delete operator.
    // The new operator returns a pointer to the first element of the array.
    // The delete operator is used to delete the array.

    // The following code creates an array of 10 integers and initializes the first 5 elements to 0.
    int *p = new int[10];

    for (int i = 0; i < 5; i++)
        p[i] = 0;

    // The following code deletes the array.
    delete[] p; // You should always delete the array once you are done with it.

    // The following code creates an array of 10 integers and initializes the first 5 elements to 0.
    int *p = new int[10]{0, 0, 0, 0, 0};

    // The following code deletes the array.
    delete[] p; // You should always delete the array once you are done with it.

    // You can reuse the same pointer to create a new array.
    p = new int[20];

    // You can pass a dynamic array to a function as a normal array parameter.
    printArr(p);

    return 0;
}

void printArr(int *myArr)
{
    for (int i = 0; i < 20; i++)
    {
        cout << myArr[i] << endl;
    }
}