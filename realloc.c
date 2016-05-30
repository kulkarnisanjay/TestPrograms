#include<stdio.h>
#include<stdlib.h>
int main() {
	int *i = (int*)malloc(8*sizeof(int));
	for(int j=0; j<8; j++) {
		i[j] = j;
 	}
	int *p = (int *)realloc(i, 10*sizeof(int));
	i=p;
	i[8]=8;
	i[11]=828;
	for (int j=0;j<12;j++) {
		printf("%d ",i[j]);
	}
	printf("\n");
	printf("%llu %llu %llu\n",sizeof(i),sizeof(i)/sizeof(int),sizeof(int));
}
