#include "AlgebraicTreeOperation.hpp"

AlgebraicTreeOperation::~AlgebraicTreeOperation() {
  if( _childLeft != (AlgebraicTreeNode*)0) delete  _childLeft;
  if(_childRight != (AlgebraicTreeNode*)0) delete _childRight;
}

AlgebraicTreeOperation::AlgebraicTreeOperation(AlgebraicTreeOperationType type):
  _type(type),
  _childLeft((AlgebraicTreeNode*)0),
  _childRight((AlgebraicTreeNode*)0) {
}

bool AlgebraicTreeOperation::isNumber() const {
  return false;
}

bool AlgebraicTreeOperation::isOperation() const {
  return true;
}

double AlgebraicTreeOperation::evaluate() const {
  double value = 0.0f;
  if(_type!=ZERO) {
    double valueLeft  = _childLeft->evaluate();
    double valueRight = _childRight->evaluate();
    switch(_type) {
    case ADD:      value = valueLeft+valueRight; break;
    case SUBTRACT: value = valueLeft-valueRight; break;
    case MULTIPLY: value = valueLeft*valueRight; break;
    case DIVIDE:   value = valueLeft/valueRight; break;
    default:                                     break;
    }
  }
  return value;
}

unsigned AlgebraicTreeOperation::toStringLength() const {
  unsigned length = 0;
  if(_type!=ZERO) {
      length++; // '(';
    length += _childLeft->toStringLength();
      length++; // '+','-','*','/'
    length += _childRight->toStringLength();
      length++; // ')';
  }
  return length;
}

unsigned AlgebraicTreeOperation::toString(char& str) const {
  char* strPtr = &str;
  if(_type!=ZERO) {
    *strPtr++ = '(';
    strPtr += _childLeft->toString(*strPtr);
    *strPtr++ =
      (_type==ADD     )?'+':
      (_type==SUBTRACT)?'-':
      (_type==MULTIPLY)?'*':
      (_type==DIVIDE  )?'/':
      '?';
    strPtr += _childRight->toString(*strPtr);
    *strPtr++ = ')';
  }

  return strPtr-&str;
}

void AlgebraicTreeOperation::setType(AlgebraicTreeOperationType type) {
  _type = type;
}

void AlgebraicTreeOperation::setChildLeft(AlgebraicTreeNode* childLeft) {
  _childLeft = childLeft;
  if(_childLeft!=(AlgebraicTreeNode*)0)
    _childLeft->setParent(this);
}

void AlgebraicTreeOperation::setChildRight(AlgebraicTreeNode* childRight) {
  _childRight = childRight;
  if(_childRight!=(AlgebraicTreeNode*)0)
    _childRight->setParent(this);
}

AlgebraicTreeNode* AlgebraicTreeOperation::getChildLeft() {
  return _childLeft;
}

AlgebraicTreeNode* AlgebraicTreeOperation::getChildRight() {
  return _childRight;
}

AlgebraicTreeNode** AlgebraicTreeOperation::getChildLeftPtr() {
  return &_childLeft;
}

AlgebraicTreeNode** AlgebraicTreeOperation::getChildRightPtr() {
  return &_childRight;
}
