// DO NOT MODIFY

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cassert>
#include <utility>
#include "RNG.h"

using namespace std;

// print vector contents to stdout stream
template<typename T = double>
void print_vec(vector<T> const& data)
{
    for (auto x_k : data)
        std::cout << x_k << std::endl;
    std::cout << std::endl;
}

// Read in 'filename' as binary 32-bit integer values
void load_vec(string const& filename, vector<int32_t>& vec)
{
    // open file via ifstream
    ifstream inputFile(filename, ios::in | ios::binary);

    // verify file is open and read 32-bit integers until eof reached
    assert(inputFile.is_open());
    int32_t value;              // placeholder for each 32-bit integer value
    bool readFlag = true;
    while (readFlag)
    {
        inputFile.read(reinterpret_cast<char *>(&value), sizeof(value));  // read 32-bits at a time
        if (inputFile.eof())
        {
            readFlag = false;
            break;          // stop when eof reached
        }
        vec.push_back(value);
    }

    // close file
    inputFile.close();
}

int main(int argc, char* argv[]) {

    // define default input variables
    int seed = 100;
    int nSamples = 20;
    unsigned int nBits = 12;
    string fileName = "testfile.dat";
    cout << scientific;
    cout.precision(8);

    // generate vector with awgn
    vector<double> vd(nSamples);
    fill_vec(vd, seed);

    // send vector<double> contents to stdout
    print_vec(vd);

    // truncate and save to new vector (and store min/max values)
    vector<int32_t> vi;
    pair<double, double> minmax;
    minmax = convert_to_fixed(vd, vi, nBits);

    // send vector<int32_t> contents to stdout
    print_vec(vi);

    // save fixed-point truncated data to file
    save_vec(vi, fileName);

    // read data from file;
    vector<int32_t> vi2;
    load_vec(fileName, vi2);

    // send vector<int32_t> contents to stdout
    print_vec(vi2);

    // convert back to double in range (min,max)
    vector<double> vd2;
    convert_to_float(vi2, vd2, nBits, minmax);

    // send vector<double> contents to stdout
    print_vec(vd2);

    return 0;
}
