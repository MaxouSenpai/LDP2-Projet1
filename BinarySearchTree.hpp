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

  //BinarySearchTree<T>& operator=(const BinarySearchTree<T>&){};

  virtual BinarySearchTree<T>& operator= (const BinarySearchTree<T>&);

  virtual Node<T>* getRoot () const;

  virtual void setRoot (Node<T>*);

  //void Insert(){}

  //void Delete(){}

  //Node<T>* Search(unsigned int x);

  virtual void inOrder(Node<T>*);

};

template <typename T> BinarySearchTree<T>::BinarySearchTree () : root(nullptr) {}

template <typename T> BinarySearchTree<T>::BinarySearchTree (const BinarySearchTree<T>& other) : root(nullptr) {if (other.getRoot() != nullptr) {setRoot(new Node<T> (*other.getRoot()));}}

template <typename T> BinarySearchTree<T>::~BinarySearchTree () {delete root;}

//BinarySearchTree<T>& operator=(const BinarySearchTree<T>&){};

template <typename T> BinarySearchTree<T>& BinarySearchTree<T>::operator= (const BinarySearchTree<T>& other) {
  if (other.getRoot() != nullptr) {setRoot(new Node<T> (*other.getRoot()));}
  return *this;
}

template <typename T> Node<T>* BinarySearchTree<T>::getRoot () const {
  return root;
}

template <typename T> void BinarySearchTree<T>::setRoot (Node<T>* r) {
  root = r;
}

//void Insert(){}

//void Delete(){}

//Node<T>* Search(unsigned int x);

template <typename T> void BinarySearchTree<T>::inOrder(Node<T>* n) {
  if (n!=nullptr){
    std::cout << "(" ;
    inOrder(n->getLeft());
    std::cout << n->getData();
    inOrder(n->getRight());
    std::cout << ")";
  }
}

#endif
