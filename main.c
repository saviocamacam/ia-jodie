#include <stdio.h>
#include <stdlib.h>
#include "puzzle8.h"
#define ordem 3

void main()
{
  int menuOption;
  int vetorVerifica[ordem * ordem] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
  int epuzzleMascara[ordem][ordem] = {1,2,3,4,5,6,7,8,0};
  int epuzzle[ordem][ordem] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
  int * distancias;

  do
  {
    printf("(1) INFORMAR VALORES\n");
    printf("(2) IMPRIMIR PUZZLE\n");
    printf("(3) BUSCAR DISTANCIAS\n");
    printf("REALIZAR BUSCA A*\n");
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
          }
          else {
            cont--;
            i--;
            j--;
            printf("Valor ja inserido ou invalido. Tente outro valor\n");
            printPuzzle(epuzzle);
          }
        }
      }
      printPuzzle(epuzzle);
    }

    if(menuOption == 2) {
      printPuzzle(epuzzle);
    }

    if(menuOption == 3) {
      distancias = buscarDistancias(epuzzle, epuzzleMascara);
      printf("> MANHATTAN: %d\n", distancias[0]);
      printf("> EUCLIDIANA: %d\n", distancias[1]);
      printf("> FORA DO LUGAR: %d\n", distancias[2]);
    }

    if(menuOption == 4) {

    }

  } while (menuOption != 9);

}
