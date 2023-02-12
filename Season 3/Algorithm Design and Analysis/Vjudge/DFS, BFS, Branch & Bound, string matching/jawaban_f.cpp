#include <stdio.h>
#include <stdlib.h>
#define bit(x,y)(((x)>>(y))&1)

int x[8];

void chess(int a,int b, int c, int d){
    if(d==8){
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                putchar(x[i]==j?'Q':'.');
            }
            puts("");
        }
        exit(0);
    }
    if(x[d]!=-1){
        int t=1<<x[d];
        if(!bit(a|b|c,x[d])){
            chess((a|t)<<1,(b|t),(c|t)>>1,d+1);
        }
        return;
    }
    for (int j = 0; j < 8; j++)
    {
        if(!bit(a|b|c,j)){
            x[d]=j;
            int t=1<<j;
            chess((a|t)<<1,(b|t),(c|t)>>1,d+1);
            x[d]=-1;
        }
    }
    
}

int main(){
    int k;
    scanf("%d",&k);
    for (int i = 0; i < 8; i++)
    {
        x[i]=-1;
    }
    while (k--)
    {
        int r,c;
        scanf("%d %d",&r,&c);
        x[r]=c;
    }
    chess(0,0,0,0);
    return 0;
}