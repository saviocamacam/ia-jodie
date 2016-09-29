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

int valorJaInserido(int epuzzle[ordem][ordem], int valor)
{
  int i, j, flag = 0;
  for(i=0; i<ordem ; i++)
  {
    for(j=0; j<ordem ; j++)
    {
      if(epuzzle[i][j] == valor)
        flag = 1;
    }
  }
  return flag;
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
