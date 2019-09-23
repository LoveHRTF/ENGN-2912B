#include <iostream>
#include <string>
#include "analyzeTextFile.h"

using namespace std;

int main(int argc, char *argv[])
{

    //Question 1: Analyze a text file and output the total number of lines as well as the total number of displayable characters including whitespace.
    string fileName;
    unsigned int lineCount = 0;
    unsigned int characterCount = 0;

    // if filename entered through the command line
    if (argc > 1)
    {
        fileName = argv[1];
    }
    // if not, ask for filename
    else
    {
      cout << "Enter a file name to analyze: ";
      cin >> fileName;

      //fileName = "../sampleTextFile.txt";
    }


    analyzeTextFile(fileName, lineCount, characterCount);
    cout << lineCount << " lines" << endl;
    cout << characterCount << " characters" << endl;

    return 0;
}
