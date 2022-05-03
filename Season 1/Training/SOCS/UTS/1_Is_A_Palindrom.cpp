#include <stdio.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++){
    char str[100];
    char str1[100];
    scanf(" %100[^\n]", str);


    int C;
    int C1;

        for(C=0,C1=0;str[C] != '\0'; C++)  
        {
            if( (str[C] < 'A' || str[C] > 'Z' ) && (str[C] < 'a' || str[C] > 'z' ) )  
                continue;                                                                              

            if(str[C] >= 'A' && str[C] <= 'Z' )
                str[C] += 32;

            str1[C1] = str[C];
            C1++;
        }
    str1[C1] = '\0'; 

    int j,strlength = strlen(str1),point = 0; 

        for( j = 0; j < strlength; j++){
                if(str1[j] == str1[strlength - 1 - j]){
                    point++;
                }
            }

            if(point == strlength){
                printf("true\n");
            } else {
                printf("false\n");
            }    
            
    
}

    return 0;
}