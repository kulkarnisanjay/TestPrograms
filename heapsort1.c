#include<stdio.h>
void heapify(int a[], int i, int heapsize){
	int left,right,largest = i,temp;
	left = i*2;
	right = i*2+1;
	printf("heap: %d %d\n",a[largest],heapsize);	
	if(left <= heapsize && a[i] < a[left]) {
		printf("%d l: %d\n",a[i],a[left]);
		largest = left;
	} else {
		largest = i;
	}
	if (right <= heapsize && a[largest] < a[right]) {
		printf("%d r: %d\n",a[i],a[right]);
		largest = right;
	}
	if (i!=largest) {
		printf("swapping %d %d\n",a[i], a[largest]);
		temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		heapify(a,largest,heapsize);
	}
}
int main() {
	int a[11] = {0,10,9,8,6,4,1,2,7,3,5}; 
	int i, temp, heapsize=10;
	for (i=5;i>=1;i--) {
		printf("calling %d\n",i);
		heapify(a,i,10);
	}
	for (i=10;i>=2;i--) {
		int temp = a[1];
		a[1] = a[i];
		a[i] = temp;
		heapsize--;
		heapify(a,1,heapsize);
	}
	for (i=1;i<=10;i++) {
		printf("%d ",a[i]);
	}
	return 0;
}
