#include <stdio.h>

int main (){

    int T;
    long long int N;
    long long int X[100000];    

    scanf("%d",&T);
    for (int i = 0; i < T; i++)
    {
        scanf("%lld",&N);
        int j;
        for(j = 0; N > 0 ;j++){  
            X[j]=N%2;    
            N=N/2;
        } 
        printf("Case #%d: ",i+1);

        for (int k = j-1 ; k >= 0; k--)
        {
            printf("%lld",X[k]);
        }
        printf("\n");
        
    }
    
     
    







    return 0;
}