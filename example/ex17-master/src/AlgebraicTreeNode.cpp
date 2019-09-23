#include "AlgebraicTreeNode.hpp"

AlgebraicTreeNode::~AlgebraicTreeNode() {
}

AlgebraicTreeNode::AlgebraicTreeNode():
  _invalid(true),
  _parent((AlgebraicTreeNode*)0) {
}

bool AlgebraicTreeNode::isRoot() const {
  return (_parent==(AlgebraicTreeNode*)0);
}

bool AlgebraicTreeNode::isInvalid() const {
  return _invalid;
}

bool AlgebraicTreeNode::isNumber() const {
  return false;
}

bool AlgebraicTreeNode::isOperation() const {
  return false;
}

void AlgebraicTreeNode::setInvalid(bool value) {
  _invalid = value;
}

void AlgebraicTreeNode::setParent(AlgebraicTreeNode* parent) {
  _parent = parent;
}

