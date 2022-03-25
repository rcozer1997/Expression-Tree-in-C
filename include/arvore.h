#ifndef ARVORE_H
#define ARVORE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

/**
 * @brief cria uma nova arvore vazia
 * @return uma nova arvore vazia 
 */
Node* novaArvore();

/**
 * @brief cria um novo nó dentro da arvore 
 * @param dir - nó filho direito do nó pai em questão
 * @param esq - nó filho esquerdo do nó pai em questão
 * @param caracter - caracter armazenado dentro do nó 
 * @return 
 */
Node* criaNo(Node* dir, Node* esq, char* caracter);

/**
 * @brief monta a arvore de expressões, fazendo tratamento do arquivo de entrada
 * @param arq - arquivo de entrada já aberto
 * @return a arvore de uma expressao aritmetica devidamente montada
 */
Node* montaArvore(FILE* arq);

/**
 * @brief libera a memoria alocada para a arvore
 * @param arv - struct da arvore alocada
 */
void liberaArvore(Node* arv);

/**
 * @brief recupera a expressao alocada na arvore, a fim de calcular seu resultado
 * @param no - Um nó da arvore a ser analisado 
 * @return o valor da expressão devidamente calculada (em float, com 2 casas de precisão)
 */
float calculaExpressoes(Node* no);

/**
 * @brief retorna o caracter alocado em um no
 * @param no - O nó de uma arvore a ser analisado 
 * @return o caracter armazenado no nó, caso este não seja nulo
 */
char* retornaCaracter(Node* no);

/**
 * @brief ordena e printa a arvore no formato "em ordem" no arquivo graphviz.txt
 * @param arv - A arvore a ser ordenada
 * @param graph - arquivo graphviz ja aberto
 */
void emOrdem(Node* arv, FILE* graph);

//int quantNodes(Node* arv);

/**
 * @brief confere os operadores dos nós de uma arvore de expressoes devidamente montada
 * @param no - O nó de uma arvore a ser analisado 
 * @param subArvEsq - o valor numérico, em float, de uma sub arvore esquerda
 * @param subArvDir - o valor numerico, em float, de uma sub arvore direita
 * @return retorna o resultado, em float, de acordo com o operando encontrado no nó pai
 */
float confereOperadores(Node* no, float subArvEsq, float subArvDir);

#endif