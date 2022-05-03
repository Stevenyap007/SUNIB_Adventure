#include <stdio.h>
#include <stdlib.h>

int main() {

    int N;
    scanf ("%d", &N);
    int Video[N];

    for(int i = 0; i < N ; i++){
        scanf("%d",&Video[i]);
    }

    int P,a,b;
    
    scanf("%d",&P);

    for (int i = 0; i < P ; i++){
        int total = 0;
        scanf("%d %d",&a,&b);
        for(int j = a - 1 ; j <= b - 1; j++){
            total += Video[j];
        }
        printf("Case #%d: %d\n",i+1,total);
    }
    
    






    return 0;
}
