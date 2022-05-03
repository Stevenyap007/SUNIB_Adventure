#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){

    int X;
    double Y, hasil;


    scanf("%d %lf",&X,&Y);
    hasil = X*(pow((1+ Y/100.00), 3));
    printf("%.2lf\n",hasil);
   



    return 0;
}