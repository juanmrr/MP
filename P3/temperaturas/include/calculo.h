/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   temperatura.h
 * Author: juanma
 *
 * Created on 22 de marzo de 2019, 18:20
 */

#ifndef TEMPERATURA_H
#define TEMPERATURA_H

static const int MESES = 12;
static const int DIAS = 31;

void ObtenerMaximoMinimo(int M[][DIAS]);
void RellenaMatrix(int M[][DIAS], int min, int max);
void mostrarMatrix(int M[][DIAS]);
int ** ResumenMaximaMinima(int M[][DIAS]);
int minimoMes(int M[][DIAS], int mes);
int maximoMes(int M[][DIAS], int mes);
float MediaMensualAjustada(int M[][DIAS], int mes);
bool secuenciaDiasCalidos(int M[][DIAS], int t, int d, int m);

#endif /* TEMPERATURA_H */

