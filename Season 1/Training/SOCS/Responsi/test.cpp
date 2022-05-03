#include <stdio.h>
#include <string.h>


int main (){

    char kata1[1000];
    char kata2[1000];
    int found[1000] = {0};

    scanf("%[^\n]",kata1);
    getchar();
    scanf("%[^\n]",&kata2);
    getchar();

    int index = 0;
    int sticky_index = 0; 
    int stickyLength = strlen(kata2);

    while(sticky_index<stickyLength){
        if(kata1[index] != kata2[sticky_index]){
            int ascii = kata2[sticky_index];
            found[ascii]++;
        }else{
            index++;
        }
        sticky_index++;
    }

    for (int i = 0; i < 1000; i++)
    {
        if(found[i] > 0){
            printf("%c",i);
        }
    }
    printf("\n");
    
    
    
    
    
    


    return 0;
}