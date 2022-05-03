#include <stdio.h>

int main(){

    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        long long int N;
        scanf("%lld", &N);

        long long int isiArray[200005] = {0};
        long long int index;
        for(int x = 0; x < N; x++){
            scanf("%lld", &index);
            ++isiArray[index];
        }

        long long int max = 0;
        for(int y = 0; y < 200005; y++){
            if(max < isiArray[y]){
                max = isiArray[y];
            }
        }

        printf("Case #%d: %lld\n", i+1, max);

        long long int total = 0;
        for(int z = 0; z < 200005; z++){
            if(isiArray[z] == max){
                if(total == 0){
                    printf("%d", z);
                    total++;
                } else {
                    printf(" %d", z);
                }
            }
        }
        puts("");
    }

    return 0;
}