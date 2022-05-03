#include <stdio.h>
#include <stdlib.h>

int main (){

    int T;
    
    scanf("%d",&T);

    for(int i = 0; i < T; i++){
        int N;
        scanf("%d", &N);

        long long int kotak[N];
        for(int j = 0; j < N; j++){
            scanf("%lld", &kotak[j]);
        }
        printf("Case #%d: ", i+1);
        for(int i = 0; i < N; i++){
            if(i != N-1){
                printf("%lld ", kotak[N - 1 - i]);
            } else if (i == N-1){
                printf("%lld\n", kotak[N - 1 - i]);
            }
        }
    }
      




    return 0;
}