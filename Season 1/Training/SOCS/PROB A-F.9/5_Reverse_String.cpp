#include <stdio.h>
#include <string.h>

int main(){

    int N;
    scanf("%d",&N);
    
    for (int i = 0; i < N; i++){
        char kata[1000];
        scanf("%s",&kata);

        int length = strlen(kata);
        printf("Case #%d : ",i+1);
        for (int j = 0; j < length; j++)
        {
            printf("%c",kata[length-1-j]);
        }
        printf("\n");
    
    }
    
    







    return 0;
}