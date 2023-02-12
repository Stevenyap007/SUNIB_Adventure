#include <stdio.h>
#include <string.h>

int main(){
    char t[1005];
    char p[1005];

    scanf("%s",t);
    scanf("%s",p);

    int len1 = strlen(t);
    int len2 = strlen(p);

    for (int i = 0; i < len1; i++)
    {
        if(strncmp(&t[i],p,len2)==0){
            printf("%d\n",i);
        }
    }
    

    return 0;
}