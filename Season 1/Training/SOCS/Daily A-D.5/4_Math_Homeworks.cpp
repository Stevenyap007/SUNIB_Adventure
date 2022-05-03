#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){

long long num1,num2,num3,num4,num5,num6,num7,num8,num9,num10,num11,num12;
double total1,total2,total3;

    scanf("(%lld+%lld)x(%lld-%lld)",&num1,&num2,&num3,&num4);
    getchar();
    scanf("(%lld+%lld)x(%lld-%lld)",&num5,&num6,&num7,&num8);
    getchar();
    scanf("(%lld+%lld)x(%lld-%lld)",&num9,&num10,&num11,&num12);
    getchar();

    total1 = (num1+num2)*(num3-num4);
    total2 = (num5+num6)*(num7-num8);
    total3 = (num9+num10)*(num11-num12);

    printf("%.0lf %.0lf %.0lf\n",total1,total2,total3);



    return 0;
}