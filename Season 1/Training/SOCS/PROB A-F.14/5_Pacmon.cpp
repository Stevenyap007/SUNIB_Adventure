#include <stdio.h>

char map[100][100];
int a, b, Poin_Makan;

void floodfill( int i, int j){
    
    if( map[i][j] == '#' || i < 0 || j < 0 || i >= a || j >= b){
        return;
    } 
    if(map[i][j] == '*'){
        Poin_Makan += 1;
    }
    map[i][j] = '#'; 
    
    floodfill(i-1, j); //atas
    floodfill(i+1, j); //bawah
    floodfill(i, j-1); //kiri
    floodfill(i, j+1); //kanan
}

int main(){
    int T;
    scanf("%d", &T); 
    
    for( int i = 1; i <= T; i++){
        Poin_Makan = 0;
        scanf("%d %d", &a, &b); 
        
        for( int j = 0; j < a; j++){
            scanf("%s", map[j]); 
        }
        for( int k = 0; k < a; k++){
            for( int l = 0; l < b; l++){
                if(map[k][l] == 'P'){
                    floodfill(k, l);
                    break;
                }
            }
        }
        printf("Case #%d: %d\n", i, Poin_Makan);
    }    
}
   
/*
2
5 5
#####
#P..#
###.#
#*.*#
#####
5 5
#####
#P#*#
#####
#.*.#
#####
*/    