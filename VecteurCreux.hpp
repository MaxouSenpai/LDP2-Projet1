#ifndef _VECTEURCREUX_H_
#define _VECTEURCREUX_H_

#include "Vecteur.hpp"
#include "BinarySearchTree.hpp"
#include <iterator>
#include <cstddef>

template <typename T> class VecteurCreux : public Vecteur<T> , protected BinarySearchTree<T> {

private:

  std::size_t size;

public:

  friend int main(); // TODO Change

  friend void ParcoursArbre(BinarySearchTree<T>& a);

  VecteurCreux (std::size_t);

  VecteurCreux (T[],std::size_t);

  virtual ~VecteurCreux ();

  virtual T& operator[](std::ptrdiff_t) override;

  virtual std::size_t getSize() const override;

  virtual T& get(std::ptrdiff_t) override; // TODO

  virtual void set(T,std::ptrdiff_t) override; // TODO

};

template <typename T>
VecteurCreux<T>::VecteurCreux (std::size_t x) : Vecteur<T> (), BinarySearchTree<T> (), size(x) {}

template <typename T>
VecteurCreux<T>::VecteurCreux (T a[], std::size_t x) : Vecteur<T> (), BinarySearchTree<T> (), size(x) {std::cout<<a[0]<<std::endl;}

template <typename T>
VecteurCreux<T>::~VecteurCreux () {}

template <typename T>
T& VecteurCreux<T>::operator[](std::ptrdiff_t i) {
  if (std::size_t(i) < this->size) {
    Node<T>* n = this->Search(unsigned(i));
    if (n != nullptr) {
      return n->getData();
    }
    else {
      Node<T>*newN = new Node<T> (unsigned(i));
      this->Insert(newN);
      return newN->getData();
    }
  }
  throw std::out_of_range("Vecteur : Index out of range");
}
//template <typename T> VecteurCreux<T>
template <typename T>
std::size_t VecteurCreux<T>::getSize() const {return this->size;}

template <typename T>
T& VecteurCreux<T>::get(std::ptrdiff_t) {return this->getRoot()->getData();}

template <typename T>
void VecteurCreux<T>::set(T d,std::ptrdiff_t i) {
  if (Node<T>* n = this->Search(unsigned(i))) {
    n->setData(d);
  }
  else {
    this->Insert(new Node<T>(unsigned(i),d));
  }
}

#endif
