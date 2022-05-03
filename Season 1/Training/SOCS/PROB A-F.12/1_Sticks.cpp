#include <stdio.h>

int main (){

    int T;
    int N,M,O;

    scanf("%d",&T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d %d",&N,&M,&O);
        printf("Case #%d: ",i+1);
        if ((N + M) > O && (N + O) > M && (M + O) > N){
            printf("Yes\n");
        } else{
            printf("No\n");
        }

    }
    





    return 0;
}