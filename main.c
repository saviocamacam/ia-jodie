#include <stdio.h>
#include <stdlib.h>
#include "puzzle8.h"
#define ordem 3

void main()
{
  int menuOption;
  int vetorVerifica[ordem * ordem] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
  int ** epuzzleMascara = inicializaEpuzzle(1);
  int ** epuzzle = inicializaEpuzzle(0);
  int * distancias;
  int caminhoOtimo;
  Node * raiz;

  do
  {
    printf("(1) INFORMAR VALORES\n");
    printf("(2) IMPRIMIR PUZZLE\n");
    printf("(3) BUSCAR DISTANCIAS\n");
    printf("(4) REALIZAR BUSCA A*\n");
    printf("REALIZAR BUSCA EM PROFUNDIDADE\n");
    printf("REALIZAR BUSCA GULOSA\n");


    scanf("%d", &menuOption);

    if(menuOption == 1)
    {
      int i, j, valor, cont=0;
      for(i = 0 ; i<ordem ; i++)
      {
        for(j = 0; j<ordem ; j++)
        {
          printf("INFORME O VALOR %d DE 9\n", ++cont);
          scanf("%d", &valor);
          if(!valorJaInserido(vetorVerifica, valor) && valor >= 0 && valor < (ordem * ordem)) {
            epuzzle[i][j] = valor;
            printPuzzle(epuzzle);
          }
          else {
            cont--;
            j--;
            printf("Valor ja inserido ou invalido. Tente outro valor\n");
            printPuzzle(epuzzle);
          }
        }
      }
    }

    if(menuOption == 2) {
      printPuzzle(epuzzle);
    }

    if(menuOption == 3) {
      distancias = buscarDistancias(epuzzle, epuzzleMascara);
      printf("> FORA DO LUGAR: %d\n", distancias[0]);
      printf("> MANHATTAN: %d\n", distancias[1]);
    }

    if(menuOption == 4) {
      raiz = inicializaArvore();
      raiz->epuzzle = epuzzle;
      caminhoOtimo = astarSearch(raiz, epuzzleMascara);
    }

  } while (menuOption != 9);

}
