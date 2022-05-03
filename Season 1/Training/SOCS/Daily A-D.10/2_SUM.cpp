#include <stdio.h>

int main (){

    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        int N;
        scanf("%d", &N);

        long long int Angin[N][N];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf("%lld", &Angin[i][j]);
            }
        }

        long long int total[N];
        for(int i = 0; i < N; i++){
            total[i] = 0;
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                total[j] += Angin[i][j];
            }
        }

        printf("Case #%d: ", i+1);
        for(int i = 0; i < N - 1; i++){
            printf("%lld ", total[i]);
        }
        printf("%lld\n", total[N - 1]);
    }




    return 0;
}