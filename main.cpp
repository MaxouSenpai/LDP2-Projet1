#include <iostream>

////////////////////////////////////////////////////////////////////////////////

template <typename T> class Vecteur {

protected:

  unsigned int size;

public:

  Vecteur (unsigned int x) : size(x) {};

  virtual ~Vecteur () {};

  virtual T& operator[](unsigned int)=0;

};

////////////////////////////////////////////////////////////////////////////////

template <typename T> class Node {

private:
  unsigned int key;
  T data;
  Node<T>* left;
  Node<T>* right;

public:

  Node (unsigned int i = 0, T t = false) : key(i), data(t), left(nullptr), right(nullptr) {}

  virtual ~Node () {}

  Node(const Node<T>&) : key(0), data(0), left(nullptr), right(nullptr) {}; //TODO

  Node& operator=(const Node<T>& other){ // TODO
    other.getKey();
    return *this;
  }

  bool operator< (const Node<T>& other) {return getKey() < other.getKey();}

  unsigned int getKey() const {return key;}

  void setKey(unsigned int i) {key = i;}

  T getData () const {return data;}

  void setData(T d) {data = d;}

  Node<T>* getLeft () const {return left;}

  void setLeft (Node<T>* n) {left = n;}

  Node<T>* getRight () const {return right;}

  void setRight (Node<T>* n) {right = n;}

};

////////////////////////////////////////////////////////////////////////////////

template <typename T> class BinaryTree {

protected:

  Node<T>* root;

public:

  BinaryTree () : root(nullptr) {}
  virtual ~BinaryTree () {}

  BinaryTree (const BinaryTree<T>& other) : root(nullptr) {
    (*this) = other;
  }

  BinaryTree& operator=(const BinaryTree<T>& other){
    if (other.getRoot() != nullptr){
      Node<T>* temp = new Node<T> ();
      (*temp) = (*other.getRoot());
      setRoot(*temp);
    }
    return *this;
  }

  Node<T>* getRoot () const {
    return root;
  }

  void setRoot (Node<T> r) {
    root = &r;
  }

  //void Insert(){}

  //void Delete(){}

  //Node<T>* Search(unsigned int x);

};

////////////////////////////////////////////////////////////////////////////////

template <typename T> class VecteurCreux : public Vecteur<T> , protected BinaryTree<T> {

private:

public:

  VecteurCreux (unsigned int x) : Vecteur<T>(x) {};

  virtual ~VecteurCreux () {};

  virtual T& operator[](unsigned int i) override {
    if ((0 <= i) && (i < this->size)){
      //T temp = getNode()->getData();
      T *temp = new T (getNode(i)->getData());
      return (*temp);
    }
    throw;
  }

  //using BinaryTree<T>::operator=;
  VecteurCreux<T>& operator=(const VecteurCreux<T>& other){
    BinaryTree<T>::operator=(other);
    this->size = other.size;
    return *this;
  }

  Node<T>* getNode(unsigned int i) const { //TODO

    if (this->root == nullptr){
      Node<T>* temp = new Node<T> ();
      return temp;
    }
    else{
      Node<T>* n = this->root;
      bool found = false;

      while (!found){
        if (i == n->getKey())
        {
          return n;
        }
        else if (i < n->getKey()){
          if (n->getLeft() != nullptr){
            n = n->getLeft();
          }
          else{
            Node<T>* temp = new Node<T> (i);
            n->setLeft(temp);
            return temp;
          }
        }
        else{
          if (n->getRight() != nullptr){
            n = n->getRight();
          }
          else{
            Node<T>* temp = new Node<T> (i);
            n->setRight(temp);
            return temp;
        }
      }

    }
  }
  return new Node<T> ();
  }
};

////////////////////////////////////////////////////////////////////////////////

int main(){
  VecteurCreux <int> a (5);
  BinaryTree <int> b;
  Node <int> temp (3,0);
  b.setRoot(temp);
  //std::cout << b.getRoot()->getKey() << std::endl;
  BinaryTree <int> c;
  c = b;
  //std::cout << c.getRoot()->getKey() << std::endl;
  Node <int> i (12,1);
  Node <int> j (2,1);

}
