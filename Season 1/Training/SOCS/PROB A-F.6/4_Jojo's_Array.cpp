#include <stdio.h>
#include <stdlib.h>

int main(){

    int CS;
    scanf("%d", &CS);

    for(int i = 1; i <= CS; i++){
        int N;
        scanf("%d", &N);

        int Array_index[N];
        long int total = 0;
        for(int x = 0; x < N; x++){
            scanf("%d", &Array_index[x]);
            total += Array_index[x];
        }

        long int totalCounter = 0;
        for(long int y = 0; y < N; y++){
            if(Array_index[y] > total){
                totalCounter += 1;
            }
        }

        printf("Case #%d: %ld\n", i, total);
        printf("%ld\n", totalCounter);
    }

    return 0;
}