#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHOMAX 1000

typedef struct num {
	int nums;
}nums;

typedef struct arqs {
	nums * nu[200];
	int top;
}arq;

nums * newNum (int num) {
	nums * n = (nums *) malloc (sizeof(nums));
	n->nums = num;
	return n;
} 

void Saida (int argc, char * argv[], arq * a)  {
	FILE * fp;
	fp = fopen(argv[argc],"w");
	fprintf (fp, "%d", a->top);
	int i;
	for (i=0; i<a->top; i++) {
		fprintf(fp, "%d", a->nu[i]);
	}
	fclose(fp);
}

void leArq (int argc, char *  argv[]) {
	FILE * fp;
	int * num;
	int i, x;

        num = calloc(TAMANHOMAX,sizeof(int));

	for (i=1; i<(argc-1); i++) {
		fp = fopen(argv[i], "r");
		arq  * a = (arq *) malloc(sizeof(arq));
		fscanf  (fp, "%d", &a->top);
		for (x=0; x<a->top; x++) {
			fscanf (fp, "%d", &num[x]);
			a->nu[x] = newNum(num[x]);
                        a->top++;
		}
                Saida (argc, argv, a);
                //free(a);
	}
	fclose(fp);
}

int main (int argc, char * argv[]) {
	int numarq=0;
        char * arquis[100];
        for (int i=1; i < (argc-1); i++) {
                strcpy(arquis[numarq], argv[i]);
                numarq++;
        }

        leArq (numarq, arquis);
        
}
