#include <stdio.h>
#include <string.h>

void Recursive_kata(char kata[],int awal,int n){
    int temp;
    if(awal >= n){
        return;
    }
    temp = kata[n];
    kata[n] = kata[awal];
    kata[awal] = temp;

    Recursive_kata(kata,awal+1,n-1);
}

void Print_Kata(char kata[],int n){
    for (int i = 0; i < n ; i++)
    {
        printf("%c",kata[i]);
    }
    printf("\n");
}

int main(){

    int T;
    char kata[1000];
    scanf("%d",&T);

    for (int i = 0; i < T; i++)
    {
        scanf(" %[^\n]s",&kata);
        int n = strlen(kata);
        Recursive_kata(kata,0,n-1);
        printf("Case #%d: ",i+1);
        Print_Kata(kata,n);
    }

    return 0;
}