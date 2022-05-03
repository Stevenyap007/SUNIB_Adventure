#include <stdio.h>

int main(){

    int N;
    int M;
    int Q;
    int jumlah;

    scanf("%d",&N);
    int jumlah_elemen[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&jumlah_elemen[i]);
    }
    
    scanf("%d",&Q);

    for (int j = 0; j < Q; j++)
    {
        int total = 0;
        jumlah = 0;
        scanf("%d",&M);
        for (int k = 0; k < N; k++)
        {
            jumlah += jumlah_elemen[k];
            if(jumlah <= M){
                total++;
            }else{
                break;
            }
            
        }
        printf("Case #%d: %d\n",j+1,total);

    }
    
    

    return  0;
}