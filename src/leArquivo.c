#include "../include/leArquivo.h"
#include "../include/arvore.h"
#include <stdio.h>
#include <stdlib.h>

void leArquivo(){

     FILE* arq = fopen("data/entrada.txt", "r");
     FILE* saida = fopen("data/saida.txt", "w"); 
     FILE* graph = fopen("data/graphviz.txt", "w");  
    if (arq == NULL)
    {
        printf("Problemas na abertura do arquivo\n");
        exit(1);
    }
    
    do{
    //int* number;
    float resultado;
    Node* arvore = montaArvore(arq);    
    resultado = calculaExpressoes(arvore);
    fprintf(graph, "strict graph {\n");
    fprintf(graph, "\n");
    preOrdem(arvore,graph);
    fprintf(saida, "%.2f\n", resultado);
    fprintf(graph, "}\n");
    fprintf(graph, "\n");
    liberaArvore(arvore);

    }while(!feof(arq));
    
    fclose(arq);
    fclose(saida);
    fclose(graph);
}   
    


