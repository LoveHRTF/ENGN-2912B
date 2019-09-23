#pragma once
#include <string>
#include <vector>
#include <utility>

//fill_vec: fill vector with wgn
void fill_vec(std::vector<double> &vd, int const& seed);

//convert_to_fixed: convert vector of floating-point format to fixed-point format
std::pair<double, double> convert_to_fixed(std::vector<double> const& vd, std::vector<int32_t>& vi, unsigned const& nBits);

//convert_to_float: convert fixed-point format back to floating-point format
void convert_to_float(std::vector<int32_t> const& vi, std::vector<double>& vd, unsigned const& nBits, std::pair<double, double> const& minmax);

//save_vec: save a fixed-point vector to a file
void save_vec(std::vector<int32_t> const& vi, std::string const& filename);
