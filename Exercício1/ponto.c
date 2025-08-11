#include "ponto.h"

#include <stdlib.h>
#include <stdio.h>


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

float y_do_ponto(PONTO *p){
    if(p==NULL) exit(1);
    
    return p->y;
}

float x_do_ponto(PONTO *p){
    if(p==NULL) exit(1);
   
    return p->x;
}