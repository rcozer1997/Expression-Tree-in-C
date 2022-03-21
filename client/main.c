#include <stdio.h>
#include <stdlib.h>
#include "../include/arvore.h"
#include "../include/leArquivo.h"

int main() 

{   
     FILE* arq = fopen("data/entrada.txt", "r");

    if (arq == NULL)
    {
        printf("Problemas na abertura do arquivo\n");
        exit(1);
    }

    Node* arvore = montaArvore(arq);
    printaArvore(arvore);     
   

    
    
    return 0;

}