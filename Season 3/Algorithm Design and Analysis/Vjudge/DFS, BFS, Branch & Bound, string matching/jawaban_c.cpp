#include <stdio.h>
#include <string.h>
int a[110][110];
int d[110],f[110],vis[110],tag=0,n;

void dfs(int u){
    
    vis[u]=1;
    tag++;
    d[u]=tag;
    for (int v = 1; v <=n ; v++)
    {
        if(vis[v]==0&&a[u][v]){
            dfs(v);
        }
    }
    tag++;
    f[u]=tag;
    
}

int main(){
    int u,k,v;
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d",&u,&k);
        for (int j = 1; j <=k; j++)
        {
            scanf("%d",&v);
            a[u][v]=1;
        }    
    }

    for (int i = 1; i <=n ; i++)
    {
        if(vis[i]==0){
            dfs(i);
        }
    }
    for (int i = 1; i <=n ; i++)
    {
        printf("%d %d %d\n",i,d[i],f[i]);
    }
    return 0;

    
}