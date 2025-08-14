#include "ponto.h"
#include "circulo.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct ponto_ {
    float x;
    float y;
  };

PONTO* ponto_criar(float x, float y){
    PONTO* ponto;
    //verificação de disponibilidade de espaço na memoria
    if((ponto=(PONTO*)calloc(1, sizeof(PONTO)))==NULL){
        exit(1);
    }
    //atribuições
    ponto->x=x;
    ponto->y=y;
    
    return ponto;
}

void ponto_apagar(PONTO *p){
    if(p != NULL){
        free(p);
    }
}
/*bool ponto_set(PONTO *p, float x, float y){
    p->x=x;
    p->y=y;
    return
}*/
float y_do_ponto(PONTO *p){
    if(p==NULL) exit(1);
    
    return p->y;
}

float x_do_ponto(PONTO *p){
    if(p==NULL) exit(1);
   
    return p->x;
}

float calcular_distancia(CIRCULO* circ, PONTO* p){
    if(circ==NULL || p==NULL) exit(1);
    float deltaX, deltaY, dist;
    PONTO* centro_do_circulo = get_centro(circ);

    deltaX = centro_do_circulo->x - p->x;
    deltaY = centro_do_circulo->y - p->y;

    dist=sqrt((deltaX * deltaX) + (deltaY * deltaY));
    
    
    return dist;
}