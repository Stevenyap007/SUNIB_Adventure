#include <stdio.h>
#include <stdlib.h>

int main() {

    int N;
    scanf("%d", &N);

    int Array_Ai[N];
    for(int x = 0; x < N; x++){
        scanf("%d", &Array_Ai[x]);
    }

    int Array_Bi[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &Array_Bi[i]);
    }
    int hasilArray[N];
    for(int z = 0; z < N; z++){
        hasilArray[Array_Ai[z]] = Array_Bi[z];
    }

    for(int y = 0; y < N - 1; y++){
        printf("%d ", hasilArray[y]);
    }

    printf("%d", hasilArray[N - 1]);
    printf("\n");





    return 0; 
}





