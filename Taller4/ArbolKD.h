#ifndef __ARBOLKD_H__
#define __ARBOLKD_H__

#include "NodoKD.h"
#include <iostream>

template <class T> class ArbolKD {
  protected:
    NodoKD<T>* raiz;
  public:
    ArbolKD();
    ArbolKD(punto val);
    ~ArbolKD();
    punto datoRaiz();
    NodoKD<T>* obtenerRaiz();
    void fijarRaiz(NodoKD<T>* n_raiz);
    bool esVacio();
    bool insertar(punto val);
    void buscar(double x, int y);
    double calcularDistancia(double x1, int y1, double x2, int y2);
    void preOrden();
    void preOrdenRecursivo(NodoKD<T>* nodo);
    void inOrden();
    void inOrdenRecursivo(NodoKD<T>* nodo);
    void posOrden();
    void posOrdenRecursivo(NodoKD<T>* nodo);
    void nivelOrden();
};
#include "ArbolKD.hxx"


#endif