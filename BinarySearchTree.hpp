#ifndef _BINARYSEARCHTREE_H_
#define _BINARYSEARCHTREE_H_

#include "Node.hpp"
#include <iostream>

template <typename K,typename V> class BinarySearchTree {

protected:

  Node<K,V>* root;

public:

  BinarySearchTree ();

  BinarySearchTree (const BinarySearchTree<K,V>&);

  virtual ~BinarySearchTree ();

  BinarySearchTree<K,V>& operator= (const BinarySearchTree<K,V>&);

  virtual Node<K,V>* getRoot () const;

  virtual void setRoot (Node<K,V>*);

  virtual void Insert (Node<K,V>*);

  virtual Node<K,V>* Search (K);

  virtual Node<K,V>* Minimum (Node<K,V>*);

  virtual Node<K,V>* Maximum (Node<K,V>*);

  virtual Node<K,V>* Successor(Node<K,V>*);

  class iterator {

    BinarySearchTree<K,V>* bst;

    Node<K,V>* current;

public:

    iterator (BinarySearchTree<K,V>*, Node<K,V>*);

    iterator ();

    iterator& operator++();

    bool operator != (const BinarySearchTree<K,V>::iterator& other);

    K getKey();

    V getValue();

  };

  virtual iterator begin ();

  virtual iterator end ();

};

template <typename K,typename V>
BinarySearchTree<K,V>::BinarySearchTree () : root(nullptr) {}

template <typename K,typename V>
BinarySearchTree<K,V>::BinarySearchTree (const BinarySearchTree<K,V>& other) : root(nullptr)
{
  if (other.root != nullptr)
    this->root = new Node<K,V> (*other.root);
}

template <typename K,typename V>
BinarySearchTree<K,V>::~BinarySearchTree () {delete this->root;}

template <typename K,typename V>
BinarySearchTree<K,V>& BinarySearchTree<K,V>::operator= (const BinarySearchTree<K,V>& other)
{
  if (this->root != nullptr)
    delete this->root;

  if (other.root != nullptr)
    this->root = new Node<K,V> (*other.root);

  else
    this->root = nullptr;

  return *this;
}

template <typename K,typename V>
Node<K,V>* BinarySearchTree<K,V>::getRoot () const {return this->root;}

template <typename K,typename V>
void BinarySearchTree<K,V>::setRoot (Node<K,V>* r) {this->root = r;}

template <typename K,typename V>
Node<K,V>* BinarySearchTree<K,V>::Search (K key)
{
  Node<K,V> *current = this->root;
  while (current != nullptr) {
    if (key == current->getKey()) {return current;}
    else if (key < current->getKey()){current = current->getLeft();}
    else {current = current->getRight();}
  }
  return current;
}

template <typename K,typename V>
void BinarySearchTree<K,V>::Insert (Node<K,V>* to_add)
{
  Node<K,V> *y = nullptr, *x = this->root;
  while (x != nullptr)
  {
    y = x;

    if (*to_add < *x)
      x = x->getLeft();

    else
      x = x->getRight();
  }

  to_add->setParent(y);

  if (y == nullptr)
    this->root = to_add;

  else if (*to_add < *y)
    y->setLeft(to_add);

  else
    y->setRight(to_add);
}

template <typename K,typename V>
Node<K,V>* BinarySearchTree<K,V>::Minimum (Node<K,V>* n)
{
  if (Node<K,V>* min = n)
  {
    while (min->getLeft() != nullptr)
      min = min->getLeft();

    return min;
  }
  else
    return nullptr;
}

template <typename K,typename V>
Node<K,V>* BinarySearchTree<K,V>::Maximum (Node<K,V>* n)
{
  if (Node<K,V>* max = n)
  {
    while (max->getRight() != nullptr)
      max = max->getRight();

    return max;
  }
  else
    return nullptr;
}

template <typename K,typename V>
Node<K,V>* BinarySearchTree<K,V>::Successor (Node<K,V>* n)
{
  if (n->getRight()!= nullptr)
    return Minimum(n->getRight());

  else
  {
    Node<K,V> *y = n->getParent();
    while (y!=nullptr && n == y->getRight())
    {
        n = y;
        y = n->getParent();
    }
    return y;
  }
}

template <typename K,typename V>
typename BinarySearchTree<K,V>::iterator BinarySearchTree<K,V>::begin () {return BinarySearchTree::iterator(this,this->Minimum(root));}

template <typename K,typename V>
typename BinarySearchTree<K,V>::iterator BinarySearchTree<K,V>::end () {return BinarySearchTree::iterator(this,nullptr);}

template <typename K,typename V>
BinarySearchTree<K,V>::iterator::iterator (BinarySearchTree<K,V>* t, Node<K,V>* n) : bst(t), current(n) {}

template <typename K,typename V>
BinarySearchTree<K,V>::iterator::iterator () : bst(nullptr), current(nullptr) {}

template <typename K,typename V>
typename BinarySearchTree<K,V>::iterator& BinarySearchTree<K,V>::iterator::operator++()
{
  current = bst->Successor(current);
  return *this;
}

template <typename K,typename V>
bool BinarySearchTree<K,V>::iterator::operator!= (const iterator& other)
{
  return this->current != other.current;
}

template <typename K,typename V>
K  BinarySearchTree<K,V>::iterator::getKey() {return current->getKey();}

template <typename K,typename V>
V  BinarySearchTree<K,V>::iterator::getValue() {return current->getValue();}

#endif
