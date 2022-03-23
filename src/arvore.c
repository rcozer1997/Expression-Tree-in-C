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
            //caso seja linux, REMOVER este fgetc
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



void preOrdem(Node* raiz){

  if(raiz != NULL){
    //printf("%s\t", raiz->caracter);
    preOrdem(raiz->dir);
    preOrdem(raiz->esq);

  }

}


float calculaArvore(Node* no)
{   
    
    char* c = retornaCaracter(no);
    if(no != NULL) 
    {
  if(no->dir == NULL && no->esq == NULL){
      //entao é numero
       return atoi(c);
       
      }
    
    int subArvEsq = calculaArvore(no->esq);
    int subArvDir = calculaArvore(no->dir);
    
    if(retornaCaracter(no)[0] == '+'){
      return (subArvEsq + subArvDir);
    }
    if(retornaCaracter(no)[0] == '-'){
      return (subArvEsq - subArvDir);
    }
    if(retornaCaracter(no)[0] == '/'){
      return (subArvEsq / subArvDir);
    }
    if(retornaCaracter(no)[0] == '*'){
      return (subArvEsq * subArvDir);
    }

    }

} 

/*void criaSaida(float resultado){
    FILE* saidas = fopen("data/saida.txt", "w");
   
    fprintf(saidas, "%.2f\n", resultado);

    //free(aux);
    fclose(saidas);

}*/

char* retornaCaracter(Node* arv){

    if(arv != NULL)
    {
      return arv->caracter;
    }



}