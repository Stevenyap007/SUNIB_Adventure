#include <stdio.h>

int main (){

    int T;
    int A,B,C;
    int potongan;

    scanf("%d",&T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d %d",&A,&B,&C);
        potongan = A * B/100;
        printf("Case #%d: ",i+1);
        if (potongan > C){
            printf ("%d\n",C);
        }else{
            printf("%d\n",potongan);
        }
    }
    






    return 0;
}