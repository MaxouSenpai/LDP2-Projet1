#FLAGS= -std=c++14 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion -Weffc++ -Wstrict-null-sentinel -Wold-style-cast -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override
FLAGS= -std=c++17 -masm=intel -fconcepts -mlong-double-128 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion -Wsign-conversion -Weffc++ -Wstrict-null-sentinel -Wold-style-cast -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override -lquadmath

CXX= g++
MAIN= Test.cpp
OUT= Test.out

all: $(OUT)

$(OUT): VecteurCreux.o Vecteur.o BinarySearchTree.o Node.o $(MAIN)
	$(CXX) $(FLAGS) $(MAIN) VecteurCreux.o Vecteur.o BinarySearchTree.o Node.o -o $(OUT)

VecteurCreux.o: VecteurCreux.cpp VecteurCreux.hpp
	$(CXX) $(FLAGS) -c VecteurCreux.cpp

Vecteur.o: Vecteur.cpp Vecteur.hpp
	$(CXX) $(FLAGS) -c Vecteur.cpp

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.hpp
	$(CXX) $(FLAGS) -c BinarySearchTree.cpp

Node.o: Node.cpp Node.hpp
	$(CXX) $(FLAGS) -c Node.cpp

.PHONY : clean

clean:
	rm *.o *.out;
