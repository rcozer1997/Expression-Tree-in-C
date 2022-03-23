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

float calculaArvore(Node* no);

void preOrdem(Node* raiz);

//void criaSaida(float resultado);

char* retornaCaracter(Node* arv);

#endif