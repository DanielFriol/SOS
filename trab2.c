#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define TAMANHOMAX 100

int nt=0;
int count=0;
pthread_t id;

typedef struct dados {
    int a;
    int n;
}d;

void quick_sort (void * v) {
    int i, j, p, t;
    if (v->n < 2)
        return;
    p = v->a[d.tam / 2];
    for (i = 0, j = v->n - 1;; i++, j--) {
        while (v->a[i] < p)
            i++;
        while (p < v->a[j])
            j--;
        if (i >= j)
            break;
        t = v->a[i];
        v->a[i] = v->a[j];
        v->a[j] = t;
    }
    if (count<nt) {
        pthread_create(&id, NULL, quick_sort, (void*)d);
        count++;
    }
    else {
        quick_sort(v->a, i);
        quick_sort(v->a + i, n - i);
    }

}

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

    d.n = n;
    d.tam=nvt;
    quick_sort((void *)d);

    printf("Tamanho vetor: %d\n",nvt);
   fo=fopen(argv[argc-1],"w");
    for(y=0;y<nvt;y++){

        fprintf(fo,"%d\n",n[y]);

    }

    free(n);

    return 0;

}

