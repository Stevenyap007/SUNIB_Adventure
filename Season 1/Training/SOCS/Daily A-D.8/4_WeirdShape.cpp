#include <stdio.h>
#include <stdlib.h>

int main (){

    int T,N;
    scanf("%d", &T);

    for( int x = 0; x < T ;x++){

        scanf("%d",&N);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(i == 0 || j == 0 || i == N - 1 || j == N - 1 || i == j || i+j == N - 1){
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }







    





    return 0;
}