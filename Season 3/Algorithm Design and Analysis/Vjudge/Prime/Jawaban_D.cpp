#include <stdio.h>
#include <stdbool.h>

bool arr[200000000];
long long int arr2[200000000];
int a = 0;

void saring(){
    arr[0] = arr[1] = false;
    for (long long int i = 2; i < 200000000; i++){
        arr[i] = true;
    }
    for (long long int i = 2; i < 200000000; i++)
    {
        if(arr[i]){
            for (long long int j = i * i; j < 200000000 ; j+= i)
            {
                arr[j] = false;
            }
            arr2[a] = i;
            a++;
        }
    }    
}

int main(){

    long long int n, angka, cek = 0;
    scanf("%lld", &n);

    saring();
    for (int i = 0; i < n; i++)
    {
        scanf("%lld",&angka);
        if(angka < 200000000){
            if(arr[angka]){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
        if (angka > 200000000){
            for (long long int i = 0; i < a; i++)
            {
                if (angka % arr2[i] == 0){
                    printf("NO\n");
                    cek = 1;
                    break;
                }
            }
            if (!cek){
                printf("YES\n");
            }
        }
        cek = 0;
    }
    



    return 0;
}