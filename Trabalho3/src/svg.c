#include "svg.h"
#include <stdio.h>
#include <stdlib.h>

void iniciaSvg(char arq[])
{
    FILE *arqout;
    
    arqout = fopen(arq, "w");
    if (arqout == NULL){ 
        printf("Nao foi possivel Abrir o arquivo svg");
        exit(1);
    }
    
    fprintf(arqout, "<svg>");
    
    fclose(arqout);
}

void finalizaSvg(char arq[])
{
	FILE* arqout;
	
    arqout = fopen(arq, "a");
     if (arqout == NULL){
        printf("Nao foi possivel Abrir o arquivo geo");
        exit(1);
    }
    
    fprintf(arqout, "\n</svg>");
    
    fclose(arqout);
}

void printaCirculo(double raio, double x, double y, char corB[], char corP[], char svg[], double espessura){
    FILE *arq;
    
    arq = fopen(svg, "a");
    if (arq == NULL){
        printf("Erro ao abrir o arquivo de saida");
        exit(1);
	}
	
	fprintf(arq, "\n\t<circle cx=\"%f\" cy=\"%f\" r=\"%f\" stroke=\"%s\" fill=\"%s\" stroke-width=\"%f\" fill-oppacity=\"0.5\" stroke-oppacity=\"0.7\" />", x, y, raio, corB, corP, espessura);
	
    fclose(arq);
}

void printaRetangulo(double largura, double altura, double x, double y, char corB[], char corP[], char svg[], double espessura){
    FILE *arq;
    
    arq = fopen(svg, "a");
    if (arq == NULL){
        printf("Erro ao abrir o arquivo de saida");
        exit(1);
	}
	
	fprintf(arq, "\n\t<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" style=\"fill:%s;stroke:%s;stroke-width:%f;fill-oppacity:0.5;stroke-oppacity:0.7\" />", x, y, largura, altura, corP, corB, espessura);
	
    fclose(arq);
}

void criaElipse(char svg[], double cx, double cy, double rx, double ry, char corP[], char corB[], double espessura)
{
    FILE *arq;
    
    arq = fopen(svg, "a");
    if (arq == NULL){
        printf("Erro ao abrir o arquivo de saida");
        exit(1);
	}

    fprintf(arq, "\n\t<ellipse cx=\"%f\" cy=\"%f\" rx=\"%f\" ry=\"%f\" style=\"fill:%s;stroke:%s;stroke-width:%f;fill-oppacity:0.5;stroke-oppacity:0.7\" />", cx, cy, rx, ry, corP, corB, espessura);

    fclose(arq);
}

void escreveSvg(float x, float y, char texto[], char svg[])
{
    FILE *arq;
    
    arq = fopen(svg, "a+");
    fprintf(arq, "\n\t<text x=\"%f\" y=\"%f\" fill=\"black\">%s</text>", x, y, texto);
    fclose(arq);
}

void criaLinha(float x1, float y1, float x2, float y2, char cor[], char svg[])
{
    FILE *arq;
    
    arq = fopen(svg, "a");
    if (arq == NULL){
        printf("Erro ao abrir o arquivo de saida");
        exit(1);
	}

	fprintf(arq, "\n\t<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" style=\"stroke:%s\" />", x1, y1, x2, y2, cor);

    fclose(arq);
}

void escreveDistancia(float x1, float y1, float x2, float y2, float distancia, char svg[])
{
    FILE *arq;
    
    arq = fopen(svg, "a");

    if(x1>=x2 && y1>=y2){
        fprintf(arq, "\n\t<text x=\"%f\" y=\"%f\" fill=\"black\">%f</text>", x2+((x1-x2)/2), y2+((y1-y2)/2), distancia);    
    } else if(x1<=x2 && y1>=y2) {
        fprintf(arq, "\n\t<text x=\"%f\" y=\"%f\" fill=\"black\">%f</text>", x1+((x2-x1)/2), y2+((y1-y2)/2), distancia);
    } else if(x1>=x2 && y1<=y2){
        fprintf(arq, "\n\t<text x=\"%f\" y=\"%f\" fill=\"black\">%f</text>", x2+((x1-x2)/2), y1+((y2-y1)/2), distancia);
    } else if(x1<=x2 && y1<=y2) {
        fprintf(arq, "\n\t<text x=\"%f\" y=\"%f\" fill=\"black\">%f</text>", x1+((x2-x1)/2), y1+((y2-y1)/2), distancia);
    }

    fclose(arq);
}