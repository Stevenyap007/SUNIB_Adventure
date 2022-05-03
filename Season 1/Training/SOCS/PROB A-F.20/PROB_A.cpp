#include <stdio.h>

int fibo_stalaktit(int n){
    if((n==0) || (n == 1)){
        return n;
    }
    else{
        return 2*fibo_stalaktit(n-1)+1;
    }
}
int main(){
    int N;

    scanf("%d", &N);

    for(int i=0; i<N; i++){
        for(int j=0; j<fibo_stalaktit(N); j++){
            for(int k=fibo_stalaktit(i); k>0; k--){
                printf(" ");
                j++;
            }
            printf("*");
            if(j+fibo_stalaktit(i+1)>=fibo_stalaktit(N)){
                break;
            }
        }
        printf("\n");
    }




    return 0;
}