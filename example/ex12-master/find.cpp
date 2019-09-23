#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //<- needed for find(.)

using namespace std;

int main(){
    vector<string> vs; //create a vector of strings

    vs.push_back("The");
    vs.push_back("cat");
    vs.push_back("in");
    vs.push_back("the");
    vs.push_back("hat");

    vector<string>::iterator vbegin = vs.begin(); // start of vs
    vector<string>::iterator vend = vs.end(); // just past end of vs

    for (vector<string>::iterator v = vbegin; v != vend; ++v){
        cout << *v << endl;
    }

    // the call to find
    vector<string>::iterator sit = find(vbegin, vend, "hat");

    // if the find failed then the value of sit will be vend
    if(sit!=vend)
        cout << "Found \"" << *sit << "\" at location " << (sit-vs.begin()) << endl;
    else
        cout << "Not found" << endl;

    return 0;
}
