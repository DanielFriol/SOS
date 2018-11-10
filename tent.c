#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define TAMANHOMAX 100

int nt=0;
int count=0;

void *chama (void *v);

void quick_sort (int *a, int n);

int main(int argc, char *argv[]){
    FILE * fp,*fo;
    int *n;
    int nvt=0;
    int tv=1;
    register int x=0,y=2;

    if (argc<2)
  {
    printf("Inválido!!! Use o comando assim:   %s numerodethreads arquivoentrada1 ... arquivosaida\n",argv[0]);
    exit(0);
  }
    nt= atoi(argv[1]);
    n= calloc(TAMANHOMAX,sizeof(int));
    for(;y<=argc-2;y++){
        fp = fopen(argv[y],"r");

        for(;!feof(fp);x++){
        //while(!feof(fp)){
            if(x<TAMANHOMAX*tv){
                fscanf(fp,"%d",&n[x]);
            }else{
                tv++;
                n=realloc(n,TAMANHOMAX*tv*sizeof(int));
                fscanf(fp,"%d",&n[x]);
            }
        }
    }
   //}
    n= realloc(n,(x+1)*sizeof(int));

    nvt=x-1;

    quick_sort(n, nvt);

    printf("Tamanho vetor: %d\n",nvt);
   fo=fopen(argv[argc-1],"w");
    for(y=0;y<nvt;y++){

        fprintf(fo,"%d\n",n[y]);

    }

    free(n);

    return 0;
}

/*void *chama (void *v) {
    quick_sort(n, nvt);
}*/

void quick_sort (int *a, int n) {
    int i, j, p, t;
    if (n < 2)
        return;
    p = a[n / 2];
    for (i = 0, j = n - 1;; i++, j--) {
        while (a[i] < p)
            i++;
        while (p < a[j])
            j--;
        if (i >= j)
            break;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
        quick_sort(a, i);
        quick_sort(a + i, n - i);
}
