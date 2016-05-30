#include<stdio.h>
struct test {
	int a;
	char c;
	float b;
	double d;
	short s;
}*t;
int main()
{
  unsigned int p;
  struct test r;
  printf("%x and size is %u \n", t, sizeof(t));
  p = ((struct test*)t)+1;
  p = t+1;
  printf("%x and size is %u \n", p, sizeof(t));
  p = &r+1;
  printf("%x and size is %u \n", p, sizeof(t));
  return 0;
}

