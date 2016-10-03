#include "puzzle8.h"
#define ordem 3

int ** inicializaEpuzzle(int flag)
{
  int ** localPuzzle = (int**) malloc(sizeof(int) * ordem);
  int i, j, count=1;
  for(i=0; i<ordem; i++)
  {
    localPuzzle[i] = (int*) malloc(sizeof(int) * ordem);
    for(j=0; j<ordem; j++)
    {
      if(flag)
        localPuzzle[i][j] = count;
      else
        localPuzzle[i][j] = -1;
      count++;
      if(count == 9)
        count = 0;
    }
  }
  return localPuzzle;
}

void printPuzzle(int **epuzzle)
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
  if(vetorVerifica[valor] == -1) {
      vetorVerifica[valor] = valor;
      return 0;
  }
  else return 1;
}

int normaliza(int valor)
{
  if(valor < 0)
  {
    valor = valor * (-1);
  }
  return valor;
}

int buscaNaMascara(int ** mascaraEpuzzle, int valor, int i, int j)
{
  int ilocal, jlocal, idiferenca=0, jdiferenca=0;
  for(ilocal=0; ilocal<ordem ; ilocal++)
  {
    for(jlocal=0; jlocal<ordem ; jlocal++)
    {
      if(mascaraEpuzzle[ilocal][jlocal] == valor)
      {
        idiferenca = i - ilocal;
        idiferenca = normaliza(idiferenca);
        jdiferenca = j - jlocal;
        jdiferenca = normaliza(jdiferenca);
        return idiferenca + jdiferenca;
      }
    }
  }
}

int * buscarDistancias(int ** epuzzle, int ** mascaraEpuzzle)
{
  int * vetorDistancias = (int*) malloc(sizeof(int) * 2);
  int i, j, foraLugar=0, manhattan=0;

  printPuzzle(epuzzle);
  printf("\n");
  printPuzzle(mascaraEpuzzle);

  for(i = 0; i< ordem ; i++)
  {
    for(j = 0; j < ordem; j++)
    {
      if(epuzzle[i][j] != mascaraEpuzzle[i][j])
      {
        foraLugar++;
        manhattan = manhattan + buscaNaMascara(mascaraEpuzzle, epuzzle[i][j], i, j);
      }
    }
  }
  vetorDistancias[0] = foraLugar;
  vetorDistancias[1] = manhattan;
  return vetorDistancias;
}

Node * inicializaArvore()
{
  Node * raiz = (Node*) malloc (sizeof(Node));
  raiz->epuzzle = NULL;
  raiz->top = NULL;
  raiz->bottom = NULL;
  raiz->right = NULL;
  raiz->left = NULL;
  raiz->g = 0;
  raiz->h = 0;
  return raiz;
}

int * buscaPosicaoVazia(int ** epuzzle)
{
  int * posicaoVazia = (int*) malloc (sizeof(int) * 2);
  int i, j;
  for(i=0; i<ordem; i++)
  {
    for(j=0; j<ordem; j++)
    {
      if(epuzzle[i][j] == 0)
      {
        posicaoVazia[0] = i;
        posicaoVazia[1] = j;
        return posicaoVazia;
      }
    }
  }
  return NULL;
}

int ** copiaEpuzzle(int ** epuzzle)
{
  int ** epuzzleCopiado = inicializaEpuzzle(0);
  int i, j;
  for(i=0; i<ordem; i++)
  {
    for(j=0; j<ordem; j++)
    {
      epuzzleCopiado[i][j] = epuzzle[i][j];
    }
  }
  return epuzzleCopiado;
}

int ** movePeca(Node * node, int * posicaoVazia, int sentido)
{
  int ** epuzzleModificado;
  int valor;
  epuzzleModificado = copiaEpuzzle(node->epuzzle);

  if(sentido == 0)
  {
    epuzzleModificado[posicaoVazia[0]][posicaoVazia[1]] = node->epuzzle[posicaoVazia[0]-1][posicaoVazia[1]];
    epuzzleModificado[posicaoVazia[0]-1][posicaoVazia[1]] = 0;
  }
  if(sentido == 1)
  {
    epuzzleModificado[posicaoVazia[0]][posicaoVazia[1]] = node->epuzzle[posicaoVazia[0]+1][posicaoVazia[1]];
    epuzzleModificado[posicaoVazia[0]+1][posicaoVazia[1]] = 0;
  }
  if(sentido == 2)
  {
    printf(">>> fala comigo crianca 1\n");
    epuzzleModificado[posicaoVazia[0]][posicaoVazia[1]] = node->epuzzle[posicaoVazia[0]][posicaoVazia[1]+1];
    epuzzleModificado[posicaoVazia[0]-1][posicaoVazia[1]+1] = 0;
  }
  if(sentido == 3)
  {
    epuzzleModificado[posicaoVazia[0]][posicaoVazia[1]] = node->epuzzle[posicaoVazia[0]][posicaoVazia[1]-1];
    epuzzleModificado[posicaoVazia[0]][posicaoVazia[1]-1] = 0;
  }
  return epuzzleModificado;
}

void calculaFn(Node * node, int ** epuzzleMascara, int heuristica)
{
  int * vetorDistancias = buscarDistancias(node->epuzzle, epuzzleMascara);

}

int astarSearch(Node * raiz, int ** epuzzleMascara)
{
  int * vetorDistancias = buscarDistancias(raiz->epuzzle, epuzzleMascara);
  if(vetorDistancias[0] != 0)
  {
    int * posicaoVazia = buscaPosicaoVazia(raiz->epuzzle);
    printf("posicao vazia i: %d\n", posicaoVazia[0]);
    printf("posicao vazia j: %d\n", posicaoVazia[1]);

    if(posicaoVazia[0] - 1 >= 0)
    {
      raiz->top = inicializaArvore();
      raiz->top->epuzzle = movePeca(raiz, posicaoVazia, 0);
      calculaFn(raiz->top, epuzzleMascara, 1);
      printf("TOP:\n");
      printPuzzle(raiz->top->epuzzle);
    }
    if(posicaoVazia[0] + 1 < ordem)
    {
      raiz->bottom = inicializaArvore();
      raiz->bottom->epuzzle = movePeca(raiz, posicaoVazia, 1);
      calculaFn(raiz->bottom, epuzzleMascara, 1);
      printf("BOTTOM:\n");
      printPuzzle(raiz->bottom->epuzzle);
    }
    if(posicaoVazia[1] + 1 < ordem)
    {
      raiz->right = inicializaArvore();
      raiz->right->epuzzle = movePeca(raiz, posicaoVazia, 2);
      calculaFn(raiz->right, epuzzleMascara, 1
      printf("RIGHT:\n");
      printPuzzle(raiz->right->epuzzle);
    }
    if(posicaoVazia[1] - 1 >= 0)
    {
      raiz->left = inicializaArvore();
      raiz->left->epuzzle = movePeca(raiz, posicaoVazia, 3);
      calculaFn(raiz->left, epuzzleMascara, 1);
      printf("LEFT:\n");
      printPuzzle(raiz->left->epuzzle);
    }
  }
  else {
    return 1;
  }
  return 0;
}
