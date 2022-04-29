#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;



struct Inverso
{
    int a,n;
};


int Euclides (int a, int b);
//template <class TIPP> // Plantillas de Funcion
int Verificar(float a, int n);
void EuclidesExt(int a, int b, int*mcd, int* x, int* y);
int  EuclidesEX(int a, int b, int*mcd, int* x, int* y);
int ModJusto(int a,int n);
int VerMod(int a,int n);
void NumInverso(int a, int n);
int NumInverso2(int a);
void p_datos(Inverso *i6);


#endif