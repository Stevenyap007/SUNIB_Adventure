#include <stdio.h>
#include <stdlib.h>

int main (){

    int M,N;
    1<=N<=100;
    1<=M<=10;

    scanf("%d %d",&N,&M);
    while(M>0){
        printf("%d\n",N);
        N++;
        M--;
    }

    return 0;
}