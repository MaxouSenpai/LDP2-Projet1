#ifndef _NODE_H_
#define _NODE_H_

template <typename T> class Node {

private:
  unsigned int key;
  T data;
  Node<T> *father, *left, *right;

public:

  Node (unsigned int=0,T=false);

  Node (const Node<T>&);

  ~Node ();

  Node<T>& operator= (const Node<T>&);

  bool operator< (const Node<T>&);

  unsigned int getKey () const;

  void setKey (unsigned int);

  const T& getData () const;

  T& getData ();

  void setData (T);

  Node<T>* getLeft () const;

  void setLeft (Node<T>* );

  Node<T>* getRight () const;

  void setRight (Node<T>*);

};

template <typename T> Node<T>::Node (unsigned int i, T t) : key(i), data(t), father(nullptr), left(nullptr), right(nullptr) {}

template <typename T> Node<T>::Node (const Node<T>& other) : key(other.getKey()), data(other.getData()), father(nullptr), left(nullptr), right(nullptr) {

  if (other.getLeft() != nullptr) {
    setLeft(new Node<T> (*other.getLeft()));
  }

  if (other.getRight() != nullptr) {
    setRight(new Node<T> (*other.getRight()));
  }
}

template <typename T> Node<T>::~Node () {
  if (getLeft() != nullptr) {
    delete getLeft();
  }

  if (getRight() != nullptr) {
    delete getRight();
  }
}

template <typename T> Node<T>& Node<T>::operator= (const Node<T>& other) {
  setKey(other.getKey());
  setData(other.getData());
  if (other.getLeft() != nullptr) {
    setLeft(new Node<T> (*other.getLeft()));
  }

  else {
    setLeft(nullptr);
  }

  if (other.getRight() != nullptr) {
    setRight(new Node<T> (*other.getRight()));
  }

  else {
    setRight(nullptr);
  }

  return *this;
}

template <typename T> bool Node<T>::operator< (const Node<T>& other) {return getKey() < other.getKey();}

template <typename T> unsigned int Node<T>::getKey () const {return key;}

template <typename T> void Node<T>::setKey (unsigned int i) {key = i;}

template <typename T> const T& Node<T>::getData () const {return data;}

template <typename T> T& Node<T>::getData () {return data;}

template <typename T> void Node<T>::setData (T d) {data = d;}

template <typename T> Node<T>* Node<T>::getLeft () const {return left;}

template <typename T> void Node<T>::setLeft (Node<T>* n) {
  //if (getLeft() != nullptr) {delete getLeft();}
  left = n;
}

template <typename T> Node<T>* Node<T>::getRight () const {return right;}

template <typename T> void Node<T>::setRight (Node<T>* n) {
  //if (getRight() != nullptr) {delete getRight();}
  right = n;
}

#endif
