#include <stdio.h>
#include <string>

int baca;

float diskon (char tipe,int harga){
    float potongan;
    printf("%d",baca);

    if (tipe == 'A'){
        potongan = 80;
        printf("%f",potongan);
    }
    return potongan;
}

int main(){
    int baca;
    char tipe;
    int harga = 80;
    scanf("%c",&tipe);
    diskon (tipe,harga);
  







    return 0;
}