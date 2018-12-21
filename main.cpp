
// Nom : Hauwaert
// Prénom : Maxime
// Matricule : 461714

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
    std::cout << "( " << (*it).getKey() << " | " << (*it).getValue() << " )" << std::endl;
}

int main()
{
  std::cout << "\nVecteurCreux <int> a\n" << std::endl;
  VecteurCreux<int> a (10);

  a.set(3,11);
  a.set(6,44);
  a.set(1,66);
  a.set(8,0);
  a.set(3,0);

  std::cout << "Comme tableau :\n" << std::endl;
  ParcoursTableau(a);
  std::cout << "\nComme arbre :\n" << std::endl;
  ParcoursArbre(a);
  std::cout << std::endl;

  VecteurCreux<int> b (a);
  std::cout << "DeepCopy de a pour b" << std::endl;

  std::cout << "Modification de certains éléments de b" << std::endl;
  b.set(7,42);
  b.set(3,55);

  std::cout << "\nVecteurCreux <int> a\n" << std::endl;
  std::cout << "Comme tableau :\n" << std::endl;
  ParcoursTableau(a);
  std::cout << "\nComme arbre :\n" << std::endl;
  ParcoursArbre(a);

  std::cout << "\nVecteurCreux <int> b\n" << std::endl;
  std::cout << "Comme tableau :\n" << std::endl;
  ParcoursTableau(b);
  std::cout << "\nComme arbre :\n" << std::endl;
  ParcoursArbre(b);
  std::cout << std::endl;

  std::cout << "Accès à un indice impossible" << std::endl;

  try
  {
    b.get(11);
  }
  catch (const std::out_of_range&)
  {
    std::cout << "Error caught : out of range\n" << std::endl;
  }

  std::cout << "BinarySearchTree <long int,float> x\n" << std::endl;
  BinarySearchTree<long int,float> x;

  x.Insert(new Node<long int,float>(12413,1.23f));
  x.Insert(new Node<long int,float>(2453,65.3f));
  x.Insert(new Node<long int,float>(124236,246.0f));

  ParcoursArbre(x);

  std::cout << "\nVecteur <double> y\n" << std::endl;
  Vecteur<double> *y = new VecteurCreux<double>(10);

  y->set(2,4.2);
  y->set(9,3.74);
  y->set(2,43.5);

  ParcoursTableau(*y);
  delete y;
  std::cout << std::endl;

  Node<char,int> i ('a',76), j ('z',8);
  std::cout << "Le Node ( " << i.getKey() << " | " << i.getValue() << " ) est ";

  if (i<j)
    std::cout << "plus petit";

  else
  std::cout << "plus grand";

  std::cout << " que le Node ( " << j.getKey() << " | " << j.getValue() << " )\n" << std::endl;

  return 0;
}
