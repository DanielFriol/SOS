#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define TAMANHOMAX 100

int part = 0;
int nt=0, count=0, nvt=0;

typedef struct vetor {
    int *a;
}v;

void *bubbleSort(void *veto) {
        v *vet = veto;
	int i, j, temp;
        int thread_part = part++;

     for (int w = thread_part * (nvt / nt); w < (thread_part + 1) * (nvt / nt); w++) {
	for (i = 0; i < nvt - 1; i++){
             for (j = (i+1); j < nvt; j++){
                  if (vet->a[j] < vet->a[i]){
                       temp = vet->a[i];
                       vet->a[i] = vet->a[j];
                       vet->a[j] = temp;
                  }
              }
        }
     }

}

int main(int argc, char *argv[]){
    FILE * fp,*fo;
    int *n;
    int tv=1;
    register int x=0,y=2;
    v *ve;

    pthread_t id[nt];

    if (argc<2)
    {
    printf("Inválido!!! Use o comando assim:   %s numerodethreads arquivoentrada1 ... arquivosaida\n",argv[0]);
    exit(0);
    }
    nt= atoi(argv[1]);
    ve->a= calloc(TAMANHOMAX,sizeof(int));
    for(;y<=argc-2;y++){
        fp = fopen(argv[y],"r");

        for(;!feof(fp);x++){
        //while(!feof(fp)){
            if(x<TAMANHOMAX*tv){
                fscanf(fp,"%d",&ve->a[x]);
            }else{
                tv++;
                ve->a=realloc(ve->a,TAMANHOMAX*tv*sizeof(int));
                fscanf(fp,"%d",&ve->a[x]);
            }
        }
    }
    //}
    ve->a= realloc(n,(x+1)*sizeof(int));
    
    nvt=x-1;

    for (int i = 0; i < nt; i++) {
        pthread_create(&id[i], NULL, bubbleSort, (void *)ve); 
    }

    for (int j = 0; j < nt; j++) {
        pthread_join(id[j], NULL);
    }


    printf("Tamanho vetor: %d\n",nvt);
    fo=fopen(argv[argc-1],"w");
    for(y=0;y<nvt;y++){

        fprintf(fo,"%d\n",ve->a[y]);

    }

    free(ve->a);

    return 0;
}
