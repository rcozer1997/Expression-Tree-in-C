#include "../include/arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node{
  char* caracter;
  Node* dir;
  Node* esq;
};


Node* novaArvore()
{
      return NULL;    
}


Node* criaNo(Node* dir, Node* esq, char* caracter)
{   
      
        Node* raiz = (Node*)malloc(sizeof(Node));
        raiz->caracter = strdup(caracter);
        raiz->dir = dir;
        raiz->esq = esq;

          return raiz;
     
}


void printaArvore(Node* raiz){

    if(raiz != NULL){
      printf("<%s", raiz->caracter);
      printaArvore(raiz->esq);
      printaArvore(raiz->dir);
      printf(">");
    }
    else 
      printf("<>"); 
}

void liberaArvore(Node* raiz){

    if(raiz != NULL){
      liberaArvore(raiz->esq);
      liberaArvore(raiz->dir);
      free(raiz);
    }

}


   
/*void manipulaArquivo (){

    FILE* arq = fopen("data/entrada.txt", "r");

    if (arq == NULL)
    {
        printf("Problemas na abertura do arquivo\n");
        exit(1);
    }
     
}*/

Node* montaArvore(FILE* arq){
    char buffer[100];
    int i;
   buffer[0] = fgetc(arq);
    
    if (buffer[0] == '(') 
    {
       Node* no = montaArvore(arq); 
       buffer[0] = fgetc(arq);
       
        if(isspace (buffer[0]) || buffer[0] == EOF){
            //come o "caracter" de final de arquivo
            fgetc(arq);        
            return no;
        }
     buffer[1] = '\0';
      
      //come o parenteses que abre um numero
      fgetc(arq); 
      Node* dir = montaArvore(arq);
      //come o parenteses que fecha um numero
      fgetc(arq);
          return criaNo(dir, no, buffer);
      
    }
    for(i = 0; isdigit(buffer[i]); i++){

     buffer[i+1] = fgetc(arq);

    }

    //Sobrescreve o parenteses de fechamento e determina final da string
   buffer[i] = '\0';
        return criaNo(novaArvore(), novaArvore(), buffer);
    
}

//((((5)-(3))*((4)/(1)))+(10))