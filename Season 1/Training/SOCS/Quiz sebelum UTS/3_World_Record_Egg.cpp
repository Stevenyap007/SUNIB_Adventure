#include <stdio.h>
long long int arrFib[1000000];
long long int fibonacci(int n){
	if ( n == 1 || n == 0 ){
		return n;
	}
	if(arrFib[n] == 0){
		arrFib[n] = fibonacci(n-2) + fibonacci(n-1);
	}

	return arrFib[n];
}

int main (){

    

    int T,N;
    scanf("%d",&T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d",&N);
        printf("Case #%d: %lld\n",i+1,fibonacci(N-1));
    }
    

    return 0;
}

