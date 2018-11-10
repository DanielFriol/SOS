#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#define TAMANHOMAX 100

typedef struct valores{
    int * vet;
    int i;
    int f;

}v;
void * chama(v * stc){
    printf("entrou");
    quick_sort(stc->vet,stc->i,stc->f);


}



void  quick_sort(int *a, int left, int right) {
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }

}

int main(int argc, char *argv[]) {
  //contador, vetor;
  int count=0, *n, tv=1,nt=0,nvt,aux=0;
  FILE * fp,*fo;
  register int x=0,y=2;


  //parâmetros errados
  if (argc<2) {
    printf("Inválido!!! Use o comando assim: %s numerodethreads arquivoentrada1 ... arquivosaida\n",argv[0]);
    exit(0);
  }

  //atribuição do numero de threads
  nt= atoi(argv[1]);

  //leitura dos arquivos de entrada
  n= calloc(TAMANHOMAX,sizeof(int));
  for(;y<=argc-2;y++){
    fp = fopen(argv[y],"r");
    for(;!feof(fp);x++){
      if(x<TAMANHOMAX*tv){
       fscanf(fp,"%d",&n[x]);
      }else{
        tv++;
        n=realloc(n,TAMANHOMAX*tv*sizeof(int));
        fscanf(fp,"%d",&n[x]);
      }
    }
  }
  n= realloc(n,(x+1)*sizeof(int));

  nvt=x-1;
   v * staux;
   staux = (v *) malloc (sizeof(v));

  //criação dos id's das threads
  pthread_t id[8];
    v v[nt];
    int cont=0;
        if(nt==1){
        v[0].vet=n;
        v[0].i=0;
        v[0].f=nvt-1;
        printf("%d %d\n",v[0].i,v[0].f);
        }else{
        int nvtd = nvt/nt ;
        float aux2 = nvt/nvtd;
        printf("%0.2f nn\n",aux2);
        v[0].i=0;
        v[0].f= nvtd;
        printf("%d %d\n",v[0].i,v[0].f);
        cont++;

        for(;cont<nt;cont++){
            if(cont==nt-1){
                v[cont].vet= n;
                v[cont].i = ((v[cont-1].f)+1);
                v[cont].f = nvt-1;
                printf("%d %d %d\n",v[cont].i,v[cont].f,cont);

            }else{
            v[cont].vet= n;
            v[cont].i= ((v[cont-1].f)+1);
            v[cont].f= ((v[cont].i)+(nvtd));
            printf("%d %d %d\n",v[cont].i,v[cont].f,cont);


            }
        }
    }

    //for(int cont=0;cont<nt;cont++){
     //quick_sort(v[cont].vet,v[cont].i,v[cont].f);

    //}




    for(int cont=0;cont<nt;cont++){
    printf("%d %d\n",nt,cont);
       pthread_create(&id[cont], NULL, chama , &v[cont]);
        }

/*

    //quick_sort(v[0].vet,v[0].i,v[0].f);
    int rc;
    for(int cont=0;cont<nt;cont++){
        if ((rc = pthread_create(&id[cont], NULL, chama , &v[cont]))) {
        printf("entrou");
      fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
      return EXIT_FAILURE;
        }
    }

    //}
*/

    for (int cont = 0; cont < nt; ++cont) {
    pthread_join(id[cont], NULL);
  }


  //abertura do arquivo de saída
  fo=fopen(argv[argc-1],"w");
  printf("%d\n",nvt);



  for (y=0; y<nvt; y++) {
    fprintf(fo, "%d\n", n[y]);
  }
  free(n);




  fclose(fo);

   printf("--------------------------------------------------------------------\n");
  printf("|                  Arquivo gerado com sucesso!!!                     |\n");
   printf("--------------------------------------------------------------------\n");

  return 0;
}
