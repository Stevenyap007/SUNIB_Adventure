#include <stdio.h>
#include <string.h>
#define INF 999999999

int e[110][110], vis[110], d[110],n;

int min_pos(){
    int i,min=INF,j;
    for ( i = 0; i <=n-1; i++)
    {
        if(vis[i]==0&&d[i]<min){
            min=d[i];
            j=i;
        }
    }
    return j;
}

void dijkstra(){
    int i,j,count=1;
    vis[0]=1;
    for ( i = 0; i <=n-1; i++)
    {
        d[i]=e[0][i];
    }
    while(count<=n-1){
        j=min_pos();
        vis[j]=1;
        for ( i = 0; i <=n-1; i++)
        {
            if(vis[i]==0&&d[i]>d[j]+e[j][i]){
                d[i]=d[j]+e[j][i];
            }
        }
        count++;
    }
    
}

int main(){
    int u,k,v,c,i,j;
    memset(e,0,sizeof(e));
    memset(vis,0,sizeof(vis));
    scanf("%d",&n);
    for ( i = 0; i <=n-1; i++)
    {
        for ( j = 0; j <=n-1; j++)
        {
            if(i==j) e[i][j]=0;
            else e[i][j]=INF;
        }
        
    }
    for ( i = 1; i <=n; i++)
    {
        scanf("%d%d",&u,&k);
        for ( j = 1; j <=k; j++)
        {
            scanf("%d%d",&v,&c);
            e[u][v]=c;
        }
        
    }
    dijkstra();
    for ( i = 0; i <=n-1; i++)
    {
        printf("%d %d\n",i,d[i]);
    }
    return 0;
    
}