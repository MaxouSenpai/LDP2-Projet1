#ifndef _VECTEUR_H_
#define _VECTEUR_H_

template <typename T> class Vecteur {

public:

  Vecteur () = default;

  Vecteur (const Vecteur&) = default;

  //Vecteur (Vecteur&&) = default;

  virtual ~Vecteur () = default;

  virtual T& operator[](unsigned int) = 0;

  virtual unsigned int getSize() const = 0;

  virtual T& get(unsigned int) = 0;

  virtual void set(T,unsigned int) = 0;

};

#endif
