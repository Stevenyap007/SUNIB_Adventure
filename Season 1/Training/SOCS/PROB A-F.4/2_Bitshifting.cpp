#include <stdio.h>
#include <stdlib.h>

int main (){

    int A,B,C,D,E,F,G;

    scanf("%d",&G);
    scanf("%d %d",&A,&B);
    scanf("%d %d",&C,&D);
    scanf("%d %d",&E,&F);

    printf("%d\n",((A/B)<<B));
    printf("%d\n",((C/D)<<D));
    printf("%d\n",((E/F)<<F));



    return 0;
}