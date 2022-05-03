#include <stdio.h>

void bubble_sort(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        
       // buat loop kedua buat ngecek masing" index 
       // tidak rerjadi swap, break
       for (int j = 0; j < n-1-i; j++)
       {
           //ngebandingin
           if (arr[j] > arr[j+1]){
               //tukar
               int temp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = temp;
           }
       }
    }   
}

void matchmaking(int arr[],int batas,int target){
    int flag = 0;
    for (int i = 0; i < batas; i++)
    {
        if(target == arr[i]){
            if(i == batas-1 ){
            printf("%d %d\n",arr[i-1],arr[i]);
            flag++;
            }else if(i < batas-1){
            printf("%d %d\n",arr[i],arr[i+1]);
            flag++;
            }
        } 
    }
    if(flag == 0){
        printf("-1 -1\n");
    }
}

int main(){

    int K,N,target;
    scanf("%d",&K);

    for (int i = 0; i < K; i++)
    {
        scanf("%d",&N);
        int pemain[N];
        for (int j = 0; j < N; j++)
        {
            scanf("%d",&pemain[j]);
        }
        bubble_sort(pemain,N);
        scanf("%d",&target);

        printf("CASE #%d: ",i+1);
        matchmaking(pemain,N,target);
    }
    













    return 0;
}