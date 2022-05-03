#include <stdio.h>

int main (){

int N;
long long int daftar[100000];
long long int jumlah = 0;

scanf ("%d",&N);

for (int i = 0; i < N; i++)
{
    scanf("%lld",&daftar[i]);
    if (daftar[i] > 0){
        jumlah += daftar[i];
    }
}
printf("%lld\n",jumlah);



    return 0;
}