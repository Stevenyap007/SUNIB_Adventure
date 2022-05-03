#include <stdio.h>

int main (){


    int N,K,P;

    scanf("%d",&N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d",&P,&K);
        int PAsli[P];
        int KKunci[K];

        for (int j = 0; j < P; j++)
        {
            scanf("%d",&PAsli[j]);
        }


        for (int k = 0; k < K; k++)
        {
            scanf("%d",&KKunci[k]);
        }


        int totalKode[P - K + 1];
        int total;

        for (int l = 0; l < P-K+1; l++)
        {
            total = 0;
            for (int m = 0; m < K; m++)
            {
                total = total + (PAsli[m + l] ^ KKunci[m]);
                
            } 
            totalKode[l] = total;
        }


        for (int o = 0; o < P-K; o++)
        {
            printf("%d ",totalKode[o]);
        }
        printf("%d\n",totalKode[P-K]);
        
        
    }
    


    return 0;
}



