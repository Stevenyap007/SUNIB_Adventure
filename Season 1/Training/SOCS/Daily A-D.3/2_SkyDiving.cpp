#include <stdio.h>
#include <stdlib.h>

int main () {

    char N1[100], N2[100];
    double H1,H2;
    int U1,U2;

    scanf("%s %lf %d %s %lf %d",N1,&H1,&U1,N2,&H2,&U2);

    printf("Name 1: %s\n",N1);
    printf("Height 1: %.2lf\n",H1);
    printf("Age 1: %d\n",U1);
    printf("Name 2: %s\n",N2);
    printf("Height 2: %.2lf\n",H2);
    printf("Age 2: %d\n",U2);

    return 0;
}