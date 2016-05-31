#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void print(int **arr) {
	printf("[");
	for (int i=0 ;i<8;i++)
		for(int j=0; j<8; j++) {
			if(arr[i][j]>1) {
				printf("%d%d ", i,j);
		}
	}
	printf("]\n");
}
int accept(int row) {
	return (row == 8);
}
void generate_combinations(int *row) {
	//(*row)++;
}
int move(int **arr, int row, int *col) {
	int i, j, found=0, found_row=0, found_col=0;
	if (row == 8) {
		return found;
	}
	for(i=*col; i<8; i++) {
		if (arr[row][i] == 0) {
			arr[row][i] = 999;
			found = 1;
			found_col = i;
			*col = i;
			found_row = row;
			break;
		}
	}
	if(found) {
		for(i=0; i<8; i++) {
			if (arr[row][i]!=999) {
				arr[row][i] = 1;
			}
		}
		for(i=0; i<8; i++) {
			if (arr[i][found_col]!=999) {
				arr[i][found_col] = 1;
			}
		}
		for (i=found_col,j=found_row; i<8 && j<8; i++,j++) {
			if (arr[j][i]!=999) {
				arr[j][i] = 1;
			}
		}
		for (i=found_col,j=found_row; i>=0 && j<8; i--,j++) {
			if (arr[j][i]!=999) {
				arr[j][i] = 1;
			}
		}
		for (i=found_col,j=found_row; i>=0 && j>=0; i--,j--) {
			if (arr[j][i]!=999) {
				arr[j][i] = 1;
			}
		}
		for (i=found_col,j=found_row; i<8 && j>=0; i++,j--) {
			if (arr[j][i]!=999) {
				arr[j][i] = 1;
			}
		}
	}
	return found;
}


void unmove(int **arr, int row, int *col) {
	int i, j, found=0, found_row=0, found_col=0;
	if (row == 8) {
		return;
	}
	for(i=*col; i<8; i++) {
		if (arr[row][i] == 999) {
			arr[row][i] = 0;
			found = 1;
			found_col = i;
			*col = i;
			found_row = row;
			break;
		}
	}
	if(found) {
		for(i=0; i<8; i++) {
			if (arr[row][i]!=999) {
				arr[row][i] = 0;
			}
		}
		for (i=found_col,j=found_row; i<8 && j<8; i++,j++) {
			if (arr[j][i]!=999) {
				arr[j][i] = 0;
			}
		}
		for (i=found_col,j=found_row; i>=0 && j<8; i--,j++) {
			if (arr[j][i]!=999) {
				arr[j][i] = 0;
			}
		}
		for (i=found_col,j=found_row; i>=0 && j>=0; i--,j--) {
			if (arr[j][i]!=999) {
				arr[j][i] = 0;
			}
		}
		for (i=found_col,j=found_row; i<8 && j>=0; i++,j--) {
			if (arr[j][i]!=999) {
				arr[j][i] = 0;
			}
		}
	}
}

void backtrack(int **arr, int row) {
	printf("%d\n",row);
	print(arr);
	if(accept(row)) {
		print(arr);
	} else {
		generate_combinations(&row);
		for (int i=0;i<8;i++) {
			if (move(arr,row, &i)) {
				backtrack(arr,row+1);
				unmove(arr,row,&i);
			} else {
				if (i >= 7) {
					return;
				}
			}
		}
	}
		
}
int main() {
	int **arr;
	arr = malloc(8 * sizeof *arr);
	for (int i=0; i<8; i++) {
        	arr[i] = malloc(8 * sizeof *arr[i]);
   	}
	backtrack(arr,0);
}

