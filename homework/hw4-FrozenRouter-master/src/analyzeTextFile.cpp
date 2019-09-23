#include "analyzeTextFile.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

void analyzeTextFile(string const& fileName, unsigned int& lineCount, unsigned int& characterCount)
{
  // initialize variables
  lineCount = 0; characterCount = 0;

  int x = 0;
  // read file, if not exists cout a warning
  ifstream buffer(fileName);
  if (!buffer){
    cout << "Warning: File Not Exists" << endl;
  } else{

    char c;
    while (buffer.get(c)){

      if (c == '\n'){
        lineCount ++;
        characterCount ++;
      } else{
        characterCount ++;
        }

    }

  }
  // close file
  buffer.close();

}
