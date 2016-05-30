#include<stdio.h>
int dblptr(int **p) {
	for (int i=0;i<6;i++) {
		printf("%d",*p[i]);
	}
        return 0;
}
int main() {
int **p = (int **)malloc(sizeof(int *)*6);
for (int i=0;i<6;i++) {
	p[i] = (int *) malloc(sizeof(int));
	*p[i] = i;
}
dblptr(p);
}

