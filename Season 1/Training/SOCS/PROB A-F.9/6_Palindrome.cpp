#include <stdio.h>
#include <string.h>
int main(){

    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        char kata[500];
        scanf("%s", &kata);

        printf("Case #%d: ", i+1);
        int length = strlen(kata);
        int point = 0;
        for(int j = 0; j < length; j++){
            if(kata[j] == kata[length - 1 - j]){
                point++;
            }
        }

        if(point == length){
            printf("Yay, it's a palindrome\n");
        } else {
            printf("Nah, it's not a palindrome\n");
        }
    }








    return 0;
}