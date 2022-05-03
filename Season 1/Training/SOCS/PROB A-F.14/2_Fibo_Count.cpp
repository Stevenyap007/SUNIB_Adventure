#include <stdio.h>

int count;
int fib(int n){
    // count++;
    if (n == 0 || n == 1){
        return n;
    }else{
        return fib(n-2) + fib(n-1);
    }
    
}


int main (){

    int T,n;

    scanf("%d",&T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d",&n);
        fib(n);
        printf("Case #%d: %d\n",i+1,fib(n+1)*2-1);
        // printf("%d",count);
        count = 0;
    }
    





    return 0;
}