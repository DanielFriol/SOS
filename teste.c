#include <stdio.h>
#include <stdlib.h>
#define TAMANHOMAX 100

int main(int argc, char *argv[])
{
  FILE *fs;
  float *num;
  int tamanhoVet=1;
  int novoTamanhoVetor;
  register int i=0;

  if (argc<2)
  { 
    fprintf(stderr,"uso:\n\t %s arquivo",argv[0]);
    exit(0);
  }

  fs = fopen(argv[1], "r");

  num = calloc(TAMANHOMAX,sizeof(float));

  while (!feof(fs))
  {
    if (i<TAMANHOMAX*tamanhoVet)
    {
        fscanf(fs,"%f", &num[i]);
        i++;
    }
    else
    {
       tamanhoVet++;
       num = realloc(num, TAMANHOMAX*tamanhoVet*sizeof(float));
       fscanf(fs,"%f", &num[i]);
       i++;
    }
  }
  
  num = realloc(num, (i-1)*sizeof(float));

  novoTamanhoVetor = i-1;

  printf("Tamanho vetor: %d\n", novoTamanhoVetor);

  for (i=0; i<novoTamanhoVetor; i++)
      printf("num[%d] = %f\n",i, num[i]);

  return 0;
}
