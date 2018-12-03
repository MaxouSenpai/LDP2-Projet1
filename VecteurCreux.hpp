#ifndef _VECTEURCREUX_H_
#define _VECTEURCREUX_H_

#include "Vecteur.hpp"
#include "BinarySearchTree.hpp"

template <typename T> class VecteurCreux : public Vecteur<T> , protected BinarySearchTree<T> {

private:

  unsigned int const size;

public:

  friend int main(); // TODO Change

  VecteurCreux (unsigned int x) : size(x) {};

  VecteurCreux (T arr[], unsigned int x) : size(x) {  };

  virtual ~VecteurCreux () {};

  virtual T& operator[](unsigned int i) override {
    if ((i > -size) || (i < size)){
      return getNode(i)->getData();
    }
    throw std::out_of_range("Vecteur : Index out of range");
  }
  using BinarySearchTree<T>::operator=;
  virtual VecteurCreux<T>& operator=(const VecteurCreux<T>& other) { //TODO Maybe Remove
    if (size == other.getSize()){
      BinarySearchTree<T>::operator=(other);
      return *this;}
    else{throw;}
  }

  virtual unsigned int getSize() const override {return size;}

  virtual T& get(unsigned int) override {return this->getRoot()->getData();} //TODO

  virtual void set(T,unsigned int) override {};

  virtual Node<T>* getNode(unsigned int i) {

    if (this->root == nullptr){
      Node<T>* temp = new Node<T> (i);
      this->root = temp;
      return temp;
    }
    else{
      Node<T>* n = this->root;
      bool found = false;

      while (!found){
        if (i == n->getKey())
        {
          found = true;
        }
        else if (i < n->getKey()){
          if (n->getLeft() != nullptr){
            n = n->getLeft();
          }
          else{
            Node<T>* temp = new Node<T> (i);
            n->setLeft(temp);
            n = temp;
          }
        }
        else{
          if (n->getRight() != nullptr){
            n = n->getRight();
          }
          else{
            Node<T>* temp = new Node<T> (i);
            n->setRight(temp);
            n = temp;
        }
      }
    }
    return n;
  }
  return new Node<T> ();
  }

};

#endif
