#ifndef _AlgebraicTreeNode_hpp_
#define _AlgebraicTreeNode_hpp_

class AlgebraicTreeNode {

public:

  virtual ~AlgebraicTreeNode();

  AlgebraicTreeNode();

  bool isRoot() const;
  bool isInvalid() const;

  virtual bool isNumber() const;
  virtual bool isOperation() const;

  virtual double   evaluate() const =0;
  virtual unsigned toStringLength() const =0;
  virtual unsigned toString(char& str) const =0;

  void setInvalid(bool value);
  void setParent(AlgebraicTreeNode* parent);

protected:

  bool               _invalid;
  AlgebraicTreeNode* _parent;

};

#endif // _AlgebraicTreeNode_h_
