#include <stdio.h>

int main() {
    int N;
    int count;
    int arr[1001] = {};

    scanf("%d",&N);
    getchar();
    arr[N];
    

    for (int i = 0; i < N; i++)
    {
        scanf("%d",&arr[i]);
    }

    for (int j = 0; j < N; j++)
    {
        if(j == 0 && arr[j] < 0){
            count++;
        }else if(arr[j] < 0){
            for (int k = j; k >= 0; k--)
            {
                if(-arr[k] == arr[j]){
                    break;
                }else if(k == 0){
                    count++;
                }
            }
            
        }
    }
    
    printf("%d\n",count);

    return 0;
}