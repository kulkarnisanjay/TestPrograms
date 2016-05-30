#include<stdio.h>
#include<stdlib.h>
int top[3];
int bottom[3];
int stack[9]; 

void initialize() {
	int i,j =0;
	for(i=0;i<3;i++) {
		top[i] = bottom[i] = j;
		j+=3;
	}
}

void push(int stackno, int element) {
	if (stackno < 1 || stackno > 3){
		printf("Wrong stackno\n");
		return;
	}
	if (top[stackno-1] > stackno*3-1) {
		printf("Can't insert Overflow\n");
		return;
	}
	stack[top[stackno-1]] = element;
	top[stackno-1]++;
}

void pop(int stackno) {
	if (stackno < 1 || stackno > 3){
		printf("Wrong stackno\n");
		return;
	}
	if (top[stackno-1] == bottom[stackno-1]) {
		printf("Nothing to pop underflow\n");
		return;
	}
	printf("popping %d\n",stack[top[stackno-1]]);
	top[stackno-1]--;
}

void display(int stackno) {
	int i;
	if (stackno < 1 || stackno > 3){
		printf("Wrong stackno\n");
		return;
	}
	for (i=bottom[stackno-1];i<top[stackno-1];i++)
		printf("%d\n",stack[i]);
}

int main()
{
  int element, stackno;

  int operation;

  do{
	printf("Enter what you want to do 1. push 2. pop 3. display 4. exit.\n");
	scanf("%d",&operation);
	switch(operation) {
		case 1: printf("Enter the stack to push\n");
			scanf("%d",&stackno);
			printf("Enter the number to push\n");
			scanf("%d",&element);
			push(stackno,element);
			break;
		case 2: printf("Enter the stack to pop");
			scanf("%d",&stackno);
			pop(stackno);
			break;
		case 3: printf("Enter the stack to display");
			scanf("%d",&stackno);
			display(stackno);
			break;
		default: break;
	}
  }while(operation!=4);
  return 0;
}
