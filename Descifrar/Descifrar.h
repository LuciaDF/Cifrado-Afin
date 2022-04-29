#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdio.h>
#include <iostream>

#include <string.h>

using namespace std;

void ConvertirNum(char a[56], int a2[56]);

int BusquedaNum(char x);

int Euclides (int a, int b);

int VerInverso(int a, int n);

void PosiblesA(int a3[], int s);

char DescifrarNum(int a1, int b, int y);
void EuclidesExt(int a, int b, int*mcd, int* x, int* y);
int  EuclidesEX(int a, int b, int*mcd, int* x, int* y);

int ModJusto(int a1);

int NumInverso(int a1);

char BusquedaLet(int x);

char DescifrarNum(int a, int b, int y);

void Llenar3D(char m[27][18][56],int nc[], int a1[], int b[]);

void Imprimir3D(char m[27][18][56]);

void p_datos();

#endif