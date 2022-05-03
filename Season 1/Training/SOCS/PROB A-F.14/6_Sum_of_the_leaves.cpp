#include <stdio.h>

int Pohon_Faktor[202];

void trav( int akar, int sum){
    if(Pohon_Faktor[akar] == 0){
        return;
    } else {
        sum += Pohon_Faktor[akar];    
        if(Pohon_Faktor[akar*2] == 0 && Pohon_Faktor[akar*2+1] == 0){
            printf("%d\n", sum);
        } else {
            trav(akar*2, sum);
            trav(akar*2+1, sum);
        }
    }
}

int main(){
    int T, N;
    scanf("%d", &T); 
    
    for( int i = 1; i <= T; i++){
        scanf("%d", &N);
        
        for( int j = 1; j <= 201; j++){
            Pohon_Faktor[j] = 0;
        }
        for( int k = 1; k <= N; k++){
            scanf("%d", &Pohon_Faktor[k]);
        }
        printf("Case #%d:\n", i);
        trav(1,0);
    }
    return 0;
}