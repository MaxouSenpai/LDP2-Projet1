#ifndef _VECTEUR_H_
#define _VECTEUR_H_

template <typename T> class Vecteur {

protected:
  unsigned int const size;

public:

  Vecteur () = default;
  Vecteur (unsigned int x) : size(x) {}
  Vecteur (const Vecteur&) = default;

  virtual ~Vecteur () = default;

  virtual T& operator[](unsigned int) = 0;

  virtual unsigned int getSize() const = 0;

  virtual T& get(unsigned int) = 0;

  virtual void set(T,unsigned int) = 0;

};

#endif
