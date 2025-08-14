#ifndef PONTO_H

    #define PONTO_H
	#include <stdbool.h>
    #include "circulo.h"
	
    typedef struct ponto_ PONTO;
    typedef struct circulo_ CIRCULO;
    
    PONTO *ponto_criar(float x, float y);
    void ponto_apagar(PONTO *p);
    bool ponto_set(PONTO *p, float x, float y);
    
    
    //fornecer individualmente o x e y do ponto
    float y_do_ponto(PONTO *p);
    float x_do_ponto(PONTO *p);
    
    float calcular_distancia(CIRCULO* circ, PONTO* p);
    
    
    /*
    Pode ser necessário definir outras operações para o TAD.
    Se for o caso, faça e justifique!
    */
#endif





