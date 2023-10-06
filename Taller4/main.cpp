#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include "ArbolKD.h"
#include "ArbolQuad.h"
#include "punto.h"
using namespace std;

template <class tree>
bool llenarArbol(tree& arbol, string fileName){
    ifstream file(fileName);
    string line, word, fruta;
    double x;
    int y;
    bool leido = false;

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
        leido = true;
    }else{
        cout << "No se pudo leer archivo" << endl;
    }
    return leido;
}

int main() {

    ArbolKD<int>arbolKD;
    ArbolQuad<int>arbolQuad;
    string nameFile;
    bool kdLeido = false;
    bool quadLeido = false;
    double x;
    int y;

    cout << "Se llenara el KD Tree y el Quad Tree con el archivo que ingrese" << endl;
    cout << "Archivo a leer: ";
    cin>>nameFile;

    cout<< "\nKDTREE--------------------------------------------------"<< std::endl;

    std::clock_t start_arbolKD = std::clock( );
    kdLeido = llenarArbol(arbolKD,nameFile);
    std::clock_t end_arbolKD = std::clock( );
    double tiempo_arbolKD = ( end_arbolKD - start_arbolKD ) / double( CLOCKS_PER_SEC );

    cout << "Tiempo de llenado Arbol KD = " << tiempo_arbolKD << "seg." << endl << endl;

    if(kdLeido){
        cout << "ARBOL KD EN RECORRIDO POR NIVELES:"<< endl;
        arbolKD.nivelOrden();
    }else{
        cout << "No se pudo leer el archivo"<< endl;
    }

    cout<< "\nQUADTREE--------------------------------------------------"<< std::endl;

    std::clock_t start_arbolQ = std::clock( );
    quadLeido = llenarArbol(arbolQuad,nameFile);
    std::clock_t end_arbolQ = std::clock( );
    double tiempo_arbolQ = ( end_arbolQ - start_arbolQ ) / double( CLOCKS_PER_SEC );

    cout << "Tiempo de llenado Quad Tree = " << tiempo_arbolQ << "seg." << endl << endl;

    if(quadLeido){
        cout << "QUAD TREE EN RECORRIDO POR NIVELES:"<< endl;
        arbolQuad.nivelOrden();
    }else{
        cout << "No se pudo leer el archivo"<< endl;
    }

    cout << "\nBUSCAR UNA FRUTA EN LOS ARBOLES";
    cout << "\nPeso:";
    cin>>x;
    cout << "Color: ";
    cin>>y;

    if(arbolKD.esVacio()){
        cout << "ARBOL KD VACIO"<< endl;
    }else{
        std::clock_t start_buscarKD = std::clock( );
        arbolKD.buscar(x, y,arbolKD.obtenerRaiz());
        std::clock_t end_buscarKD = std::clock( );
        double tiempo_buscarKD =
                ( end_buscarKD - start_buscarKD ) / double( CLOCKS_PER_SEC );
        cout << "Tiempo de buscar (" << x << " , " << y <<") en Arbol KD = " << tiempo_buscarKD << "seg." << endl << endl;
    }

    if(arbolQuad.esVacio()){
        cout << "QUAD TREE VACIO"<< endl;
    }else{
        std::clock_t start_buscarQ = std::clock( );
        arbolQuad.buscar(x, y,arbolQuad.obtenerRaiz());
        std::clock_t end_buscarQ = std::clock( );
        double tiempo_buscarQ =
                ( end_buscarQ - start_buscarQ ) / double( CLOCKS_PER_SEC );
        cout << "Tiempo de buscar (" << x << " , " << y <<") en Quad tree = " << tiempo_buscarQ << "seg." << endl << endl;
    }
    return 0;
}
