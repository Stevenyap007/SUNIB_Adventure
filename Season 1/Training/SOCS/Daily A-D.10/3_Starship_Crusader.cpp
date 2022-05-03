#include <stdio.h>

int main(){

    int T,N;
    scanf("%d",&T);

    for(int i = 0; i < T; i++){
        scanf("%d",&N);

        long long int X[N];
        for(int j = 0; j < N; j++){
            scanf("%lld",&X[j]);
        }

        long long int Y[N];
        for(int j = 0; j < N; j++){
            scanf("%lld",&Y[j]);
        }
        int count = 0;
        
        for(int k = 0; k < N; k++ ){
            if(X[k] < Y[k]){
                count++;
            }
        }

        printf("Case #%d: %d\n",i+1,count);


    }





    return 0;
}