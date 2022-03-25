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


void liberaArvore(Node* arv){

    if(arv != NULL){
      liberaArvore(arv->esq);
      liberaArvore(arv->dir);
      free(arv);
    }

}


Node* montaArvore(FILE* arq){
    char buffer[1000];
    int i;
   buffer[0] = fgetc(arq);
    
    if (buffer[0] == '(') 
    {
       Node* no = montaArvore(arq); 
       buffer[0] = fgetc(arq);
       
        if(isspace (buffer[0]) || buffer[0] == EOF){
            //come o "caracter" de final de arquivo
            //caso seja linux, REMOVER este fgetc
            //fgetc(arq);        
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

float calculaExpressoes(Node* no)
{   
    float resultado;
    char* c = retornaCaracter(no);
    if(no != NULL) 
    {
  if(no->dir == NULL && no->esq == NULL){
      //entao é numero
       return atoi(c);
       
      }  
    float subArvEsq = calculaExpressoes(no->esq);
    float subArvDir = calculaExpressoes(no->dir);

      resultado = confereOperadores(no, subArvEsq, subArvDir);
      return resultado;
    }

} 

float confereOperadores(Node* no, float subArvEsq, float subArvDir){

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

char* retornaCaracter(Node* no){

    if(no != NULL)
    {
      return no->caracter;
    }
}

void emOrdem(Node* arv, FILE* graph)
{
   //number = number + 1;
   int i;
 if(arv!=NULL)
 {
  emOrdem(arv->esq, graph);  
  fprintf(graph, "no[label = %s];\n no--no\n",arv->caracter);
  emOrdem(arv->dir, graph);
 }
 
}
/*
int quantNodes(Node* arv){
  if (arv!= NULL){
    return 1 + quantNodes(arv->esq) + quantNodes(arv->dir);
  }

}*/