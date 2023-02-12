#include <stdio.h>

#define max 100000000
int a[max];

int main(){

    int i,j,p=0;
    a[0] = 1;
    a[1] = 1;

    for (int i = 4; i <= max; i+=2)
    {
        a[i] = 1;
    }
    for (int i = 3; i*i <= max; i+=2)
    {
        if(a[i]==0){
            for (int j = 3*i; j <= max; j+=(2*i))
            {
                a[j]=1;
            }
            
        }
    }
    for (int i = 0; i <= max; i++)
    {
        if(a[i]==0){
            p++;
            if(p%100==1){
                printf("%d\n",i);
            }
        }
    }
    
    





    return 0;
}