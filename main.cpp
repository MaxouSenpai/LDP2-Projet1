//template <class myType>
template <typename myType>
class Vecteur {
public:
  Vecteur () {};
  virtual ~Vecteur () {};
  virtual myType& operator[](unsigned int)=0;
};

template <typename myType>
class BinaryTree {
private:
  myType data;
  unsigned int indice;
  BinaryTree<myType>* leftChild;
  BinaryTree<myType>* rightChild;

public:
  BinaryTree () : data(0), indice(0), leftChild(nullptr), rightChild(nullptr) {}
  ~BinaryTree () {}
  myType getData() {return data;}
  unsigned int getIndice() {return indice;}
  BinaryTree<myType>* getLeftChild() {return leftChild;}
  void setLeftChild(myType* c) {leftChild = c;}
  BinaryTree<myType>* getRightChild() {return rightChild;}
  void setRightChild(myType* c) {rightChild = c;}
  myType& get(unsigned int x) {
    if (x == indice){
      return data;
    }
    else if (x < indice && getLeftChild() != nullptr) {
      return getLeftChild()->get(x);
    }
    else if (x > indice && getRightChild() != nullptr){
      return getRightChild()->get(x);
    }
  }
};


template <typename myType>
class VecteurCreux : public Vecteur<myType> {

private:
  unsigned int size;
  BinaryTree <myType> binary_tree;

public:
  VecteurCreux () : size(0), binary_tree() {};
  virtual ~VecteurCreux () {};
  virtual myType& operator[](unsigned int x) override {return binary_tree.get(x);}
};

int main(){
  VecteurCreux <int> a;
  BinaryTree <int> b;
}
