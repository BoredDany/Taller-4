#include "ArbolQuad.h"
#include "NodoQuad.h"
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
      } else if (val.x > nodo->obtenerDato().x && val.y > nodo->obtenerDato().y){//superior derecho
        nodo = nodo->obtenerHijoSupDer();
      } else if (val.x > nodo->obtenerDato().x && val.y <= nodo->obtenerDato().y){//inferior derecho
        nodo = nodo->obtenerHijoInfDer();
      } else if (val.x <= nodo->obtenerDato().x && val.y <= nodo->obtenerDato().y){//inferior izquierdo
        nodo = nodo->obtenerHijoInfIzq();
      } else if (val.x >= nodo->obtenerDato().x && val.y > nodo->obtenerDato().y){//superior izquierdo
        nodo = nodo->obtenerHijoSupIzq();
      }    
    }

    if (!duplicado){
      NodoQuad* nodoNuevo = new NodoQuad(val);
      if (val.x > padre->obtenerDato().x && val.y > padre->obtenerDato().y){//superior derecho
        padre->fijarHijoSupDer(nodoNuevo);
      } else if (val.x > padre->obtenerDato().x && val.y <= padre->obtenerDato().y){//inferior derecho
        padre->fijarHijoInfDer(nodoNuevo);
      } else if (val.x <= padre->obtenerDato().x && val.y <= padre->obtenerDato().y){//inferior izquierdo
        padre->fijarHijoInfIzq(nodoNuevo);
      } else if (val.x >= padre->obtenerDato().x && val.y > padre->obtenerDato().y){ //superior izquierdo
        padre->fijarHijoSupIzq(nodoNuevo);
      }
      return true;
    }
  }
}

template <class T>
void ArbolQuad<T> ::buscar(double x, int y, NodoQuad * nodo){
    double distancia = calcularDistancia(x,y,nodo->obtenerDato().x,nodo->obtenerDato().y);
    NodoQuad* mejorNodo = nullptr;
    buscarR(x,y,this->raiz, distancia, &mejorNodo);
    if(mejorNodo != nullptr){
        cout << "\nRESULTADO DEL QUADTREE";
        cout << "\nES " << mejorNodo->obtenerDato() << " con distancia " << distancia << endl << endl;
    }else{
        cout << "ERROR AL ENCONTRAR" << endl;
    }
}

template <class T>
void ArbolQuad<T> ::buscarR(double x, int y, NodoQuad * nodo, double& mejorDistancia, NodoQuad** mejorNodo){
    double distancia;

    if (nodo != nullptr) {

        distancia = calcularDistancia(x,y,nodo->obtenerDato().x, nodo->obtenerDato().y);

        if(distancia <= mejorDistancia){
            mejorDistancia = distancia;
            *mejorNodo = nodo;
        }

        buscarR(x,y,nodo->obtenerHijoSupIzq(),mejorDistancia,mejorNodo);
        buscarR(x,y,nodo->obtenerHijoSupDer(),mejorDistancia,mejorNodo);
        buscarR(x,y,nodo->obtenerHijoInfIzq(),mejorDistancia,mejorNodo);
        buscarR(x,y,nodo->obtenerHijoInfDer(),mejorDistancia,mejorNodo);
    }
}

template <class T>
double ArbolQuad<T> ::calcularDistancia(double x1, int y1, double x2, int y2){
    double distancia = 0, distanciaX = 0, distanciaY = 0;
    distanciaX = pow(x1-x2,2);
    distanciaY = pow(y1-y2,2);
    distancia = sqrt(distanciaY+distanciaX);
    return distancia;
}

template <class T>
void ArbolQuad<T> :: preOrden(){
  preOrden(this->raiz);
}

template <class T>
void ArbolQuad<T> :: preOrden(NodoQuad *nodo){
  if (nodo != nullptr)
  {
    cout << nodo->obtenerDato() << endl;
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
    cout << nodo->obtenerDato() << endl;
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
    cout << nodo->obtenerDato() << endl;
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
      cout << nodo->obtenerDato() << endl;
      if (nodo->obtenerHijoSupIzq() != nullptr){
        cola.push(nodo->obtenerHijoSupIzq());
      }
      if (nodo->obtenerHijoSupDer() != nullptr){
        cola.push(nodo->obtenerHijoSupDer());
      }
      if (nodo->obtenerHijoInfDer() != nullptr){
          cola.push(nodo->obtenerHijoInfDer());
      }
      if (nodo->obtenerHijoInfIzq() != nullptr){
          cola.push(nodo->obtenerHijoInfIzq());
      }
    }
  }
}