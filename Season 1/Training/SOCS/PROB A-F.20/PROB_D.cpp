#include<stdio.h>

int main(){
    
    FILE *read = fopen("testdata.in","r");
    
    int min, count = 0, page = 0, flag = 1, start = 0;
    fscanf(read,"%d\n", &min);

    char temp;
    
    while(!feof(read)){
        fscanf(read, "%c", &temp);
        if(temp == ' ' || temp == '\n' || temp == '\0'){
            if(start == 1){
                start = 0;
                count++;
            }
        }else if(temp == '#'){
            if(count < min){
                printf("page %d: %d word(s)\n", page + 1, count);
                flag = 0;
            }           
            fscanf(read,"%c", &temp);            
            count = 0;
            page++;
        }else{
            start = 1;
        }
    }   
    if(flag == 1)
        printf("The essay is correct\n");
    return 0;
}