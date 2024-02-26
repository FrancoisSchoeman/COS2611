// Chapter 8: Strings and Vectors
// Chapter 8.3: Vectors

#include <iostream>

#include <vector> // For the vector class

using namespace std;

int main()
{

    // A vector is similar to an array, but it can grow and shrink in size

    // Creating a vector variable
    vector<int> myVector;

    // Initializing a vector with elements
    vector<int> myVector2 = {1, 2, 3, 4, 5};

    // Initializing a vector with a size
    vector<int> myVector3(10); // Create a vector with 10 elements, each element is 0

    // Adding elements to a vector
    myVector.push_back(10); // Add 10 to the end of the vector

    // Accessing elements in a vector
    cout << myVector[0] << endl; // Access the first element in the vector

    // Removing elements from a vector
    myVector.pop_back(); // Remove the last element in the vector

    // Getting the size of a vector
    cout << myVector.size() << endl; // Returns an unsigned int

    // Creating a vector with elements
    vector<int> myVector2(10, 5); // Create a vector with 10 elements, each element is 5

    // Creating a vector with elements from an array
    int myArray[] = {1, 2, 3, 4, 5};
    vector<int> myVector3(myArray, myArray + 5); // The "myArray + 5" is the end of the array

    // Looping through a vector
    // Example 1:
    for (unsigned int i = 0; i < myVector.size(); i++)
    {
        cout << myVector[i] << endl;
    }

    // Example 2:
    for (auto i : myVector)
    {
        cout << i << endl;
    }

    // Using a vector
    // Example 1:
    vector<int> v;
    cout << "Enter a list of positive numbers.\n"
         << "Place a negative number at the end.\n";
    int next;
    cin >> next;
    while (next > 0)
    {
        v.push_back(next);
        cout << next << " added. ";
        cout << "v.size( ) = " << v.size() << endl;
        cin >> next;
    }
    cout << "You entered:\n";
    for (unsigned int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    // Get the memory capacity of a vector
    cout << "Capacity: " << v.capacity() << endl;

    // Make the capacity of a vector more efficient with the reserve() function
    v.reserve(100); // Reserve 100 elements in the vector

    return 0;
}