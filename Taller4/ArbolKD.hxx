#include "ArbolKD.h"
#include <queue>
#include <list>
#include <cmath>

using namespace std;

template <class T>
ArbolKD<T>::ArbolKD() {
    this->raiz = nullptr;
}

template <class T>
ArbolKD<T>::ArbolKD(punto val) {
    this->raiz = new NodoKD<T>(val);
}

template <class T>
ArbolKD<T>::~ArbolKD() {
    delete this->raiz;
}

template <class T>
punto ArbolKD<T>::datoRaiz() {
    if (raiz) {
        return this->raiz->obtenerDato();
    } else {
        throw runtime_error("El árbol está vacío");
    }
}

template <class T>
NodoKD<T>* ArbolKD<T>::obtenerRaiz() {
    return this->raiz;
}

template <class T>
void ArbolKD<T>::fijarRaiz(NodoKD<T>* n_raiz) {
    this->raiz = n_raiz;
}

template <class T>
bool ArbolKD<T>::esVacio() {
    return (this->raiz == nullptr);
}

template <class T>
bool ArbolKD<T>::insertar(punto val) {

    NodoKD<T> * padre = this->raiz;
    NodoKD<T> * nodo = this->raiz;
    bool insertado = false;
    int dimension = 1;

    if(this->esVacio()){
        NodoKD<T> * raiz = new NodoKD<T>(val);
        this->raiz = raiz;
        insertado = true;
    }else{
        while(padre != nullptr){
            nodo = padre;

            if(dimension % 2 != 0){//dimension x
                if(val.x <= padre->obtenerDato().x){
                    padre = padre->obtenerHijoIzq();
                    dimension++;
                }else{
                    padre = padre->obtenerHijoDer();
                    dimension++;
                }
            }else{//dimension y
                if(val.y <= padre->obtenerDato().y){
                    padre = padre->obtenerHijoIzq();
                    dimension++;
                }else{
                    padre = padre->obtenerHijoDer();
                    dimension++;
                }
            }
        }

        dimension--;

        if(nodo != nullptr){
            NodoKD<T>* nuevo = new NodoKD<T>(val);

            if(dimension % 2 != 0) {//dimension x
                if(val.x <= nodo->obtenerDato().x && nodo->obtenerHijoIzq() == nullptr) {
                    nodo->fijarHijoIzq(nuevo);
                    insertado = true;
                }else if(val.x > nodo->obtenerDato().x && nodo->obtenerHijoDer() == nullptr){
                    nodo->fijarHijoDer(nuevo);
                    insertado = true;
                }
            }else {//dimension y
                if(val.y <= nodo->obtenerDato().y && nodo->obtenerHijoIzq() == nullptr) {
                    nodo->fijarHijoIzq(nuevo);
                    insertado = true;
                }else if(val.y > nodo->obtenerDato().y && nodo->obtenerHijoIzq() == nullptr){
                    nodo->fijarHijoDer(nuevo);
                    insertado = true;
                }
            }
        }

    }
    return insertado;
}

template <class T>
double ArbolKD<T>::calcularDistancia(double x1, int y1, double x2, int y2){
    double distancia = 0, distanciaX = 0, distanciaY = 0;
    distanciaX = pow(x1-x2,2);
    distanciaY = pow(y1-y2,2);
    distancia = sqrt(distanciaY+distanciaX);
    return distancia;
}

