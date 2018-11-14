#ifndef TREE_H
#define TREE_H

#include <string>

class TreeNode {
 public:
  TreeNode()
      : value(std::string()),
        count(new int(1)),
        left(nullptr),
        right(nullptr) {}
  TreeNode(const TreeNode &orig)
      : value(orig.value),
        count(orig.count),
        left(orig.left),
        right(orig.right) {
    ++*count;
  }
  ~TreeNode() {
    if (--*count == 0) {
      delete count;
      count = nullptr;
      if (left) {
        delete left;
        left = nullptr;
      }
      if (right) {
        delete right;
        right = nullptr;
      }
    }
  }
  TreeNode &operator=(const TreeNode &rhs);

 private:
  std::string value;
  int *count;
  TreeNode *left;
  TreeNode *right;
};

TreeNode &TreeNode::operator=(const TreeNode &rhs) {
  ++*rhs.count;
  if (--*count == 0) {
    delete count;
    if (left) {
      delete left;
    }
    if (right) {
      delete right;
    }
  }
  value = rhs.value;
  count = rhs.count;
  left = rhs.left;
  right = rhs.right;
  return *this;
}

class BinStrTree {
 public:
  BinStrTree() : root(new TreeNode()) {}
  BinStrTree(const BinStrTree &orig) : root(new TreeNode(*orig.root)) {}
  ~BinStrTree() { delete root; }
  BinStrTree &operator=(const BinStrTree &rhs) {
    auto newp = new TreeNode(*rhs.root);
    delete root;
    root = newp;
    return *this;
  }

 private:
  TreeNode *root;
};

#endif
