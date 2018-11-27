template <typename myType> class Vecteur {

public:

  Vecteur () {};

  virtual ~Vecteur () {};

  virtual myType& operator[](unsigned int)=0;

};


template <typename myType> class BinaryTree {

private:

  myType data;

  unsigned int indice;

  BinaryTree<myType>* leftChild;

  BinaryTree<myType>* rightChild;

public:

  BinaryTree () : data(0), indice(0), leftChild(nullptr), rightChild(nullptr) {}

  ~BinaryTree () {}

  BinaryTree (const BinaryTree&);

  BinaryTree& operator=(const BinaryTree<myType>& other){
    setData(other.getData());
    setIndice(other.getIndice());
    if (other.getLeftChild() != nullptr){
      BinaryTree<myType> *temp = new BinaryTree<myType>();
      temp = other.getLeftChild();
      setLeftChild(temp);
    }
    if (other.getRightChild() != nullptr){
      BinaryTree<myType> *temp = new BinaryTree<myType>();
      temp = other.getRightChild();
      setRightChild(temp);
    }
    return *this;
  }

  myType getData() const {return data;}

  void setData(myType d){data = d;}

  unsigned int getIndice() const {return indice;}

  void setIndice(unsigned int i) {indice = i;}

  BinaryTree<myType>* getLeftChild() const {return leftChild;}

  void setLeftChild(BinaryTree<myType>* c) {leftChild = c;}

  BinaryTree<myType>* getRightChild() const {return rightChild;}

  void setRightChild(BinaryTree<myType>* c) {rightChild = c;}

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
    else {
      return data; // To Delete
    }
  }
};


template <typename myType> class VecteurCreux : public Vecteur<myType> {

private:

  unsigned int size;

  BinaryTree <myType> binary_tree;

public:

  VecteurCreux () : size(0), binary_tree() {};

  virtual ~VecteurCreux () {};

  virtual myType& operator[](unsigned int x) override {if ((0 <= x) && (x < size)){return binary_tree.get(x);}else{throw;}}


};

int main(){
  VecteurCreux <int> a;
  BinaryTree <int> b;
  BinaryTree <int> c;
  b=c;
}
