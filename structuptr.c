#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct insider {
   int num;
};
struct worklist {
 int a;
 float b;
 struct insider ins[3];
 char c[20];
};
int main()
{
 struct worklist wl;
 struct worklist *wlp;
 int *ip;
 wl.a = 23;
 wl.b = 35.2;
 strncpy(wl.c, "heytherei'm", sizeof(wl.c)-1);
 wl.c[10] = '\0';
 wl.ins[0].num = 12;
 wl.ins[1].num = 23;
 wl.ins[2].num = 34;
 wlp = &wl;
 ip = &wlp->ins[2].num;
 printf("%d is",*ip);
 return 0; 
}
