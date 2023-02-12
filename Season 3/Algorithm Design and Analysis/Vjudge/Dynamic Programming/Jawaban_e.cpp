#include <bits/stdc++.h>
using namespace std;

int INF = 0x3f3f3f3f;
int dist[25][25];
int dp[1<<16][25];

int main(){
    int n,m;
    cin >> n >> m;
    memset(dist,INF,sizeof(dist));
    for(int i = 1 ; i<=m ; i++ ){
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v] = w;
    }

    memset(dp, INF, sizeof(dp));
    dp[1][0] = 0;
    for(int s = 0; s< (1<<n); s++){
        for(int i = 0; i < n; i++){
            if(s & (1<<i)){
                for (int j = 0; j < n;j++){
                    if(j != i && (s & (1<<j))){
                        dp[s][i] = min(dp[s][i], dp[s ^ 1 << i][j] + dist[j][i]);
                    }
                }
            }
        }
    }

    int ans = INF;
    for (int i = 1; i < n; i++) {
        ans = min(ans, dp[(1<<n) - 1][i] + dist[i][0]);
    }
    if (ans == INF) ans = -1;
        cout << ans << endl;
    
    return 0;


}
