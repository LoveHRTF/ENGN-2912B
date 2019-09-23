#ifndef _AlgebraicTreeOperation_hpp_
#define _AlgebraicTreeOperation_hpp_

#include "AlgebraicTreeNode.hpp"

enum AlgebraicTreeOperationType {
  ZERO,ADD,SUBTRACT,MULTIPLY,DIVIDE
};

class AlgebraicTreeOperation : public AlgebraicTreeNode {

public:

  virtual ~AlgebraicTreeOperation();

  AlgebraicTreeOperation(AlgebraicTreeOperationType type=ZERO);

  virtual bool isNumber() const;
  virtual bool isOperation() const;

  virtual double     evaluate() const;
  virtual unsigned   toStringLength() const;
  virtual unsigned   toString(char& str) const;

  void setType(AlgebraicTreeOperationType type);
  void setChildLeft(AlgebraicTreeNode* childLeft);
  void setChildRight(AlgebraicTreeNode* childRight);

  AlgebraicTreeNode* getChildLeft();
  AlgebraicTreeNode* getChildRight();

  AlgebraicTreeNode** getChildLeftPtr();
  AlgebraicTreeNode** getChildRightPtr();

private:

  AlgebraicTreeOperationType _type;
  AlgebraicTreeNode*         _childLeft;
  AlgebraicTreeNode*         _childRight;

};

#endif // _AlgebraicTreeOperation_h_
