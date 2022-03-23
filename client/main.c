#include <stdio.h>
#include <stdlib.h>
#include "../include/arvore.h"

int main() 

{   
     FILE* arq = fopen("data/entrada.txt", "r");
     FILE* saida = fopen("data/saida.txt", "w");   
    if (arq == NULL)
    {
        printf("Problemas na abertura do arquivo\n");
        exit(1);
    }
    
    float resultado;
    do{
        
    Node* arvore = montaArvore(arq);
    //printaArvore(arvore);
    //printf("\n\n");     
    preOrdem(arvore);
    //emOrdem(arvore);
    //printf("\n\n");
    resultado = calculaArvore(arvore);
   
    fprintf(saida, "%.2f\n", resultado);
    //criaSaida(resultado);

    }while(!feof(arq));

    
    return 0;

}