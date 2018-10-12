#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct num {
	int nums;
}nums;

typedef struct arqs {
<<<<<<< HEAD
	nums * nums[200];
=======
	num* nums[2000000];
>>>>>>> 4572dadbeb0b3d3c629f8c4cf893e20f5f80b092
	int top;
}arq;

nums * newNum (int num) {
	nums * n = (nums *) malloc (sizeof(nums));
	n->nums = num;
	return n;
}

void Saida (char * argv[], int argc, arq * a)  {
	FILE * fp;
	fp = fopen(argv[argc-1],"w");
	fprintf (fp, "%d", a->top);
	int i;
	for (i=0; i<a->top; i++) {
		fprintf(fp, "%d", a->nums[i]);
	}
	fclose(fp);
}

void leArq (int argc, char argv[]) {
	FILE * fp;
	int num[200];
	int i, x;
	for (i=2; i<(argc-2); i++) {
		fp = fopen("argv[i]", "r");
		arq  * a = (arq *) malloc(sizeof(arq));
		fscanf  (argv[i], "%d", &a->top);
		for (x=0; x<a->top; x++) {
			fscanf (argv[i], "%d", &num);
			a->nums[x] = newNum(num);
		}
	}
	fclose(fp);
}

<<<<<<< HEAD
int main (int argc, char * argv[]) {
	
=======
int main (int argc, string * argv[]) {

>>>>>>> 4572dadbeb0b3d3c629f8c4cf893e20f5f80b092
}
