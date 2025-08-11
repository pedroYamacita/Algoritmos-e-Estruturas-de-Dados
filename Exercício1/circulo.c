#include "circulo.h"
#include "ponto.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

struct circulo_ {
    PONTO *p;
    float raio;
  };


CIRCULO* circulo_criar(PONTO *p, float raio){
    
    if(p==NULL) return NULL;
    
    //condição de existencia de um circulo
    if(raio<=0){
        return NULL;
    }

    CIRCULO* circ=(CIRCULO*)calloc(1, sizeof(CIRCULO));
    //verificar disponibilidade de memoria
    if(circ==NULL){
        exit(1);
    }
    //atribuições
    circ->p = p;
    circ->raio = raio;

    return circ;
}

void circulo_apagar(CIRCULO* circ){
    if(circ != NULL){
        ponto_apagar(circ->p);
        free(circ);
    }
}

float circulo_area(CIRCULO *circ){
    if(circ==NULL) exit(1);

    float area = 3.14 * pow(circ->raio, 2);
    return area;
}

float get_x_do_centro(CIRCULO* circ){
    if(circ==NULL || circ->p==NULL) exit(1);

    float xCentro = x_do_ponto(circ->p);
    return xCentro;
}

float get_y_do_centro(CIRCULO* circ){
    if(circ==NULL || circ->p==NULL) exit(1);
    float yCentro = y_do_ponto(circ->p);
    return yCentro;
}