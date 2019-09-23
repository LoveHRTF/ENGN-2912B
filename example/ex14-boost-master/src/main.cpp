#include <iostream>
#include <vector>

// make sure the 'boost' library is loaded on your system!
#include <boost/filesystem.hpp>

// add only cout and endl to the global namespace
using std::cout;
using std::endl;

// create a namespace alias for boost::filesystem
namespace fs = boost::filesystem;

// main function
int main(int argc, char* argv[]) {

	// use the Boost filesystem library to print directory contents
	try {

		// accept user argument for path, otherwise use current working directory
		fs::path pname(".");
		if (argc > 1)
			pname = argv[1];

		// provide a directory listing of all files
		if (fs::exists(pname) && fs::is_directory(pname)) {
			for (fs::directory_entry& x : fs::directory_iterator(pname)) {
				cout << x.path() << endl;
			}
		}
		else {
			cout << "\"" << pname.string() << "\" is not a valid directory." << endl;
		}
	}
	catch (const fs::filesystem_error& ex) {
		cout << endl << "Caught you red handed!" << endl;
		cout << ex.what() << endl;
	}

	return 0;
}

