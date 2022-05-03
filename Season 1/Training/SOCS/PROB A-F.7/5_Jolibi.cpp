#include <stdio.h>
#include <stdlib.h>
int main (){

    int N;
    scanf("%d",&N);
    int Jojo, Lili, Bibi;
    int peserta[N];
    int  total = 0;

    scanf("%d %d %d",&Jojo,&Lili,&Bibi);

    for (int i = 0; i < N ; i++) {
        scanf("%d",&peserta[i]);
    }    
    for (int j = 0; j < N ; j++){
        total += peserta[j];  
    }

    total = total + Jojo + Lili +  Bibi;
    total /= N + 3;

    if(Jojo < total){
        printf("Jojo tidak lolos\n");
    } else if (Jojo == total || Jojo > total){
        printf("Jojo lolos\n");
    }

    if(Lili < total){
        printf("Lili tidak lolos\n");
    } else if (Lili == total || Lili > total){
        printf("Lili lolos\n");
    }

    if(Bibi < total){
        printf("Bibi tidak lolos\n");
    } else if (Bibi == total || Bibi > total){
        printf("Bibi lolos\n");
    }
    






    return 0;
}