#include<stdio.h>
int er;
setptr(int *p, int d) {
   *p = d;
}
int main()
{
  er=9;
  int *p = &er;
 
  int d=109;
  setptr(p,d);
  printf("%d %u\n",*p,&d);
  return 0;
}
