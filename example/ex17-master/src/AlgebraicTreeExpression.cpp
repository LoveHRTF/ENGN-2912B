#include <stdlib.h>
#include <string.h>
#include "AlgebraicTreeExpression.hpp"

AlgebraicTreeExpression::~AlgebraicTreeExpression() {
  if(_root!=(AlgebraicTreeNode*)0) delete _root;
}

AlgebraicTreeExpression::AlgebraicTreeExpression():
  _root((AlgebraicTreeNode*)0),
  _parsedLength(0),
  _parsingError(false) {
}

bool AlgebraicTreeExpression::isEmpty() const {
  return (_root==(AlgebraicTreeNode*)0);
}

double AlgebraicTreeExpression::evaluate() const {
  return (isEmpty())?0.0:_root->evaluate();
}

char* AlgebraicTreeExpression::toString() const {
  char* str = (char*)0;
  if(isEmpty()==false) {
    unsigned length = _root->toStringLength()+1;
    str = new char[length];
    memset(str,'\0',length*sizeof(char));
    _root->toString(*str); // ==length
  }
  return str;
}

void AlgebraicTreeExpression::setRoot(AlgebraicTreeNode* root) {
  _root = root;
}

unsigned AlgebraicTreeExpression::getParsedLength() const {
  return _parsedLength;
}

bool AlgebraicTreeExpression:: getParsingError() const {
  return _parsingError;
}

AlgebraicTreeExpression::AlgebraicTreeExpression(const char* expression):
  _root((AlgebraicTreeNode*)0),
  _parsedLength(0),
  _parsingError(false) {
  unsigned length = strlen(expression);
  _parsedLength = _parse(expression,(AlgebraicTreeNode**)0);
  if(length>_parsedLength) _parsingError = true;
  if(_parsingError==false) _parse(expression,&_root);
}

unsigned AlgebraicTreeExpression::_parse
(const char* expression, AlgebraicTreeNode** nodePtr) {
  unsigned length = 0;
  char*    ptr = (char*)expression;
  bool     onlyCheckSyntax = (nodePtr==(AlgebraicTreeNode**)0);

  if(onlyCheckSyntax==true) {
    // just verify the expression syntax

    if(*ptr == '(') { // operator node

      ptr++;
      unsigned lengthLeft = _parse(ptr,(AlgebraicTreeNode**)0);
      ptr += lengthLeft;
      if(_parsingError==false) {
        if(*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/') {
          ptr++;
          unsigned lengthRight = _parse(ptr,(AlgebraicTreeNode**)0);
          ptr += lengthRight;
          if(_parsingError==false) {
            if(*ptr == ')')
              ptr++;
            else
              _parsingError = true;
          }
        } else {
          _parsingError = true;
        }
      }

      length = ptr-expression;

    } else /* if(*ptr != '(') */ { // number node

      char * ptrEnd = ptr;
      strtod(ptr,&ptrEnd);
      length = ptrEnd - ptr;
      _parsingError = (length==0);

    }

  } else /* if(onlyCheckSyntax==false) */ if(_parsingError==false) {

    // we can assume that the expression syntax has already been
    // verified; construct the tree without checking for errors

    if(*ptr == '(') { // operator node
      ptr++;

      AlgebraicTreeOperation* node = new AlgebraicTreeOperation();
      *nodePtr = node;

      ptr += _parse(ptr,node->getChildLeftPtr());

      AlgebraicTreeOperationType type =
        (*ptr == '+')?ADD:
        (*ptr == '-')?SUBTRACT:
        (*ptr == '*')?MULTIPLY:
        (*ptr == '/')?DIVIDE:
        ZERO; // ZERO should never happen
      ptr++;
      node->setType(type);

      ptr += _parse(ptr,node->getChildRightPtr());

      ptr++; // (*ptr == ')'

      length = ptr-expression;

    } else /* if(*ptr != '(') */ { // number node

      AlgebraicTreeNumber* node = new AlgebraicTreeNumber();
      *nodePtr = node;

      char* ptrEnd = ptr;
      double value = strtod(ptr,&ptrEnd);
      node->setValue(value);
      length = ptrEnd - ptr;

    }
  }

  return length;
}

