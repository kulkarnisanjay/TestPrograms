#include<stdio.h>
void swap( char *a, char *b)
{
  char temp = *a;
  *a = *b;
  *b = temp;
}

void permu(char *actual, char *current)
{
  int i,len;
  len = strlen(current);
  if (len == 1)
 	printf("%s\n",actual);
  for (i=0;i<len;i++) {
	swap(&current[0],&current[i]);
	permu(actual,current+1);
	swap(&current[0],&current[i]);
 }
}
int main()
{
  char str[7] = "sanjay";
  permu(str,str);
  return 0;
}
