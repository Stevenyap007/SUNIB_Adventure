#include <stdio.h>

int main(){

    int N;
    int M;

    scanf("%d %d",&N,&M);

    int angka_masuk[N];
    int angka_keluar[M];
    int total;
    int maksimum = 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%d",&angka_masuk[i]);
    }

    for (int j = 0; j < M; j++)
    {
        scanf("%d",&angka_keluar[j]);
    }

    printf("Maximum number is ");
    for (int k = 0; k < M; k++)
    {
        total = 0;
        for (int l = 0; l < N; l++)
        {
            if(angka_keluar[k] == angka_masuk[l]){
               for (int m = l; m < N-1; m++)
               {
                   angka_masuk[m] = angka_masuk[m+1];
               }
               N--;
               l--;
            }
        }
        
    }

    if(N == 0){
        printf("-1\n");
    } else {
        int max = 0;
        for(int j = 0; j < N; j++){
            if(angka_masuk[j] > max){
                max = angka_masuk[j];
            }
        }
        printf("%ld\n", max);
    }



    return 0;
}