#include <stdio.h>


int main (){

    int T;
    int N,M;
    int temp;
    scanf("%d",&T);

    for (int x = 0; x < T; x++)
    {
        scanf("%d %d",&N,&M);
        char stage[N][M];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                scanf(" %c",&stage[i][j]);   
            }            
        }
        int makan  = 0;
    for (int i = 1; i < N-1; i++)
    {
        if(i % 2 != 0){
            for (int j = 1; j < M-1; j++)
            {
                if((stage[i][j] == 'P') && (stage[i][j+1] == '.')){
                    temp = stage[i][j];
                    stage[i][j] = stage[i][j+1];
                    stage[i][j+1] = temp;
                }else if((stage[i][j] == 'P') && (stage[i][j+1] == '*')){
                    temp = stage[i][j];
                    stage[i][j] = stage[i][j+1];
                    stage[i][j+1] = temp;
                    makan++;
                }else if ((stage[i][j] == 'P') && (stage[i+1][j] == '*')){
                    temp = stage[i][j];
                    stage[i+1][j] = stage[i][j];
                    stage[i+1][j] = temp;
                    makan++;
                }
            }
        }else if (i % 2 == 0){
            for (int j = 1; j < M-1; j++)
            {
                if((stage[i][M - j - 1] == 'P') && (stage[i][M - j - 2] == '.')){
                    temp = stage[i][j];
                    stage[i][j] = stage[i][j+1];
                    stage[i][j+1] = temp;
                }else if((stage[i][M - j - 1] == 'P') && (stage[i][M - j - 2] == '*')){
                    temp = stage[i][M - j - 1];
                    stage[i][M - j - 1] = stage[i][M - j -2];
                    stage[i][M - j - 2] = temp;
                    makan++;
                }else if((stage[i][M - j - 1] == 'P') && (stage[i+1][M - j - 1] == '*')){
                    temp = stage[i][M - j - 1];
                    stage[i+1][M - j - 1] = stage[i][M - j - 1];
                    stage[i+1][M - j - 1] = temp;
                    makan++;
                }
            }
        }    
    }
        printf("Case #%d: %d\n",x+1,makan);
        

    }
    return 0;
}

