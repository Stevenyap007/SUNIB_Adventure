#include <stdio.h>
#include <string.h>

int main (){

    int T;
    scanf("%d",&T);

    for(int i = 0; i < T;i++){
        char kata[1000];
        scanf("%s", &kata);

        int length = strlen(kata);
        printf("Case %d: ", i+1);
        for(int j = 0; j < length - 1; j++){
            printf("%d-", kata[j]);
        }
        printf("%d\n", kata[length - 1]);
    }








    return 0;
}