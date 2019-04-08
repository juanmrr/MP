/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: juanma
 *
 * Created on 22 de marzo de 2019, 18:18
 */

#include <cstdlib>
#include <calculo.h>
#include <iostream>

using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {

    int M[MESES][DIAS];
    
    RellenaMatrix(M, 0, 25);
    
    mostrarMatrix(M);
    
    float promedio_abril = MediaMensualAjustada(M, 4);
    
    cout << "El promedio de abril es " << promedio_abril << endl;
    
    int **resumen = ResumenMaximaMinima(M);
    
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < MESES; j++){
            cout << resumen[i][j] << "\t";
        }
        cout << endl;
    }
    
    bool secuencia = false;
    
    secuencia = secuenciaDiasCalidos(M, 20, 3, 4);
    
    cout << "¿Hubo en abril una temperatura superior a 20º durante más de 3 días? " << secuencia;
          
}
