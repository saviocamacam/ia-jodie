#include <stdio.h>
#define ordem 3

void print(int epuzzle[ordem][ordem])
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

void main() {
  int epuzzleMascara[ordem][ordem] = {1,2,3,4,5,6,7,8,0};
  print(epuzzleMascara);
}
