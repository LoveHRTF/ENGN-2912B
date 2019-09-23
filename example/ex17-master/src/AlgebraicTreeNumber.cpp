#include <stdio.h>
#include "AlgebraicTreeNumber.hpp"

// class AlgebraicTreeNumber : public AlgebraicTreeNode {

AlgebraicTreeNumber::~AlgebraicTreeNumber() {
}

AlgebraicTreeNumber::AlgebraicTreeNumber(const double value):
  _value(value) {
  setInvalid(false);
}

bool AlgebraicTreeNumber::isNumber() const {
  return true;
}

bool AlgebraicTreeNumber::isOperation() const {
  return false;
}

double AlgebraicTreeNumber::evaluate() const {
  return _value;
}

unsigned AlgebraicTreeNumber::toStringLength() const {
  static char buff[BUFF_LENGTH];
  return sprintf(buff,NUMBER_FORMAT,_value);
}

unsigned AlgebraicTreeNumber::toString(char& str) const {
  return sprintf(&str,NUMBER_FORMAT,_value);
}

void AlgebraicTreeNumber::setValue(double value) {
  _value = value;
}

