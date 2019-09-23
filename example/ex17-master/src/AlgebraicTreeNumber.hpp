#ifndef _AlgebraicTreeNumber_hpp_
#define _AlgebraicTreeNumber_hpp_

#include "AlgebraicTreeNode.hpp"

class AlgebraicTreeNumber : public AlgebraicTreeNode {

public:

  virtual ~AlgebraicTreeNumber();

  AlgebraicTreeNumber(const double value=0.0);

  virtual bool isNumber() const;
  virtual bool isOperation() const;

  virtual double     evaluate() const;
  virtual unsigned   toStringLength() const;
  virtual unsigned   toString(char& str) const;

  void setValue(double value);

private:

  double _value;

};

#define BUFF_LENGTH 256
#define NUMBER_FORMAT "%.4f"

#endif // _AlgebraicTreeNumber_h_
