#include<stdio.h>
#define PAGE 4096
#define PAGEOFFSET (PAGE-1)
#define PAGEMASK ~(PAGEOFFSET)
int main()
{
   int offset;
   printf("Enter the offset\n");
   scanf("%d",&offset);
   printf("pageoffset %d and page mask %d\n",offset & PAGEOFFSET, offset & PAGEMASK);
   return 0;
}
