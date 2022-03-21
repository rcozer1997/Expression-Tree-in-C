#ifndef ARVORE_H
#define ARVORE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

Node* novaArvore();

Node* criaNo(Node* dir, Node* esq, char* caracter);

Node* montaArvore(FILE* arq);

//void abreArquivo();

void leArquivo();

void printaArvore(Node* raiz);

void liberaArvore(Node* raiz);



#endif