// Chapter 6: I/O Streams
// Chapter 6.1: Streams and Basic File I/O

#include <iostream>
#include <fstream>
#include <cstdlib> // For the exit function

// Example 1: Reads three numbers from the file infile.dat, sums the numbers, and writes the sum to the file outfile.dat.
//(A better version of this program will be given in Display 6.2.)
int main()
{
    using namespace std;

    ifstream inStream;
    ofstream outStream;

    inStream.open("infile.dat");             // open() is a member function of the ifstream class
    outStream.open("outfile.dat", ios::app); // ios::app is a flag that tells the ofstream class to append to the file instead of overwriting it

    int first, second, third;

    if (inStream.fail()) // fail() is a member function of the ifstream class that returns true if the file failed to open
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }

    // Read the first 3 numbers from the file
    inStream >> first >> second >> third;

    // Write the sum of the first 3 numbers to the file
    outStream << "The sum of the first 3\n"
              << "numbers in infile.dat\n"
              << "is " << (first + second + third) << endl;

    inStream.close();
    outStream.close();

    return 0;
}

// Example 2: Asks the user for a filename and then opens that file for input.
// If the file opens successfully, the program reads the first 3 numbers from the file and writes the sum to the screen.
// If the file fails to open, the program writes an error message to the screen.
int main()
{
    using namespace std;

    ifstream inStream;
    char inFileName[16];

    cout << "Enter the input file name: ";
    cin >> inFileName;

    inStream.open(inFileName);

    if (inStream.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }

    int first, second, third;

    // Read the first 3 numbers from the file
    inStream >> first >> second >> third;

    // Write the sum of the first 3 numbers to the screen
    cout << "The sum of the first 3\n"
         << "numbers in " << inFileName << "\n"
         << "is " << (first + second + third) << endl;

    inStream.close();

    return 0;
}