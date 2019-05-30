#ifndef __CIRCULO_H
#define __CIRCULO_H

typedef void *Circulo;

Circulo criaCirculo(char id[20], char corB[20], char corP[20], double raio, double x, double y, double espessura);

double retornaCX(Circulo c);

double retornaCY(Circulo c);

double retornaCR(Circulo c);

double retornaCEspessura(Circulo c);

char *retornaCID(Circulo c);

char *retornaCCorP(Circulo c);

char *retornaCCorB(Circulo c);

#endif