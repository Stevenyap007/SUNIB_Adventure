#include <stdio.h>

int main(){
    int n,count = 1;
    scanf("%d",&n);
    int gedung[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &gedung[i]);
    }

    for (int i = 0; i < n; i++)
    {
        // printf (" i = %d ",i);
        if((gedung[i] == 0) && (gedung[i-1] < gedung[i+1]) && (gedung[i+1] - gedung[i-1] == 2)){
            gedung[i] = gedung[i-1] + 1;
            // printf("cek1\n");
        }
        else if((gedung[i] == 0) && (gedung[i-1] > gedung[i+1]) && (gedung[i-1] - gedung[i+1] == 2)){
            gedung[i] = gedung[i-1] - 1;
            // printf("cek2\n");
        }
        else if((gedung[i] == 0) && (gedung[i-1] < gedung[i+1])){
            gedung[i] = gedung[i-1] + 1;
            // printf("cek3\n");
        }
        else if((gedung[i] == 0) && (gedung[i-1] > gedung[i+1])){
            gedung[i] = gedung[i+1] + 1;
            // printf("cek4\n");
        }
        else if((gedung[i-1] == gedung[i+1]) && (i != 0)){
            gedung[i] = gedung[i-1] + 1;
            // printf("cek5\n");
        }
    }
    

    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if(gedung[i+1]-gedung[i] == 1 || gedung[i+1]-gedung[i] == -1){
            // printf("\n %d masuk\n",i);
            count++;
        }else{
            // printf("%d reset\n",i);
            if(temp < count){
                temp = count;
            }
            count = 1;
        }
    }

    printf("%d\n",temp);
    
    
    





    return 0;
}115