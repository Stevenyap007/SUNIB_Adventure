#include <stdio.h>

int main(){

int T;
long int N;

scanf("%d",&T);
for (int i = 0; i < T; i++)
{
    int count = 0;
    scanf("%ld",&N);
    long int factorN = 0;
    long int POW = 0;
    for(int i = 1; i * i <= N; i++){
        if(N % i == 0 && i * i != N){
            factorN++;
        } else if(i * i == N){
            POW++;
        }
    }
    printf("Case #%d: %ld\n",i+1,(factorN * 2) + POW);
}












    return 0;
}