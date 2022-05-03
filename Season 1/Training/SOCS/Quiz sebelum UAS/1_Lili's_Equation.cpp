#include <stdio.h>
int total = 0;
int rekursif(int M, int N){
    
    if (M == 0 || N == 0){
        return total +=1;
    }
    return rekursif(M-1,N-1) + rekursif(M-1,N) + rekursif(M,N-1);
}

int main (){

    int M,N;

    scanf("%d %d",&M,&N);
    rekursif(M,N);
    printf("%d\n",total);










    return 0;
}