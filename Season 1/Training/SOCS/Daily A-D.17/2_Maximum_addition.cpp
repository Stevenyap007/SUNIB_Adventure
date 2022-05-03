#include <stdio.h>

int main() {

    int T, N;
    unsigned long long int M;
    scanf("%d", &T); 
    
    for(int i=0; i<T; i++) {
        scanf("%d %llu", &N, &M); 
        int segmen[N];

        for(int j=0; j<N; j++) {
            scanf("%d", &segmen[j]); 
            
        }

        int z = 0, max[N], r = 0; 
        unsigned long long int temp;

        for(int j = 0; j < N; j++) {
            if(segmen[j] > M) {
                continue;
            }
            else {
                z = 1;
                temp = segmen[j];
                for(int k=j+1; k < N; k++) {
                    temp += segmen[k];
                    if(temp <= M) {
                        z++;
                    }
                    else {
                        break;
                    }
                }
            }
            max[j] = z;
            if(max[j] > r) {
                r = max[j];
            }
        }

        if(r != 0) {
            printf("Case #%d: %d\n", i+1, r);
        }
        else {
            printf("Case #%d: -1\n", i+1);
        }
    }

    return 0;
}

