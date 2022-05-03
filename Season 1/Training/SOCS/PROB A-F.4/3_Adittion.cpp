#include <stdio.h>
#include <stdlib.h>

int main (){

    int num1,num2,num3,num4,num5,num6;
    char a,b;

    scanf("%d %c %d %c",&num1,&a,&num2,&b);
    scanf("%d %c %d %c",&num3,&a,&num4,&b);
    scanf("%d %c %d %c",&num5,&a,&num6,&b);
    printf("%d\n",num1+num2);
    printf("%d\n",num3+num4);
    printf("%d\n",num5+num6);



    return 0;
}