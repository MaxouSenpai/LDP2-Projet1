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

  virtual Node<T>* Minimum ();

  virtual Node<T>* Successor(Node<T>*);

  virtual void inOrder (Node<T>*);

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
Node<T>* BinarySearchTree<T>::Minimum() {
  if (Node<T>* min = getRoot()) {
    while (min->getLeft() != nullptr) {
      min = min->getLeft();
    }
    return min;
  }
  else {return nullptr;}
}

template <typename T>
Node<T>* BinarySearchTree<T>::Successor(Node<T>*) {return getRoot();}


#endif
