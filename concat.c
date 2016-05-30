#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank ";

    
    // Declare second integer, double, and String variables.
    int j;
    double e;
    char s2[1024];
    // Read and save an integer, double, and String to your variables.
    scanf("%d",&j);
    scanf("%lf",&e);
    scanf("%20[^\n]", s2);
    // scanf("%s",s2);
    // Print the sum of both integer variables on a new line.
    printf("%d\n",j+i);
    // Print the sum of the double variables on a new line.
    printf("%.1f\n",e+d);
    // Concatenate and print the String variables on a new line
    puts(s2);
//    strcat(s,s2);
    // The 's' variable above should be printed first.
//    printf("%s \n",s);
//    puts(s);


    return 0;
}
