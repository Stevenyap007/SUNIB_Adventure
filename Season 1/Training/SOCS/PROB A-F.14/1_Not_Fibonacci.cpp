#include <stdio.h>

// 0 + 1 = 1
// 1 + 1 = 2
// 1 + 2 = 3
// 2 + 3 = 5 

int main (){

    int a,b,c;

    scanf("%d %d",&a,&b);
    scanf("%d",&c);
    int total;
    for (int i = 0; i < c - 1; i++)
    {
        
        total = a + b;
        a = b;
        b = total;
    }
    
    printf("%d\n",total);









    return 0;
}