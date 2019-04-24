/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: juanma
 *
 * Created on 23 de abril de 2019, 16:19
 */

#include <cstdlib>
#include "aux.h"
#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */

const int CENTINELA = 0;

int main(int argc, char** argv) {
    
    int * v = new int[TAM];
    int util_v = TAM;
    int util_v2 = 0;
    
    int entrada;
    int i = 0;
    
    do{
        cout << "introduzca un valor entero (0 para terminar)" << endl;
        cin >> entrada;
        if (i == util_v){
            do {
                cout << "No hay espacio en el array. Redimensione: 1-> una casilla 2-> un bloque 3-> duplicar" << endl;
                cin >> entrada;
            }while (entrada > 3 || entrada < 1);
            
            redimensiona(v, entrada, util_v);
            cout << "El array ha sido redimensionado" << endl;
        }
        else {
            v[i] = entrada;
            i++;
        }
        mostrar(v, util_v);
    }while (entrada != CENTINELA);
    
    int * v2;
    
    v2 = obtenerSegmento(v, util_v, util_v2);
    
    mostrar(v2, util_v2);
    
    delete [] v;
    delete [] v2;
    
    Punto2D * puntos;
    int contador = 0;
    int tamanio;
    
    ifstream leer;
    
    leer.open(argv[1], ios::in);
    if(leer.is_open()){
        leer >> tamanio;
        puntos = new Punto2D[tamanio];
        while (!leer.eof()){
            leer >> puntos[contador].x;
            leer >> puntos[contador].y;
            contador++;
            if (leer.eof())
                break;
        }
        leer.close();
    }
    
    double dist;
    Punto2D * min;
    
    min = menorDistancia(puntos, tamanio);
    dist = distancia(min[0], min[1]);
    
    cout << "La distancia mínima es entre el punto " << min[0].x << "," << min[0].y << " y " << min[1].x << "," << min[1].y << " y es: " << dist << endl;

    delete [] puntos;
    delete min;
    
    char ** M = new char *[TAM];
    for (int i = 0; i < TAM; i++)
        M[i] = new char[TAM];
    
    limpiar (M);
    imprime (M);
    
    Punto2D p = {1.0, 3.0};
    
    cout << "Dibujamos un cuadrado de lado 3" << endl;
    
    dibujarCuadrado (M, p, 3);
    imprime (M);
    
    cout << "Rotamos el cuadrado" << endl;
    
    char ** M2;
    
    M2 = rotar (M);
    imprime (M2);
    
    for (int i = 0; i < TAM; i++){
        delete [] M[i];
        delete [] M2[i];
    }
    delete [] M;
    delete [] M2;
    
   
    
    return 0;
}

