#include <stdio.h>
#include <stdlib.h>

int main(){

    int T,N;
    
    scanf("%d",&T);

    for(int i = 0; i < T ; i++){
        scanf("%d",&N);
        long int items[N];
        long int sum = 0;
        for (int j = 0 ; j < N ;j++){
            scanf("%ld",&items[j]);
            sum += items[j];
        }
        printf("Case #%d: %ld\n",i+1,sum);
    }




    return 0;
}
