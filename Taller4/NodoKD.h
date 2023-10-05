#ifndef __NODOKD_H__
#define __NODOKD_H__

#include "punto.h"


template <class T> class NodoKD {
protected:
  punto dato;
  NodoKD* hijoIzq;
  NodoKD* hijoDer;
public:
  NodoKD();
  NodoKD(punto val);
  ~NodoKD();
  bool esHoja();
  punto obtenerDato();
  void fijarDato(punto val);
  NodoKD* obtenerHijoIzq();
  NodoKD* obtenerHijoDer();
  void fijarHijoIzq(NodoKD* izq);
  void fijarHijoDer(NodoKD* der);
};

#include "NodoKD.hxx"


#endif