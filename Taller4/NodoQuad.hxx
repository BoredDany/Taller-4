#include "NodoQuad.h"

NodoQuad :: NodoQuad(){
  this->hijoSupIzq = nullptr;
  this->hijoSupDer = nullptr;
  this->hijoInfIzq = nullptr;
  this->hijoInfDer = nullptr;
}

NodoQuad :: NodoQuad(punto val){
  this->hijoSupIzq = nullptr;
  this->hijoSupDer = nullptr;
  this->hijoInfIzq = nullptr;
  this->hijoInfDer = nullptr;
  this->dato = val;
}

NodoQuad ::~NodoQuad(){
  delete this->hijoSupIzq;
  delete this->hijoSupDer;
  delete this->hijoInfIzq;
  delete this->hijoInfDer;
}

punto NodoQuad :: obtenerDato(){
  return this->dato;
}

void NodoQuad :: fijarDato(punto val){
  this->dato = val;
}

NodoQuad* NodoQuad ::obtenerHijoSupIzq(){
  return this->hijoSupIzq;
}

NodoQuad* NodoQuad ::obtenerHijoSupDer(){
  return this->hijoSupDer;
}

NodoQuad* NodoQuad ::obtenerHijoInfIzq(){
  return this->hijoInfIzq;
}

NodoQuad* NodoQuad ::obtenerHijoInfDer(){
  return this->hijoInfDer;
}

void NodoQuad ::fijarHijoSupIzq(NodoQuad* sizq){
  this->hijoSupIzq = sizq;
}

void NodoQuad ::fijarHijoSupDer(NodoQuad* sder){
  this->hijoSupDer = sder;
}

void NodoQuad ::fijarHijoInfIzq(NodoQuad* iizq){
  this->hijoInfIzq = iizq;
}

void NodoQuad ::fijarHijoInfDer(NodoQuad* ider){
  this->hijoInfDer = ider;
}

bool NodoQuad ::esHoja(){
  return (this->hijoSupIzq == nullptr && this->hijoSupDer == nullptr && this->hijoInfIzq == nullptr && this->hijoInfDer == nullptr);
}