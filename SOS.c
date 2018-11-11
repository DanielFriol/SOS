#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#define TAMANHOMAX 100


//struct para passar os valores para as threads
typedef struct valores{
    int i;
    int f;

}v;

//função que recebe uma struct, que será passada para o pthread_creat e chamar o sort
void * chama(v * stc){
    quick_sort(stc->i,stc->f);


}
int *n;



//mergesorte para ordenar os blocos no final
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}



//quicksort para usar com as threads
void  quick_sort(int left, int right) {
    int i, j, x, y;

    i = left;
    j = right;
    x = n[(left + right) / 2];

    while(i <= j) {
        while(n[i] < x && i < right) {
            i++;
        }
        while(n[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = n[i];
            n[i] = n[j];
            n[j] = y;
            i++;
            j--;
        }
    }

    if(j > left) {
        quick_sort(left, j);
    }
    if(i < right) {
        quick_sort(i, right);
    }

}

int main(int argc, char *argv[]) {
    //atribuição de variáveis
    int count=0, tv=1,nt=0,nvt,aux=0;
    FILE * fp,*fo;
    register int x=0,y=2;

    //atribuição do numero de threads
    nt= atoi(argv[1]);

    //alocando o vetor de struct dinamicamente
    v* v= malloc(nt*sizeof(v));

    //verificação de parâmetros errados
    if((nt>16) || ((nt%2)>0) || (nt==10) || (nt==6) || (nt==12) || (nt==14)){
        printf("Inválido!!! Use somente 1,2,4,8 ou 16 threads");
        exit(0);

    }
    if (argc<2) {
        printf("Inválido!!! Use o comando assim: %s numerodethreads arquivoentrada1 ... arquivosaida\n",argv[0]);
        exit(0);
  }




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

    //criação dos id's das threads
    pthread_t id[nt];

    //divisão das posições do vetor para passar para as threads
    int cont=0;
        if(nt==1){
        v[0].i=0;
        v[0].f=nvt-1;
        }else{
        int nvtd = nvt/nt ;
        float aux2 = nvt/nvtd;
        v[0].i=0;
        v[0].f= nvtd;
        cont++;
        for(;cont<nt;cont++){
            if(cont==nt-1){
                v[cont].i = ((v[cont-1].f)+1);
                v[cont].f = nvt-1;

            }else
            v[cont].i= ((v[cont-1].f)+1);
            v[cont].f= ((v[cont].i)+(nvtd));

            }
        }






    //criando as threads
    int rc;
    for(int cont=0;cont<nt;cont++){
        if ((rc = pthread_create(&id[cont], NULL, chama , &v[cont]))) {
      fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
      return EXIT_FAILURE;
        }
    }


    //join das threads
    for (int cont = 0; cont < nt; ++cont) {
    pthread_join(id[cont], NULL);
  }


   //mergesort para ordenar os blocos
   if(nt==2){
        merge(n,v[0].i,v[1].i,v[1].f);



   }else{
        mergeSort(n,0,nvt-1);
    }

  //abertura do arquivo de saída
  fo=fopen(argv[argc-1],"w");



    //printando o vetor no arquivo
  for (y=0; y<nvt; y++) {
    fprintf(fo, "%d\n", n[y]);
  }




    //fechando o arquivo
        fclose(fo);

   printf("--------------------------------------------------------------------\n");
  printf("|                  Arquivo gerado com sucesso!!!                     |\n");
   printf("--------------------------------------------------------------------\n");

  return 0;
}
