/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   aux.h
 * Author: juanma
 *
 * Created on 23 de abril de 2019, 16:38
 */

#ifndef AUX_H
#define AUX_H

const int BLOQUE = 5;
const int TAM = 10;

struct Punto2D{
    float x;
    float y;
};

void redimensiona (int * & p, int tipo, int &cap);
void mostrar (int * & v, int &cap);
int * obtenerSegmento (const int * v, const int &util_v, int &util_v2);
double distancia (const Punto2D &p1, const Punto2D &p2);
Punto2D * menorDistancia (const Punto2D * puntos, const int &tamanio);
void limpiar (char ** &M);
void imprime (char ** &M);
void dibujarCuadrado (char ** &M, const Punto2D &p, const int &l);
char ** rotar (char ** &M);

#endif /* AUX_H */

