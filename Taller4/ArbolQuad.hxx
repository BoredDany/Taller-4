#include "ArbolQuad.h"
#include <queue>

template <class T>
ArbolQuad<T>::ArbolQuad() {
  this->raiz = nullptr;
}
template <class T>
ArbolQuad<T> :: ArbolQuad(punto val){
  NodoQuad *nodo = new NodoQuad(val);
  this->raiz = nodo;
}
template <class T>
ArbolQuad<T>:: ~ArbolQuad(){
  if (this->raiz == nullptr)
  {
    delete this->raiz;
    this->raiz = nullptr;
  }
}
template <class T>
punto ArbolQuad<T>:: datoRaiz(){
  return (this->raiz)->obtenerDato();
}
template <class T>
NodoQuad* ArbolQuad<T>::obtenerRaiz() {
  return this->raiz;
}
template <class T>
void ArbolQuad<T> ::fijarRaiz(NodoQuad *n_raiz){
  this->raiz = n_raiz;
}
template <class T>
bool ArbolQuad<T> :: esVacio(){
  return (this->raiz == nullptr);
}
template <class T>
bool ArbolQuad<T> :: insertar(punto val){
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
template <class T>
void ArbolQuad<T> :: preOrden(){
  preOrden(this->raiz);
}
template <class T>
void ArbolQuad<T> :: preOrden(NodoQuad *nodo){
  if (nodo != nullptr)
  {
    cout << nodo->obtenerDato() << " ";
    preOrden(nodo->obtenerHijoSupIzq());
    preOrden(nodo->obtenerHijoSupDer());
    preOrden(nodo->obtenerHijoInfIzq());
    preOrden(nodo->obtenerHijoInfDer());
    
  }
}
template <class T>
void ArbolQuad<T> :: inOrden(){
  inOrden(this->raiz);
}
template <class T>
void ArbolQuad<T> :: inOrden(NodoQuad *nodo){
  if (nodo != nullptr)
  {
    inOrden(nodo->obtenerHijoSupIzq());
    inOrden(nodo->obtenerHijoSupDer());
    cout << nodo->obtenerDato() << " ";
    inOrden(nodo->obtenerHijoInfIzq());
    inOrden(nodo->obtenerHijoInfDer());
  }
}
template <class T>
void ArbolQuad<T> :: posOrden(){
  posOrden(this->raiz);
}
template <class T>
void ArbolQuad<T> :: posOrden(NodoQuad *nodo){
  if (nodo != nullptr)
  {
    posOrden(nodo->obtenerHijoSupIzq());
    posOrden(nodo->obtenerHijoSupDer());
    posOrden(nodo->obtenerHijoInfIzq());
    posOrden(nodo->obtenerHijoInfDer());
    cout << nodo->obtenerDato() << " ";
  }
}
template <class T>
void ArbolQuad<T> :: nivelOrden(){
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