/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <calculo.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void RellenaMatrix(int M[][DIAS], int min, int max){
    
    int num_valores = max - min + 1;
	int i,j;
	time_t t;
        
	srand ((int) time(&t));
	
	// relleno la matriz con valores aleatorios
	for(i = 0; i < MESES; i++)
		for(j = 0; j < DIAS; j++)
			M[i][j] = (rand() % num_valores) + min;

}

void mostrarMatrix(int M[][DIAS]){
    
    for(int i = 0; i < MESES; i++){
        for(int j = 0; j < DIAS; j++){
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
    
}

int maximoMes(int M[][DIAS], int mes){
    
    int maximo = -100;
    
    for(int i = 0; i < DIAS; i++){
        if (maximo < M[mes][i])
            maximo = i;
    }
    
    return maximo;
    
}

int minimoMes(int M[][DIAS], int mes){
    
    int minimo = 100;
    
    for(int i = 0; i < DIAS; i++){
        if (minimo > M[mes][i])
            minimo = i;
    }
    
    return minimo;
    
}

int ** ResumenMaximaMinima(int M[][DIAS]){
    
    int **resumen = new int*[2];
    for (int i = 0; i < 2; i++)
        resumen[i] = new int[MESES];
    
    for (int j = 0; j < 2; j++){
        for (int i = 0; i < MESES; i++){
            if (j%2){
                resumen[j][i] = M[i][minimoMes(M, i)];
            }else{
                resumen[j][i] = M[i][maximoMes(M, i)];
            }
        }
    }
    
    return resumen;
    
}

float MediaMensualAjustada(int M[][DIAS], int mes){
    
    float promedio;
    int acumulado = 0;
    
    int maximo = maximoMes(M, mes);
    int minimo = minimoMes(M, mes);
    
    for (int i = 0; i < DIAS; i++){
        if (i != maximo && i != minimo){
            acumulado = acumulado + i;
        }
    }
    
    promedio = acumulado/29.0;
    
    return promedio;
    
}

bool secuenciaDiasCalidos(int M[][DIAS], int t, int d, int mes){
    
    bool secuencia = false;
    int duracion = 0;
    int i = 0;
    
    while(i < DIAS && !secuencia){
        if (M[mes][i] > t){
            duracion = duracion + 1;
            if (duracion >= d)
                secuencia = true;
        }else
            duracion = 0;
        i++;
    }
    
    return secuencia;
    
}