/*template <class T>
void ArbolKD<T>::buscar(double x, int y){
    if(this->esVacio()){
        return ;
    }else{
        int dimension = 1;
        double distancia = 0, distanciaRes = 0;
        NodoKD<T> * nodoActual = this->raiz;
        NodoKD<T> * nodoRes = this->raiz;
        bool encontrado = false;

        while(nodoActual != nullptr && !encontrado){

            if(nodoActual->obtenerDato().x == x && nodoActual->obtenerDato().y == y){
                nodoRes = nodoActual;
                distanciaRes = calcularDistancia(x,y,nodoRes->obtenerDato().x, nodoRes->obtenerDato().y);
                std::cout << "NODO IDENTICO ENCONTRADO CON DISTANCIA " << distanciaRes << endl;
                std::cout << "La fruta es: " << nodoRes->obtenerDato() << endl;
                return;
            }else{
                if(dimension % 2 != 0){//x
                    std::cout << "X " << std::endl;
                    if(x <= nodoActual->obtenerDato().x){
                        nodoRes = nodoActual;
                        nodoActual = nodoActual->obtenerHijoIzq();
                        dimension++;
                    }else if (x > nodoActual->obtenerDato().x){
                        nodoRes = nodoActual;
                        nodoActual = nodoActual->obtenerHijoDer();
                        dimension++;
                    }
                    distanciaRes = calcularDistancia(x,y,nodoRes->obtenerDato().x, nodoRes->obtenerDato().y);
                    distancia = calcularDistancia(x,y,nodoActual->obtenerDato().x, nodoActual->obtenerDato().y);
                    std::cout << nodoActual->obtenerDato().x <<" - " << x << endl;
                    std::cout << nodoActual->obtenerDato().y <<" - " << y << endl;
                    std::cout << "DISTANCIA  " << distancia << endl;
                }else{//y
                    std::cout << "Y  " << std::endl;
                    if(y <= nodoActual->obtenerDato().y){
                        nodoRes = nodoActual;
                        nodoActual = nodoActual->obtenerHijoIzq();
                        dimension++;
                    }else if (y > nodoActual->obtenerDato().y){
                        nodoRes = nodoActual;
                        nodoActual = nodoActual->obtenerHijoDer();
                        dimension++;
                    }
                    distanciaRes = calcularDistancia(x,y,nodoRes->obtenerDato().x, nodoRes->obtenerDato().y);
                    distancia = calcularDistancia(x,y,nodoActual->obtenerDato().x, nodoActual->obtenerDato().y);
                    std::cout << nodoActual->obtenerDato().x <<" - " << x << endl;
                    std::cout << nodoActual->obtenerDato().y <<" - " << y << endl;
                    std::cout << "DISTANCIA  " << distancia << endl;
                }
            }


            if(distancia < distanciaRes){
                nodoRes = nodoActual;
                distanciaRes = distancia;
                std::cout << "DISTANCIA MENOR " << distanciaRes << endl;
            }

            if(nodoActual->obtenerHijoDer() == nullptr && nodoActual->obtenerHijoIzq() == nullptr){
                std::cout << "NODO MAS PARECIDO CON DISTANCIA " << distanciaRes << endl;
                std::cout << "La fruta es posiblemente: " << nodoRes->obtenerDato()<< endl;
                encontrado = true;
            }

        }
    }
}*/

template <class T>
void ArbolKD<T>::buscar(double x, int y, NodoKD<T> * nodo) {
    double distancia = calcularDistancia(x,y,nodo->obtenerDato().x,nodo->obtenerDato().y);
    NodoKD<T>* mejorNodo = nullptr;
    buscarR(x,y,this->raiz, distancia, &mejorNodo);
    if(mejorNodo != nullptr){
        cout << "\nES " << mejorNodo->obtenerDato() << " con distancia " << distancia << endl << endl;
    }else{
        cout << "ERROR AL ENCONTRAR" << endl;
    }
}

template <class T>
void ArbolKD<T>::buscarR(double x, int y, NodoKD<T> * nodo, double& mejorDistancia, NodoKD<T>** mejorNodo){

    double distancia;

    if (nodo != nullptr) {

        distancia = calcularDistancia(x,y,nodo->obtenerDato().x, nodo->obtenerDato().y);

        if(distancia <= mejorDistancia){
            mejorDistancia = distancia;
            *mejorNodo = nodo;
        }

        buscarR(x,y,nodo->obtenerHijoIzq(),mejorDistancia,mejorNodo);
        buscarR(x,y,nodo->obtenerHijoDer(),mejorDistancia,mejorNodo);
    }
}


template <class T>
void ArbolKD<T>::preOrden() {
    preOrdenRecursivo(this->raiz);
}

template <class T>
void ArbolKD<T>::preOrdenRecursivo(NodoKD<T>* nodo) {
    if (nodo) {
        cout << nodo->obtenerDato() << " ";
        preOrdenRecursivo(nodo->obtenerHijoIzq());
        preOrdenRecursivo(nodo->obtenerHijoDer());
    }
}

template <class T>
void ArbolKD<T>::inOrden() {
    inOrdenRecursivo(this->raiz);
    cout << endl;
}

template <class T>
void ArbolKD<T>::inOrdenRecursivo(NodoKD<T>* nodo) {
    if (nodo) {
        inOrdenRecursivo(nodo->obtenerHijoIzq());
        cout << nodo->obtenerDato() << endl;
        inOrdenRecursivo(nodo->obtenerHijoDer());
    }
}

template <class T>
void ArbolKD<T>::posOrden() {
    posOrdenRecursivo(this->raiz);
}

template <class T>
void ArbolKD<T>::posOrdenRecursivo(NodoKD<T>* nodo) {
    if (nodo) {
        posOrdenRecursivo(nodo->obtenerHijoIzq());
        posOrdenRecursivo(nodo->obtenerHijoDer());
        cout << nodo->obtenerDato() << " ";
    }
}

template <class T>
void ArbolKD<T>::nivelOrden() {
    if (!this->raiz) {
        return;
    }

    std::queue<NodoKD<T>*> cola;
    cola.push(this->raiz);

    while (!cola.empty()) {
        NodoKD<T>* nodo = cola.front();
        cola.pop();

        cout << nodo->obtenerDato() << " ";

        if (nodo->obtenerHijoIzq()) {
            cola.push(nodo->obtenerHijoIzq());
        }

        if (nodo->obtenerHijoDer()) {
            cola.push(nodo->obtenerHijoDer());
        }
    }
}
