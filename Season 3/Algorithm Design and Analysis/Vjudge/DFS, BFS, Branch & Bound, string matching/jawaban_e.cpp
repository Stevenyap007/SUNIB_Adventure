#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
std::vector<int>adj[N];
int par[N];
bool vis[N];

void dfs(int u, int p){
    vis[u] = true;
    par[u] = p;
    for (auto x : adj[u])
    {
        if(!vis[x]){
            dfs(x,p);
        }
    }
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    while (m--)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        if(!vis[i]){
            dfs(i,i);
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int s,t;
        cin >> s >> t;
        if(par[s]==par[t]){
            cout << "yes\n";
        }else{
            cout << "no\n";
        }
    }
    return 0;
    
    
}