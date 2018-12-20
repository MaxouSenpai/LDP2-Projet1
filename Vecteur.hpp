#ifndef _VECTEUR_H_
#define _VECTEUR_H_

#include <cstddef>
#include <cstdlib>
#include <exception>
#include <stdexcept>

template <typename T> class Vecteur {

public:

  Vecteur () = default;

  Vecteur (const Vecteur&) = default;

  virtual ~Vecteur () = default;

  virtual std::size_t getSize () const = 0;

  virtual T get (std::ptrdiff_t) = 0;

  virtual void set (std::ptrdiff_t,T) = 0;

};

#endif
