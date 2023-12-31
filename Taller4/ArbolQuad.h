#include "NodoQuad.h"
#include <iostream>

#ifndef __ARBOLQUAD_H__
#define __ARBOLQUAD_H__
template <class T> class ArbolQuad  {
protected:
  NodoQuad *raiz;

public:
  ArbolQuad();
  ArbolQuad(punto val);
  ~ArbolQuad();
  punto datoRaiz();
  NodoQuad *obtenerRaiz();
  void fijarRaiz(NodoQuad *n_raiz);
  bool esVacio();
  bool insertar(punto val);
  void buscar(double x, int y, NodoQuad * nodo);
  void buscarR(double x, int y, NodoQuad * nodo, double& mejorDistancia, NodoQuad** mejorNodo);
  double calcularDistancia(double x1, int y1, double x2, int y2);
  void preOrden();
  void preOrden(NodoQuad *nodo);
  void inOrden();
  void inOrden(NodoQuad *nodo);
  void posOrden();
  void posOrden(NodoQuad *nodo);
  void nivelOrden();
};

#include "ArbolQuad.hxx"
#endif
