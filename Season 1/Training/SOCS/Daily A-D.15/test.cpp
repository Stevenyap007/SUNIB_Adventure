#include<stdio.h>

char fibbostring (char f1, char f2, int n){
    if (n==0){
        printf("%c", f1);
    } else if (n==1){
        printf("%c", f2);
    } else {
        return fibbostring(f1, f2, n-1) + fibbostring(f1, f2, n-2);
    }
}

int main()
{
    int testcase;
    scanf("%d", &testcase);

    for(int i=0;i<testcase;i++){
        char f1, f2;
        int n;

        scanf("%d %c %c", &n, &f1, &f2);
        getchar();
        printf("Case #%d: ", i+1);
        fibbostring(f1, f2, n);
        printf("\n");
    }
    return 0;
}