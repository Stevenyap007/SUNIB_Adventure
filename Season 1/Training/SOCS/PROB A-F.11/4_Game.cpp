#include <stdio.h>

int main(){

    int N, M;
    scanf("%d %d", &N, &M);

    char kata[N];
    scanf("%s", &kata);

    int A[M];
    for(int i = 0; i < M; i++){
        scanf("%d", &A[i]);
    }

    for(int j = 0; j < N; j++){
        for(int x = 0; x < M; x++){
            if(j == A[x]){
                if(kata[j] > 64 && kata[j] < 91){
                    kata[j] += 32;
                } else if(kata[j] > 96 && kata[j] < 123){
                    kata[j] -= 32;
                }
            }
        }
    }

    printf("%s\n", kata);
    return 0;

}
