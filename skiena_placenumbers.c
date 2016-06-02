#include<stdio.h>
#include<stdlib.h>

int accept(int k, int *placed_array, int len) {
	if (k < 1) {
		/*for (int i=0 ; i< len; i++) {
			printf("%d ",placed_array[i]);
		}
		printf("\n");*/
		return 1;
	}
	return 0;
		
}

int move(int pos, int *placed_array, int num, int len) {
	if (placed_array[pos]) {
		return 0;
	} else if(placed_array[pos+num+1] || ((pos+num+1) > len)) {
		return 0;
	} else {
		placed_array[pos] = num;
		placed_array[pos+num+1] = num;
		return 1;
	}
}

void unmove(int pos, int *placed_array, int num) {
	if (placed_array[pos] == num) {
		placed_array[pos] = 0;
	}
	if (placed_array[pos+num+1] == num) {
		placed_array[pos+num+1] = 0;
	}
}

int backtrack(int num, int *placed_array, int len) {
	for (int i=0 ; i< len; i++) {
		printf("%d ",placed_array[i]);
	}
	printf("\n");
	if(accept(num, placed_array, len)) {
		return 1;
	} else {
		for (int i=0; i< len; i++) {
			if(move(i, placed_array, num, len)) {
				if (backtrack(num-1, placed_array, len)) {
					return 1;
				}
				unmove(i, placed_array, num);
			}
		}
		return 0;	
	}
}
int main(int argc, char *argv[]) {
	int num = atoi(argv[1]);
	int *placed_array = (int *)malloc(sizeof(int)*num*2);
	backtrack(num, placed_array, num*2);
	return 0;
}
