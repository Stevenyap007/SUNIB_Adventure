#include <stdio.h>
#include <stdlib.h>

int main(){

    double num1,num2,num3,num4,num5,num6,num7,num8,num9,num10,num11,num12;
    double total1,total2,total3;


    scanf("%lf %lf %lf %lf",&num1,&num2,&num3,&num4);
    scanf("%lf %lf %lf %lf",&num5,&num6,&num7,&num8);
    scanf("%lf %lf %lf %lf",&num9,&num10,&num11,&num12);

    total1 = (2*(num1/1)) + (4*(num2/2)) + (6*(num3/3)) + (4*(num4/4));
    total2 = (2*(num5/1)) + (4*(num6/2)) + (6*(num7/3)) + (4*(num8/4));
    total3 = (2*(num9/1)) + (4*(num10/2)) + (6*(num11/3)) + (4*(num12/4));



    printf("%.2lf\n",total1);
    printf("%.2lf\n",total2);
    printf("%.2lf\n",total3);





    return 0;
}