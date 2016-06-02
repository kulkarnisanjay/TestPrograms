#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char numtotxt[10][5] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int accept(int k, int n) {
	if (k >= n) {
		return 1;
	}
	return 0;
}

void print(char *combo, int k) {
	combo[k+1] = '\0';
	printf("%s\n",combo);
}

void backtrack(char *input, char *combo, int k, int n) {
	if(accept(k,n)) {
		print(combo,k);
	} else {
		int arridx = input[k]-'0';
		int len = strlen(numtotxt[arridx]);
		for(int i=0; i < len; i++) {
			combo[k] = numtotxt[arridx][i];
			backtrack(input, combo, k+1, n);
		}
	}
}
int main() {
	char input[] = "2304";
	char *combo = (char *)malloc(10);
	backtrack(input, combo, 0, 4);
	return 0;
}
