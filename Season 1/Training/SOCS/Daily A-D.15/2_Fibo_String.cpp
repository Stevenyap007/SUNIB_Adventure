#include<stdio.h>

char Fibonacci_Kata(int n,char a, char b){
    if (n==0){
        printf("%c", a);
    } else if (n==1){
        printf("%c", b);
    }else{
        return Fibonacci_Kata(n-1,a, b) + Fibonacci_Kata(n-2,a, b);
    } 
}

int main()
{
    int T;
    scanf("%d", &T);

    for(int i=0;i<T;i++){
        char huruf1, huruf2;
        int n;

        scanf("%d %c %c", &n, &huruf1, &huruf2);
        getchar();
        printf("Case #%d: ", i+1);
        Fibonacci_Kata(n, huruf1, huruf2);
        printf("\n");
    }
    return 0;
}