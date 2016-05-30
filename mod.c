#include<stdio.h>
int main()
{
   int i=0, j;
   for (i=0;i<5;i++)
   {
	j = i%5;
  	 printf("%d %d\n",j,j%32);
   }
   return 0;
}
