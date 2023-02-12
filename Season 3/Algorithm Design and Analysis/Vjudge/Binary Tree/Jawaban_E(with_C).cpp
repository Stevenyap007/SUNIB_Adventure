#include <stdio.h>

int main(){
    int n,x,y;
    int i[10000];
    int cost = 0;

    while (scanf("%d", &n), n)
    {
       for (x = 0; x < n; x++)
       {
            scanf("%d", &i[x]);
       }
       cost = 0;
       for (x = 1; x < n; x++)
       {
            for ( y = x; y < n; y++)
            {
                if(i[y]<i[x-1]){
                    i[y]^=i[x-1]^=i[y]^=i[x-1];
                }
            }
            for (y = x; y < n; y++)
            {
                if(i[y]<i[x]){
                    i[y]^=i[x]^=i[y]^=i[x];
                }
            }
            cost+=(i[x]=i[x]+i[x-1]);
       }
       printf("%d\n", cost);
       break;
    }
    return 0;
}