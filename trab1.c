#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct num {
	int nums;
}nums;

typedef struct arqs {
	num* nums[2000000];
	int top;
}arq;

arq.top = 0;

num * newNum (int num) {
	num * n = (num *) malloc (sizeof(num));
	n->nums = num;
	return n;
}

void Saida (string argv[], arq * a)  {
	FILE * arq;
	arq = fopen(argv[argc-1],"w");
	fprintf (arq, "%d", a->top);
	for (int i=0; i<a->top; i++) {
		fprintf(arq, "%d"; a->nums[i]);
	}
	fclose(arq);
}

void leArq (int argc, string argv[]) {
	FILE * arq;
	int num[];
	for (int i=2; i<(argc-2); i++) {
		arq = fopen("argv[i]", "r");
		arqs  * arq = (arqs *) malloc(sizeof(arqs));
		fscanf  (argv[i], "%d", &arq->top);
		for (int x=0; x<arq->top; x++) {
			fscanf (argv[i], "%d", &num);
			arq->nums = newNum(num);
		}
	}
	fclose(arq);
}

int main (int argc, string * argv[]) {

}
