#include "ArbolQuad.h"
#include <queue>

ArbolQuad :: ArbolQuad(){
  this->raiz = nullptr;
}

ArbolQuad :: ArbolQuad(punto val){
  NodoQuad *nodo = new NodoQuad(val);
  this->raiz = nodo;
}

ArbolQuad :: ~ArbolQuad(){
  if (this->raiz == nullptr)
  {
    delete this->raiz;
    this->raiz = nullptr;
  }
}

punto ArbolQuad :: datoRaiz(){
  return (this->raiz)->obtenerDato();
}

NodoQuad * ArbolQuad :: obtenerRaiz(){
  return this->raiz;
}

void ArbolQuad ::fijarRaiz(NodoQuad *n_raiz){
  this->raiz = n_raiz;
}

bool ArbolQuad :: esVacio(){
  return (this->raiz == nullptr);
}

bool ArbolQuad :: insertar(punto val){
  if (this->esVacio()) {
    this->raiz = new NodoQuad(val);
    return true;
  } else {
    NodoQuad* nodo = this->raiz;
    NodoQuad* padre = this->raiz;
    bool duplicado = false;

    while (nodo != nullptr){
      padre = nodo;
      if (val == nodo->obtenerDato()){
        duplicado = true;
        break;
      } else if (val.x > nodo->obtenerDato().x && val.y >= nodo->obtenerDato().y){
        nodo = nodo->obtenerHijoSupDer();
      } else if (val.x > nodo->obtenerDato().x && val.y <= nodo->obtenerDato().y){
        nodo = nodo->obtenerHijoInfDer();
      } else if (val.x < nodo->obtenerDato().x && val.y >= nodo->obtenerDato().y){
        nodo = nodo->obtenerHijoInfIzq();
      } else if (val.x < nodo->obtenerDato().x && val.y <= nodo->obtenerDato().y){   
        nodo = nodo->obtenerHijoSupIzq();
      }    
    }

    if (!duplicado){
      NodoQuad* nodoNuevo = new NodoQuad(val);
      if (val.x > padre->obtenerDato().x && val.y >= padre->obtenerDato().y){
        padre->fijarHijoSupDer(nodoNuevo);
      } else if (val.x > padre->obtenerDato().x && val.y <= padre->obtenerDato().y){
        padre->fijarHijoInfDer(nodoNuevo);
      } else if (val.x < padre->obtenerDato().x && val.y >= padre->obtenerDato().y){
        padre->fijarHijoInfIzq(nodoNuevo);
      } else if (val.x < padre->obtenerDato().x && val.y <= padre->obtenerDato().y){    
        padre->fijarHijoSupIzq(nodoNuevo);
      }
      return true;
    }
  }
}

void ArbolQuad :: preOrden(){
  preOrden(this->raiz);
}

void ArbolQuad :: preOrden(NodoQuad *nodo){
  if (nodo != nullptr)
  {
    cout << nodo->obtenerDato() << " ";
    preOrden(nodo->obtenerHijoSupIzq());
    preOrden(nodo->obtenerHijoSupDer());
    preOrden(nodo->obtenerHijoInfIzq());
    preOrden(nodo->obtenerHijoInfDer());
    
  }
}

void ArbolQuad :: inOrden(){
  inOrden(this->raiz);
}

void ArbolQuad :: inOrden(NodoQuad *nodo){
  if (nodo != nullptr)
  {
    inOrden(nodo->obtenerHijoSupIzq());
    inOrden(nodo->obtenerHijoSupDer());
    cout << nodo->obtenerDato() << " ";
    inOrden(nodo->obtenerHijoInfIzq());
    inOrden(nodo->obtenerHijoInfDer());
  }
}

void ArbolQuad :: posOrden(){
  posOrden(this->raiz);
}

void ArbolQuad :: posOrden(NodoQuad *nodo){
  if (nodo != nullptr)
  {
    posOrden(nodo->obtenerHijoSupIzq());
    posOrden(nodo->obtenerHijoSupDer());
    posOrden(nodo->obtenerHijoInfIzq());
    posOrden(nodo->obtenerHijoInfDer());
    cout << nodo->obtenerDato() << " ";
  }
}

void ArbolQuad :: nivelOrden(){
  if (!this->esVacio())
  {
    queue<NodoQuad *> cola;
    cola.push(this->raiz);
    NodoQuad *nodo;

    while (!cola.empty())
    {
      nodo = cola.front();
      cola.pop();
      cout << nodo->obtenerDato() << " ";
      if (nodo->obtenerHijoSupIzq() != nullptr)
      {
        cola.push(nodo->obtenerHijoSupIzq());
      }
      if (nodo->obtenerHijoSupDer() != nullptr)
      {
        cola.push(nodo->obtenerHijoSupDer());
      }
      if (nodo->obtenerHijoInfIzq() != nullptr)
      {
        cola.push(nodo->obtenerHijoInfIzq());
      }
      if (nodo->obtenerHijoInfDer() != nullptr)
      {
        cola.push(nodo->obtenerHijoInfDer());
      }
    }
  }
}