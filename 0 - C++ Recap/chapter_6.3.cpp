// Chapter 6: I/O Streams
// Chapter 6.3: Character I/O

#include <iostream>
#include <fstream>
#include <cstdlib> // For the exit function
#include <iomanip> // For the Manipulators (setw, setprecision, etc.)
#include <cctype>  // For the toupper() and tolower() functions

using namespace std;

int main()
{
    // Using the get() function (input stream only)
    char c1, c2, c3;
    cin.get(c1); // also reads the newline character '\n'
    cin.get(c2);
    cin.get(c3);

    // Using the get() function to determine the end of a line
    cout << "Enter a line of input and I will echo it:\n";
    char symbol;
    do
    {
        cin.get(symbol);
        cout << symbol;
    } while (symbol != '\n');
    cout << "That's all for this demonstration.";

    // Using the put() function (output stream only)
    cout.put('H');

    // Using the putback() function to return a character to the input stream (input stream only)
    char next;
    ifstream fin;
    ofstream fout;
    fin.open("infile.dat");
    fout.open("outfile.dat");

    fin.get(next);
    while (next != ' ')
    {
        fout.put(next);
        fin.get(next);
    }
    fin.putback(next);

    // Function to use get() that inputs an istream object and ignores newline characters
    void getNoNewline(istream & inStream); // istream is the base class for all input streams (cin, ifstream, etc.)

    // Function to use put() that outputs an ostream object and converts newline characters to spaces
    void putNoNewline(char c, ostream &outStream); // ostream is the base class for all output streams (cout, ofstream, etc.)

    // Default Arguments to Functions
    void NewLine(istream &inStream = cin); // cout is the default argument

    // The eof() function
    // eof() is a member function of the istream class that returns true if the end of the file has been reached
    // Example 1:
    if (!fin.eof())
        cout << "Not done yet.";
    else
        cout << "End of the file.";

    return 0;

    // Example 2:
    fin.get(next);
    while (!fin.eof()) // eof() will not be true until it has tried to read past the end of the file
    {
        cout << next;
        fin.get(next);
    }

    // toupper(), tolower(), isspace(), isupper(), islower(), isalpha(), isdigit() functions
    char u = toupper('a');        // u = 'A'
    cout << toupper('a') << endl; // this will not output 'A' because toupper returns an int

    cout << static_cast<char>(toupper('a')) << endl; // this will output 'A' because we convert the int to a char

    char l = tolower('A');        // l = 'a'
    cout << tolower('A') << endl; // this will not output 'a' because tolower returns an int

    cout << isspace(' ') << endl; // true

    cout << isupper('A') << endl; // true

    cout << islower('a') << endl; // true

    cout << isalpha('a') << endl; // true

    cout << isdigit('1') << endl; // true
}

void getNoNewline(istream &inStream)
{
    char symbol;
    do
    {
        inStream.get(symbol);
    } while (symbol != '\n');
}

void putNoNewline(char c, ostream &outStream)
{
    if (c == '\n')
        outStream.put(' ');
    else
        outStream.put(c);
}