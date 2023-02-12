#include<stdio.h>

int main(){
    int n,t;
    scanf("%d",&n);
    int arr[n];
    int count = 0;
    int temp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                count++;
            }
        }
        
    }

    printf("%d",count);
    return 0;
    
    
}