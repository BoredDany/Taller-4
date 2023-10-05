#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include "ArbolKD.h"
#include "punto.h"
using namespace std;

template <class tree>
void llenarArbol(tree& arbol, string fileName){
    ifstream file(fileName);
    string line, word, fruta;
    double x;
    int y;

    if(file.is_open()){
        while(getline(file,line)){
            stringstream str (line);
            str>>fruta;
            str>>x;
            str>>y;
            punto p;
            p.dato = fruta;
            p.x = x;
            p.y = y;
            arbol.insertar(p);
        }
    }else{
        cout << "No se pudo leer archivo";
    }
}

template <class tree>
void buscar(double x, int y, tree arbol){
    string frtuta;
    arbol.buscar(x, y);
}

int main() {
    ArbolKD<int>arbolKD;
    string nameFile;
    cout << "Archivo a leer: ";
    cin>>nameFile;


    cout<< "\nKD--------------------------------------------------"<< std::endl;
    std::clock_t start_arbolKD = std::clock( );
    llenarArbol(arbolKD,nameFile);
    std::clock_t end_arbolKD = std::clock( );
    double tiempo_arbolKD =
            ( end_arbolKD - start_arbolKD ) / double( CLOCKS_PER_SEC );

    cout << "Tiempo de llenado Arbol KD = " << tiempo_arbolKD << "seg." << endl << endl;
    cout << "ARBOL KD EN RECORRIDO POR NIVELES:"<< endl;
    arbolKD.nivelOrden();
    cout << endl;

    double x;
    int y;
    cout << "BUSCAR UNA FRUTA";
    cout << "Peso:";
    cin>>x;
    cout << "Color: ";
    cin>>y;


    std::clock_t start_buscarKD = std::clock( );
    buscar(x,y,arbolKD);
    std::clock_t end_buscarKD = std::clock( );
    double tiempo_buscarKD =
            ( end_buscarKD - start_buscarKD ) / double( CLOCKS_PER_SEC );
    //cout << "ENCONTRADO: " << fruta << endl;
    cout << "Tiempo de buscar Arbol KD = " << tiempo_buscarKD << "seg." << endl << endl;


    return 0;
}
