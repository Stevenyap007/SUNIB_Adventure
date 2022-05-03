#include <stdio.h>
#include <string.h>


int main(){

    char kata[1000];
    scanf("%s",&kata);

    int length = strlen(kata);

    for (int i = 0; i < length; i++)
    {
        printf("%c",kata[length-1-i]);
    }

    //or

    // printf("%s",strrev(kata));














    return 0;
}

