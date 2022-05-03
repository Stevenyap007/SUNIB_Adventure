#include <stdio.h>

int rumus(int N){

    if (N == 0 || N == 1){
        return N;
    }else if (N % 2 != 0){
        return rumus (N - 1) + rumus(N + 1);
    }else if (N % 2 == 0){
        return rumus(N/2);
    }
}

int main (){

    int T;
    int N;

    scanf("%d",&T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d",&N);
        printf("Case #%d: %d\n",i+1,rumus(N));
    }
    







    return 0;
}