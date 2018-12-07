#ifndef _BINARYSEARCHTREE_H_
#define _BINARYSEARCHTREE_H_

#include "Node.hpp"
#include <iostream>

template <typename T> class BinarySearchTree {

protected:

  Node<T>* root;

public:

  BinarySearchTree ();

  BinarySearchTree (const BinarySearchTree<T>&);

  virtual ~BinarySearchTree ();

  BinarySearchTree<T>& operator= (const BinarySearchTree<T>&);

  virtual Node<T>* getRoot () const;

  virtual void setRoot (Node<T>*);

  virtual void Insert (Node<T>*);

  virtual Node<T>* Search (unsigned int);

  virtual Node<T>* Minimum (Node<T>*);

  virtual Node<T>* Maximum (Node<T>*);

  virtual Node<T>* Successor(Node<T>*);

  virtual void inOrder (Node<T>*);

  class iterator;

  iterator begin() {return BinarySearchTree::iterator(this,this->Minimum(root));}

  iterator end() {return BinarySearchTree::iterator(this,this->Maximum(root)->getRight());}

};

template <typename T>
BinarySearchTree<T>::BinarySearchTree () : root(nullptr) {}

template <typename T>
BinarySearchTree<T>::BinarySearchTree (const BinarySearchTree<T>& other) : root(nullptr) {
  if (other.getRoot() != nullptr) {
    setRoot(new Node<T> (*other.getRoot()));
  }
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree () {
  delete root;
}

template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator= (const BinarySearchTree<T>& other) {
  if (other.getRoot() != nullptr) {
    setRoot(new Node<T> (*other.getRoot()));
  }
  return *this;
}

template <typename T>
Node<T>* BinarySearchTree<T>::getRoot () const {
  return root;
}

template <typename T>
void BinarySearchTree<T>::setRoot (Node<T>* r) {
  root = r;
}

template <typename T>
Node<T>* BinarySearchTree<T>::Search(unsigned int key) {
  Node<T> *current = getRoot();
  while (current != nullptr) {
    if (key == current->getKey()) {return current;}
    else if (key < current->getKey()){current = current->getLeft();}
    else {current = current->getRight();}
  }
  return current;
}

template <typename T>
void BinarySearchTree<T>::Insert (Node<T>* to_add) {
  Node<T> *y = nullptr, *x = getRoot();
  while (x != nullptr) {
    y = x;
    if (*to_add < *x) {x = x->getLeft();}
    else {x = x->getRight();}
  }
  to_add->setParent(y);
  if (y == nullptr) {setRoot(to_add);}
  else if (*to_add < *y) {y->setLeft(to_add);}
  else {y->setRight(to_add);}
}

template <typename T>
void BinarySearchTree<T>::inOrder(Node<T>* n) {
  if (n!=nullptr){
    std::cout << "(" ;
    inOrder(n->getLeft());
    std::cout << n->getData();
    inOrder(n->getRight());
    std::cout << ")";
  }
}

template <typename T>
Node<T>* BinarySearchTree<T>::Minimum(Node<T>* n) {
  if (Node<T>* min = n) {
    while (min->getLeft() != nullptr) {
      min = min->getLeft();
    }
    return min;
  }
  else {return nullptr;}
}

template <typename T>
Node<T>* BinarySearchTree<T>::Maximum (Node<T>* n) {
  if (Node<T>* max = n) {
    while (max->getRight() != nullptr) {
      max = max->getRight();
    }
    return max;
  }
  else {return nullptr;}
}

template <typename T>
Node<T>* BinarySearchTree<T>::Successor (Node<T>* n) {
  if (n->getRight()){return Minimum(n->getRight());}
  else {
    Node<T> *y = n->getParent();
    while (y!=nullptr) {
      if (n == y->getRight()){
      n = y;
      y = n->getParent();
      }
      else {return y;}
    }
    return y;
  }
}

template <typename T>
class BinarySearchTree<T>::iterator {

  friend class BinarySearchTree<T>;
  friend int main();
  BinarySearchTree<T>* bst;

  Node<T>* current;

  iterator (BinarySearchTree<T>* t, Node<T>* n) : bst(t), current(n) {}

public:

  iterator () : bst(nullptr), current(nullptr) {}

  iterator& operator++() {
    current = bst->Successor(current);
    return *this;
  }
  friend bool operator != (const iterator& i1, const iterator& i2) {
    return i1.current != i2.current;
  }
};
/*
template <typename T>
BinarySearchTree::iterator BinarySearchTree<T>::begin() {return BinarySearchTree::iterator(this,this->get_min());}

template <typename T>
BinarySearchTree::iterator BinarySearchTree<T>::end() {return BinarySearchTree::iterator(this,this->Maximum(root)->getRightChild());}
*/


#endif
