// Chapter 17: Templates
// Chapter 17.1: Templates for Data Abstraction

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// If you want to separate the implementation of the overloaded friend insertion operator << from the header,
// then it requires a little bit of extra work. We must make a forward declaration of the << operator which
// in turn requires a forward declaration of the GenericList class.
// Below illustrates the required changes to genericlist.h while the part after main() illustrates the changes to
// genericlist.cpp, which simply has the additional implementation.

// This version moves the implementation of the overloaded <<
// to the .cpp file, but requires adding some forward declarations.
template <class ItemType>
class GenericList;
// We need a forward declaration of the GenericList template
// class for the friend header declaration that comes right after it.
template <class ItemType>
ostream &operator<<(ostream &outs, const GenericList<ItemType> &theList);
// Forward declaration of the friend << for the definition inside the
// GenericList class below. These must be defined here since << is not a member of the class.
template <class ItemType>
class GenericList
{
    // The rest of this class is identical to the previous file except the overloaded operator
    // below has no implementation code and an additional<>.
    friend ostream &operator<< <>(ostream &outs, const GenericList<ItemType> &theList);
    // Overloads the << operator so it can be used to output the contents of the list.
    // Note the <> needed after the operator (or function) name! //The implementation is in genericlist.cpp (Display 17.8).
};

int main()
{

    return 0;
}

// The rest of this file is identical to Display 17.6 except for the Implementation of <<.
template <class ItemType>
ostream &operator<<(ostream &outs, const GenericList<ItemType> &theList)
{
    for (int i = 0; i < theList.currentLength; i++)
        outs << theList.item[i] << endl;
    return outs;
}