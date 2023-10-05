#include "NodoKD.h"

template <class T>
NodoKD<T>::NodoKD() {
    this->hijoIzq = nullptr;
    this->hijoDer = nullptr;
}

template <class T>
NodoKD<T>::NodoKD(punto val) {
    this->dato = val;
    this->hijoIzq = nullptr;
    this->hijoDer = nullptr;
}

template <class T>
NodoKD<T>::~NodoKD() {
    delete this->hijoIzq;
    delete this->hijoDer;
}

template <class T>
bool NodoKD<T>::esHoja() {
    return (this->hijoIzq == nullptr && this->hijoDer == nullptr);
}

template <class T>
punto NodoKD<T>::obtenerDato() {
    return this->dato;
}

template <class T>
void NodoKD<T>::fijarDato(punto val) {
    this->dato = val;
}

template <class T>
NodoKD<T>* NodoKD<T>::obtenerHijoIzq() {
    return this->hijoIzq;
}

template <class T>
NodoKD<T>* NodoKD<T>::obtenerHijoDer() {
    return this->hijoDer;
}

template <class T>
void NodoKD<T>::fijarHijoIzq(NodoKD* izq) {
    this->hijoIzq = izq;
}

template <class T>
void NodoKD<T>::fijarHijoDer(NodoKD* der) {
    this->hijoDer = der;
}
