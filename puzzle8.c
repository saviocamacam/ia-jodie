#include "puzzle8.h"
#define ordem 3

void printPuzzle(int epuzzle[ordem][ordem])
{
  int i, j;
  for(i = 0; i < ordem; i++)
  {
    for(j = 0; j < ordem; j++)
    {
      printf("%d\t", epuzzle[i][j]);
    }
    printf("\n\n");
  }
}

int valorJaInserido(int * vetorVerifica, int valor)
{
  printf("vetor: %d\n", vetorVerifica[valor]);
  if(vetorVerifica[valor] == valor)
    return 1;
  else return 0;
}

int * buscarDistancias(int epuzzle[ordem][ordem], int mascaraEpuzzle[ordem][ordem])
{
  int * vetorDistancias = (int*) malloc(sizeof(int) * 3);
  int i, j, foraLugar=0;
  for(i = 0; i< ordem ; i++)
  {
    for(j = 0; j < ordem; j++)
    {
      if(epuzzle[i][j] == mascaraEpuzzle[i][j])
        foraLugar++;
    }
  }

  return vetorDistancias;
}
