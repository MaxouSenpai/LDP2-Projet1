#include <iostream>
#include <string>
#include <vector>
// TODO delete all std::cout
////////////////////////////////////////////////////////////////////////////////

template <typename T> class Vecteur {

public:

  Vecteur () = default;

  Vecteur (const Vecteur&) = default;

  //Vecteur (Vecteur&&) = default;

  virtual ~Vecteur () = default;

  virtual T& operator[](unsigned int) = 0;

  virtual unsigned int getSize() const = 0;

  virtual T& get(unsigned int) = 0;

  virtual void set(T,unsigned int) = 0;

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

  Node(const Node<T>& other) : key(other.getKey()), data(other.getData()), left(nullptr), right(nullptr) {
    if (other.getLeft() != nullptr) {setLeft(new Node<T> (*other.getLeft()));}
    if (other.getRight() != nullptr) {setRight(new Node<T> (*other.getRight()));}
  };

  virtual ~Node () {
    if (getLeft() != nullptr) {delete getLeft();}
    if (getRight() != nullptr) {delete getRight();}
  }

  virtual Node& operator=(const Node<T>& other){
    setKey(other.getKey());
    setData(other.getData());
    if (other.getLeft() != nullptr) {setLeft(new Node<T> (*other.getLeft()));}
    else {setLeft(nullptr);}
    if (other.getRight() != nullptr) {setRight(new Node<T> (*other.getRight()));}
    else {setRight(nullptr);}
    return *this;
  }

  //bool operator< (const Node<T>& other) {return getKey() < other.getKey();}

  virtual unsigned int getKey() const {return key;}

  virtual void setKey(unsigned int i) {key = i;}

  virtual const T& getData () const {return data;}

  virtual T& getData () {return data;}

  virtual void setData(T d) {data = d;}

  virtual Node<T>* getLeft () const {return left;}

  virtual void setLeft (Node<T>* n) {
    //if (getLeft() != nullptr) {delete getLeft();}
    left = n;
  }

  virtual Node<T>* getRight () const {return right;}

  virtual void setRight (Node<T>* n) {
    //if (getRight() != nullptr) {delete getRight();}
    right = n;
  }

};

////////////////////////////////////////////////////////////////////////////////

template <typename T> class BinarySearchTree {

protected:

  Node<T>* root;

public:

  BinarySearchTree () : root(nullptr) {}

  BinarySearchTree (const BinarySearchTree<T>& other) : root(nullptr) {if (other.getRoot() != nullptr) {setRoot(new Node<T> (*other.getRoot()));}}

  virtual ~BinarySearchTree () {delete root;}

  //BinarySearchTree<T>& operator=(const BinarySearchTree<T>&){};

  virtual BinarySearchTree<T>& operator= (const BinarySearchTree<T>& other) {
    if (other.getRoot() != nullptr) {setRoot(new Node<T> (*other.getRoot()));}
    return *this;
  }

  virtual Node<T>* getRoot () const {
    return root;
  }

  virtual void setRoot (Node<T>* r) {
    root = r;
  }

  //void Insert(){}

  //void Delete(){}

  //Node<T>* Search(unsigned int x);

  virtual void inOrder(Node<T>* n) {
    if (n!=nullptr){
      std::cout << "(" ;
      inOrder(n->getLeft());
      std::cout << n->getData();
      inOrder(n->getRight());
      std::cout << ")";
    }
  }

};

////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////

int main(){

  //Vecteur <int>* r = new VecteurCreux <int> (7);
  //VecteurCreux <int> a = *static_cast<VecteurCreux<int>*>(r);
  VecteurCreux <int> a (10);
  a[2] = 3;
  a[3] = 42;
  a[2] = 6;

  a.inOrder(a.getRoot());
  std::cout << std::endl;

  for (unsigned int i = 0 ; i < a.getSize() ; i++){
    std::cout << "a[" << i << "] : " << a[i] << std::endl;
  }

  a.inOrder(a.getRoot());
  std::cout << std::endl;

  //bool b ();

  //static_cast<bool>(false);

  int b = false;

  std::cout << b << std::endl;

  int arr[] = {12,15,18,10};

  VecteurCreux<int> c (arr,4);

  //VecteurCreux <int> a (5);
  //BinarySearchTree <int> b;
  //Node <int> temp (3,0);
  //b.setRoot(temp);
  //b.setRoot(Node <int> (3,0));
  //std::cout << b.getRoot()->getKey() << std::endl;
  //BinarySearchTree <int> c;
  //c = b;
  //std::cout << c.getRoot()->getKey() << std::endl;
  //Node <int> i (12,1);
  //Node <int> j (i);

  //std::cout << i.getData() << " " << j.getData() << std::endl;

  //j.setData(3);

  //std::cout << i.getData() << " " << j.getData() << std::endl;

//Node<int> i (12,1);

//Node<int>* s = new Node<int> (16,4);

//std::cout << '1' << std::endl;

//i.setLeft(s);

//std::cout << '2' << std::endl;

//Node<int> j (i);
//Node<int> j = i;

//std::cout << i.getLeft()->getData() << " " << j.getLeft()->getData() << std::endl;

//j.getLeft()->setData(69);

//std::cout << i.getLeft()->getData() << " " << j.getLeft()->getData() << std::endl;

/*
  Node <std::string> p (12);
  Node <std::string> m (p);

  std::cout << p.getData() << " " << m.getData() << std::endl;

  m.setData("ho");

  std::cout << p.getData() << " " << m.getData() << std::endl;


  std::string test = "hey";

  std::string yo (test);

  std::string test2 ();

  std::cout << test << " " << yo << std::endl;
*/
}
