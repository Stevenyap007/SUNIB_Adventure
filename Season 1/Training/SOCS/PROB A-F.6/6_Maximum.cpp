#include <stdio.h>

int main (){

    int P;
    scanf("%d",&P);

    for(int i =0; i<P; i++){
        long long int N;
        scanf("%lld", &N);

        long long int MAX1, MAX2;
        MAX1 = 1000000, MAX2 = -1000000;
        long long int x;

        for(int j = 0; j < N; j++){
            scanf("%lld", &x);
            if(x >= MAX2){
                MAX1 = MAX2;
                MAX2 = x;
            } else if(x >= MAX1){
                MAX1 = x;
            }
        }

        long long int total;
        total = MAX2 + MAX1;

        printf("Case #%d: %lld\n",i + 1,total);
    }
        
    

    return 0;
}