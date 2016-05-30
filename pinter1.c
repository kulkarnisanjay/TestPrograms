#include <stdio.h>
#include <stdlib.h>

int *p = NULL;
void test(int * pt1, int**pt2){
    p = (int*)malloc(sizeof(int));    
    pt1 = p;
    *pt2 = p;
    printf("p points to %p\n", p);
    printf("pt1 points to %p\n", pt1);
    printf("pt2 points to %p\n", *pt2);
}

int main(void) {
    int *p1 = NULL; 
    int *p2 = NULL;

    printf("p points to %p\n", p);
    printf("p1 points to %p\n", p1);
    printf("p2 points to %p\n", p2);

    test(p1, &p2);

    printf("p points to %p\n", p);
    printf("p1 points to %p\n", p1);
    printf("p2 points to %p\n", p2);

    return 0;
}
