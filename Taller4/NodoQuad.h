using namespace std;
#include "punto.h"

#ifndef __NODOQUAD_H__
#define __NODOQUAD_H__

class NodoQuad {
protected:
    punto dato;
    NodoQuad* hijoSupIzq;
    NodoQuad* hijoSupDer;
    NodoQuad* hijoInfIzq;
    NodoQuad* hijoInfDer;
public:
    NodoQuad();
    NodoQuad(punto val);
    ~NodoQuad();
    punto obtenerDato();
    void fijarDato(punto val);
    NodoQuad* obtenerHijoSupIzq();
    NodoQuad* obtenerHijoSupDer();
    NodoQuad* obtenerHijoInfIzq();
    NodoQuad* obtenerHijoInfDer();
    void fijarHijoSupIzq(NodoQuad* sizq);
    void fijarHijoSupDer(NodoQuad* sder);
    void fijarHijoInfIzq(NodoQuad* iizq);
    void fijarHijoInfDer(NodoQuad* ider);
    bool esHoja();
};

#include "NodoQuad.hxx"
#endif