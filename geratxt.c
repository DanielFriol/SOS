#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>


int main(){
FILE * fp = fopen("arq1.in","w");
srand(time(NULL));
int n = rand();

int cont=0;
for(cont=0;cont<n;cont++){
    srand(time(NULL));
    fprintf(fp,"%d",rand());


}


}
