#include <stdio.h>
#include <string.h>

int main(){

    int T;
    char S[1000];

    scanf("%d",&T);

    for (int i = 0; i < T; i++)
    {
        scanf("%s",&S);
        printf("Case %d: ",i+1);
        for (int j = 0; j < strlen(S); j++)
        {
           printf("%d",S[strlen(S)-1-j]%2);
        }
        printf("\n");
    }

    return 0;
}