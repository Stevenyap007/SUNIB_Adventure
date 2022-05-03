#include <stdio.h>

int Jobonacci(int N){
    if (N == 0){
        return N;
    }else if (N % 2 != 0){
        return 1;
    }else{
        return Jobonacci(N-1) + Jobonacci(N-2);
    }
}

int main(){

    int N;

    scanf("%d",&N);
    printf("%d\n",Jobonacci(N));


    return 0;
}