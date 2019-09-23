#ifndef _AlgebraicTreeExpression_hpp_
#define _AlgebraicTreeExpression_hpp_

#include "AlgebraicTreeNode.hpp"
#include "AlgebraicTreeNumber.hpp"
#include "AlgebraicTreeOperation.hpp"

class AlgebraicTreeExpression {

public:

  ~AlgebraicTreeExpression();

  AlgebraicTreeExpression();
  AlgebraicTreeExpression(const char* expression);

  bool     isEmpty() const;
  double   evaluate() const;
  char*    toString() const;

  void     setRoot(AlgebraicTreeNode* root);
  unsigned getParsedLength() const;
  bool     getParsingError() const;

protected:

  AlgebraicTreeNode* _root;

  unsigned _parsedLength;
  bool     _parsingError;
  unsigned _parse(const char* expression, AlgebraicTreeNode** parentPtr);

};

#endif // _AlgebraicTreeExpression_h_
