#include <stdio.h>

int main (){

    
    int N;
    scanf("%d", &N);

    long long int A[N];
    for(int i = 0; i < N; i++){
        scanf("%lld", &A[i]);
    }

    long long int ganjil_bawah;
    long long int total = 0;
    for(int i = 0; i < N; i++){
        total += A[i];
    }

    for(int j = 0; j < N; j++){
        if(A[j] % 2 != 0){
            ganjil_bawah = A[j];
            break;
        }
    }

    if(total % 2 != 0){
        total -= ganjil_bawah;
    }

    printf("%lld\n", total);

    
    

    return 0;
}