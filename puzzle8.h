#ifndef _PUZZLE8_H_
#define _PUZZLE8_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ordem 3

//Funcao que imprime o 8puzzle
void printPuzzle(int epuzzle[ordem][ordem]);
//Verifica se um valor ja foi inserido
int valorJaInserido(int * vetorVerifica, int valor);

int * buscarDistancias(int epuzzle[ordem][ordem], int mascaraEpuzzle[ordem][ordem]);
#endif
