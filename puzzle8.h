#ifndef _PUZZLE8_H_
#define _PUZZLE8_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ordem 3

//No de puzzle
typedef struct node {
  int ** epuzzle;
  struct node * top;
  struct node * bottom;
  struct node * right;
  struct node * left;
  int g;
  int h;
} Node;

//Inicializa a arvore de busca
Node * inicializaArvore();
//Inicializa o puzzle
int ** inicializaEpuzzle(int flag);
//Imprime o 8puzzle
void printPuzzle(int ** epuzzle);
//Verifica se um valor ja foi inserido
int valorJaInserido(int * vetorVerifica, int valor);
//Busca todos os valores de heurísticas
int * buscarDistancias(int ** epuzzle, int ** mascaraEpuzzle);
//Executa a busca A*
int astarSearch(Node * raiz, int ** epuzzleMascara);
#endif
