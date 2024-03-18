#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "../stackType.h"

using namespace std;

int main()
{

    double GPA;                   // current GPA
    double highestGPA;            // highest GPA
    string name;                  // current name of student
    stackType<string> stack(100); // Stack with 100 spaces

    ifstream inFile;
    inFile.open("data.dat");

    if (!inFile)
    {
        cout << "The file does not exist! Exiting...";
        return 1;
    }

    cout << fixed << showpoint;
    cout << setprecision(2);

    inFile >> GPA >> name;
    highestGPA = GPA;

    while (inFile)
    {
        if (GPA > highestGPA)
        {
            stack.initializeStack();

            if (!stack.isFullStack())
            {
                stack.push(name);
            }

            highestGPA = GPA;
        }
        else if (GPA == highestGPA)
        {
            if (!stack.isFullStack())
            {
                stack.push(name);
            }
            else
            {
                cout << "Stack overflow!";
                return 1;
            }
        }

        inFile >> GPA >> name;
    }

    cout << "Highest GPA: " << highestGPA << endl;

    cout << "Students with the highest GPA:" << endl;
    while (!stack.isEmptyStack())
    {
        cout << stack.top() << endl;
        stack.pop();
    }

    cout << "### end of program ###";
}