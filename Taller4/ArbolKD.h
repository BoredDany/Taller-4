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