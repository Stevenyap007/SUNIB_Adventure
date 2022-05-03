#include <stdio.h>
#include <stdlib.h>

int main(){

    int T,N;
    scanf("%d",&T);
    for(int i =0; i<T; i++){
        scanf("%d",&N);
        int A[N];
        for(int j =0; j<N;j++){
            scanf("%d",&A[j]);
        }
        int B[N];
        for(int k =0; k<N;k++){
            scanf("%d",&B[k]);
        }
        int hasil[N];
        printf("Case #%d: ",i+1);
        for(int z =0; z<N-1;z++){
            hasil[z]= A[z] - B[z];
            printf("%d ",hasil[z]);
        }
        hasil[N-1]= A[N-1] - B[N-1];
        printf("%d",hasil[N-1]);
        printf("\n");
    }










    return 0;
}