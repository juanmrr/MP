/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdint>
#include <iostream>
#include "aux.h"
#include <cmath>

void redimensiona (int * & p, int tipo, int &cap){
    
    int old_cap = cap;
    
    switch(tipo){
        case 1: 
            cap = cap+1;
            break;
        case 2:
            cap = cap + BLOQUE;
            break;
        case 3:
            cap = cap * 2;
        default:
            std::cout << "Opción inválida" << std::endl;
    }
    
    int * aux = new int[cap];
    
    for (int i = 0; i < old_cap; i++)
        aux[i] = p[i];
    
    delete [] p;
    
    p = aux;
    
}

void mostrar (int * & v, int &cap){
    
    for (int i = 0; i < cap; i++)
        std::cout << v[i] << " ";
    
    std::cout << std::endl;
    
}

int * obtenerSegmento (const int * v, const int &util_v, int &util_v2){
    
    int * aux;
    
    for (int i = 0; i < util_v; i++){
        if (v[i] % 2){
            redimensiona(aux, 1, util_v2);
            aux[util_v2 - 1] = i;
        }
    }
    
    return aux;
    
}

double distancia (const Punto2D &p1, const Punto2D &p2){
    
    double distancia;
    
    distancia = sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
    
    return distancia;
    
}

Punto2D * menorDistancia (const Punto2D * puntos, const int &tamanio){
    
    Punto2D * p = new Punto2D[2];
    
    double min = distancia(puntos[0], puntos[1]);;
    double dist;
    
    for (int i = 0; i < tamanio; i++){
        for (int j = i; j < tamanio; j++){
            if (i != j){
                dist = distancia(puntos[i], puntos[j]);
                if (dist < min){
                    min = dist;
                    p[0] = puntos[i];
                    p[1] = puntos[j];
                }
            }
        }
    }
    
    return p;
    
}

void limpiar (char ** &M){
    
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++){
            M[i][j] = '.';
        }
    
}

void imprime (char ** &M){
    
    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            std::cout << M[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void dibujarCuadrado (char ** &M, const Punto2D &p, const int &l){
    
    for (int i = p.y; i < p.y + l; i++)
        for (int j = p.x; j < p.x + l; j++)
            M[i][j] = '*';
    
}

char ** rotar (char ** &M){
    
    char **aux = new char *[TAM];
    for (int i = 0; i < TAM; i++)
        aux[i] = new char[TAM];
        
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            aux[i][j] = M[j][i];
    
    return aux;
    
}