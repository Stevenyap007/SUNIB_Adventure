#include <stdio.h>

int main(){

    int T,N,K;
    scanf("%d",&T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d",&N,&K);
        int list_berat_pisang[N];

        for (int j = 0; j < N; j++)
        {
            scanf("%d",&list_berat_pisang[j]);
        }
        int total_diet = 0;

        for (int k = 0; k < N; k++)
        {
            if(K <= list_berat_pisang[k]){
                total_diet++;
            }
        }
        printf("Case #%d: %d\n",i+1,total_diet);
    }
    
    










    return 0;
}