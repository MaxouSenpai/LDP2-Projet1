#include "Node.hpp"
#include "Vecteur.hpp"
#include "BinarySearchTree.hpp"
#include "VecteurCreux.hpp"

int main(){
  VecteurCreux <int> a (10);
  a[9] = 123145;
  a[0] = 134;
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
  return 0;
}
