#include <stdio.h>
#include <stdlib.h>

int main() {

    int N,a,b;
    int HB_New[100];
    scanf("%d", &N);

    int HB_1[N];
    for(int x = 0; x < N; x++){
        scanf("%d", &HB_1[x]);
    }

    int New;
    scanf("%d", &New);

    for(int x = 0; x < New; x++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("Case #%d: ", x + 1);
        HB_1[a-1] = b;
        
        for(int z = 0; z < N-1; z++){
            printf("%d ", HB_1[z]);
        }
        printf("%d\n", HB_1[N-1]);
    }






    return 0;
}