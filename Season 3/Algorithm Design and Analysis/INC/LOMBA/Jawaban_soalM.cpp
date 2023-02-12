#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
    int tc,result = 0, count = 1, temp=0;

    scanf("%d",&tc);
    getchar();
    
    int arr[tc];
    
    for(int i=0;i<tc;i++){
        scanf("%d", &arr[i]);

        if(i%2 == 0 && i != 0){
            if(arr[i-2]> arr[i]){
                arr[i-1] = arr[i-2] - 1;
            }
            else{
                arr[i-1] = arr[i-2] + 1;
            }
        }else{
            temp++;
        }
    }
    
    if(tc%2 == 0){
        arr[tc-1] = arr[tc-2] + 1;
    }
    
    int i=0;
    while(i < tc){
        if(abs(arr[i] - arr[i+1]) == 1){
            count++;
        }
        else{
            count = i%2==0 ? 1:2 ;
        } 
        if(result < count){
            result = count;
        }
        i++;
    }
    printf("%d\n",result);

    return 0;
}