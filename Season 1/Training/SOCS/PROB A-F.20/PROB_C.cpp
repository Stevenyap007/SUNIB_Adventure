#include <stdio.h>

char denah[100][100];
int N,M;
int lantai;

void floodfill( int i, int j){
    //base case
    if( denah[i][j] == '#' || i < 0 || j < 0 || i >= N || j >= M){
        return;
    }
    //food
    if(denah[i][j] == '.'){
        lantai += 1;
    }
    denah[i][j] = '#'; //menunjukkan telah dikunjungi
    
    floodfill(i-1, j); // atas
    floodfill(i+1, j); // bawah
    floodfill(i, j-1); // kiri
    floodfill(i, j+1); // kanan
}
int main(){
    int T;
    scanf("%d",&T);

    for (int i = 0; i < T; i++)
    {
        lantai = 0;
        scanf("%d %d",&N,&M);
        denah[N][M];
        for (int j = 0; j < N; j++)
        {
            scanf("%s",&denah[j]);
        }

        for (int k = 0; k < N; k++)
        {
            for (int l = 0; l < M; l++)
            {
                if(denah[k][l] == 'S'){
                    floodfill(k, l);
                    break;
                }    
            }
            
        }
        printf("Case #%d: %d\n", i+1, lantai);
        

    }
    













    return 0;
}