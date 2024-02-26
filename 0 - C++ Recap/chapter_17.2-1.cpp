// Chapter 17: Templates
// Chapter 17.2: Templates for Data Abstraction

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Syntax for class templates:
template <class T>
class Pair
{
public:
    Pair();
    Pair(T firstValue, T secondValue);
    void setElement(int position, T value);
    // Precondition: position is 1 or 2.
    // Postcondition: The position indicated has been set to value.
    T getElement(int position) const;
    // Precondition: position is 1 or 2.
    // Returns the value in the position indicated.
private:
    T first;
    T second;
};

// Type Definitions:
// Example:
typedef Pair<int> PairOfInt;
// The type PairOfInt is equivalent to Pair<int>.

// Another example of a template class:
template <class ItemType>
class GenericList
{
public:
    GenericList(int max);
    // Initializes the object to an empty list that can hold up to //max items of type ItemType.
    ~GenericList();
    // Returns all the dynamic memory used by the object to the freestore.
    int length() const; // Returns the number of items on the list.
    void add(ItemType newItem);
    // Precondition: The list is not full.
    // Postcondition: The newItem has been added to the list.
    bool full() const; // Returns true if the list is full.
    void erase();      // Removes all items from the list so that the list is empty.
    friend ostream &operator<<(ostream &outs, const GenericList<ItemType> &theList)
    {
        for (int i = 0; i < theList.currentLength; i++)
            outs << theList.item[i] << endl;
        return outs;
    }
    // Overloads the << operator so it can be used to output the contents of the list.
    // The items are output one per line.
    // Precondition: If outs is a file output stream, then outs has already been connected to a file.

    // Note the implementation of the overloaded << in the header file!
    // This is commonly done with overloaded friend templates.
    // Since << is a friend it is NOT a member of the class but rather in the namespace,
    // this is the simplest implementation and may make more sense than putting it in genericlist.cpp.
private:
    ItemType *item;    // pointer to the dynamic array that holds the list.
    int maxLength;     // max number of items allowed on the list.
    int currentLength; // number of items currently on the list.
};

int main()
{
    // Example 1:
    Pair<int> score; // The type needs to be specified in angle brackets next to the class name.
    score.setElement(1, 3);
    score.setElement(2, 4);

    Pair<char> seats; // The type needs to be specified in angle brackets next to the class name.
    seats.setElement(1, 'A');
    seats.setElement(2, 'B');

    // Example 2:
    PairOfInt score2; // This is the same as Pair<int> score2;

    // Example 3:
    PairOfInt pair1, pair2; // This is the same as Pair<int> pair1, pair2;

    // Example 4:
    GenericList<int> firstList(2);
    firstList.add(1);
    firstList.add(2);
    cout << "firstList = \n"
         << firstList << endl;

    GenericList<char> secondList(10);
    secondList.add('A');
    secondList.add('B');
    secondList.add('C');
    cout << "secondList = \n"
         << secondList;

    return 0;
}

template <class T>                              // The template prefix needs to be repeated for each member function.
void Pair<T>::setElement(int position, T value) // Notice the <T> after Pair.
{
    if (position == 1)
        first = value;
    else if (position == 2)
        second = value;
    else
    {
        cout << "Error: Illegal pair position.\n";
        exit(1); // The exit function is in the cstdlib header file.
    }
}

template <class T>                                                                  // The template prefix needs to be repeated for each member function.
Pair<T>::Pair(T firstValue, T secondValue) : first(firstValue), second(secondValue) // Notice the <T> after Pair.
{
}

// Syntax to use a class template as an argument to a function:
// Option 1:
int addUp(const Pair<int> &thePair); // Returns the sum of the two integers in thePair.

// Option 2:
template <class T>
T addUp(const Pair<T> &thePair);
// Precondition: The operator + is defined for values of type T.
// Returns the sum of the two values in thePair.

//* Implementation of the GenericList class:
// Uses cstdlib:
template <class ItemType>
GenericList<ItemType>::GenericList(int max) : maxLength(max), currentLength(0)
{
    item = new ItemType[max];
}

template <class ItemType>
GenericList<ItemType>::~GenericList()
{
    delete[] item;
}

template <class ItemType>
int GenericList<ItemType>::length() const
{
    return (currentLength);
}

// Uses iostream and cstdlib:
template <class ItemType>
void GenericList<ItemType>::add(ItemType newItem)
{
    if (full())
    {
        cout << "Error: adding to a full list.\n";
        exit(1);
    }
    else
    {
        item[currentLength] = newItem;
        currentLength = currentLength + 1;
    }
}

template <class ItemType>
bool GenericList<ItemType>::full() const
{
    return (currentLength == maxLength);
}

template <class ItemType>
void GenericList<ItemType>::erase()
{
    currentLength = 0;
}