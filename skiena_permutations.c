#include<stdio.h>
int accept(int *arr, int arrlen, int sublen) {
	if (arrlen == sublen) {
		return 1;
	}

	return 0;
}

int generatecandidate(int *arr, int arrlen, int *subarr, int sublen) {
	return arrlen-sublen;
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void backtrack(int *arr, int arrlen, int *subarr, int sublen) {
	if (sublen > arrlen)
		return;
	int numcandidate = 0;
	if(accept(arr, arrlen, sublen)) {
		for (int j=0; j<arrlen; j++) {
			printf("%d",arr[j]);
		}
		printf("\n");
	} else {
		numcandidate = generatecandidate(arr, arrlen, subarr, sublen);
		for(int i=0; i<numcandidate; i++ ) {
			swap(&subarr[0],&subarr[i]);
			if (i==0 || subarr[0]!=subarr[i]) {
				backtrack(arr,arrlen,subarr+1,sublen+1);
			}
			swap(&subarr[0],&subarr[i]);
		}
	}
	return;
}
int main() {
	int arr[] = {1,2,3};
	int *subarr = arr;
	backtrack(arr, 3, subarr, 0);
	return 0;
}
