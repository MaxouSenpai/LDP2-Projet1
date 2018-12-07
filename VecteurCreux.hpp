#ifndef _VECTEURCREUX_H_
#define _VECTEURCREUX_H_

#include "Vecteur.hpp"
#include "BinarySearchTree.hpp"

template <typename T> class VecteurCreux : public Vecteur<T> , protected BinarySearchTree<T> {

public:

  friend int main(); // TODO Change

  VecteurCreux (unsigned int);

  VecteurCreux (T[], unsigned int);

  virtual ~VecteurCreux ();

  virtual T& operator[](unsigned int) override;

  virtual unsigned int getSize() const override;

  virtual T& get(unsigned int) override; // TODO

  virtual void set(T,unsigned int) override; // TODO

};

template <typename T>
VecteurCreux<T>::VecteurCreux (unsigned int x) : Vecteur<T> (x), BinarySearchTree<T> () {}

template <typename T>
VecteurCreux<T>::VecteurCreux (T arr[],unsigned int x) : Vecteur<T> (x), BinarySearchTree<T> () {}

template <typename T>
VecteurCreux<T>::~VecteurCreux () {}

template <typename T>
T& VecteurCreux<T>::operator[](unsigned int i) {
  if ((i > -this->size) || (i < this->size)) {
    Node<T>* n = this->Search(i);
    if (n != nullptr) {
      return n->getData();
    }
    else {
      Node<T>*newN = new Node<T> (i);
      this->Insert(newN);
      return newN->getData();
    }
  }
  throw std::out_of_range("Vecteur : Index out of range");
}
//template <typename T> VecteurCreux<T>
template <typename T>
unsigned int VecteurCreux<T>::getSize() const {return this->size;}

template <typename T>
T& VecteurCreux<T>::get(unsigned int) {return this->getRoot()->getData();}

template <typename T>
void VecteurCreux<T>::set(T,unsigned int){}

#endif
