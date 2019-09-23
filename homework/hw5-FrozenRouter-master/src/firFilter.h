#pragma once
#include <vector>

//fill vector with wgn
void fill_vec(std::vector<double> &vd, int const& seed);

class firFilter
{
public:
  firFilter();
  firFilter(std::vector<double> const& referenceFilter);

  void SetCoef(std::vector<double> const& referenceFilter);
  std::vector<double> GetCoef();
  std::vector<double> filter(std::vector<double> const& input);

private:
  std::vector<double> h;
};
