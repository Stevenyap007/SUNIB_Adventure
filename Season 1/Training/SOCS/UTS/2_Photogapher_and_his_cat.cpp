#include <stdio.h>

int main(){

    int C;
    scanf("%d", &C);

    for(int i = 0; i < C; i++){
        int N;
        scanf("%d", &N);

        long int foto[N];
        for(int j = 0; j < N; j++){
            scanf("%ld", &foto[j]);
        }

        long int temp;
        for(int x = 0; x < N; ++x){
            for(int y = x + 1; y < N; ++y){
                if(foto[x] > foto[y]){
                    temp = foto[x];
                    foto[x] = foto[y];
                    foto[y] = temp;
                }
            }
        }

        long int total = 0;
        long int min = 1000;
        for(int i = 0; i < N; i++){
            total = foto[i] - foto[i-1];
            if(total < 0){
                total *= -1;
            }

            if(total < min){
                min = total;
            }
        }

        printf("%ld\n", min);
    }

    return 0;
}