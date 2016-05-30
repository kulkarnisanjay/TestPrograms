#include<stdio.h>
#include<string.h>
void print(char *arr, int len) {
	printf("[");
	for(int i=0; i<len; i++) {
		if(arr[i]!='0') {
			printf("%c", arr[i]);
		}
	}
	printf("]\n");
}
int accept(int curlen, int len) {
	return (curlen == len);
}
int generate_combinations(char *arr, int *c) {
	c[0]=1;
	c[1]=0;
	return 2;
}
void move(char *arr, int i, char *c, int curlen) {
	if (i==0) {
		*c = arr[curlen];
		arr[curlen] = '0';
	}
}
void unmove(char *arr, int i, char c, int curlen) {
	if (i==0) {
		arr[curlen] = c;
	}
}
void backtrack(char *arr, int len, char *curptr, int curlen) {
	int c[2];
	char temp;
	int combinations=0;
	if(accept(curlen, len)) {
		print(arr, len);
	} else {
		combinations = generate_combinations(arr, c);
		for (int i=0;i<combinations;i++) {
			move(arr,c[i],&temp,curlen);
			backtrack(arr,len,curptr+1,curlen+1);
			unmove(arr,c[i],temp,curlen);
		}
	}
		
}
int main() {
	char arr[] = "1234";
	char *subarr = arr;
	backtrack(arr,strlen(arr),subarr,0);
}

