#include <stdio.h>
#include <stdlib.h>

#include "ponto.h"
#include "circulo.h"



int main(){
    float x, y, xCentro, yCentro, raio;
    float dist;

    scanf(" %f %f", &x, &y);
    scanf(" %f %f %f", &xCentro, &yCentro, &raio);

    PONTO* ponto = ponto_criar(x, y);
    if(ponto==NULL) return 1;
    
    PONTO* centro_do_circulo = ponto_criar(xCentro, yCentro);
    if(centro_do_circulo == NULL){
        ponto_apagar(centro_do_circulo);
        return 1;
    }

    CIRCULO* circulo = circulo_criar(centro_do_circulo, raio);
   
    if(circulo == NULL){
        ponto_apagar(centro_do_circulo);
        ponto_apagar(ponto);
        return 1;
    }
    
    dist=calcular_distancia(circulo, ponto);

    if(dist<raio){
        printf("O ponto é interior à circunferência.\nDistância: %.2f\n", dist);
    }
    else if(dist==raio){
        printf("O ponto pertence à circunferência.\nDistância: %.2f\n", dist);
    }
    else{
        printf("O ponto é exterior à circunferência.\nDistância: %.2f\n", dist);
    }
    
    circulo_apagar(circulo);
    ponto_apagar(ponto);
    
    return 0;
}