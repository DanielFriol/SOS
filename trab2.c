#include <stdio.h>
#include <stdlib.h>
#define TAMANHOMAX 100

int main(int argc, char *argv[]){
    FILE * fp,*fo;
    int *n;
    int nt=0;
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

        n= realloc(n,(x+1)*sizeof(int));

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


    nvt=x-1;
    printf("Tamanho vetor: %d\n",nvt);
   // fo=fopen(argv[argc-1],"w");
    //for(y=0;y<nvt;y++){
     //   fprintf(fo,"%d\n",n[y]);

    //}

    free(n);

    return 0;

}

