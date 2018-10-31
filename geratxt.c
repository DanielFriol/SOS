#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(){
FILE * fp = fopen("arq5.in","w");
srand(time(NULL));
int n = rand();
int cont=0;
for(cont=0;cont<n;cont++){

    fprintf(fp,"%d\n",rand());


}

return 0;

}
