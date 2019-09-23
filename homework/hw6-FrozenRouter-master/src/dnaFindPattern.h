#ifndef __DNAFINDPATTERN_H
#define __DNAFINDPATTERN_H
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;
boost::system::error_code ec;
// stores
// string 	-> the matched regular expression,
// unsigned -> the line number where the expression is matched (use indexing starting from 1 NOT 0),
// unsigned -> the starting character position where the expression is matched (use indexing starting from 1 NOT 0),
typedef std::tuple<std::string, unsigned, unsigned> dnaPatternContainer;

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
/*
 * dnaPattern:  searches for patterns within a data file containing ASCII strings of DNA sequences											
 */
class dnaPattern {
public:
    /************************************************** Con/Destructors *************************************************************/
	dnaPattern() {												// default constructor
																// Do Nothing
	}

	dnaPattern(fs::path fname) {								// alternate constructor to set the file name
		filename_ = fname;
	}

	dnaPattern(fs::path fname, std::regex patt) { 				// alternate constructor to set the file name and regex string, update the isPatternSet_ flag
		filename_ = fname;
		regexPattern_ = patt;
		isPatternSet_ = true;
	}
	/************************************************** Set Functions *************************************************************/
	void setFilename(std::string fname) {						// clear the searchResults_ vector and update the file name string
	    filename_ = fname;
		searchResults_.clear();									// Clean Vector
	}

	void setPattern(std::string patt) {                         // clear the searchResults_ vector, update the regex string and the isPatternSet_ flag
		regexPattern_ = patt;
		isPatternSet_ = true;
		searchResults_.clear();									// Clean Vector
	}
	/************************************************** Function Blocks *************************************************************/
	void search(); 												// execute regex search for the specified pattern

	dnaPatternContainer &operator[](unsigned k) { 				// a random access operator to the searchResults_ vector 
		dnaPatternContainer dnaContainer = searchResults_.at(k);
		return dnaContainer;
	}

	std::vector<dnaPatternContainer> getSearchResults() { 		// Save Search Result in Container
		return searchResults_;
	}
	/************************************************** Data Members *************************************************************/
private:
	fs::path filename_ = "";									// the file to be processed
	std::regex regexPattern_;									// a regular expression pattern that is specified by the user
	std::vector<dnaPatternContainer> searchResults_;			// a vector pointing to locations in the file where the pattern exists (use indexing starting from 1 NOT 0)
	bool isPatternSet_ = false;									// a boolean variable to check whether a valid regex pattern is set
};
	/************************************************** Class Ends *************************************************************/

void dnaPattern::search() { 									// Actual Search Function Here, use library<regex>

	cout << "Searching in file " << filename_ << endl;			
	std::ifstream dnaData(filename_.c_str()); 					// Open file as c style string
	std::string dnaDataLine; 									// Define string for line data

	if (dnaData){ 														// When data exists in this file
	unsigned linePosition = 1;
	getline(dnaData,dnaDataLine);  								// Get Data from single line
		while(!dnaData.eof()){ 											// When file was not terminated
			

			//getchar();
			//cout << "Line Data is: " << dnaDataLine << endl; 

			std::smatch result;											// Define Matching result
			string::const_iterator iterStart = dnaDataLine.begin(); 	// Define Iteration start point
			string::const_iterator iterEnd = dnaDataLine.end();  		// Define Interation end point
			
			while (regex_search(iterStart, iterEnd, result, regexPattern_)){
   				iterStart = result[0].second;
				unsigned MatchPosition = result.position(0) + 1;
				
				//cout << "Result is: " << result[0] << endl;cout << "Matched at: " << MatchPosition << endl;cout << "Line : " << linePosition << endl;

				auto thisResult = std::make_tuple (result[0],linePosition, MatchPosition); 	// Put results into continer
				searchResults_.push_back(thisResult); 										// Put result continer into continer vector
			}
			getline(dnaData,dnaDataLine);  								// Get Data from single line
			linePosition ++; 																// Increate line count
		}
	}
	dnaData.close();
}
	/************************************************** Wrapper Here *************************************************************/
/*
 * dnaFindPattern:  rapper function to dnaPattern class that accepts std::strings
 *
 * Input:
 *		strPath			// an absolute/relative path to a directory or a specific file
 *		strPattern		// a regular expression string
 *
 * Output:
 * 		vector<dnaPattern> - a vector of dnaPattern objects (one per file searched)
 *
 * Note:
 * Only return an object for a file that was successfully searched.
 * Even if the search could not find the regular expression contained in the file an object needs to be returned.
 */

std::vector<dnaPattern> dnaFindPatterns(std::string strPath, std::string strPattern){
	std::vector<dnaPattern> dnaObjVector(0);

	try { 
		std::regex re(strPattern); 															// Check if input regular expression is currect

		string targetPath = strPath;  														// Convert path to string
		boost::filesystem::path myPath(targetPath);  										// Setup Path
		boost::filesystem::directory_iterator endIter; 										// Setup the iterator:end

        if(is_directory(myPath)){

		for (boost::filesystem::directory_iterator iter(myPath); iter != endIter; iter++) {	// Iterate all files			 
			dnaPattern Obj; 														// Create the search object
			Obj.setFilename(iter->path().string()); 								// Set the file to be searched
			Obj.setPattern(strPattern); 											// Set the pattern to be searched
			Obj.search();               											// Search for pattern
			dnaObjVector.push_back(Obj); 											// Pushback the entire object
		}

		} else {
			dnaPattern Obj; 														// Create the search object
			Obj.setFilename(strPath); 												// Set the file to be searched
			Obj.setPattern(strPattern); 											// Set the pattern to be searched
			Obj.search();               											// Search for pattern
			dnaObjVector.push_back(Obj); 											// Pushback the entire object
		}

	}
	catch (const std::regex_error& err) {
		cout << err.what() << '\n' << " Re-enter Valid Regular Expression String" << endl;
	}


	return dnaObjVector;
}

#endif // __DNAFINDPATTERN_H
