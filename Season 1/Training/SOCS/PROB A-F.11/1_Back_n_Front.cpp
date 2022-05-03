#include <stdio.h>
#include <string.h>


int main (){

    int N;

    char S[100];

    for (int i = 0; i < 3; i++)
    {
       scanf("%d %s",&N,&S);

       printf("%c%c\n",S[strlen(S)-1],S[0]);
    }
    
    return 0;
}