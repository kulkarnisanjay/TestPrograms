#include<stdio.h>
void heapify(int a[], int i, int heapsize){
	int left,right,largest = i,temp;
	left = i*2+1;
	right = i*2+2;
//	printf("heapsort(a, %d, %d)\n",a[largest],heapsize);
//	for (int i=0;i<6;i++) printf("%d ",a[i]);
//	printf("\n");
	if(left <= heapsize && a[i] < a[left]) {
//		printf("%d l: %d\n",a[i],a[left]);
		largest = left;
	} else {
		largest = i;
	}
	if (right <= heapsize && a[largest] < a[right]) {
//		printf("%d r: %d\n",a[i],a[right]);
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
	int a[11] = {1,2,3,4,5,6};//15,19,10,7,17,16};
	int i, temp, heapsize=6;
	for (i=heapsize/2-1;i>=0;i--) {
		printf("calling %d\n",i);
		heapify(a,i,heapsize-1);
	}
	printf("part 2: heapify\n");
	for (heapsize=i=5;i>=0;i--) {
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		heapsize--;
		heapify(a,0,heapsize);
	}
	for (i=0;i<6;i++) {
		printf("%d ",a[i]);
	}
	return 0;
}
