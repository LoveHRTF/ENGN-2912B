#include <iostream>
#include <vector>

#define DEBUG

#include "dnaFindPattern.h"

using namespace std;

// main function
int main(int argc, char* argv[]) {

	// default parameters
	string pname = "../data";
	string pattern = "(GAAA).*";

	switch (argc) {
		case 3:
			pattern = argv[2];
		case 2:
			pname = argv[1];
		case 1:
			break;
		default:
			cout << "Invalid number of parameters entered" << endl;
			return 1;
	}

	vector<dnaPattern> patt = dnaFindPatterns(pname,pattern);

	return 0;
}
