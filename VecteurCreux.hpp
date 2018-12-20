#ifndef _VECTEURCREUX_H_
#define _VECTEURCREUX_H_

#include "Vecteur.hpp"
#include "BinarySearchTree.hpp"
#include <iterator>
#include <cstddef>

template <typename V> class VecteurCreux : public Vecteur<V> , protected BinarySearchTree<unsigned int, V> {

private:

  std::size_t size;

  void setSearch (std::ptrdiff_t,V,Node<unsigned int,V>*);

public:

  friend int main();

  VecteurCreux (std::size_t);

  VecteurCreux (V[],std::size_t); // TODO

  VecteurCreux (VecteurCreux<V>&);

  virtual ~VecteurCreux ();

  VecteurCreux<V>& operator= (const VecteurCreux<V>&);

  virtual std::size_t getSize () const override;

  virtual V get (std::ptrdiff_t) override;

  virtual void set (std::ptrdiff_t,V) override;

};

template <typename V>
VecteurCreux<V>::VecteurCreux (std::size_t x) : Vecteur<V> (), BinarySearchTree<unsigned int,V> (), size(x) {}

template <typename V>
VecteurCreux<V>::VecteurCreux (V a[], std::size_t x) : Vecteur<V> (), BinarySearchTree<unsigned int,V> (), size(x) {}

template <typename V>
VecteurCreux<V>::VecteurCreux (VecteurCreux<V>& other) : Vecteur<V> (), BinarySearchTree<unsigned int,V> (other), size(other.size) {}

template <typename V>
VecteurCreux<V>::~VecteurCreux () {}

template <typename V>
VecteurCreux<V>& VecteurCreux<V>::operator= (const VecteurCreux<V>& other)
{
  return this;
}


template <typename V>
std::size_t VecteurCreux<V>::getSize () const {return this->size;}

template <typename V>
V VecteurCreux<V>::get (std::ptrdiff_t k)
{
  if (std::size_t(k) >= this->size)
    throw std::out_of_range("Vecteur : Index out of range");

  else
  {
    if (Node <unsigned int,V> *n = this->Search(unsigned(k)))
      return n->getValue();

    else
      return V(false);
  }
}

template <typename V>
void VecteurCreux<V>::set (std::ptrdiff_t k, V v)
{
  if (std::size_t(k) >= this->size)
    throw std::out_of_range("Vecteur : Index out of range");

  else
  {
    if (v!=V(false))
    {
        if (this->root == nullptr)
          this->root = new Node<unsigned int, V> (unsigned(k),v);

        else
          this->setSearch(k,v,this->root);
    }
  }
}

template <typename V>
void VecteurCreux<V>::setSearch (std::ptrdiff_t k, V v, Node<unsigned int, V>* n)
{
  if (unsigned(k) == n->getKey())
  {
    n->setValue(v);
  }

  else if (k < n->getKey())
  {
    if (n->getLeft())
      setSearch(k,v,n->getLeft());

    else
    {
      Node<unsigned int, V> *temp = new Node<unsigned int, V> (unsigned(k),v);
      temp->setParent(n);
      n->setLeft(temp);
    }
  }

  else
  {
    if (n->getRight())
      setSearch(k,v,n->getRight());

    else
    {
      Node<unsigned int, V> *temp = new Node<unsigned int, V> (unsigned(k),v);
      temp->setParent(n);
      n->setRight(temp);
    }
  }
}

#endif
