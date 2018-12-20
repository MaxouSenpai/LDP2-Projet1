#ifndef _NODE_H_
#define _NODE_H_

template <typename K,typename V> class Node {

private:
  K key;
  V value;
  Node<K,V> *parent, *left, *right;

public:

  Node (K=false,V=false);

  Node (const Node<K,V>&);

  ~Node ();

  Node<K,V>& operator= (const Node<K,V>&);

  bool operator< (const Node<K,V>&);

  const K& getKey () const;

  void setKey (K);

  V& getValue ();

  void setValue (V);

  Node<K,V>* getParent () const;

  void setParent (Node<K,V>*);

  Node<K,V>* getLeft () const;

  void setLeft (Node<K,V>*);

  Node<K,V>* getRight () const;

  void setRight (Node<K,V>*);

};

template <typename K,typename V> Node<K,V>::Node (K k, V v) : key(k), value(v), parent(nullptr), left(nullptr), right(nullptr) {}

template <typename K,typename V> Node<K,V>::Node (const Node<K,V>& other) : key(other.key), value(other.value), parent(nullptr), left(nullptr), right(nullptr)
{
  if (other.left != nullptr)
  {
    Node<K,V> *temp = new Node<K,V> (*other.left);
    temp->setParent(this);
    this->left = temp;
  }

  if (other.right != nullptr) {
    Node<K,V> *temp = new Node<K,V> (*other.right);
    temp->setParent(this);
    this->right = temp;
  }
}

template <typename K,typename V> Node<K,V>::~Node ()
{
  if (this->left != nullptr)
    delete this->left;

  if (this->right != nullptr)
    delete this->right;
}

template <typename K,typename V> Node<K,V>& Node<K,V>::operator= (const Node<K,V>& other)
{
  this->key = other.key;
  this->value = other.value;

  if (this->left != nullptr)
    delete this->left;

  if (other.left != nullptr)
    this->left = new Node<K,V> (*other.left);

  else
    this->left = nullptr;


  if (this->right != nullptr)
    delete this->right;

  if (other.right != nullptr)
    this->right = new Node<K,V> (*other.right);

  else
    this->right = nullptr;

  return *this;
}

template <typename K,typename V> bool Node<K,V>::operator< (const Node<K,V>& other) {return this->key < other.key;}

template <typename K,typename V> const K& Node<K,V>::getKey () const {return this->key;}

template <typename K,typename V> void Node<K,V>::setKey (K i) {this->key = i;}

template <typename K,typename V> V& Node<K,V>::getValue () {return this->value;}

template <typename K,typename V> void Node<K,V>::setValue (V v) {this->value = v;}

template <typename K,typename V> Node<K,V>* Node<K,V>::getParent () const {return this->parent;}

template <typename K,typename V> void Node<K,V>::setParent (Node<K,V>* n) {this->parent = n;}

template <typename K,typename V> Node<K,V>* Node<K,V>::getLeft () const {return this->left;}

template <typename K,typename V> void Node<K,V>::setLeft (Node<K,V>* n) {this->left = n;}

template <typename K,typename V> Node<K,V>* Node<K,V>::getRight () const {return this->right;}

template <typename K,typename V> void Node<K,V>::setRight (Node<K,V>* n) {this->right = n;}

#endif
