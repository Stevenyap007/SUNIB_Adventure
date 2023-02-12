

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char T[1000001],P[10001];
    int n,k,p,t;
    while (scanf("%s",T)!=EOF)
    {
        scanf("%s",P);
        p=strlen(P);
        t=strlen(T);
        for (int i = 0; i < t; i++)
        {
            k=strncmp(&T[i],P,p);
            if(k==0){
                printf("%d\n",i);
            }
        }
        
    }
    
    return 0;
}