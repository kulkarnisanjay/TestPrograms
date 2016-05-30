#include<stdio.h>
#define FUNCADD(a,b,c,d) { \
	*c=*a+*b; 	   \	
	*d=123;		   \
	printf("%d %d\n",*c,*d); \
}			   
int main() {
  int a=9232,b=12,c,d=0;
  FUNCADD(&a,&b,&c,&d);
  printf("%d %d",c,d);
  
  return 0;
}
