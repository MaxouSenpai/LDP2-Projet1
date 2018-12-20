#include "Node.hpp"
#include "Vecteur.hpp"
#include "BinarySearchTree.hpp"
#include "VecteurCreux.hpp"
#include <cstddef>

template <typename V>
void ParcoursTableau (Vecteur<V> &v)
{
  for (std::ptrdiff_t i = 0; std::size_t(i)<v.getSize();i++)
    std::cout << "Vecteur [" << i << "] = " << v.get(i) << std::endl;
}

template <typename K,typename V>
void ParcoursArbre (BinarySearchTree<K,V> &tree)
{
  for (typename BinarySearchTree<K,V>::iterator it = tree.begin() ; it != tree.end() ; ++it)
    std::cout << "( " << it.getKey() << " | " << it.getValue() << " )" << std::endl;
}


int main()
{/*

  VecteurCreux<int> x (10);

  x.set(3,11);
  x.set(6,44);
  x.set(1,66);

  ParcoursTableau(x);

  ParcoursArbre(x);
*/
  Node <unsigned, int> a;
  Node <unsigned, int> b (a);
  Node <unsigned, int> c = a;

  BinarySearchTree <unsigned,int> d;
  BinarySearchTree <unsigned,int> e (d);
  BinarySearchTree <unsigned,int> f = d;

  VecteurCreux <int> g (1);
  VecteurCreux <int> h (g);
  VecteurCreux <int> i = g;


  return 0;
}
