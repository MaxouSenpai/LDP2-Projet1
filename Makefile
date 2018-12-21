FLAGS= -std=c++17 -masm=intel -fconcepts -mlong-double-128 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion -Wsign-conversion -Weffc++ -Wstrict-null-sentinel -Wold-style-cast -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override -lquadmath

CXX= g++-8
MAIN= main.cpp
OUT= Test.out

all: $(OUT)

$(OUT): VecteurCreux.hpp Vecteur.hpp BinarySearchTree.hpp Node.hpp $(MAIN)
	$(CXX) $(FLAGS) $(MAIN) -o $(OUT)

.PHONY : clean

clean:
	rm *.o *.out;
